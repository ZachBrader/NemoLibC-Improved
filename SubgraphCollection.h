#ifndef SUBGRAPHCOLLECTION_H
#define SUBGRAPHCOLLECTION_H

#include "Config.hpp"
#include "Subgraph.hpp"
#include "NautyLink.h"
#include "graph64.h"
#include "SubgraphEnumerationResult.h"
#include <fstream>

// forward declare types for references below
class Subgraph;
class NautyLink;

class SubgraphCollection : public SubgraphEnumerationResult
{
public:
	// Constructors
	SubgraphCollection()
	{
		subgraphCollectionFile.open("SubgraphCollection.txt");
		nemoCollectionFile.open("NemoCollection.txt");
	}
	virtual ~SubgraphCollection() {
		std::cout << "Nemo Collection Results are recorded under nemoCollection.txt" << std::endl;
		subgraphCollectionFile.close();
		nemoCollectionFile.close();
	}
	SubgraphCollection(const SubgraphCollection& other) = default;

	// Subgraph Enumeration Result
	virtual void add(Subgraph& currentSubgraph, NautyLink& nautylink)
	{
		graph64 label = nautylink.nautylabel(currentSubgraph);
		uint64_t total = (labelFreqMap.count(label) == 0 ? 1 : labelFreqMap[label] + 1);
		labelFreqMap[label] = total;
		labelToSubgraph[label].push_back(currentSubgraph);
		subgraphCollectionFile << std::to_string(label) + "\n" << currentSubgraph << "\n";
	}

	virtual std::unordered_map <graph64, double> getRelativeFrequencies(void)
	{
		std::unordered_map<graph64, double> result_map;
		uint64_t totalSubgraphCount = 0;

		for (auto& p : labelFreqMap)
		{
			totalSubgraphCount += labelFreqMap[p.first];
		}

		for (auto& p : labelFreqMap)
		{
			double count = static_cast<double>(labelFreqMap[p.first]);
			result_map[p.first] = count / static_cast<double>(totalSubgraphCount);
		}

		return result_map;
	}

	virtual void buildFile(int graphSize, Statistical_Analysis::stats_data& data)
	{
		for (auto& p : labelToSubgraph)
		{
			if (Statistical_Analysis::getPValue(p.first, data) <= 0.05)
			{
				for (auto& q : labelToSubgraph[p.first])
				{
					nemoCollectionFile << std::to_string(p.first) + "\n" << q << "\n";
				}
			}
		}
	}

	//Getters
	inline std::unordered_map<graph64, uint64_t> getlabeFreqMap()
	{
		return labelFreqMap;
	}

private:
	std::ofstream subgraphCollectionFile;
	std::ofstream nemoCollectionFile;
	std::unordered_map<graph64, uint64_t> labelFreqMap;
	std::unordered_map<graph64, std::vector<Subgraph>> labelToSubgraph;
};

#endif /* SUBGRAPHCOLLECTION_H */

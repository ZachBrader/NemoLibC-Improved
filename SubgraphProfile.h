/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SubgraphProfile.h
 * Author: Wooyoung
 *
 * Created on October 29, 2017, 3:05 PM
 */

#ifndef SUBGRAPHPROFILE_H
#define SUBGRAPHPROFILE_H

#include "Config.hpp"
#include "SubgraphEnumerationResult.h"
#include "Utility.hpp"
#include "graph64.h"
#include <fstream>
#include "Stats.hpp"
//#include <unordered_map>

using namespace Statistical_Analysis;

class Subgraph;
class NautyLink;

// The primary structure of a subgraph profile. Essentially a table to map
	// labels(String) and nodes(Integer) to the frequency of subgraphs
	// of type label that include the node.

/* This class will have two maps: subgraphprofile and subgraphcount map */
class SubgraphProfile:public SubgraphEnumerationResult {
public:
    // get the size of vertex as parameter
	SubgraphProfile()
	{
		subgraphProfileFile.open("SubgraphProfile.txt");
		nemoProfileFile.open("NemoProfile.txt");
	}
	virtual ~SubgraphProfile()
	{
                std::cout << "NemoProfile results were stored under NemoProfile.txt" << std::endl;
		subgraphProfileFile.close();
		nemoProfileFile.close();
	}

	std::unordered_map<graph64, uint64_t> getlabelFreqMap(int); //need subgraphsize to calculate frequency
	std::unordered_map <graph64, double> getRelativeFrequencies()
	{
		std::unordered_map<graph64, double> result_map;
		uint64_t totalSubgraphCount = 0;

		totalSubgraphCount = this->getTotalSubgaphCount();

		for (auto& p : labelToVertexToFreq)
		{
			int count = 0;
			for (auto& q : labelToVertexToFreq[p.first]) 
			{
				count += labelToVertexToFreq[p.first][q.first];
			}
			
			result_map[p.first] = count / static_cast<double>(totalSubgraphCount);
		}

		return result_map;
	}

	inline std::unordered_map<graph64, std::unordered_map<vertex, uint64_t>> getlabelToVertexToFreq()
	{
		return labelToVertexToFreq;
	}

	virtual void add(Subgraph& currentSubgraph, NautyLink& nautylink)
	{
		std::vector<vertex> vertices = currentSubgraph.getNodes();
		graph64 label = nautylink.nautylabel(currentSubgraph);
		std::unordered_map<vertex, uint64_t>& nodeToFrequency = labelToVertexToFreq[label];
		
		for (int i = 0; i < vertices.size(); i++) {
			int currentNode = currentSubgraph.get(i);
			uint64_t currentFreq = (nodeToFrequency.count(currentNode) == 0 ? 1 : nodeToFrequency[currentNode] + 1);
			nodeToFrequency[currentNode] = currentFreq;
		}
	}

	virtual void buildFile(int graphSize, Statistical_Analysis::stats_data& data)
	{
		int sizeOfSubgraph = graphSize;

		// Generate Subgraph Profile
		subgraphProfileFile << "Node" << "\t";
		for (auto& p : labelToVertexToFreq)
		{
			subgraphProfileFile << p.first << "\t";
		}
		subgraphProfileFile << std::endl;

		for (int i = 0; i < sizeOfSubgraph; i++)
		{
			subgraphProfileFile << i << "\t";
			for (auto& p : labelToVertexToFreq)
			{
				subgraphProfileFile << labelToVertexToFreq[p.first][i] << "\t";
			}
			subgraphProfileFile << std::endl;
		}

		// Generate NemoProfile -- Only includes motifs
		nemoProfileFile << "Node" << "\t";
		for (auto& p : labelToVertexToFreq)
		{
			if (Statistical_Analysis::getPValue(p.first, data) <= 0.05)
			{
				nemoProfileFile << p.first << "\t";
			}
		}
		nemoProfileFile << std::endl;

		for (int i = 0; i < sizeOfSubgraph; i++)
		{
			nemoProfileFile << i << "\t";
			for (auto& p : labelToVertexToFreq)
			{
				if (Statistical_Analysis::getPValue(p.first, data) <= 0.05)
				{
					nemoProfileFile << labelToVertexToFreq[p.first][i] << "\t";
				}
			}
			nemoProfileFile << std::endl;
		}
	}

private:
	std::unordered_map<graph64, std::unordered_map<vertex, uint64_t>> labelToVertexToFreq;
	std::ofstream nemoProfileFile;
	std::ofstream subgraphProfileFile;

	uint64_t getTotalSubgaphCount(void)
	{
		uint64_t totalcount = 0;
		for (auto& p : labelToVertexToFreq)
		{
			for (auto& q : labelToVertexToFreq[p.first])
			{
				totalcount += labelToVertexToFreq[p.first][q.first];
			}
		}
		return totalcount;
	}
};

#endif /* SUBGRAPHPROFILE_H */

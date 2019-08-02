#include "Config.hpp"
#include "Utility.hpp"
#include "Graph.h"
#include "SubgraphCount.hpp"
#include "SubgraphProfile.h"
#include "SubgraphCollection.h"
#include "Stats.hpp"
#include <chrono>
#include <string>
#include <iostream>
#include "ESU.h"
#include "RandomGraphAnalysis.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::chrono::seconds;
using std::chrono::milliseconds;


/*
 * Simple C++ Test Suite
 */

template<typename T>
void printmap(const T& _map)
{
	for (const auto& p : _map)
		cout << p.first << " => " << p.second << endl;
}


void display_help(string _name)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "\t" << _name << " [file path] [# threads] [motif size] [# random graphs]" << std::endl;
	std::cout << "\t\t[file path]       -- complete or relative path to graph (g6 or d6 formatted) file." << std::endl;
	std::cout << "\t\t[# threads]       -- number of threads to use (ignored for sequential nemolib)." << std::endl;
	std::cout << "\t\t[motif size]      -- size of motif to search for." << std::endl;
	std::cout << "\t\t[# random graphs] -- number of random graphs to use for ESU." << std::endl;
	std::cout << "\t\t[--h | --help]    -- use instead of [file path] to display this help menu." << std::endl;
} // end method display_help


int main(int argc, char** argv)
{
	if(argc > 1 && (string(argv[1]) == "--h" || string(argv[1]) == "--help"))
	{
		display_help(argv[0]);
		return 0;
	} // end if

	const string filename = argc > 1 ? argv[1] : "exampleGraph.txt";
	const std::size_t motifSize = argc > 2 ? atoi(argv[2]) : 3;
	const std::size_t randomCount = argc > 3 ? atoi(argv[3]) : 1000;
	const bool directed = argc > 4 ? (atoi(argv[4]) > 0 ? true : false) : false; // If not specified, assume undirected
	
	// NEMO COUNT
	SubgraphCount subc;

	// NEMO COLLECTION
	//SubgraphCollection subc;

	// NEMO PROFILE
	//SubgraphProfile subc;

	vector<double> probs(motifSize - 2, 1.0);
	probs.insert(probs.end(), { 0.5, 0.5 });
	auto begin = _Clock::now();
	Graph targetg(filename, directed);

	ESU::enumerate(targetg, dynamic_cast<SubgraphEnumerationResult*>(&subc), static_cast<int>(motifSize));

	std::unordered_map<graph64, double> targetLabelRelFreqMap(std::move(subc.getRelativeFrequencies()));

	cout << "Analyzing random graphs..." << endl << endl;

	std::unordered_map<graph64, vector<double>> randLabelRelFreqsMap = std::move(RandomGraphAnalysis::analyze(targetg, randomCount, motifSize, probs));

	cout << "Comparing target graph to random graphs ... " << endl << endl;

	Statistical_Analysis::stats_data data{&targetLabelRelFreqMap, &randLabelRelFreqsMap, randomCount};

	auto end = _Clock::now();

	cout << endl << data << endl;

	cout << "Time = " << chrono_duration<milliseconds, decltype(begin)>(begin, end) << " milliseconds." << endl;
	cout << "Time = " << chrono_duration<seconds, decltype(begin)>(begin, end) << " seconds." << endl;

	return (EXIT_SUCCESS);
}

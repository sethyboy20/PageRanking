#include <iostream>
#include "Graph.h"

int main()
{
	// Create empty graph
	Graph createdGraph;

	// Read # of lines and power iterations
	int no_of_lines, power_iterations;
	std::string from, to;
	std::cin >> no_of_lines;
	std::cin >> power_iterations;

	// Read each edge ("from" URL links to "to" URL)
	// Add each edge to the graph (Adjacency list)
	for (int i = 0; i < no_of_lines; i++) {
		std::cin >> from;
		std::cin >> to;
		createdGraph.addEdge(from, to);
	}

	// Retrieve the page rank
	createdGraph.pageRank(power_iterations);
}
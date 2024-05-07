#include "Graph.h"
#include <iostream>
#include <iomanip>

Graph::Graph() { // Constructor
    numVertices = 0;
}

void Graph::addEdge(std::string from, std::string to) {

    // Add from/to vertices to the vertices container
    if (vertices.find(from) == vertices.end())
            vertices[from] = numVertices++;
    if (vertices.find(to) == vertices.end())
            vertices[to] = numVertices++;

    // Get the int key and val for the edge container
    int key = vertices.find(from)->second;
    int val = vertices.find(to)->second;

    // Insert the edge
    edges[key].insert(val);
}

bool Graph::findEdge(int from, int to) {
    // Traverse the out-edges of the "from" vertex
    // Determine if an edge pointing to "to" vertex exists
    if (edges[from].find(to) != edges[from].end())
        return true;

    return false;
}

void Graph::pageRank(int p) {

    // Create initial rank vector r(0)
    std::vector<double> rank;
    for (int i = 0; i < numVertices; i++) {
        rank.push_back((double)1/numVertices);
    }
    
    // Begin power iterations
    for (int powIter = 1; powIter < p; powIter++) {
        // Create next rank vector
        std::vector<double> newRank;

        // Iterate through each list of vertices doing matrix multiplication (M.r)
        // This forms the next iteration of the rank vector
        for (int i = 0; i < numVertices; i++) {
            double newVal = 0;
            for (int j = 0; j < numVertices; j++) {
                // If there is an edge from j to i,
                // multiply 1/outdegree(j) by corresponding rank value
                if (findEdge(j, i))
                    newVal += ((double) 1 / edges[j].size()) * rank[j];
            }
            newRank.push_back(newVal);
        }
        rank = newRank;
    }

    // Print the page rank for all URLs (alphabetical order)
    for (auto it : vertices) {
        std::cout << std::fixed << std::setprecision(2) << it.first << " " << rank[it.second] << std::endl;
    }
} 

std::map<std::string, int> Graph::getVertices() { // FOR TESTING
    return vertices;
}

std::map<int, std::set<int>> Graph::getEdges() { // FOR TESTING
    return edges;
}

std::vector<double> Graph::getRank(int p) { // FOR TESTING

    // Create initial rank vector r(0)
    std::vector<double> rank;
    for (int i = 0; i < numVertices; i++) {
        rank.push_back((double)1/numVertices);
    }
    
    // Begin power iterations
    for (int powIter = 1; powIter < p; powIter++) {
        // Create next rank vector
        std::vector<double> newRank;

        // Iterate through each list of vertices doing matrix multiplication (M.r)
        // This forms the next iteration of the rank vector
        for (int i = 0; i < numVertices; i++) {
            double newVal = 0;
            for (int j = 0; j < numVertices; j++) {
                // If there is an edge from j to i,
                // multiply 1/outdegree(j) by corresponding rank value
                if (findEdge(j, i)) {
                    double edgeNum = edges[j].size();
                    newVal += ((double) 1 / edgeNum) * rank[j];
                }
            }
            newRank.push_back(newVal);
        }
        rank = newRank;
    }

    return rank;
}

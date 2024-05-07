#pragma once
#include <string>
#include <map>
#include <set>
#include <vector>

class Graph {
    private:
    int numVertices;
    std::map<std::string, int> vertices; // Store/map vertices to numbers
    std::map<int, std::set<int>> edges; // Store edges connected by vertices
    bool findEdge(int from, int to);
    public:
    Graph();
    void addEdge(std::string from, std::string to);
    void pageRank(int p);
    std::map<std::string, int> getVertices(); // FOR TESTING
    std::map<int, std::set<int>> getEdges(); // FOR TESTING
    std::vector<double> getRank(int p); // FOR TESTING
};
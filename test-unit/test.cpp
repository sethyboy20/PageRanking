#define CATCH_CONFIG_MAIN
#include "../src/Graph.h"
#include "../src/Graph.cpp"
#include "catch.hpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("1 Power Iteration", "[flag]"){
	Graph createdGraph;

	createdGraph.addEdge("seth", "john");
	createdGraph.addEdge("seth", "amy");
	createdGraph.addEdge("mike", "amy");
	createdGraph.addEdge("chris", "mike");
	createdGraph.addEdge("carol", "mike");
	createdGraph.addEdge("carol", "seth");
	createdGraph.addEdge("dave", "mike");
	createdGraph.addEdge("steve", "john");

	std::vector<double> rank = createdGraph.getRank(1);

	REQUIRE(rank.size() == 8);
	for (int i = 0; i < rank.size(); i++) {
		REQUIRE(rank[i] == (double)1/8);
	}
}

TEST_CASE("2 Power Iterations", "[flag]"){
	Graph createdGraph;

	createdGraph.addEdge("seth", "john");
	createdGraph.addEdge("seth", "amy");
	createdGraph.addEdge("mike", "amy");

	std::vector<double> rank = createdGraph.getRank(2);

	REQUIRE(rank.size() == 4);
	REQUIRE(rank[0] == 0);
	REQUIRE(rank[1] == (double)1/8);
	REQUIRE(rank[2] == (double)3/8);
	REQUIRE(rank[3] == 0);
}

TEST_CASE("Inserting 10,000 Vertices", "[flag]"){
	Graph createdGraph;

	for (int i = 0; i < 9999; i++) {
		createdGraph.addEdge(std::to_string(i), "test");
		createdGraph.addEdge("test", std::to_string(i));
	}

	std::map<std::string, int> vertices = createdGraph.getVertices();

	REQUIRE(vertices.size() == 10000);
}

TEST_CASE("10,000 Power Iterations", "[flag]"){
	Graph createdGraph;

	createdGraph.addEdge("seth", "john");
	createdGraph.addEdge("john", "seth");

	std::vector<double> rank = createdGraph.getRank(10000);

	REQUIRE(rank.size() == 2);
	REQUIRE(rank[0] == (double)1/2);
	REQUIRE(rank[1] == (double)1/2);
}

TEST_CASE("100 Vertices & 5 Iterations", "[flag]"){
	Graph createdGraph;

	createdGraph.addEdge("test", "test");
	for (int i = 0; i < 99; i++) {
		createdGraph.addEdge("test", std::to_string(i));
	}

	std::vector<double> rank = createdGraph.getRank(5);

	std::cout << std::pow((double)1/100, 100);
	REQUIRE(rank.size() == 100);
	for (int i = 0; i < 100; i++) {
		double tester = rank[i];
		REQUIRE(tester == Approx((double)1/(double)10000000000));
	}
}
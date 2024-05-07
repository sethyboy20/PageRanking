run:
	g++ -std=c++14 -Werror -Wuninitialized -o build/main src/main.cpp src/Graph.cpp && build/main
test:
	g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
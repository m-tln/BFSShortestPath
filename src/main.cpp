#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>

#include "Graph.hpp"
#include "BFS.hpp"
#include "BFSShortestPathVisitor.hpp"

void Input(uint64_t& vertexes_number, uint64_t& edges_number,
           std::vector<Edge<>>& edges, uint64_t& start) {
  std::ifstream input("../input/input.txt");
  input >> vertexes_number;
  input >> edges_number;
  edges.resize(edges_number);
  for (auto& [source, target] : edges) {
    input >> source >> target;
  }
  input >> start;
}

void Solve() {
  using Edge = Edge<uint64_t>;
  using Graph = Graph<Edge>;

  uint64_t vertexes_number;
  uint64_t edges_number;
  std::vector<Edge> edges;
  uint64_t start;

  Input(vertexes_number, edges_number, edges, start);

  Graph graph(edges);
  BFSShortestPathVisitor<Graph> visitor;
  BFS(graph, start, visitor);
  for (uint64_t i = 0; i < vertexes_number; ++i) {
    if (auto res = visitor.GetDistance(i); res.has_value()) {
      std::cout << res.value() << '\n';
    } else {
      throw std::logic_error(std::format("No path between {} and {}", start, i));
    }
  }
}

int main() {
  Solve();
}
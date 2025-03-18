#ifndef BFSSHORTESTPATH_GRAPH_HPP_
#define BFSSHORTESTPATH_GRAPH_HPP_

#include <cstdint>
#include <span>
#include <utility>
#include <vector>
#include <concepts>
#include <unordered_map>

template<typename Vertex = uint64_t>
class Edge {
 public:
  using VertexT = Vertex;
  Vertex source;
  Vertex target;

  Edge() = default;

  Edge(const Vertex& source, const Vertex& target) : source(source), target(target) {}
};


template<typename T, typename Vertex>
concept IsEdge = std::is_base_of_v<Edge<Vertex>, T>;
                                                                            
template<typename Edge>                                                     
requires IsEdge<Edge, typename Edge::VertexT>                               
class Graph {                                                               
 public:
  using EdgeT = Edge;
  using VertexT = Edge::VertexT;

  Graph(std::span<const Edge> edges);

  const std::vector<Edge>& GetOutGoingEdges(const VertexT& vertex) const {
    return edges_.at(vertex);
  }

 private:
  std::unordered_map<typename Edge::VertexT, std::vector<Edge>> edges_;
};

template<typename Edge>
requires IsEdge<Edge, typename Edge::VertexT>
Graph<Edge>::Graph(std::span<const Edge> edges) {
  for (const auto& [source, target] : edges) {
    edges_[source].emplace_back(source, target);
    edges_[target].emplace_back(target, source);
  }
}

#endif //BFSSHORTESTPATH_GRAPH_HPP_

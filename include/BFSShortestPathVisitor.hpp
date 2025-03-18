#ifndef BFSSHORTESTPATH_BFSShortestPathVisitor_HPP_
#define BFSSHORTESTPATH_BFSShortestPathVisitor_HPP_

#include <queue>
#include <unordered_map>
#include <optional>
#include <cstdint>
#include "Visitor.hpp"
#include "Graph.hpp"

template<typename Graph>
class BFSShortestPathVisitor : public AbstractVisitor<Graph> {
 public:
  void InitializeVertex(const Graph::VertexT& vertex) final;
  void ExamineVertex(Graph::VertexT& vertex) final;
  bool Empty() const;
  void EdgeRelaxed(const Graph::EdgeT& edge) final;
  std::optional<uint64_t> GetDistance(const Graph::VertexT& vertex) const;

 private:
  std::unordered_map<typename Graph::VertexT, uint64_t> dist_eval_;
  std::unordered_map<typename Graph::VertexT, bool> visited_;
  std::queue<typename Graph::VertexT> bfs_queue_;
};

#include "../src/BFSShortestPathVisitor.cpp"

#endif //BFSSHORTESTPATH_BFSShortestPathVisitor_HPP_

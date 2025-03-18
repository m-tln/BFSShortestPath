#ifndef BFSSHORTESTPATH_INCLUDE_BFS_HPP_
#define BFSSHORTESTPATH_INCLUDE_BFS_HPP_

#include "Graph.hpp"
#include "Visitor.hpp"


template<typename Graph, typename Visitor>
void BFS(const Graph& graph, const typename Graph::VertexT& start, Visitor& visitor) {
  visitor.InitializeVertex(start);
  while (!visitor.Empty()) {
    typename Graph::VertexT target;
    visitor.ExamineVertex(target);
    for (const auto& edge : graph.GetOutGoingEdges(target)) {
      visitor.EdgeRelaxed(edge);
    }
  }
}

#endif //BFSSHORTESTPATH_INCLUDE_BFS_HPP_

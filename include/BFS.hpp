#ifndef BFSSHORTESTPATH_INCLUDE_BFS_HPP_
#define BFSSHORTESTPATH_INCLUDE_BFS_HPP_

#include "Graph.hpp"
#include "Visitor.hpp"

template<typename Graph, typename Visitor>
void BFS(const Graph& graph, const typename Graph::VertexT& start, Visitor& visitor);

#include "../src/BFS.cpp"

#endif //BFSSHORTESTPATH_INCLUDE_BFS_HPP_

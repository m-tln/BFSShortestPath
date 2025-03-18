template<typename Edge>
requires IsEdge<Edge, typename Edge::VertexT>
Graph<Edge>::Graph(std::span<const Edge> edges) {
  for (const auto& [source, target] : edges) {
    edges_[source].emplace_back(source, target);
    edges_[target].emplace_back(target, source);
  }
}
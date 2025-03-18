
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
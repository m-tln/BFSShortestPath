template<typename Graph>
void BFSShortestPathVisitor<Graph>::InitializeVertex(const Graph::VertexT& vertex) {
  dist_eval_[vertex] = 0;
  visited_[vertex] = true;
  bfs_queue_.push(vertex);
}

template<typename Graph>
void BFSShortestPathVisitor<Graph>::ExamineVertex(Graph::VertexT& vertex) {
  vertex = bfs_queue_.front();
  bfs_queue_.pop();
  visited_[vertex] = true;
}

template<typename Graph>
bool BFSShortestPathVisitor<Graph>::Empty() const {
  return bfs_queue_.empty();
}

template<typename Graph>
void BFSShortestPathVisitor<Graph>::EdgeRelaxed(const Graph::EdgeT& edge) {
  const auto& [start, target] = edge;
  if (!visited_[target]) {
    visited_[target] = true;
    dist_eval_[target] = dist_eval_[start] + 1;
    bfs_queue_.push(target);
  }
}

template<typename Graph>
std::optional<uint64_t> BFSShortestPathVisitor<Graph>::GetDistance(const Graph::VertexT& vertex) const {
  if (dist_eval_.contains(vertex)) {
    return dist_eval_.at(vertex);
  }
  return std::nullopt;
}
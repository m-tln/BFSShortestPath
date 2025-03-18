#ifndef BFSSHORTESTPATH_VISITOR_HPP_
#define BFSSHORTESTPATH_VISITOR_HPP_

template<typename Graph>
class AbstractVisitor {
 public:
  virtual void InitializeVertex(const Graph::VertexT& vertex) = 0;
  virtual void ExamineVertex(Graph::VertexT& vertex) = 0;
  virtual void EdgeRelaxed(const Graph::EdgeT& edge) = 0;
  virtual ~AbstractVisitor() = default;
};

#endif //BFSSHORTESTPATH_VISITOR_HPP_

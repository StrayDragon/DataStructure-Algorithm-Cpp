#include <initializer_list>
#include <iostream>
#include <functional>
// .h
template <typename WeightType = int>
struct Edge;

template <typename WeightType = int>
class Graph {
 public:
  virtual int getNumberOfVertices() const = 0;
  virtual int getNumberOfEdges() const = 0;
  virtual WeightType getEdgeWeight(size_t vertexLabel1,
                                   size_t vertexLabel2) const = 0;
  virtual void addEdge(Edge<WeightType> e) = 0;
  virtual void removeEdge(Edge<WeightType> e) = 0;
  virtual void depthFirstTraversal(VertexType startPosition,
                                   std::function<void(T&)> visit) = 0;
  virtual void breadthFirstTraversal(VertexType startPosition,
                                     std::function<void(T&)> visit) = 0;
};

// .cpp
template <typename WeightType = int>
struct Edge {
  size_t vertexLabel1;
  size_t vertexLabel2;
  WeightType weight;
};

template <typename VertexType,
          typename WeightType = int,
          size_t MATRIX_NUM = 10>
class AdjMatrixGraph : public Graph<WeightType> {
  WeightType relationsOfVertices_[MATRIX_NUM][MATRIX_NUM];
  VertexType vertices_[MATRIX_NUM];
  size_t countOfVertices_;
  size_t countOfEdges_;

 public:
  AdjMatrixGraph();
  AdjMatrixGraph(const AdjMatrixGraph& graph);
  AdjMatrixGraph(std::initializer_list<Edge<WeightType>> edges);
  ~AdjMatrixGraph() = default;

  int getNumberOfVertices() const override;
  int getNumberOfEdges() const override;
  WeightType getEdgeWeight(size_t vertexLabel1,
                           size_t vertexLabel2) const override;
  void addEdge(Edge<WeightType> e) override;
  void removeEdge(Edge<WeightType> e) override;
  void depthFirstTraversal(VertexType startPosition,
                                   std::function<void(T&)> visit) override;
  void breadthFirstTraversal(VertexType startPosition,
                                     std::function<void(T&)> visit) override;
};

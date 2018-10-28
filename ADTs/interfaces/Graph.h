//
// Created by straydragon on 18-10-21.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H
#define DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H

/**
 * @brief 图(Graph) 接口声明
 *
 * @tparam VertexType 元素类型
 */
template <typename VertexType>
class Graph {
 public:
  virtual int getNumberOfVertices() const = 0;
  virtual int getNumberOfEdges() const = 0;
  virtual bool add(VertexType startPosition, VertexType endPosition, int edgeWight) = 0;
  virtual bool remove(VertexType startPosition, VertexType endPosition) = 0;
  virtual bool getEdgeWeight(VertexType startPosition, VertexType endPosition) const = 0;
  virtual void depthFirstTraversal(VertexType startPosition, void (*visit)(VertexType&)) = 0;
  virtual void breadthFirstTraversal(VertexType startPosition, void (*visit)(VertexType&)) = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H

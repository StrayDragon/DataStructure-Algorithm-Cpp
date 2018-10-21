//
// Created by straydragon on 18-10-21.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H
#define DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H

/**
 * @brief 图(Graph) 接口声明
 *
 * @tparam E 元素类型
 */
template <typename T>
class Graph {
 public:
  virtual int getNumberOfVertices() const = 0;
  virtual int getNumberOfEdges() const = 0;
  virtual bool add(T startPosition, T endPosition, int edgeWight) = 0;
  virtual bool remove(T startPosition, T endPosition) = 0;
  virtual bool getEdgeWeight((T startPosition, T endPosition)) const = 0;
  virtual void depthFirstTraversal((T startPosition, void (*visit)(T&))) = 0;
  virtual void breadthFirstTraversal((T startPosition, void (*visit)(T&))) = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H

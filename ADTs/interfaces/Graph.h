//
// Created by straydragon on 18-10-21.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H
#define DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H

#include <functional>
/**
 * @brief 图(Graph) 接口声明
 *
 * @tparam VertexType 顶点类型
 * @tparam EdgeWight 边权重类型,默认为int
 */
template <typename VertexType, typename EdgeWight = int>
class Graph {
 public:
  /**
   * @brief 获取顶点个数
   *
   * @return size_t 顶点个数
   */
  virtual size_t getNumberOfVertices() const = 0;

  /**
   * @brief 获得边的个数
   *
   * @return size_t 边的个数
   */
  virtual size_t getNumberOfEdges() const = 0;

  /**
   * @brief 加入指定边
   *
   * @param startPosition
   * @param endPosition
   * @param edgeWight
   * @return true
   * @return false
   */
  virtual bool add(VertexType startPosition,
                   VertexType endPosition,
                   EdgeWight edgeWight) = 0;
  // virtual bool addVertex(VertexType startPosition,
  //                  VertexType endPosition,
  //                  EdgeWight edgeWight) = 0;
  // virtual bool addEdge(VertexType startPosition,
  //                  VertexType endPosition,
  //                  EdgeWight edgeWight) = 0;

  /**
   * @brief 移除指定边
   *
   * @param startPosition
   * @param endPosition
   * @return true
   * @return false
   */
  virtual bool remove(VertexType startPosition, VertexType endPosition) = 0;
  // virtual bool removeEdge(VertexType startPosition, VertexType endPosition) =
  // 0; virtual bool removeVertex(VertexType startPosition, VertexType
  // endPosition) = 0;

  /**
   * @brief 获取指定边的权重
   *
   * @param startPosition
   * @param endPosition
   * @return false
   */
  virtual EdgeWight getEdgeWeight(VertexType startPosition,
                                  VertexType endPosition) const = 0;

  /**
   * @brief 深度优先遍历
   *
   * @param startPosition
   * @param visit
   */
  virtual void depthFirstTraversal(VertexType startPosition,
                                   std::function<void(T&)> visit) = 0;

  /**
   * @brief 广度优先遍历
   *
   * @param startPosition
   * @param visit
   */
  virtual void breadthFirstTraversal(VertexType startPosition,
                                     std::function<void(T&)> visit) = 0;
};
#endif  // DATASTRUCTURE_ALGORITHM_CPP_GRAPH_H

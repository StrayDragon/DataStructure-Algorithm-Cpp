//
// Created by straydragon on 18-10-27.
//
#ifndef DATASTRUCTURE_ALGORITHM_CPP_ADJACENCYMATRIXGRAPH_H
#define DATASTRUCTURE_ALGORITHM_CPP_ADJACENCYMATRIXGRAPH_H

#include <cstddef>
#include <string>
#include <vector>

#include "interfaces/Graph.h"
#include "interfaces/noncopyable.h"

template <typename VertexType, typename WeightType = int>
class AdjacencyMatrixGraph final : noncopyable,
                                   public Graph<VertexType, WeightType> {
  static const AcyclicGraphTypes TYPE = AcyclicGraphTypes::UNDIRECTED_WEIGHTED;

  static std::string GetTypeString() {
    return std::string("Undirected/Weighted AcyclicGraph");
  }

  static AcyclicGraphTypes GetType() { return TYPE; }

  struct Edge {
    VertexType v1_;
    VertexType v2_;
    WeightType weight_;

    Edge(VertexType v1, VertexType v2, WeightType weight = 0)
        : v1_(v1), v2_(v2), weight_(weight) {}
  };

  static const int MAX_VERTICES_NUM = 10;

 private:
  WeightType _relationTable[MAX_VERTICES_NUM][MAX_VERTICES_NUM];  //表示权重大小
  VertexType _vertices[MAX_VERTICES_NUM];                         //表示顶点
  std::vector<Edge> _edges;  //表示边信息
  size_t _countOfVertices;   //顶点数量
  size_t _countOfEdges;      //边数量

  bool _isFound(VertexType vertex);

 public:
  AdjacencyMatrixGraph();

  size_t getAmountOfVertices() const override;

  size_t getAmountOfEdges() const override;

  bool add(VertexType startPosition, VertexType endPosition) override;

  bool add(VertexType startPosition,
           VertexType endPosition,
           WeightType edgeWight) override;

  bool remove(VertexType startPosition, VertexType endPosition) override;

  WeightType getEdgeWeight(VertexType startPosition,
                           VertexType endPosition) const override;

  void depthFirstTraversal(VertexType startPosition,
                           std::function<void(VertexType&)> visit) override;

  void breadthFirstTraversal(VertexType startPosition,
                             std::function<void(VertexType&)> visit) override;
};

#include "AdjacencyMatrixGraph.cpp"

#endif  // DATASTRUCTURE_ALGORITHM_CPP_ADJACENCYMATRIXGRAPH_H

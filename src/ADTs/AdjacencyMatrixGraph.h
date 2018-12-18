//
// Created by straydragon on 18-10-27.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ADJACENCYMATRIXGRAPH_H
#define DATASTRUCTURE_ALGORITHM_CPP_ADJACENCYMATRIXGRAPH_H

#include <cstddef>
#include <initializer_list>
#include "interfaces/Graph.h"

template <typename VertexType, typename WeightType = int>
class AdjacencyMatrixGraph : public Graph<VertexType> {
  struct Edge {
    VertexType v1;
    VertexType v2;
    WeightType weight;
  };

  static const int MAX_VERTEX_NUM = 10;

 private:
  WeightType _relationTable[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  VertexType _vertices[MAX_VERTEX_NUM];
  int _countOfVertices;
  int _countOfEdges;

 public:
  AdjacencyMatrixGraph();

  AdjacencyMatrixGraph(std::initializer_list<Edge> vertices);

  AdjacencyMatrixGraph(const AdjacencyMatrixGraph& graph);

  ~AdjacencyMatrixGraph();

  int getNumberOfVertices() const override;

  int getNumberOfEdges() const override;

  bool add(VertexType startPosition, VertexType endPosition, int edgeWight) override;

  bool remove(VertexType startPosition, VertexType endPosition) override;

  bool getEdgeWeight(VertexType startPosition, VertexType endPosition) override;

  void depthFirstTraversal(VertexType startPosition, void (*visit)(T&)) override;

  void breadthFirstTraversal(VertexType startPosition, void (*visit)(T&)) override;
};

#include "AdjacencyMatrixGraph.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ADJACENCYMATRIXGRAPH_H

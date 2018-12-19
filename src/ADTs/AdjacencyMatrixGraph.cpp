//
// Created by straydragon on 18-10-27.
//

#include "AdjacencyMatrixGraph.h"

template<typename VertexType, typename WeightType>
AdjacencyMatrixGraph<VertexType, WeightType>::AdjacencyMatrixGraph():_countOfVertices(0), _countOfEdges(0) {
  for (int i = 0; i < MAX_VERTICES_NUM; ++i) {
    for (int j = 0; j < MAX_VERTICES_NUM; ++j) {
      _relationTable[i][j] = WeightType();
    }
    _vertices[i] = VertexType();
  }
}

template<typename VertexType, typename WeightType>
size_t AdjacencyMatrixGraph<VertexType, WeightType>::getAmountOfVertices() const {
  return _countOfVertices;
}

template<typename VertexType, typename WeightType>
size_t AdjacencyMatrixGraph<VertexType, WeightType>::getAmountOfEdges() const {
  return _countOfEdges;
}

template<typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::_isFound(VertexType vertex) {
  int index = -1;
  for (int i = 0; i < _countOfVertices; ++i) {
    if (vertex == _vertices[i])
      index = i;
  }
  return index >= 0;
}

template<typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::add(VertexType startPosition, VertexType endPosition) {

  if (_countOfVertices + 2 > MAX_VERTICES_NUM)
    return false;
  else {
    _eages.push_back(Edge(startPosition, endPosition));
    _countOfEdges++;

    if (!_isFound(startPosition))
      _vertices[_countOfVertices++] = startPosition;

    if (!_isFound(endPosition))
      _vertices[_countOfVertices++] = endPosition;

    return true;
  }
}

template<typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::add(VertexType startPosition,
                                                       VertexType endPosition,
                                                       WeightType edgeWight) {
  if (_countOfVertices + 2 > MAX_VERTICES_NUM)
    return false;
  else {
    _eages.push_back(Edge(startPosition, endPosition, edgeWight));
    _countOfEdges++;

    _relationTable[_countOfVertices][_countOfVertices + 1] = edgeWight;
    _relationTable[_countOfVertices + 1][_countOfVertices] = edgeWight;
    _vertices[_countOfVertices++] = startPosition;
    _vertices[_countOfVertices++] = endPosition;
    return true;
  }
}

template<typename VertexType, typename WeightType>
bool AdjacencyMatrixGraph<VertexType, WeightType>::remove(VertexType startPosition, VertexType endPosition) {
  return false;
}

template<typename VertexType, typename WeightType>
WeightType AdjacencyMatrixGraph<VertexType, WeightType>::getEdgeWeight(VertexType startPosition,
                                                                       VertexType endPosition) const {
  return WeightType();
}

template<typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::depthFirstTraversal(VertexType startPosition,
                                                                       std::function<void(VertexType&)> visit) {

}

template<typename VertexType, typename WeightType>
void AdjacencyMatrixGraph<VertexType, WeightType>::breadthFirstTraversal(VertexType startPosition,
                                                                         std::function<void(VertexType&)> visit) {

}

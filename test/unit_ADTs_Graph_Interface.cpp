//
// Created by straydragon on 18-12-19.
//

#include <gtest/gtest.h>

#include "../src/ADTs/interfaces/Graph.h"
#include "../src/ADTs/AdjacencyMatrixGraph.h"

template<typename VertexType, typename WeightType=int>
void GraphInterfaceTestSuit(Graph<VertexType, WeightType>* graph) {
  ASSERT_EQ(graph->getAmountOfVertices(), 0);
  ASSERT_EQ(graph->getAmountOfEdges(), 0);

  ASSERT_TRUE(graph->add(0, 1, 2));
  ASSERT_TRUE(graph->add(2, 1, 2));
  ASSERT_TRUE(graph->add(3, 1, 2));
  ASSERT_EQ(graph->getAmountOfVertices(), 4);
  ASSERT_EQ(graph->getAmountOfEdges(), 3);
}

TEST(ADTs_Graph_Interface, impl_AdjacencyMatrixGraph_int) {
  auto* adjMatrixGraph = new AdjacencyMatrixGraph<int>();
  GraphInterfaceTestSuit(adjMatrixGraph);
  delete adjMatrixGraph;
}
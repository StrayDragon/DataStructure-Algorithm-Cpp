//
// Created by straydragon on 18-12-20.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ADJLISTGRAPH_H
#define DATASTRUCTURE_ALGORITHM_CPP_ADJLISTGRAPH_H

#include <string>
#include <vector>
#include "../../ADTs/exceptions/Exception.h"
#include "../../ADTs/interfaces/noncopyable.h"

/**
 * @brief 无向无权图(最简单的图模型)
 * 允许出现 自环 和 出现 平行边 (连接同一对顶点的两条以上的边)
 *
 */
class SimplestAdjListGraph final : noncopyable {
  /**
   * @brief 顶点个数
   */
  const int v_;
  /**
   * @brief 边个数
   */
  int e_;
  /**
   * @brief 模拟表
   */
  std::vector<std::vector<int>> adj_;

 public:
  /**
   * @brief 创建一个含有v个顶点但不含边的图
   *
   * @param v 指定的v个顶点
   */
  explicit SimplestAdjListGraph(int v) : v_(v), e_(0), adj_(v) {}

  /**
   * @brief 添加一条边 v1-v2
   *
   * @param v1 顶点1
   * @param v2 顶点2
   */
  void addEdge(int v1, int v2) {
    if (v1 >= v_ || v2 >= v_)
      throw Exception("std::vector IndexOutOfBound!");
    adj_[v1].push_back(v2);
    adj_[v2].push_back(v1);
    e_++;
  }

  /**
   * @brief 获取指定顶点的度
   *
   * @param v 指定顶点
   * @return int
   */
  int degreeOf(int v) {
    int degree = 0;
    for (auto w : adj_.at(v)) {
      degree++;
      ((void)w);
    }
    return degree;
  }

  /**
   * @brief 获取图中最大的度
   *
   * @return int
   */
  int maxDegree() {
    int max = 0;
    for (int v = 0; v < v_; ++v) {
      if (degreeOf(v) > max)
        max = degreeOf(v);
    }
    return max;
  }

  /**
   * @brief 计算所有顶点平均度数
   *
   * @return double
   */
  double avgDegree() { return 2 * e_ / v_; }

  /**
   * @brief 获取该图自环个数
   *
   * @return int
   */
  int numberOfSelfLoops() {
    int count = 0;
    for (int v = 0; v < v_; ++v) {
      for (auto w : adj_[v])
        if (v == w)
          count++;
    }
    return count / 2;
  }

  /**
   * @brief 获取“顶点数量”
   *
   * @return int 顶点数量
   */
  int getAmountOfVertices() const { return v_; }

  /**
   * @brief 获取“边数量”
   *
   * @return int 边数量
   */
  int getAmountOfEdges() const { return e_; }

  /**
   * @brief 序列化为字符串表示
   *
   * @return std::string
   */
  std::string toString() {
    std::string s =
        std::to_string(v_) + " vertices, " + std::to_string(e_) + " edges!\n";
    for (int v = 0; v < v_; ++v) {
      s += std::to_string(v) + ": ";
      for (auto w : adj_[v]) {
        s += std::to_string(w) + " ";
      }
      s += "\n";
    }
    return s;
  }
};

class SearchSALG {
 public:
  /**
   * @brief 找到和起点 s 连通的所有顶点
   *
   * @param g
   * @param s
   */
  SearchSALG(SimplestAdjListGraph g, int s) {}

  /**
   * @brief v 和 s 是否连通的
   *
   * @param v
   * @return true
   * @return false
   */
  bool marked(int v);

  /**
   * @brief 与 s 连通的顶点总数
   *
   * @return int
   */
  int count();
};
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ADJLISTGRAPH_H

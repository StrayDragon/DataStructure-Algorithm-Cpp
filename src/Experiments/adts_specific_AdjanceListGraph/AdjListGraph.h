//
// Created by straydragon on 18-12-20.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ADJLISTGRAPH_H
#define DATASTRUCTURE_ALGORITHM_CPP_ADJLISTGRAPH_H

#include <vector>
#include <string>
#include "../../ADTs/interfaces/noncopyable.h"
#include "../../ADTs/exceptions/Exception.h"

class AdjListGraph final : noncopyable {
  int v_;
  int e_;
  std::vector<std::vector<int>> adj_;
 public:
  explicit AdjListGraph(int v) : v_(v), e_(0), adj_(v) {}

  bool add(int v, int w) {
    if (v >= v_ || w >= v_) throw Exception("std::vector IndexOutOfBound!");
    adj_[v].push_back(w);
    adj_[w].push_back(v);
    e_++;
    return true;
  }

  int degreeOf(int v) {
    int degree = 0;
    for (auto w : adj_.at(v)) {
      degree++;
      ((void) w);
    }
    return degree;
  }

  int maxDegree() {
    int max = 0;
    for (int v = 0; v < v_; ++v) {
      if (degreeOf(v) > max) max = degreeOf(v);
    }
    return max;
  }

  double avgDegree() {
    return 2 * e_ / v_;
  }

  int numberOfSelfLoops() {
    int count = 0;
    for (int v = 0; v < v_; ++v) {
      for (auto w : adj_[v])
        if (v == w) count++;
    }
    return count / 2;
  }

  std::string toString() {
    std::string s = std::to_string(v_) + " vertices, " + std::to_string(e_) + " edges!\n";
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

#endif //DATASTRUCTURE_ALGORITHM_CPP_ADJLISTGRAPH_H

//
// Created by straydragon on 18-12-19.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_NONCOPYABLE_H
#define DATASTRUCTURE_ALGORITHM_CPP_NONCOPYABLE_H

class noncopyable {
 private:
  noncopyable(const noncopyable&) = delete;
  noncopyable& operator=(const noncopyable&) = delete;

 public:
  noncopyable() = default;
  ~noncopyable() = default;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_NONCOPYABLE_H

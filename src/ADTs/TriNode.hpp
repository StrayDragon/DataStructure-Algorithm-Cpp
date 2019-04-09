//
// Created by straydragon on 19-4-9.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_TRINODE_H
#define DATASTRUCTURE_ALGORITHM_CPP_TRINODE_HPP

#include "../Utilities/Rc.hpp"
template<typename E>
class TriNode {
  using Ptr = Rc<TriNode<E>>;
 private:
  E smallData_, largeData_;
  Ptr lChild_;
  Ptr mChild_;
  Ptr rChild_;
 public:
  TriNode() : smallData_(E()), largeData_(E()) {}

  explicit TriNode(const E& e) : smallData_(e), largeData_(E()) {}

  TriNode(const E& e, Ptr lChild, Ptr mChild, Ptr rChild) {
    //TODO:Not finish: What is a better way to save 2-3 Tree node?
  }

  bool isLeft() const;
  bool isTwoChildren() const;
  bool isThreeChildren() const;

  void setSmallData(E smallData) {
    smallData_ = smallData;
  }
  void setLargeData(E largeData) {
    largeData_ = largeData;
  }
  void setLChild(const Ptr& lChild) {
    lChild_ = lChild;
  }
  void setMChild(const Ptr& mChild) {
    mChild_ = mChild;
  }
  void setRChild(const Ptr& rChild) {
    rChild_ = rChild;
  }

  E getSmallData() const {
    return smallData_;
  }
  E getLargeData() const {
    return largeData_;
  }
  const Ptr& getLChild() const {
    return lChild_;
  }
  const Ptr& getMChild() const {
    return mChild_;
  }
  const Ptr& getRChild() const {
    return rChild_;
  }
};

template<typename E>
bool TriNode<E>::isLeft() const {
  return (
      this->lChild_ == nullptr && this->mChild_ == nullptr && this->rChild_ == nullptr
  );
}

template<typename E>
bool TriNode<E>::isTwoChildren() const {
  return
      (this->lChild_ && this->mChild_ && this->rChild_ == nullptr) ||
          (this->lChild_ && this->mChild_ == nullptr && this->rChild_) ||
          (this->lChild_ == nullptr && this->mChild_ && this->rChild_);
}

template<typename E>
bool TriNode<E>::isThreeChildren() const {
  return this->lChild_ && this->mChild_ && this->rChild_;
}
#endif //DATASTRUCTURE_ALGORITHM_CPP_TRINODE_H

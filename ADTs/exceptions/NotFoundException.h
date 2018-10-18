//
// Created by straydragon on 18-10-14.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_NOTFOUNDEXCEPTION_H
#define DATASTRUCTURE_ALGORITHM_CPP_NOTFOUNDEXCEPTION_H

#include "Exception.h"

class NotFoundException : public Exception {
  explicit NotFoundException(const std::string& msg = "") : Exception(msg) {}
};
#endif  // DATASTRUCTURE_ALGORITHM_CPP_NOTFOUNDEXCEPTION_H

#ifndef DATASTRUCTURE_ALGORITHM_CPP_PRECONDITIONFAILED
#define DATASTRUCTURE_ALGORITHM_CPP_PRECONDITIONFAILED
#include "Exception.h"
class PreconditionFailedException : public Exception {
 public:
  explicit PreconditionFailedException(const std::string& msg = "")
      : Exception(msg) {}
};

#endif
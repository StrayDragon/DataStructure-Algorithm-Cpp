#ifndef DATASTRUCTURE_ALGORITHM_CPP_EXCEPTION
#define DATASTRUCTURE_ALGORITHM_CPP_EXCEPTION
#include <exception>
#include <string>
class Exception : public std::exception {
 public:
  /** Constructor (C strings).
   *  @param message C-style string error message.
   *                 The string contents are copied upon construction.
   *                 Hence, responsibility for deleting the c char* lies
   *                 with the caller.
   */
  explicit Exception(const char* message) : _msg(message) {}
  /** Constructor (C++ STL strings).
   *  @param message The error message.
   */
  explicit Exception(const std::string& message) : _msg(message) {}
  /** Destructor.
   * Virtual to allow for subclassing.
   */
  virtual ~Exception() throw() {}
  /** Returns a pointer to the (constant) error description.
   *  @return A pointer to a c const c char*. The underlying memory
   *          is in posession of the c Exception object. Callers a must
   *          not attempt to free the memory.
   */
  virtual const char* what() const throw() { return _msg.c_str(); }

 protected:
  /** Error message.
   */
  std::string _msg;
};

#endif
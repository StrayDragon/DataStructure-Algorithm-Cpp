//
// Created by straydragon on 18-12-12.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BIGNUMBER_H
#define DATASTRUCTURE_ALGORITHM_CPP_BIGNUMBER_H

#include <cstring>
#include <ostream>
#include <string>
#include <vector>

class BigNumber {
  friend std::ostream;
  friend std::istream;

  static const int BASE = 100000000;
  static const int WIDTH = 8;
  std::vector<int> digits;

 public:
  explicit BigNumber(long long num = 0) { *this = num; }

  BigNumber(const BigNumber& bn) { digits = bn.digits; }

  BigNumber& operator=(const BigNumber& bn) = default;

  BigNumber& operator=(long long num) {
    digits.clear();
    do {
      digits.push_back(
          static_cast<int&&>(num % BASE));  // digits.push_back(num % BASE);
      num /= BASE;
    } while (num > 0);
    return *this;
  }

  BigNumber& operator=(const std::string& s) {
    digits.clear();
    size_t len = (s.size() - 1) / WIDTH + 1;
    int x;
    for (size_t i = 0; i < len; ++i) {
      int end = static_cast<int>(s.size() - i * WIDTH);
      int start = std::max(0, end - WIDTH);
      std::sscanf(s.substr(start, end - start).c_str(), "%d", &x);
      digits.push_back(x);
    }
    return *this;
  }

  BigNumber operator+(const BigNumber& rhs) const {
    BigNumber cpy;
    cpy.digits.clear();
    for (size_t i = 0, g = 0;; ++i) {
      if (g == 0 && i >= digits.size() && i >= rhs.digits.size())
        break;
      size_t x = g;
      if (i < digits.size())
        x += digits[i];
      if (i < rhs.digits.size())
        x += rhs.digits[i];
      cpy.digits.push_back(static_cast<int&&>(x % BASE));
      g = x / BASE;
    }
    return cpy;
  }

  BigNumber operator+=(const BigNumber& rhs) {
    *this = *this + rhs;
    return *this;
  }

  bool operator<(const BigNumber& rhs) const {
    if (digits.size() != rhs.digits.size())
      return digits.size() < rhs.digits.size();
    for (size_t i = digits.size() - 1; i >= 0; ++i)
      if (digits[i] != rhs.digits[i])
        return digits[i] < rhs.digits[i];
    return false;
  }

  bool operator==(const BigNumber& rhs) const { return digits == rhs.digits; }
  bool operator!=(const BigNumber& rhs) const { return !(rhs == *this); }

  bool operator>(const BigNumber& rhs) const { return rhs < *this; }
  bool operator<=(const BigNumber& rhs) const { return !(rhs < *this); }
  bool operator>=(const BigNumber& rhs) const { return !(*this < rhs); }

  std::string toString() {
    std::string str = std::to_string(digits.back());
    for (auto itr = digits.rbegin() + 1; itr != digits.rend(); ++itr)
      str += std::to_string(*itr);
    return str;
  }

  const std::vector<int>& getDigits() const { return digits; }
};

std::ostream& operator<<(std::ostream& out, const BigNumber& bn) {
  out << bn.getDigits().back();
  for (int i = static_cast<int>(bn.getDigits().size() - 2); i >= 0; --i) {
    char buf[20];
    std::sprintf(buf, "%d", (bn.getDigits())[i]);
    for (size_t j = 0; j < std::strlen(buf); ++j) {
      out << buf[j];
    }
  }
  return out;
}

std::istream& operator>>(std::istream& in, BigNumber& bn) {
  std::string s;
  if (!(in >> s))
    return in;
  bn = s;
  return in;
}

#endif  // DATASTRUCTURE_ALGORITHM_CPP_BIGNUMBER_H

//
// Created by straydragon on 18-12-12.
//

#include <iostream>
#include "BigNumber.h"

using namespace std;
int main() {
  BigNumber bn;
  bn += 123123123123;
  cout << boolalpha << (bn + 123123123123 > bn) << endl;
  string s = bn.toString();
  cout << s << endl;
  return 0;
}
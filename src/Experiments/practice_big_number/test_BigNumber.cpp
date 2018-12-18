//
// Created by straydragon on 18-12-12.
//

#include <iostream>
#include "BigNumber.h"

using namespace std;
int main() {
  BigNumber bn;
  bn = 123123123123;
  cin >> bn;
  cout << boolalpha << (BigNumber(123123123123) > bn) << endl;
  string s = bn.toString();
  cout << s << endl;
  return 0;
}
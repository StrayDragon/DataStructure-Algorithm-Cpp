#include <cassert>
#include <iostream>
#include <string>

#include "../ADTs/ArrayBag.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    ArrayBag<string> arrayBag;
    arrayBag.add("0");
    arrayBag.add("1");
    arrayBag.add("2");
    arrayBag.add("3");
    arrayBag.add("4");
    arrayBag.add("5");
    arrayBag.add("X");

    assert(arrayBag.getCurrentSize() == 6);
    return 0;
}

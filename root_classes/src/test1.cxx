/*
 * test1.cxx
 *
 */

#include "test1.h"

#include <iostream>

#ifdef __ROOT__
  ClassImp(Test1);
#endif

Test1::Test1():
  TObject(),
  _x(42)
{
  std::cout << "[Test1::Test1]\n";
}


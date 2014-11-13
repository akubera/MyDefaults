/*
 * test2.cxx
 *
 */

#include "test2.h"

#include <iostream>

#ifdef __ROOT__
  ClassImp(Test2);
#endif

Test2::Test2():
  TObject(),
  _x(42000)
{
  std::cout << "[Test2::Test2]\n";
}


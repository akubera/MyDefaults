/*
 * src/test1.h
 */

#ifndef TEST1_H_
#define TEST1_H_

#include <TObject.h>

class Test1 : public TObject {
public:
  Test1();

protected:
  int _x;

#ifdef __ROOT__
  ClassDef(Test1, 0);
#endif

};

#endif

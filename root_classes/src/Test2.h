/*
 * src/test2.h
 */

#ifndef TEST2_H_
#define TEST2_H_

#include <TObject.h>

class Test2 : public TObject {
public:
  Test2();

protected:
  int _x;


ClassDef(Test2, 0);
};

#endif

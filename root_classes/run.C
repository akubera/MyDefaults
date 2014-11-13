/*
 * run.C
 *
 * A ROOT macro to see if the code is generated properly
 *
 * usage: root run.C
 *
 */
 
#include <cassert>
#include <iostream>

#include <TSystem.h>
#include <TClass.h>

#ifndef __CINT__
#include "Test1.h"
#include "Test2.h"
#endif

using namespace std;

void
run()
{
  gSystem->Load("MyLib");

  Test1 t1;
  
  Test2 t2;
  
  TString t1_class(t1.IsA()->GetName());
  
  cout << "Class of t1 : '" << t1_class.Data() << "'\n";
  
  assert(t1_class == "Test1");
  
  cout << "Done.";
}

//
// Now run.C is compilable
//
#if !defined(__CINT__) && !defined(__ROOTCLING__)
int main()
{
  run();
  return 0;
}
#endif

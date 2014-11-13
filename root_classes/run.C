/*
 * run.C
 *
 * A ROOT macro to see if the code is generated properly
 *
 * usage: root run.C
 *
 */
 
#include <cassert>
 
void
run()
{
  gInterpreter->Load("MyLib");
  gROOT
  Test1 t1;
  
  Test2 t2;
  
  TString t1_class(t1.IsA()->GetName());
  
  cout << "Class of t1 : '" << t1_class.Data() << "'\n";
  
  assert(t1_class == "Test1");
  
  cout << "Done.";
}

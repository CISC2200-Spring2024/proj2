#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BigInt.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#define SIZE 10

int main()
{
  string input1,input2, op;

  cin >> op;
  cin >> input1;
  cin >> input2;

  ds::BigInt a(input1);
  ds::BigInt b(input2);

  if (op=="add")
  {
  	ds::BigInt r;
  	ds::BigInt::add (a, b, r);

  	r.output ();  
  } 
  else if (op=="subtract")
  {
	//assume a>=b
  	ds::BigInt r2;
  	ds::BigInt::subtract (a,b,r2);
  
  	r2.output (); 
   }

}

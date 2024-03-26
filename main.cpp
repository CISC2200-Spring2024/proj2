#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BigInt.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

int main()
{
  ds::BigInt * p = new ds::BigInt();

  ds::BigInt a("1234567890123");
  ds::BigInt b("1567890123");

  a.output(); //this should display a's value: 1234567890123

  ds::BigInt r;
  ds::BigInt::add (a, b, r);

  r.output ();  //This should display 1236135780246

  ds::BigInt r2;
  ds::BigInt::subtract (a,b,r2);
  
  r2.output (); //This should display 123000000000

  
 
}

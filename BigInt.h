#ifndef BIGINT_H
#define BIGINT_H

#include "SLList.h"
using namespace std;

namespace ds{

class BigInt 
{
    public: 
        //Constructors
        BigInt(); //default constructor
        BigInt(string nums); //custom constructor

        void output();
        static void add(BigInt& x, BigInt& y, BigInt& r);
        static void subtract(BigInt& x, BigInt& y, BigInt& r2);

        /** Override `<<` to print all digits to os. */
        friend std::ostream &operator<<(std::ostream &os, const BigInt &bi);
        /** Override < to compare a and b, return true  if a<b; otherwise return false */
        friend  bool operator<(const BigInt &a, const BigInt &b);

        /** return a+b */
        friend  BigInt operator+(const BigInt &a, const BigInt &b);

        /** return the absolute difference between a and b,
           if a>b, return a-b; otherwise, return b-a */
        friend  BigInt operator-(const BigInt &a, const BigInt &b);

    private:
        SLList<int> list;

        //remove leading zeros in the integer, e.g., 009990 => 9990
        void removeLeadingZeros();

        //clear all digits in the calling object 
        void clear(); 

    
};

}
#endif //BIGINT_H

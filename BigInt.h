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



    private:
        SLList<int> list;

        //remove leading zeros in the integer, e.g., 009990 => 9990
        void removeLeadingZeros();

        //clear all digits in the calling object 
        void clear(); 

    
};

}
#endif //BIGINT_H

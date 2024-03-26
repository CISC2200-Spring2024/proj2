#include "BigInt.h"
#include "SLList.h"
#include <assert.h>

using namespace std;

namespace ds{

//default constructor
BigInt::BigInt() : list()
{
    list.addFirst(0); //creates an "empty" list, storing only the number 0
}

//custom constructor, takes a big integer in the form of a string and stores it as a list of integers
//If nums is "1289", the digits are stored in the list in the order of : 9, 8, 2, 1
// i.e., the digits are stored in the list in the reversed order of the way we read it:
// ones digit first, tens digit next, ..., and most significant digit last 
BigInt::BigInt(string nums) 
{
    int len = nums.length();
    for(int i=0; i < len; i++)
    {
        list.addFirst(nums[i] - '0'); // addFirst stores nums[i] in reverse order to SLList

    }
}

//displays the big integer stored in the calling object
//Refer to the previous constructor.
//We need to display the digits stored in the list in reverse order: display the last digit first, and the first digit last
void BigInt::output() 
{
    int length = list.size();
    for(int i = length -1; i >= 0; i--) //iterates through entire list backwards, printing each digit at pos i, because they are stored in reverse order
    {
        int digit = list.get(i);
        cout << digit;
    }
    cout << endl;
}

//remove leading zeros in the integer, e.g., 009990 => 9990
void BigInt::removeLeadingZeros()
{
    int i = list.size()-1;
    int digit = list.get(i); //get most significant digit 

    while (digit==0 && list.size()!=1) {
       //exit loop upon encoutnering first none zero digit, or there is only one digit left 
       list.removeLast(); 

       i--; //move to next
       digit = list.get(i);
    }
}

//Remove all digits from the big int's list 
void BigInt::clear()
{
	int length=list.size();	

        for (int i=0;i<length;i++)
            list.removeFirst();

        assert (list.size()==0);
}

//adds two BigInts (x and y) together, storing their sum in a separate BigInt object, r
void BigInt::add(BigInt& x, BigInt& y, BigInt& r)
{
    //make sure r is empty 
    r.clear();

    int max_size = max(x.list.size(), y.list.size());
    int carry = 0; //to keep track of when to carry the 1

    //starting from one, tens, ... digits, adding corresponding digits together, 
    // while maintaining the carry digit 
    for(int i = 0; i < max_size; i++) //iterate through both lists, through the size of the one that is larger
    {
      int x_digit = 0;  
      if(i < x.list.size()) //check to avoid segmentation fault
      {
        x_digit = x.list.get(i);
      }

      int y_digit = 0;
      if(i < y.list.size()) //check to avoid segmentation fault
      {
        y_digit = y.list.get(i);
      }
    
      int sum = x_digit + y_digit +  carry; //adds the current two digits together, + the carried 1, if applicable
      carry = sum / 10; //determines if 1 will be carried to the next pass, because answer will always be either 1 or 0
      int remainder = sum % 10; //will essentially drop any number in the 10s place, allowing just the 1s place to get added to r

      r.list.addLast(remainder);

    }

    if(carry > 0)
        r.list.addLast(carry); //for the very final digit, updates the number properly if there was one final 1 to be carried over

}

//subtracts two BigInts (x - y), storing their difference in a separate BigInt object, r2
//function logic assumes that x is the list being subtracted FROM, i.e. the larger number value wise, 
// and y is the number BEING subtracted
void BigInt::subtract(BigInt& x, BigInt& y, BigInt& r2) 
{
    r2.clear();

    int max_size = max(x.list.size(), y.list.size());
    int borrow = 0; //initializes borrow to 0


    for (int i = 0; i < max_size; i++) //iterates through the size of the larger number, digits wise
    {
        int x_digit = 0;
        if(i < x.list.size()) //check to avoid segmentation fault
        {
            x_digit = x.list.get(i);
        }

        int y_digit = 0;
        if(i < y.list.size()) //check to avoid segmentation fault
        {
            y_digit = y.list.get(i);
        }

        x_digit -= borrow; //if a 1 had to be borrowed from previous pass, this step reflects that change in the current x digit

        int difference = x_digit - y_digit; //subtracts the two digits, after having updated x if necessary
        if (difference < 0) //if difference < 0, indicates that x was smaller than y, and a 1 will need to be borrowed from next digit
        {
            difference += 10; //reflects the process of borrowing a one from the next digit
            borrow = 1; //indicates that the next pass will have to update the x digit because a 1 was borrowed
        }
        else
        {
            borrow = 0; //resets borrow if no 1 was borrowed for the pass
        }

       r2.list.addLast(difference); //stores the final difference to the list

    }

    //removes the leading 0s in the r2
    r2.removeLeadingZeros(); 
    
}

}

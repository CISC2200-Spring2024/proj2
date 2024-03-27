
# CISC 2200 Programming Project #2

In this optional project assignment, we review project #1 solution and practice **overloading operators**.

## Provided code

The solutions to project 1 is provided, with a few new operator overloading functions declared in **BigInt.h**.

From your terminal (mac or WSL/Ubunto) window, you can use the following command to download it:
```
git clone https://github.com/CISC2200-Spring2024/proj2.git
```

## Programming Environment Setup
If you haven't done so already, please set up programming environment our our own computer, by following [Setup Tutorial](https://eecs280staff.github.io/tutorials/). 

- The _Commannd Line Tools_ are required. 

- The _C++ Dev Environment_ (VSCode) is highly recommened.

**Please follow these tutorials closely and carefully.**


## Requirements

Design a class named **BigInt** in a file named **BigInt.h**, implement the class methods in a file named **BigInt.cpp**,
and test the class in a file named **main.cpp**. 

Detailed requirements: 

1. In **BigInt.cpp** file, implement the operator+ overloading. You can call the **add** function directly, or you can replace **add** with the operator+ overloading.
2. In **BigInt.cpp** file, implement the operator< overloading.  
3. In **BigInt.cpp** file, implement the operator- overloading. Pay attention that it should return the absolute difference between the two arguments.
4. Overload the << operator, so that we can output BigInt object using << operator.  
5. Modify **test.cpp** file to test the these operators. 
   
## Hints:
   When implement operator- overloading, you can consult the following:
    ```
     BigInt operator-(const BigInt &a, const BigInt &b) {
    
        if (a < b) { //calling your operator< to compare a and b 
           return b - a;  //calling this function, but passing b as the first argument, a as second argument 
        }
       // starting from this line, we can assume that `a >= b`
       // code similar to that in subtract ...

    

     }
    ```
   



## Requirement

Instead of specifying what constructors and member functions you need to implement, the **main.cpp** provided in this repository 
demonstrated how the **BigInt** class is used. **Please try your best to figure out what member functions are required, and what their
function signature should be from the user code. One example is commented below for a constructor:** 

```
  ds::BigInt a("1234567890123");
     //This implies that we should provide a constructor that takes a string as parameter
      //This constructor should initialize a to represent a big integer of value: 1234567890123
  ds::BigInt b("1567890123");

  a.output(); //this should display a's value: 1234567890123

  ds:BigInt r;
  ds::BigInt::add (a, b, r);

  r.output ();  //This should display 1236135780246

  ds:BigInt r2;
  ds::BigInt::subtract (a,b,r2);

  r2.output (); //This should display 123000000000
```

The **test.cpp** provides another more flexbile way to test your **BigInt** class: 
```
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
```

## Style ##

The coding style part is worth 20 points. The rubrics for the style requirement is as follows: 

* Insufficient or no comments: -1 point (-2 max)
* Code not indented correctly: -1 point (-2 max)
* Redundant code: -1 point (-2 max)
* Overly complicated code: -1 point (-2 max)

## Submission 

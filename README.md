
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

In the file **BigInt.h**, four operator overloading functions have been declared. You need to implement them in **BigInt.cpp** file. 

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
   

## Style ##

The coding style part is worth 20 points. The rubrics for the style requirement is as follows: 

* Insufficient or no comments: -1 point (-2 max)
* Code not indented correctly: -1 point (-2 max)
* Redundant code: -1 point (-2 max)
* Overly complicated code: -1 point (-2 max)

## Submission 

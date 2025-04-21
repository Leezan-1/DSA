#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Recursion
{

public:
    static void print1toN(int n);

    static void printNto1(int n);

    static int sumOfN(int n);

    static int factorialOfN(int n);

    static int powerFunction(int n, int p);
};

#endif
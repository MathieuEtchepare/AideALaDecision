#ifndef B2VARIABLE_H_INCLUDED
#define B2VARIABLE_H_INCLUDED

#include <vector>
#include <iostream>
#include "B2Constraint.h"

class Variable{
    int value;
    std::vector<int> domain;
    std::vector <Constraint*> constraints;

public:
    Variable(int val);
    ~Variable();
    int getValue(){return value;}
    void push_domain(int n);
    void print();
};

#endif // B2VARIABLE_H_INCLUDED

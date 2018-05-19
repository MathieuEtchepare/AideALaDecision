#ifndef B2VARIABLE_H_INCLUDED
#define B2VARIABLE_H_INCLUDED

#include <vector>
#include <iostream>
#include "B2Constraint.h"

class Variable{
    int _id;
    int _value;
    std::vector<int> _domain;
public:
    Variable(int id);
    ~Variable();

    int getId(){return _id;}
    int getValue(){return _value;}

    void push_domain(int n);
    void print();
};

#endif // B2VARIABLE_H_INCLUDED

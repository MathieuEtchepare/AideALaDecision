#ifndef B2VARIABLE_H_INCLUDED
#define B2VARIABLE_H_INCLUDED

#include <vector>
#include <iostream>
#include "B2Constraint.h"
<<<<<<< HEAD

=======
>>>>>>> 4e291a735f6c2aac8fdb11abae278382e434bd62
class Variable{
    int value;
    std::vector<int> domain;
    std::vector <Constraint*> constraints;
<<<<<<< HEAD
public:
    Variable(int val);
    ~Variable();
    void push_domain(int n);
    void print();
=======

>>>>>>> 4e291a735f6c2aac8fdb11abae278382e434bd62
};

#endif // B2VARIABLE_H_INCLUDED

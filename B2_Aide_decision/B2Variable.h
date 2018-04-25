#ifndef B2VARIABLE_H_INCLUDED
#define B2VARIABLE_H_INCLUDED

#include <vector>
#include "B2Constraint.h"
public class Variable{
    int value;
    std::vector <Constraint*> constraints;

}

#endif // B2VARIABLE_H_INCLUDED

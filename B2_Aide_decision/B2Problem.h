#ifndef B2PROBLEM_H_INCLUDED
#define B2PROBLEM_H_INCLUDED

#include "B2Variable.h"
#include "B2BinaryConstraint.h"
#include "B2MultipleConstraint.h"

#include <vector>
#include <map>
#include <iostream>
#include <fstream>

class Problem{
    std::map<int, Variable*> _variables;
    std::vector <Constraint*> _constraints;
public :
    Problem(std::string const &filename);
    ~Problem();
    void readFile(std::string const &filename);
    void print();
};


#endif // B2PROBLEM_H_INCLUDED

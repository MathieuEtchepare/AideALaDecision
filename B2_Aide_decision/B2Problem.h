#ifndef B2PROBLEM_H_INCLUDED
#define B2PROBLEM_H_INCLUDED


#include "B2Variable.h"
#include <vector>
#include <iostream>
#include <fstream>

class Problem{
    std::vector<Variable> variables;
public :
    Problem(std::string const &filename);
    ~Problem();
    void readFile(std::string const &filename);
    void print();
};


#endif // B2PROBLEM_H_INCLUDED

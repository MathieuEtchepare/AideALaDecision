#ifndef B2PROBLEM_H_INCLUDED
#define B2PROBLEM_H_INCLUDED

#include "B2Variable.h"
#include "B2BinaryConstraint.h"
#include "B2MultipleConstraint.h"

#include <vector>
#include <map>
#include <iostream>
#include <fstream>

#define DEBUG 0
class Node{
    public:
    int _index, _valueVariable;
    std::map<int, int> _current_variables;
    std::map<int, std::vector<int> > _current_domains;
};

class Problem{
    int _nVariables;
    std::vector<int> _variables; // variables ID's
    std::map<int, std::vector<int> > _domains; // variables ID's give Domain
    std::vector <Constraint*> _constraints;
public :
    Problem(std::string const &filename);
    ~Problem();
    void readFile(std::string const &filename);
    void print();
    void printVariablesOrder();

    std::map<int, int> method_trivial(Node node);
    std::map<int, int> method_reduction(Node node);
    std::vector<int> new_domain(int idVariables, std::vector<int> domain, std::map<int, int> current_variables);

    void sort_variables(); // tri les variables du plus petit domaine de valeur au plus grand
    void reverse_sort_variables(); // tri les variables du plus petit domaine de valeur au plus grand

    std::map<int, std::vector<int> > getDomains() {return _domains;}
};


#endif // B2PROBLEM_H_INCLUDED

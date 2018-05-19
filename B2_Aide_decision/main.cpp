#include <iostream>
#include "B2Problem.h"
#include "B2includes.h"
using namespace std;

int main()
{
    Problem p("test.txt");
    p.print();

    Node n;
    n._idVariable = 0;
    n._current_domains = p.getDomains();

    map<int, int> m = p.trivial(n);

    for(map<int, int>::iterator it=m.begin(); it!=m.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
    /**
    vector<Constraint*> contraintes;
    vector<Variable*> temp;
    temp.push_back(new Variable(1));
    temp.push_back(new Variable(2));
    temp.push_back(new Variable(1));
    temp.push_back(new Variable(3));

    contraintes.push_back(new BinaryConstraint(temp[0], temp[2], 0));
    contraintes.push_back(new BinaryConstraint(temp[0], temp[1], 1));
    contraintes.push_back(new BinaryConstraint(temp[3],temp[1], 2));
    contraintes.push_back(new BinaryConstraint(temp[2], temp[3], 3));
    contraintes.push_back(new ConstraintSum(temp, 7));

   for(unsigned int i = 0; i < contraintes.size(); i++)
    {
        cout<<contraintes[i]->test()<<endl;
    }
    */
    return 0;
}

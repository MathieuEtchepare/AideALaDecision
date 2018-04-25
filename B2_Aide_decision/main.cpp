#include <iostream>
#include "B2includes.h"
using namespace std;

int main()
{
    vector<Constraint*> contraintes;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(4);

    contraintes.push_back(new ConstraintEquality(1,1));
    contraintes.push_back(new ConstraintInequality(1,1));
    contraintes.push_back(new ConstraintSuperior(2,1));
    contraintes.push_back(new ConstraintInferior(1,2));
    contraintes.push_back(new ConstraintSum(temp, 9));

    for(unsigned int i = 0; i < contraintes.size(); i++)
    {
        cout<<contraintes[i]->test()<<endl;
    }
    return 0;
}

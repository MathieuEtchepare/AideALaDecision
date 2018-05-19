#include "B2MultipleConstraint.h"

using namespace std;

bool MultipleConstraint::test(){
    int result = _result;

    for(unsigned int i = 0; i < _variables.size(); i++)
    {
        result-=_variables[i]->getValue();
    }
    return(result == 0);
}

void MultipleConstraint::print() const{
    for(unsigned int i = 0; i < _variables.size() - 1; i++){
        cout << "x" << _variables[i]->getId() << " + ";
    }
    cout << "x" << _variables.back()->getId() << " = " << _result << endl;
}

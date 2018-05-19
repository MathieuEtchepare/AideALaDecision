#include "B2MultipleConstraint.h"

using namespace std;

bool MultipleConstraint::test(){
    int result = _result;

    for(unsigned int i = 0; i < _idVariables.size(); i++)
    {
        result -= _variables[_idVariables[i]];
    }
    return(result == 0);
}

void MultipleConstraint::print() const{
    for(unsigned int i = 0; i < _idVariables.size() - 1; i++){
        cout << "x" << _idVariables[i] << " + ";
    }
    cout << "x" << _idVariables.back() << " = " << _result << endl;
}

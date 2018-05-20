#include "B2MultipleConstraint.h"

using namespace std;

bool MultipleConstraint::test(){
    int result = _result;

    switch(_type){
        case 7:
            for(unsigned int i = 0; i < _idVariables.size(); i++)
            {
                result -= _variables[_idVariables[i]];
            }
            return(result == 0);
        break;
        case 8:
            for(unsigned int i = 0; i < _idVariables.size(); i++)
            {
                result -= _variables[_idVariables[i]];
            }
            return(result < 0);
        break;
        case 9:
            for(unsigned int i = 0; i < _idVariables.size(); i++)
            {
                result -= _variables[_idVariables[i]];
            }
            return(result > 0);
        break;
        default:
            std::cout << "Error type of binary constraint undefined" << std::endl;
            return false;
    }


}

bool MultipleConstraint::canTest(){
    for(unsigned int i = 0; i < _idVariables.size(); i++){
        if(_variables.find(_idVariables[i]) == _variables.end()) return false;
    }
    return true;
};

void MultipleConstraint::print() const{
    for(unsigned int i = 0; i < _idVariables.size() - 1; i++){
        cout << "x" << _idVariables[i] << " + ";
    }
    switch(_type){
        case 7:
            cout << "x" << _idVariables.back() << " = " << _result << endl;
        break;
        case 8:
            cout << "x" << _idVariables.back() << " < " << _result << endl;
        break;
        case 9:
            cout << "x" << _idVariables.back() << " > " << _result << endl;
        break;
    }
}

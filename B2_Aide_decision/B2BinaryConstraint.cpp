#include "B2BinaryConstraint.h"

bool BinaryConstraint::test(){
    switch(_type){
        case 1:
            return (_variables[_idV1] == _variables[_idV2]);
        break;
        case 2:
            return (_variables[_idV1] != _variables[_idV2]);
        break;
        case 3:
            return (_variables[_idV1] <= _variables[_idV2]);
        break;
        case 4:
            return (_variables[_idV1] < _variables[_idV2]);
        break;
        default:
            std::cout << "Error type of binary constraint undefined" << std::endl;
            return false;
    }
};

void BinaryConstraint::print() const{
    std::cout << "x" << _idV1;
    switch(_type){
        case 1:
            std::cout << " = ";
        break;
        case 2:
            std::cout << " != ";
        break;
        case 3:
            std::cout << " <= ";
        break;
        case 4:
            std::cout << " < ";
        break;
    }
    std::cout << "x" << _idV2 << std::endl;
}

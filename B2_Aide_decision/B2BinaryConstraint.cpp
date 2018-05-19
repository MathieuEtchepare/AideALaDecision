#include "B2BinaryConstraint.h"

bool BinaryConstraint::test(){
    switch(_type){
        case 1:
            return (_v1->getValue() == _v2->getValue());
        break;
        case 2:
            return (_v1->getValue() != _v2->getValue());
        break;
        case 3:
            return (_v1->getValue() > _v2->getValue());
        break;
        case 4:
            return (_v1->getValue() < _v2->getValue());
        break;
        default:
            std::cout << "Error type of binary constraint undefined" << std::endl;
            return false;
    }
};

void BinaryConstraint::print() const{
    std::cout << "x" << _v1->getId();
    switch(_type){
        case 1:
            std::cout << " = ";
        break;
        case 2:
            std::cout << " != ";
        break;
        case 3:
            std::cout << " > ";
        break;
        case 4:
            std::cout << " < ";
        break;
    }
    std::cout << "x" << _v2->getId() << std::endl;
}

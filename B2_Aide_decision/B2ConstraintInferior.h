#ifndef B2CONSTRAINTINFERIOR_H_INCLUDED
#define B2CONSTRAINTINFERIOR_H_INCLUDED

#include "B2BinaryConstraint.h"

class ConstraintInferior : public BinaryConstraint{
    public:
      ConstraintInferior(Variable* first, Variable* second){
        setV1(first);
        setV2(second);
    };
    ~ConstraintInferior(){};
    bool test(){return (getV1()->getValue() < getV2()->getValue());}
};


#endif // B2CONSTRAINTINFERIOR_H_INCLUDED

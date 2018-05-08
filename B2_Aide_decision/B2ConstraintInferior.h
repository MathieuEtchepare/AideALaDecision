#ifndef B2CONSTRAINTINFERIOR_H_INCLUDED
#define B2CONSTRAINTINFERIOR_H_INCLUDED

#include "B2BinaryConstraint.h"

class ConstraintInferior : public BinaryConstraint{
    public:
    ConstraintInferior(Variable* v1, Variable* v2) : BinaryConstraint(v1, v2, 3) {};
    ~ConstraintInferior(){};
    bool test(){return (getV1()->getValue() < getV2()->getValue());}
};

#endif // B2CONSTRAINTINFERIOR_H_INCLUDED

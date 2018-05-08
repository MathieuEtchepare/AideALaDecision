#ifndef B2CONSTRAINTINEQUALITY_H
#define B2CONSTRAINTINEQUALITY_H

#include "B2BinaryConstraint.h"

class ConstraintInequality : public BinaryConstraint{
public:
    ConstraintInequality(Variable* v1, Variable* v2) : BinaryConstraint(v1, v2, 1) {};
    ~ConstraintInequality(){};
    bool test(){return (getV1()->getValue() != getV2()->getValue());}
};

#endif // B2CONSTRAINTINEQUALITY_H

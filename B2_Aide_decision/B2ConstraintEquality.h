#ifndef B2CONSTRAINTEQUALITY_H_INCLUDED
#define B2CONSTRAINTEQUALITY_H_INCLUDED

#include "B2BinaryConstraint.h"

class ConstraintEquality : public BinaryConstraint{
public:
    ConstraintEquality(Variable* v1, Variable* v2) : BinaryConstraint(v1, v2, 0) {};
    ~ConstraintEquality(){};
    bool test(){return (getV1()->getValue() == getV2()->getValue());}
};

#endif // B2CONSTRAINTEQUALITY_H_INCLUDED

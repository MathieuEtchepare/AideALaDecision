#ifndef B2CONSTRAINTSUPERIOR_H_INCLUDED
#define B2CONSTRAINTSUPERIOR_H_INCLUDED

#include "B2BinaryConstraint.h"

class ConstraintSuperior : public BinaryConstraint{
public:
    ConstraintSuperior(Variable* v1, Variable* v2) : BinaryConstraint(v1, v2, 2) {};
    ~ConstraintSuperior(){};
    bool test(){return (getV1()->getValue() > getV2()->getValue());}
};

#endif // B2CONSTRAINTSUPERIOR_H_INCLUDED

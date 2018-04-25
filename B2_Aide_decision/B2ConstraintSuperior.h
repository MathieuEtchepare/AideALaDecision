#ifndef B2CONSTRAINTSUPERIOR_H_INCLUDED
#define B2CONSTRAINTSUPERIOR_H_INCLUDED

#include "B2BinaryConstraint.h"

class ConstraintSuperior : public BinaryConstraint{
public:
    ConstraintSuperior(Variable* first, Variable* second){
        setV1(first);
        setV2(second);
    };
    ~ConstraintSuperior(){};
    bool test(){return (getV1()->getValue() > getV2()->getValue());}
};

#endif // B2CONSTRAINTSUPERIOR_H_INCLUDED

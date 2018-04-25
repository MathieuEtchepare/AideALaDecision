#ifndef B2CONSTRAINTINEQUALITY_H
#define B2CONSTRAINTINEQUALITY_H

#include "B2BinaryConstraint.h"

class ConstraintInequality : public BinaryConstraint{
public:
    ConstraintInequality(Variable* first, Variable* second){
        setV1(first);
        setV2(second);
    };
    ~ConstraintInequality(){};
    bool test(){return (getV1()->getValue() != getV2()->getValue());}
};

#endif // B2CONSTRAINTINEQUALITY_H

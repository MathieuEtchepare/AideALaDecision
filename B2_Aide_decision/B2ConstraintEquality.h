#ifndef B2CONSTRAINTEQUALITY_H_INCLUDED
#define B2CONSTRAINTEQUALITY_H_INCLUDED

#include "B2BinaryConstraint.h"

class ConstraintEquality : public BinaryConstraint{
public:
    ConstraintEquality(Variable* first, Variable* second){
        setV1(first);
        setV2(second);
    };
    ~ConstraintEquality(){};
    bool test(){return (getV1()->getValue() == getV2()->getValue());}
};

#endif // B2CONSTRAINTEQUALITY_H_INCLUDED

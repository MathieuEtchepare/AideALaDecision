#ifndef B2CONSTRAINTEQUALITY_H_INCLUDED
#define B2CONSTRAINTEQUALITY_H_INCLUDED

#include "B2Constraint.h"

class ConstraintEquality : public Constraint{
    int value1, value2;
public:
    ConstraintEquality(int v1, int v2){
        value1 = v1;
        value2 = v2;
    };
    ~ConstraintEquality(){};
    bool test(){return (value1 == value2);}
};

#endif // B2CONSTRAINTEQUALITY_H_INCLUDED

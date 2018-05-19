#ifndef B2BINARYCONSTRAINT_H_INCLUDED
#define B2BINARYCONSTRAINT_H_INCLUDED

#include "B2Variable.h"
#include "B2Constraint.h"

class BinaryConstraint : public Constraint{
    Variable *_v1, *_v2;
public:
        BinaryConstraint(Variable* v1, Variable* v2, int type) : Constraint(type) {
            setV1(v1);
            setV2(v2);
        }
        ~BinaryConstraint(){}

        virtual bool test();
        virtual void print() const;

        Variable* getV1(){return _v1;}
        Variable* getV2(){return _v2;}
        void setV1(Variable* v){_v1 = v;}
        void setV2(Variable* v){_v2 = v;}
};


#endif // B2BINARYCONSTRAINT_H_INCLUDED

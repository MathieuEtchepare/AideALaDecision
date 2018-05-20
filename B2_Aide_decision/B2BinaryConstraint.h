#ifndef B2BINARYCONSTRAINT_H_INCLUDED
#define B2BINARYCONSTRAINT_H_INCLUDED

#include "B2Variable.h"
#include "B2Constraint.h"

class BinaryConstraint : public Constraint{
    int _idV1, _idV2;
public:
        BinaryConstraint(int idV1, int idV2, int type) : Constraint(type) {
            _idV1 = idV1;
            _idV2 = idV2;
        }
        ~BinaryConstraint(){}

        virtual bool test();
        virtual bool canTest();
        virtual void print() const;
};


#endif // B2BINARYCONSTRAINT_H_INCLUDED

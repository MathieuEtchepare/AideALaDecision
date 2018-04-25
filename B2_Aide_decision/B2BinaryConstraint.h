#ifndef B2BINARYCONSTRAINT_H_INCLUDED
#define B2BINARYCONSTRAINT_H_INCLUDED

class BinaryConstraint : public Constraint{
    Variable *v1, *v2;
public:
        BinaryConstraint(){};
        ~BinaryConstraint(){};
        virtual bool test(){};
        Variable* getV1(){return v1;}
        Variable* getV2(){return v2;}
        void setV1(Variable* v){v1 = v;}
        void setV2(Variable* v){v2 = v;}
};


#endif // B2BINARYCONSTRAINT_H_INCLUDED

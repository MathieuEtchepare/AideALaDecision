#ifndef B2CONSTRAINTINEQUALITY_H
#define B2CONSTRAINTINEQUALITY_H


class ConstraintInequality : public Constraint{
    int value1, value2;
    public:
        ConstraintInequality(int v1, int v2){
            value1 = v1;
            value2 = v2;
        };
        ~ConstraintInequality(){};
        bool test(){return (value1 != value2);}
};

#endif // B2CONSTRAINTINEQUALITY_H

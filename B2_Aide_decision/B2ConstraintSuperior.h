#ifndef B2CONSTRAINTSUPERIOR_H_INCLUDED
#define B2CONSTRAINTSUPERIOR_H_INCLUDED

class ConstraintSuperior : public Constraint{
    int value1, value2;
    public:
        ConstraintSuperior(int v1, int v2){
            value1 = v1;
            value2 = v2;
        };
        ~ConstraintSuperior(){};
        bool test(){
            return (value1 > value2);
        }
};

#endif // B2CONSTRAINTSUPERIOR_H_INCLUDED

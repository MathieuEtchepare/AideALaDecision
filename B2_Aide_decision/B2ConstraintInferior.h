#ifndef B2CONSTRAINTINFERIOR_H_INCLUDED
#define B2CONSTRAINTINFERIOR_H_INCLUDED

class ConstraintInferior : public Constraint{
    int value1, value2;
    public:
        ConstraintInferior(int v1, int v2){
            value1 = v1;
            value2 = v2;
        };
        ~ConstraintInferior(){};
        bool test(){
            return (value1 < value2);
        }
};


#endif // B2CONSTRAINTINFERIOR_H_INCLUDED

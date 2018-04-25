#ifndef B2CONSTRAINTSUM_H_INCLUDED
#define B2CONSTRAINTSUM_H_INCLUDED

#include <vector>

class ConstraintSum : public Constraint{
private:
    std::vector<Variable*> operands;
    int result;
    public:
        ConstraintSum(std::vector<Variable*> op, int res){
            for(unsigned int i = 0; i < op.size(); i++)
            {
                operands.push_back(op[i]);
            }
            op.clear();
            result = res;
        };
        ~ConstraintSum(){};
        bool test(){
            for(unsigned int i = 0; i < operands.size(); i++)
            {
                result-=operands[i]->getValue();
            }
            return(result == 0);
        }
};

#endif // B2CONSTRAINTSUM_H_INCLUDED

#ifndef B2CONSTRAINTSUM_H_INCLUDED
#define B2CONSTRAINTSUM_H_INCLUDED

#include <vector>

#include "B2Variable.h"
#include "B2Constraint.h"

class MultipleConstraint : public Constraint{
private:
    std::vector<Variable*> _variables;
    int _result;
    public:
        MultipleConstraint(int res, int type) : Constraint(type){
            _result = res;
        }

        MultipleConstraint(std::vector<Variable*> op, int res, int type) : Constraint(type){
            for(unsigned int i = 0; i < op.size(); i++)
            {
                _variables.push_back(op[i]);
            }
            _result = res;
        }

        ~MultipleConstraint(){}

        virtual bool test();
        virtual void print() const;

        void addVariable(Variable* var){
            _variables.push_back(var);
        }
};

#endif // B2CONSTRAINTSUM_H_INCLUDED

#ifndef B2CONSTRAINTSUM_H_INCLUDED
#define B2CONSTRAINTSUM_H_INCLUDED

#include <vector>

#include "B2Variable.h"
#include "B2Constraint.h"

class MultipleConstraint : public Constraint{
private:
    std::vector<int> _idVariables;
    int _result;
    public:
        MultipleConstraint(int res, int type) : Constraint(type){
            _result = res;
        }

        MultipleConstraint(std::vector<int> ids, int res, int type) : Constraint(type){
            for(unsigned int i = 0; i < ids.size(); i++)
            {
                _idVariables.push_back(ids[i]);
            }
            _result = res;
        }

        ~MultipleConstraint(){}

        virtual bool test();
        virtual bool canTest();
        virtual void print() const;

        void addVariable(int id){
            _idVariables.push_back(id);
        }
};

#endif // B2CONSTRAINTSUM_H_INCLUDED

#ifndef B2CONSTRAINT_H_INCLUDED
#define B2CONSTRAINT_H_INCLUDED

#include <map>

/*
*   Type :
*   0 => equality (binaire)
*   1 => inequality (binaire)
*   2 => superior (binaire)
*   3 => inferior (binaire)
*   4 => sum (multiple)
*/

class Constraint{
protected:
    int _type;
    std::map<int, int> _variables; // [id, value]
public:
        Constraint(int type) : _type(type) {}
        virtual ~Constraint(){}
        virtual bool test() = 0; // renvoie vrai si la contrainte est respecté
        virtual bool canTest() = 0; // renvoie vrai si les variables requises sont toutes presentes
        virtual void print() const = 0;
        int getType(){ return _type;}
        void setVariables(std::map<int, int> variables){ _variables = variables; }
};


#endif // B2CONSTRAINT_H_INCLUDED

#ifndef B2CONSTRAINT_H_INCLUDED
#define B2CONSTRAINT_H_INCLUDED

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
public:
        Constraint(int type) : _type(type) {}
        virtual ~Constraint(){}
        virtual bool test() = 0;
        virtual void print() const = 0;
        int getType(){ return _type;}
};


#endif // B2CONSTRAINT_H_INCLUDED

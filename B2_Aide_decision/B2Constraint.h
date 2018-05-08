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
    int _type;

public:
        Constraint(int type) : _type(type) {};
        ~Constraint(){};
        virtual bool test() = 0;
};


#endif // B2CONSTRAINT_H_INCLUDED

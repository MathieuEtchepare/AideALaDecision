#ifndef B2CONSTRAINT_H_INCLUDED
#define B2CONSTRAINT_H_INCLUDED

class Constraint{
    int type;


public:
        Constraint(){};
        ~Constraint(){};
        virtual bool test(){std::cout<<"NIKE TA MERE";}
};


#endif // B2CONSTRAINT_H_INCLUDED

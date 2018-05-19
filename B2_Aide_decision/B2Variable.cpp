#include "B2Variable.h"

using namespace std;

Variable::Variable(int id){
    _id = id;
}

Variable::~Variable(){}

void Variable::push_domain(int n){
    _domain.push_back(n);
}

void Variable::print(){
    cout << "x" << _id;
    cout << ": { ";
    for(unsigned int i = 0; i < _domain.size(); i++){
        cout << _domain[i] << " ";
    }

    cout << "}" << endl;
}

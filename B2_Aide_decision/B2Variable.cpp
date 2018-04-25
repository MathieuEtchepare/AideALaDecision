#include "B2Variable.h"

using namespace std;

Variable::Variable(int val){
    value = val;
}

Variable::~Variable(){}

void Variable::push_domain(int n){
    domain.push_back(n);
}

void Variable::print(){
    cout << "Value : " << value << endl;
    cout << "Domain : ";
    for(unsigned int i = 0; i < domain.size(); i++){
        cout << domain[i] << " ";
    }

    cout << endl;
}

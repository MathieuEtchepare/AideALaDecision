#include "B2Problem.h"

using namespace std;

Problem::Problem(string const &filename){
    readFile(filename);
}
Problem::~Problem(){

}

void Problem::readFile(string const &filename){
    ifstream flow;
    int index, value, field, n;
    flow.open(filename.c_str());

    if(flow.fail()) {
        cerr << "ERREUR DE CHARGEMENT DU FICHIER" << endl;
        return;
    }

    flow >> index;
    for(int i = 0; i < index; i++){
        flow >> value;
        flow >> field;

        Variable var(value);
        for(int j = 0; j < field; j++){
            flow >> n;
            var.push_domain(n);
        }
        variables.push_back(var);
    }

    print();
}

void Problem::print(){
    cout << "Problem details : " << endl << endl;
    for(unsigned int i = 0; i < variables.size(); i++){
        variables[i].print();
    }
}

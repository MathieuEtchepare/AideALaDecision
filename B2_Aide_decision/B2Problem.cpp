#include "B2Problem.h"

using namespace std;

Problem::Problem(string const &filename){
    readFile(filename);
}

Problem::~Problem(){

}

void Problem::readFile(string const &filename){
    ifstream flow;
    int index, field;
    int n, m;
    flow.open(filename.c_str());

    if(flow.fail()) {
        cerr << "ERREUR DE CHARGEMENT DU FICHIER" << endl;
        return;
    }

    // On charge les domaines de valeurs
    flow >> index;
    for(int i = 0; i < index; i++){
        flow >> n; // recupere le numero de la variable
        flow >> field; // recupere la taille du domaine

        _variables[n] = new Variable(n);
        for(int j = 0; j < field; j++){
            flow >> m;
            _variables[n]->push_domain(m);
        }
    }

    // On charge les contraines
    flow >> index; // recupere le type de la contrainte
    while(index != -1){
        if(index > 0 && index <= 4){
            flow >> n;
            flow >> m;
            _constraints.push_back(new BinaryConstraint(_variables[n], _variables[m], index));
        }else if(index > 4 && index <= 5){
            std::vector<Variable*> vars;
            flow >> n;
            flow >> m;
            while(m != -2){
                vars.push_back(_variables[m]);
                flow >> m;
            }
            _constraints.push_back(new MultipleConstraint(vars, n, index));
        }else{
            cerr << "ERREUR DE CHARGEMENT DE LA CONTRAINTE A L'INDEX " << index << endl;
        }

        flow >> index;
    }
}

void Problem::print(){
    cout << "Problem details : " << endl << endl;
    for(map<int, Variable*>::iterator it=_variables.begin(); it!=_variables.end(); ++it)
    {
        it->second->print();
    }

    cout << endl;
    for(unsigned int i = 0; i < _constraints.size(); i++){
        _constraints[i]->print();
    }
}

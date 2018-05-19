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
    flow >> _nVariables;
    for(int i = 0; i < _nVariables; i++){
        vector<int> domain;

        flow >> n; // recupere le numero de la variable
        flow >> field; // recupere la taille du domaine

        for(int j = 0; j < field; j++){
            flow >> m;
            domain.push_back(m);
        }
        _variables.push_back(n);
        _domains[n] = domain;
    }

    // On charge les contraines
    flow >> index; // recupere le type de la contrainte
    while(index != -1){
        if(index > 0 && index <= 4){
            flow >> n;
            flow >> m;
            _constraints.push_back(new BinaryConstraint(n, m, index));
        }else if(index > 4 && index <= 5){
            std::vector<int> vars;
            flow >> n;
            flow >> m;
            while(m != -2){
                vars.push_back(m);
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
    for(map<int, vector<int> >::iterator it=_domains.begin(); it!=_domains.end(); ++it)
    {
        cout << "x" << it->first;
        cout << ": { ";
        for(unsigned int i = 0; i < it->second.size(); i++){

            cout << it->second[i] << " ";
        }
        cout << "}" << endl;
    }
    cout << endl;
    for(unsigned int i = 0; i < _constraints.size(); i++){
        _constraints[i]->print();
    }
}

map<int, int> Problem::trivial(Node node){
    if(node._current_variables.size() == _variables.size()){ // C'est une fueille
        for(unsigned int i = 0; i < _constraints.size(); i++){
            _constraints[i]->setVariables(node._current_variables);
            if(!_constraints[i]->test()){
                map<int, int> m;
                return m;
            }
        }
        cout << "On a trouve une solution!" << endl;
        return node._current_variables;
    }else{
        //Selection de la prochain variable
        int nextId = node._idVariable + 1;
        if(DEBUG) cout << "On passe a la variable : " << nextId << endl;
        for(unsigned int i = 0; i < _domains[nextId].size(); i++){
            Node n;
            n._idVariable = nextId;
            n._valueVariable = _domains[nextId][i];
            //if(DEBUG) cout << "On lui met la valeur : " << n._valueVariable << endl;

            n._current_variables = node._current_variables; // On rajoute la nouvelle variable
            n._current_variables[n._idVariable] = n._valueVariable;
            n._current_domains = node._current_domains;

            map<int, int> solution = trivial(n);

            if(solution.size() != 0) return solution;
        }

    }

    map<int, int> m;
    return m;
}




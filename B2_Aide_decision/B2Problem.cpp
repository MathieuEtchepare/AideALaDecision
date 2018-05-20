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
        if(index > 0 && index <= 6){
            flow >> n;
            flow >> m;
            _constraints.push_back(new BinaryConstraint(n, m, index));
        }else if(index > 6 && index <= 9){
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

void Problem::printVariablesOrder(){
    cout << ": { ";
    for(unsigned int i = 0; i < _variables.size(); i++){ // on parcourt les variables
            cout << _variables[i] << " ";
    }
    cout << "}" << endl;
}

map<int, int> Problem::method_trivial(Node node){
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
        int nextIndex = node._index + 1; // index qui point vers l'id de la variable
        int idVariable = _variables[nextIndex];

        for(unsigned int i = 0; i < _domains[idVariable].size(); i++){
            Node n;
            n._index = nextIndex;
            n._valueVariable = _domains[idVariable][i];

            n._current_variables = node._current_variables; // On rajoute la nouvelle variable
            n._current_variables[idVariable] = n._valueVariable;

            n._current_domains = node._current_domains; // En trivial, on ne s'occupe pas des domaines de valeurs

            map<int, int> solution = method_trivial(n);

            if(solution.size() != 0) return solution;
        }

    }

    map<int, int> m;
    return m;
}

map<int, int> Problem::method_reduction(Node node){
    if(node._current_variables.size() == _variables.size()){ // C'est une fueille
        cout << "On a trouve une solution!" << endl;
        return node._current_variables;
    }else{
        //Selection de la prochain variable
        int nextIndex = node._index + 1; // index qui point vers l'id de la variable
        int idVariable = _variables[nextIndex];
        //cout << "analyse variable : " << idVariable << endl;
        bool child = true; // Si il y a encore moyen d'aller plus beau (tout les domaines ne sont pas nuls)
        for(unsigned int i = 0; i < node._current_domains[idVariable].size(); i++){
            child = true;

            Node n;
            n._index = nextIndex;
            n._valueVariable = node._current_domains[idVariable][i];

            n._current_variables = node._current_variables; // On rajoute la nouvelle variable
            n._current_variables[idVariable] = n._valueVariable;

            n._current_domains = node._current_domains; // En trivial, on ne s'occupe pas des domaines de valeurs

            for(int j = nextIndex + 1; j < _nVariables; j++){ // On parcourt toute les variables pas encore traiter pour reduire leurs domaine de valeurs
                int jVariable = _variables[j];
                n._current_domains[jVariable] = new_domain(jVariable, n._current_domains[jVariable], n._current_variables);
                if(n._current_domains[jVariable].size() == 0) child = false;
            }

            if(child){
                map<int, int> solution = method_reduction(n);
                if(solution.size() != 0) return solution;
            }
        }

    }

    map<int, int> m;
    return m;
}

vector<int> Problem::new_domain(int idVariables, vector<int> domain, map<int, int> current_variables){
    vector<int> final_domain;
    bool add = true;

    cout << "new domain for " << idVariables << endl;
    for(unsigned int i = 0; i < domain.size(); i++){ // On test pour chaque valeur dans le domaine si c'est possible
        add = true;
        current_variables[idVariables] = domain[i]; // On rajoute temporairement la valeur de la variable en cours pour les contraintes
        for(unsigned int j = 0; j < _constraints.size(); j++){
            _constraints[j]->setVariables(current_variables);
            if(_constraints[j]->canTest())if(!_constraints[j]->test()) add = false;
        }
        if(add) {
            cout << "adding value : " << domain[i] << endl;
            final_domain.push_back(domain[i]);
        }
    }

    return final_domain;
}

void Problem::sort_variables(){
    for(unsigned int i = 0; i < _variables.size(); i++){ // on parcourt les variables
        for(unsigned int j = i; j < _variables.size(); j++){ // on parcourt les variables
            unsigned int length_domain_i = _domains[_variables[i]].size();
            unsigned int length_domain_j = _domains[_variables[j]].size();
            if(length_domain_j < length_domain_i){
                int tmp = _variables[i];
                _variables[i] = _variables[j];
                _variables[j] = tmp;
            }
        }
    }
}

void Problem::reverse_sort_variables(){
    for(unsigned int i = 0; i < _variables.size(); i++){ // on parcourt les variables
        for(unsigned int j = i; j < _variables.size(); j++){ // on parcourt les variables
            unsigned int length_domain_i = _domains[_variables[i]].size();
            unsigned int length_domain_j = _domains[_variables[j]].size();
            if(length_domain_j > length_domain_i){
                int tmp = _variables[i];
                _variables[i] = _variables[j];
                _variables[j] = tmp;
            }
        }
    }
}

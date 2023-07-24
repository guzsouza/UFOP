#include "Chefe.h"

Chefe::Chefe(
    const string nome, const string usuario, const string senha,
    const vector<Funcionario*> funcionarios
):  Pessoa(nome, usuario, senha), funcionarios(funcionarios) {}

void Chefe::setFuncionarios(vector<Funcionario*> funcionarios) {
    this->funcionarios = funcionarios;
}
vector<Funcionario*> Chefe::getFuncionarios() const {
    // return this->funcionarios;
    return this->funcionarios;
}

/*
void Chefe::adicionarFuncionario(Funcionario* funcionario) {
    if (funcionario == nullptr) return;
    
    vector<Funcionario*> lista = this->getFuncionarios();
    lista.push_back(funcionario);
    // this->setFuncionarios(lista);
    this->funcionarios = lista;
}

void Chefe::listarFuncionarios() {
    // for (auto i = this->funcionarios.begin(); i != this->funcionarios.end(); ++i)
    for (auto funcionario:funcionarios)
        // cout << (*i).getNome() << endl;
        cout << funcionario->getNome() << endl;
}
*/





// bool Chefe::logar(string usuario, string senha) {
//     return (this->getUsuario() == usuario && this->getSenha() == senha);
// }

/*
bool Chefe :: logar(string user, string s){
    return (usuario == user && senha == s);
}

void Chefe :: cadastrarFuncionario(string nome, string cargo, double salario, string user, string s){
    if(cargo == "Vendedor"){
        // a class chefe deveria ser friend da Vendedor?
        Vendedor* vendedor = new Vendedor(nome, salario);
        //adicionar este novo vendedor a lista de funcionarios do chefe
    }else if(cargo == "supervisor"){
        Supervisor* supervisor = new Supervisor(nome, salario);
        // mesmos questionamentos do primeiro if
    }else {
        cout << "O cargo informado é inválido." << endl;
    }
}
*/
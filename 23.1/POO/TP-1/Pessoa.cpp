#include "Pessoa.h"

Pessoa::Pessoa(
    const string nome, const string usuario, const string senha
): nome(nome), usuario(usuario), senha(senha) {}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}
string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setUsuario(string usuario) {
    this->usuario = usuario;
}
const string &Pessoa::getUsuario() const {
    return usuario;
}

void Pessoa::setSenha(string senha) {
    this->senha = senha;
}
const string &Pessoa::getSenha() const {
    return senha;
}

bool Pessoa::logar(string usuario, string senha) {
    return (this->getUsuario() == usuario && this->getSenha() == senha);
}
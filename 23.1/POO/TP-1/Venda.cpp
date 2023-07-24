#include "Venda.h"

Venda::Venda(const float valor): valor(valor) {}

void Venda::setValor(float valor) {
    this->valor = valor;
}
float Venda:: getValor() const {
    return this->valor;
}
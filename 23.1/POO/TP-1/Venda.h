#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include <string>

using namespace std;

class Venda {
    private:
        float valor;
        
    public:
        Venda(const float = 0.0);
        // virtual ~Venda();

        // Getters e Setters

        void setValor(float);
        float getValor() const;
};

#endif
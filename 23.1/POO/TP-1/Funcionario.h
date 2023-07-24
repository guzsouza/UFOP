#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <iostream>
#include <string>
#include <vector>

#include "Pessoa.h"
#include "Hora.h"

using namespace std;

enum class TipoFuncionario { Vendedor, Supervisor };

class Funcionario : public Pessoa {
    private:
        string funcao;
        TipoFuncionario tipo;
    protected:    
        float salarioPorHora;
        Hora tempoTrabalhado;
        Hora horasPendentes;
        vector<Hora*> semana;
    public:
        Funcionario(
            const string = "", const string = "", const string = "",
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor,
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const vector<Hora*> = vector<Hora*>()
        );
        // virtual ~Funcionario();

        // Getters e Setters

        void setSalarioPorHora(float);
        float getSalarioPorHora() const;

        void setTempoTrabalhado(Hora);
        Hora getTempoTrabalhado() const;

        void setHorasPendentes(Hora);
        Hora getHorasPendentes() const;

        void setFuncao(string);
        const string &getFuncao() const;
        
        void setTipo(TipoFuncionario);
        TipoFuncionario getTipo() const;

        void setSemana(vector<Hora*>);
        vector<Hora*> getSemana() const;

        // Funções

        // Pega o horario de inicio e de fim do funcionário
        // Calcula o tempo trabalhado
        // Se o funcionario trabalhar mais que 10 horas em um dia, o sistema invalida
        virtual void cadastrarPonto(Hora, Hora) = 0;
        virtual float calcularSalario() = 0;
        virtual float bonificacao() = 0;    // Funcao que aumenta salario do funcionario
        // void ImprimeSalario();

    // private:
        bool ponto(Hora, Hora, Hora*, int*, int*);
        bool tempoSemana(vector<Hora*>);
    // protected:
        float calculoSalarioPorHoras(TipoFuncionario);
};

#endif
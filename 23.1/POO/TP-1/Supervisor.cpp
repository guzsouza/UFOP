#include "Supervisor.h"

// /*
Supervisor::Supervisor(
    const string nome, const string usuario, const string senha,
    const string funcao, const TipoFuncionario tipo, const float salarioPorHora,
    const Hora& tempoTrabalhado, const Hora& horasPendentes,
    const vector<Hora*> semana, const vector<Vendedor*> vendedores
): Funcionario(
        nome, usuario, senha, funcao, tipo, salarioPorHora, tempoTrabalhado, 
        horasPendentes, semana
    ), vendedores(vendedores) {}
// */

void Supervisor::setVendedor(vector<Vendedor*> Vendedor) {
    this->vendedores = Vendedor;
}
vector<Vendedor*> Supervisor::getVendedor() const {
    return this->vendedores;
}

void Supervisor::cadastrarPonto(Hora inicio, Hora fim) {
    int horasTrabalhado, minutosTrabalhado;
    Hora horasPendentes = this->getHorasPendentes();
    
    if(!this->ponto(inicio, fim, &horasPendentes, &horasTrabalhado, &minutosTrabalhado)) {
        cout << "Não é possivel registrar ponto, excedeu as horas diarias" << endl;
        return;
    }

    // Se o funcionário trabalhou menos que 8 horas no dia
    // adicionamos o tempo que ficou faltando nas horas pendentes
    if(horasTrabalhado < 8) {
        if(minutosTrabalhado != 0) {
            horasPendentes.setHoras(horasPendentes.getHoras() - (7 - horasTrabalhado));
            horasPendentes.setMinutos(horasPendentes.getMinutos() - (60 - minutosTrabalhado));

            if(horasPendentes.getMinutos() <= -60) {
                horasPendentes.setMinutos(horasPendentes.getMinutos() + 60);
                horasPendentes.setHoras(horasPendentes.getHoras() - 1);
            }
        }
        else horasPendentes.setHoras(horasPendentes.getHoras() - (8 - horasTrabalhado));
    }

    // Atribuimos as horas trabalhadas removendo as horas extras
    Hora tempoTrabalhado(horasTrabalhado, minutosTrabalhado);

    if(semana.size() == 7) {
        if(!this->tempoSemana(semana)) {
            cout << "Não é possivel registrar ponto, excedeu as horas semanais" << endl;
            return;
        } 
        semana.clear();
    }

    this->setTempoTrabalhado(tempoTrabalhado);

    cout << "Ponto cadastrado com sucesso.\n" << endl;

    return;
}

float Supervisor::calcularSalario() {
    return calculoSalarioPorHoras(this->getTipo()) + bonificacao();
}

float Supervisor::bonificacao() {
    float valorTotal = 0.0;

    for(auto i = this->vendedores.begin(); i != this->vendedores.end(); ++i) {
        vector<Venda*> vendas = (*i)->getVendas();
        for(auto j = vendas.begin(); j != vendas.end(); ++j)
            valorTotal += (*j)->getValor() * 0.01;
    }
    
    return valorTotal;
}

/*
void Supervisor::adicionarVendedor(Vendedor vendedor) {
    this->vendedores.push_back(vendedor);
}

void Supervisor::listarVendedores() {
    for (auto i = this->vendedores.begin(); i != this->vendedores.end(); ++i)
        cout << (*i).getNome() << endl;
}
*/
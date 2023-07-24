#include "Vendedor.h"

Vendedor::Vendedor(
    const string nome, const string usuario, const string senha,
    const string funcao, const TipoFuncionario tipo, const float salarioPorHora,
    const Hora& tempoTrabalhado, const Hora& horasPendentes,
    const vector<Hora*> semana, const vector<Venda*> vendas
): Funcionario(
        nome, usuario, senha, funcao, tipo, salarioPorHora, tempoTrabalhado, 
        horasPendentes, semana
    ), vendas(vendas) {}

void Vendedor::setVendas(vector<Venda*> vendas) {
    this->vendas = vendas;
}
vector<Venda*> Vendedor::getVendas() const {
    return this->vendas;
}

void Vendedor::cadastrarPonto(Hora inicio, Hora fim) {
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
    horasTrabalhado += this->getTempoTrabalhado().getHoras();
    minutosTrabalhado += this->getTempoTrabalhado().getMinutos();

    if(minutosTrabalhado >= 60) {
        minutosTrabalhado -= 60;
        horasTrabalhado += 1;
    }

    Hora tempoTrabalhado(horasTrabalhado, minutosTrabalhado);
    vector<Hora*> semana = this->getSemana();
    semana.push_back(&tempoTrabalhado);

    cout << semana.size() << endl;

    if(semana.size() == 5 || semana.size() == 6) {
        if(!this->tempoSemana(semana)) {
            cout << "Não é possivel registrar ponto, excedeu as horas semanais" << endl;
            return;
        } 
        semana.clear();
    }

    this->setSemana(semana);
    this->setTempoTrabalhado(tempoTrabalhado);

    cout << "Ponto cadastrado com sucesso.\n" << endl;

    return;
}

float Vendedor::calcularSalario() {
    return this->calculoSalarioPorHoras(this->getTipo()) + bonificacao();
}

float Vendedor::bonificacao() {
    float valorTotal = 0.0;

    // for (auto i = this->vendas.begin(); i != this->vendas.end(); ++i)
    for (auto venda:this->getVendas())
        // valorTotal += (*i)->getValor() * 0.1;
        valorTotal += venda->getValor() * 0.1;
    
    return valorTotal;
}

void Vendedor::adicionarVenda(Venda* venda) {
    this->vendas.push_back(venda);
}

/*
void Vendedor::listarVendas() {
    for (auto i = this->vendas.begin(); i != this->vendas.end(); ++i)
        cout << (*i)->getValor() << endl;
}
*/
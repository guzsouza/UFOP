#include "Chefe.h"
#include "Funcionario.h"
#include "Supervisor.h"
#include "Vendedor.h"
#include "Venda.h"
#include "Hora.h"
#include <iostream>
#include <vector>
#include <stdexcept>

//Gabriel Saldanha
//Mariana Macedo
//Gabriel Henrique
//Maria Bessa
//Gustavo Zacarias
//Joao Ramalho



using namespace std;

// /*
// void cadastrarFuncionario(Chefe* chefe, vector<Funcionario*> *funcionarios) {
void cadastrarFuncionario(vector<Funcionario*> *funcionarios) {
    string nome = "", usuario = "", senha = "", funcao = "";
    float salarioPorHora = 0;
    int tipoFuncionario = -1;

    Funcionario *funcionario = new Vendedor();
    
    cout << "Informe os dados do Funcionario" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << endl << "Usuario: ";
    getline (cin, usuario);
    cout << endl << "Senha: ";
    getline (cin, senha);
    cout << endl << "Salário por hora: ";
    cin >> salarioPorHora;
    do {
        cout << endl << "Tipo: " << endl << "   0- Vendedor" << endl << "   1- Supervisor" << endl;
        cin >> tipoFuncionario;
        if(tipoFuncionario == 0)
            funcionario = new Vendedor(nome, usuario, senha, funcao, TipoFuncionario::Vendedor, salarioPorHora);
        else if(tipoFuncionario == 1)
            funcionario = new Supervisor(nome, usuario, senha, funcao, TipoFuncionario::Supervisor, salarioPorHora);
        else
            cout << "Informe um t&&o válido" << endl;
    } while(tipoFuncionario != 0 && tipoFuncionario != 1);

    // chefe->adicionarFuncionario(funcionario);
    
    funcionarios->push_back(funcionario);

    // delete funcionario;
}

void telaChefe(Chefe *chefe, vector<Funcionario*> *funcionarios) {
    string opcaoStr;
    int opcao = -1;
    bool verifica;
    do {
        verifica = 1; 
        try {
            cout << "---------------------Tela Chefe---------------------" << endl;
            cout << "    0- Cadastrar funcionário" << endl;
            cout << "    1- Listar funcionários cadastrados" << endl;
            cout << "    2- Checar ponto" << endl;
            cout << "    3- Calcular salário" << endl;
            cout << "    4- Voltar" << endl;

            cout << "Informe a opção que deseja execultar:" << endl;
            cin >> opcaoStr;
            opcao = stoi(opcaoStr);
        } catch (const invalid_argument& e) {
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }

        if(verifica){
            switch (opcao) {
                case 0:
                    // Funcionario funcionario = new Funcionario(...dados)
                    // cadastrarFuncionario(chefe, funcionarios);
                    cadastrarFuncionario(funcionarios);
                    // teste2(funcionarios);
                    // teste(funcionarios);
                    break;
                
                case 1:
                    // funcionarios.map((funcionario) => return funcionario.dados)
                    // chefe->listarFuncionarios();
                    // cout << "asdfasd" << endl;
                    // Funcionario *teste = new Funcionario((*chefe).getFuncionarios().begin());
                    // cout << teste->getNome() << endl;
                    
                    // for(auto funcionario:(*chefe).getFuncionarios()) {
                    for(auto funcionario:(*funcionarios)) {
                        cout << "Nome: " << funcionario->getNome() << endl;
                    }
                    // teste2(funcionarios);
                    break;
                
                case 2:
                    // Passa por todos os funcionarios e informa os seus dados(Nome, Tempo Trabalhado)
                    for(auto funcionario:(*funcionarios)) {
                        cout << "Nome: " << funcionario->getNome() << endl;
                        cout << "Tempo Trabalhado: " << funcionario->calcularSalario()/funcionario->getSalarioPorHora() << " horas" << endl;
                    }
                    break;
                
                case 3:
                    // Passa por todos os funcionarios e informa os seus dados(Nome, Salário)
                    
                    
                    for(auto funcionario:(*funcionarios)) {
                        cout << "Nome: " << funcionario->getNome() << endl;
                        cout << "Salário: " << funcionario->calcularSalario() << "R$" << endl;
                    }
                    break;
                
                case 4:
                    break;
                
                default:
                    cout << "Informe uma opção válida.\n" << endl;
                    break;
            }
        }
    } while(opcao != 4 && verifica != 0);
}

void cadastrarPonto(Funcionario *funcionario) {
    Hora *pontoInicio, *pontoFim;
    int horasPontoInicio, minutosPontoInicio, horasPontoFim, minutosPontoFim;
    
    cout << "Informe as Horas do inicio do ponto: ";
    cin >> horasPontoInicio;
    cout << endl << "Informe os Minutos do inicio do ponto: ";
    cin >> minutosPontoInicio;
    cout << endl << "Informe as Horas do fim do ponto: ";
    cin >> horasPontoFim;
    cout << endl << "Informe os Minutos do fim do ponto: ";
    cin >> minutosPontoFim;

    pontoInicio = new Hora(horasPontoInicio, minutosPontoInicio);
    pontoFim = new Hora(horasPontoFim, minutosPontoFim);

    funcionario->cadastrarPonto(*pontoInicio, *pontoFim);

    cout << funcionario->getTempoTrabalhado().getHoras() << ":" << funcionario->getTempoTrabalhado().getMinutos() << endl;
}

void listarVendas(Vendedor *vendedor) {
    cout << "Nome do vendedor: " << vendedor->getNome() << endl;
    
    for(auto venda:vendedor->getVendas())
        cout << "Valor Venda: " << venda->getValor() << endl;
}

void telaFuncionario(Funcionario *funcionario, vector<Funcionario*> *funcionarios) {
    int opcao;
    Vendedor* vendedor = dynamic_cast<Vendedor*>(funcionario);
    vector<Vendedor*> vendedores;
    for(auto func:(*funcionarios))
        vendedores.push_back(dynamic_cast<Vendedor*>(func));
    // Supervisor* supervisor = dynamic_cast<Supervisor*>(funcionario);

    do {
        cout << "------------------Tela Funcionário------------------" << endl;
        cout << "    0- Cadastrar ponto" << endl;
        cout << "    1- Exibir salário" << endl;
        cout << "    2- Cadastrar venda" << endl;
        cout << "    3- Listar vendas" << endl;
        cout << "    4- Voltar para o Menu Inicial" << endl;

        cout << "Informe a opção que deseja execultar:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                // int horarioChegada, horarioSaida
                // int horasTrabalhada = horarioSaida - horarioChegada
                // funcionario.setPonto(horasTrabalhada)
                cadastrarPonto(funcionario);
                break;
            
            case 1:
                // int salario = calcSalario(funcionario.dados)
                // print salario
                cout << "Salário: " << funcionario->calcularSalario() << "R$" << endl;
                break;
            
            case 2: {
                if(funcionario->getTipo() == TipoFuncionario::Supervisor) {
                    cout << "Apenas Vendedores podem realizar vendas" << endl;  // Trocar por um alerta ou um warning
                    break;
                }

                float valorVenda; // <= adicionar o valor da venda
                Venda* venda = new Venda();

                cout << "Informe o Valor da Venda: ";
                cin >> valorVenda;

                venda->setValor(valorVenda);

                // funcionario.adicionarVenda(venda);
                vendedor->adicionarVenda(venda);

                // delete venda;

                break;
            }

            case 3:
                if(funcionario->getTipo() == TipoFuncionario::Supervisor) {
                    for(auto vendedor:vendedores) {
                        // cout << vendedor.get ->getNome();
                        listarVendas(vendedor);
                    }            
                    break;
                }
                // if(funcionario.isSupervisor)
                    // supervisor.funcionarios.map((funcionario) => return funcionario.vendas)
                // else
                    // funcionario.vendas
                listarVendas(vendedor);

                break;
            
            case 4:
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
                break;
        }
    } while(opcao != 4);
}

bool login(Chefe *chefe, vector<Funcionario*> *funcionarios, int tipoLogin, string usuario, string senha) {
    bool achou = false;
    
    // Procura se o usuario e senha existem na lista de Chefes
    if(tipoLogin == 0) {
        // Uma maneira de procurar todos os chefes
        // E examinar usuario e senha de cada chefe
        achou = chefe->logar(usuario, senha);
        if(achou)
            cout << "Logou." << endl;
        else
            cout << "Não logou." << endl;

        // Se achar um chefe q os dados batem c os q foram passados, vamos para a tela do chefe
        if(achou)
            // Tela Chefe
            telaChefe(chefe, funcionarios);
    }
    else {
        // Uma maneira de procurar todos os funcionarios
        // E examinar usuario e senha de cada funcionario
        for(auto funcionario:(*funcionarios))
            if(funcionario->logar(usuario, senha)) {
                achou = true;
                telaFuncionario(funcionario, funcionarios);
            }
                
        // Se achar um funcionario q os dados batem c os q foram passados, vamos para a tela do funcionario
    }

    // Se o Chefe/Funcionario conseguiram acessar sua tela, sera retornado True e voltaremos para o Menu Inicial
    // Se os dados de login n bateram c os q temos armazenados, sera retornado False e voltaremos para o Menu de Login para o usuaro tentar novamente ou voltar manualmente para a o Menu Inicial

    return achou;
}

bool realizarLogin(Chefe *chefe, vector<Funcionario*> *funcionarios, int tipoLogin, string usuario, string senha) {
    // Se conseguir fazer login
    
    if(login(chefe, funcionarios,tipoLogin, usuario, senha)) return true;
    // if(true) return true;
    
    // Se n conseguir fazer login vai exibir mensagem de erro e retornara para a Tela de Login
    cout << "Login inválida.\n" << endl;

    return false;
}

void telaLogin(Chefe *chefe, vector<Funcionario*> *funcionarios) {
    int tipoLogin;
    string usuario, senha;
    
    do {
        cout << "-----------------------Login------------------------" << endl;
        cout << "    0- Login Chefe" << endl;
        cout << "    1- Login Funcionário" << endl;
        cout << "    2- Voltar ao Menu Inicial" << endl;
        cin >> tipoLogin;

        switch (tipoLogin)
        {
            case 0:
            case 1:
                cout << "Informe o seu usuario:" << endl;
                cin >> usuario;

                cout << "Informe a sua senha:" << endl;
                cin >> senha;

                // Se n conseguir fazer login retorna para o menu de login
                if(!realizarLogin(chefe, funcionarios,tipoLogin, usuario, senha))
                    return;
                break;
            
            case 2:
                cout << "Voltando para a tela de login:" << endl;
                break;
            
            default:
                break;
        }
    } while(tipoLogin != 2);
}

void telaInicial(Chefe *chefe, vector<Funcionario*> *funcionarios) {
    int opcao;

    do {
        cout << "--------------------Menu Inicial--------------------" << endl;
        cout << "    0- Login" << endl;
        cout << "    1- Sair do menu" << endl;

        cout << "Informe a opção que deseja execultar:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                telaLogin(chefe, funcionarios);
                break;
            
            case 1:
                cout << "Finalizando.\n" << endl;
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
        }
    } while(opcao != 1);
}

Chefe* iniciarChefe() {
    string nome, usuario, senha;
    int opcao;

    Chefe* chefe;

    cout << "Cadastre o Chefe:" << endl;
    cout << "Informe seu nome: ";
    getline(cin, nome);
    
    cout << "Quer adicionar Usuario e Senha?" << endl;
    cout << "   0- Não (se mantem como padrão Usuario = 'admin' e Senha = 'admin')" << endl;
    cout << "   1- Sim" << endl;
    cin >> opcao;

    if(opcao == 0) chefe = new Chefe(nome);
    else {
        cout << endl << "Usuário: ";
        cin >> usuario;
        cout << endl << "Senha: ";
        cin >> senha;

        chefe = new Chefe(nome, usuario, senha);
    }
    
    fflush(stdin);
    cout << "Chefe criado com sucesso" << endl << endl;

    return chefe;
}
// */

int main() {
    Chefe *chefe;
    vector<Funcionario*> funcionarios;

    chefe = iniciarChefe();
    
    telaInicial(chefe, &funcionarios);
    
    cout << "Finalizando o programa.\n" << endl;
    // delete chefe, funcionarios;
    
    return 0;
}


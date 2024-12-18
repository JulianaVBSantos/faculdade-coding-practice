#include <iostream>
#include <string>
#include <iomanip> // Para std::fixed e std::setprecision

using namespace std;

// Classe Cliente: representa um cliente do banco
class Cliente {
private:
    string nome; // Nome do cliente
    string cpf;  // CPF do cliente

public:
    // Construtor da classe Cliente
    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}

    // Método getter para obter o nome do cliente
    string getNome() const {
        return nome;
    }

    // Método getter para obter o CPF do cliente
    string getCpf() const {
        return cpf;
    }
};

// Classe ContaBancaria: representa uma conta bancária
class ContaBancaria {
private:
    int numero;          // Número da conta
    double saldo;       // Saldo da conta
    Cliente titular;    // Titular da conta (objeto da classe Cliente)

public:
    // Construtor da classe ContaBancaria
    ContaBancaria(int numero, Cliente titular, double saldo = 0.0) 
        : numero(numero), titular(titular), saldo(saldo) {}

    // Método para depositar um valor na conta
    void depositar(double valor) {
        saldo += valor; // Adiciona o valor ao saldo
        cout << "Depositado: R$ " << fixed << setprecision(2) << valor 
             << " na conta " << numero << endl;
    }

    // Método para sacar um valor da conta
    void sacar(double valor) {
        if (valor > saldo) { // Verifica se há saldo suficiente
            cout << "Saldo insuficiente para saque de R$ " << valor << endl;
        } else {
            saldo -= valor; // Subtrai o valor do saldo
            cout << "Sacado: R$ " << fixed << setprecision(2) << valor 
                 << " da conta " << numero << endl;
        }
    }

    // Sobrecarga do método transferir para transferir para uma conta
    void transferir(double valor, ContaBancaria &destino) {
        if (valor > saldo) { // Verifica se há saldo suficiente
            cout << "Saldo insuficiente para transferência de R$ " << valor << endl;
        } else {
            saldo -= valor; // Subtrai o valor do saldo
            destino.depositar(valor); // Deposita o valor na conta destino
            cout << "Transferido: R$ " << fixed << setprecision(2) << valor 
                 << " da conta " << numero << " para a conta " << destino.numero << endl;
        }
    }

    // Sobrecarga do método transferir para transferir para duas contas
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        if (valor > saldo) { // Verifica se há saldo suficiente
            cout << "Saldo insuficiente para transferência de R$ " << valor << endl;
        } else {
            double valorPorConta = valor / 2; // Divide o valor entre as duas contas
            saldo -= valor; // Subtrai o valor total do saldo
            destino1.depositar(valorPorConta); // Deposita na primeira conta
            destino2.depositar(valorPorConta); // Deposita na segunda conta
            cout << "Transferido: R$ " << fixed << setprecision(2) << valorPorConta 
                 << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << numero << endl;
        }
    }

    // Método para exibir o saldo atual da conta
    void exibirSaldo() const {
        cout << "Saldo atual da conta " << numero << ": R$ " << fixed << setprecision(2) << saldo << endl;
    }

    // Método para exibir as informações do titular e da conta
    void exibirInformacoes() const {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
        cout << "Numero da Conta: " << numero << ", Saldo: R$ " << fixed << setprecision(2) << saldo << endl;
    }
};

int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0); // Conta de Ana com R$ 1000
    ContaBancaria conta2(1002, cliente2);          // Conta de Bruno, saldo inicial de R$ 0
    ContaBancaria conta3(1003, cliente3);          // Conta de Carla, saldo inicial de R$ 0

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais de cada conta
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
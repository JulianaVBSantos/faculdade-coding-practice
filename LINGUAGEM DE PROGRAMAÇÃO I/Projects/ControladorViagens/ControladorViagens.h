#ifndef CONTROLADORVIAGENS_H
#define CONTROLADORVIAGENS_H

#include <string>
#include <vector>
#include <map>

// Definições de classes auxiliares

class Cidade {
public:
    Cidade(std::string nome);
    std::string getNome();
private:
    std::string nome;
};

class Trajeto {
public:
    Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia);
    Cidade* getOrigem();
    Cidade* getDestino();
    char getTipo();
    int getDistancia();
private:
    Cidade* origem;
    Cidade* destino;
    char tipo;
    int distancia;
};

class Transporte {
public:
    Transporte(std::string nome, char tipo, int capacidade, int velocidade,
               int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual);
    std::string getNome();
    char getTipo();
    int getCapacidade();
    int getVelocidade();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
private:
    std::string nome;
    char tipo;
    int capacidade;
    int velocidade;
    int distancia_entre_descansos;
    int tempo_de_descanso;
    Cidade* localAtual;
};

class Passageiro {
public:
    Passageiro(std::string nome, Cidade* localAtual);
    std::string getNome();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
private:
    std::string nome;
    Cidade* localAtual;
};

class Viagem {
public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);
    void iniciarViagem();
    void avancarHoras(int horas);
    bool isEmAndamento();
    Cidade* getOrigem();
    Cidade* getDestino();
    Transporte* getTransporte();
private:
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    bool emAndamento;
    int horasEmTransito;
};

// Classe ControladorDeTransito
class ControladorDeTransito {
public:
    ControladorDeTransito(); // Declaração do construtor

    void cadastrarCidade(std::string nome);
    void cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, std::string localAtual);
    void cadastrarPassageiro(std::string nome, std::string localAtual);
    void iniciarViagem(std::string nomeTransporte, std::string nomeOrigem, std::string nomeDestino);
    void relatarPassageiros();
    void relatarTransportes();
    void relatarViagensEmAndamento();
    void relatarCidadesMaisVisitadas();

private:
    Cidade* buscarCidade(std::string nome);
    std::vector<Cidade*> cidades;
    std::vector<Trajeto*> trajetos;
    std::vector<Transporte*> transportes;
    std::vector<Passageiro*> passageiros;
    std::vector<Viagem*> viagens;
};

#endif // CONTROLADORVIAGENS_H
#include "ControladorViagens.h"
#include <iostream>

// Implementação das classes auxiliares

Cidade::Cidade(std::string nome) : nome(nome) {}

std::string Cidade::getNome() {
    return nome;
}

Trajeto::Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia)
    : origem(origem), destino(destino), tipo(tipo), distancia(distancia) {}

Cidade* Trajeto::getOrigem() { return origem; }
Cidade* Trajeto::getDestino() { return destino; }
char Trajeto::getTipo() { return tipo; }
int Trajeto::getDistancia() { return distancia; }

Transporte::Transporte(std::string nome, char tipo, int capacidade, int velocidade,
                       int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual)
    : nome(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade),
      distancia_entre_descansos(distancia_entre_descansos), tempo_de_descanso(tempo_de_descanso), localAtual(localAtual) {}

std::string Transporte::getNome() { return nome; }
char Transporte::getTipo() { return tipo; }
int Transporte::getCapacidade() { return capacidade; }
int Transporte::getVelocidade() { return velocidade; }
Cidade* Transporte::getLocalAtual() { return localAtual; }
void Transporte::setLocalAtual(Cidade* local) { localAtual = local; }

Passageiro::Passageiro(std::string nome, Cidade* localAtual) : nome(nome), localAtual(localAtual) {}

std::string Passageiro::getNome() { return nome; }
Cidade* Passageiro::getLocalAtual() { return localAtual; }
void Passageiro::setLocalAtual(Cidade* local) { localAtual = local; }

Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino)
    : transporte(transporte), passageiros(passageiros), origem(origem), destino(destino), emAndamento(false), horasEmTransito(0) {}

void Viagem::iniciarViagem() {
    if (transporte->getLocalAtual() == origem) {
        emAndamento = true;
        std::cout << "Viagem iniciada de " << origem->getNome() << " para " << destino->getNome() << ".\n";
    } else {
        std::cout << "Erro: Transporte não está na cidade de origem.\n";
    }
}

void Viagem::avancarHoras(int horas) {
    if (emAndamento) {
        horasEmTransito += horas;
        std::cout << "Avançando " << horas << " horas na viagem.\n";
        if (horasEmTransito * transporte->getVelocidade() >= origem->getNome().length()) { // Simulação simples
            emAndamento = false;
            transporte->setLocalAtual(destino);
            std::cout << "Viagem concluída! Chegamos a " << destino->getNome() << ".\n";
        }
    } else {
        std::cout << "Viagem não está em andamento.\n";
    }
}

bool Viagem::isEmAndamento() { return emAndamento; }
Cidade* Viagem::getOrigem() { return origem; }
Cidade* Viagem::getDestino() { return destino; }
Transporte* Viagem::getTransporte() { return transporte; }

ControladorDeTransito::ControladorDeTransito() {
    // Inicialização se necessário
}

void ControladorDeTransito::cadastrarCidade(std::string nome) {
    cidades.push_back(new Cidade(nome));
    std::cout << "Cidade " << nome << " cadastrada.\n";
}

void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia) {
    Cidade* origem = buscarCidade(nomeOrigem);
    Cidade* destino = buscarCidade(nomeDestino);
    if (origem && destino) {
        trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
        std::cout << "Trajeto de " << nomeOrigem << " para " << nomeDestino << " cadastrado.\n";
    } else {
        std::cout << "Erro ao cadastrar trajeto: Cidade não encontrada.\n";
    }
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, std::string localAtual) {
    Cidade* local = buscarCidade(localAtual);
    if (local) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, local));
        std::cout << "Transporte " << nome << " cadastrado.\n";
    } else {
        std::cout << "Erro ao cadastrar transporte: Cidade não encontrada.\n";
    }
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localAtual) {
    Cidade* local = buscarCidade(localAtual);
    if (local) {
        passageiros.push_back(new Passageiro(nome, local));
        std::cout << "Passageiro " << nome << " cadastrado.\n";
    } else {
        std::cout << "Erro ao cadastrar passageiro: Cidade não encontrada.\n";
    }
}

void ControladorDeTransito::iniciarViagem(std::string nomeTransporte, std::string nomeOrigem, std::string nomeDestino) {
    // Encontrar transporte
    Transporte* transporte = nullptr;
    for (auto& t : transportes) {
        if (t->getNome() == nomeTransporte) {
            transporte = t;
            break;
        }
    }

    if (transporte == nullptr) {
        std::cout << "Erro: Transporte não encontrado.\n";
        return;
    }

    // Encontrar as cidades de origem e destino
    Cidade* origem = buscarCidade(nomeOrigem);
    Cidade* destino = buscarCidade(nomeDestino);

    if (origem == nullptr || destino == nullptr) {
        std::cout << "Erro: Cidade de origem ou destino não encontrada.\n";
        return;
    }

    // Criar uma nova viagem
    Viagem* viagem = new Viagem(transporte, {}, origem, destino);
    viagens.push_back(viagem);

    // Iniciar viagem
    viagem->iniciarViagem();
    std::cout << "Viagem iniciada de " << nomeOrigem << " para " << nomeDestino << " usando o transporte " << nomeTransporte << ".\n";
}

void ControladorDeTransito::relatarPassageiros() {
    std::cout << "\nRelatório de Passageiros:\n";
    if (passageiros.empty()) {
        std::cout << "Nenhum passageiro cadastrado.\n";
    } else {
        for (auto& passageiro : passageiros) {
            std::cout << "Passageiro: " << passageiro->getNome() 
                      << ", Local Atual: " << passageiro->getLocalAtual()->getNome() << "\n";
        }
    }
}

void ControladorDeTransito::relatarTransportes() {
    std::cout << "\nRelatório de Transportes:\n";
    if (transportes.empty()) {
        std::cout << "Nenhum transporte cadastrado.\n";
    } else {
        for (auto& transporte : transportes) {
            std::cout << "Transporte: " << transporte->getNome() 
                      << ", Tipo: " << transporte->getTipo() 
                      << ", Local Atual: " << transporte->getLocalAtual()->getNome() << "\n";
        }
    }
}

void ControladorDeTransito::relatarViagensEmAndamento() {
    std::cout << "\nRelatório de Viagens em Andamento:\n";
    bool encontrou = false;
    for (auto& viagem : viagens) {
        if (viagem->isEmAndamento()) {
            encontrou = true;
            std::cout << "Viagem de " << viagem->getOrigem()->getNome() 
                      << " para " << viagem->getDestino()->getNome() 
                      << ", Transporte: " << viagem->getTransporte()->getNome() << "\n";
        }
    }
    if (!encontrou) {
        std::cout << "Nenhuma viagem em andamento.\n";
    }
}

void ControladorDeTransito::relatarCidadesMaisVisitadas() {
    std::cout << "\nRelatório de Cidades Mais Visitadas:\n";
    if (cidades.empty()) {
        std::cout << "Nenhuma cidade cadastrada.\n";
    } else {
        for (auto& cidade : cidades) {
            std::cout << "Cidade: " << cidade->getNome() << "\n";
        }
    }
}

Cidade* ControladorDeTransito::buscarCidade(std::string nome) {
    for (auto& cidade : cidades) {
        if (cidade->getNome() == nome) {
            return cidade;
        }
    }
    return nullptr;
}
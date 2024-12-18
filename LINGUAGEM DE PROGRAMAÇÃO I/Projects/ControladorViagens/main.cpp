#include <iostream>
#include "ControladorViagens.h"

int main() {
    ControladorDeTransito controlador;

    // Cadastrar Cidades
    controlador.cadastrarCidade("Natal");
    controlador.cadastrarCidade("Recife");
    controlador.cadastrarCidade("São Paulo");

    // Cadastrar Trajetos
    controlador.cadastrarTrajeto("Natal", "Recife", 'A', 200);
    controlador.cadastrarTrajeto("Recife", "São Paulo", 'A', 300);
    controlador.cadastrarTrajeto("São Paulo", "Natal", 'A', 400);

    // Cadastrar Transportes
    controlador.cadastrarTransporte("Ônibus 1", 'A', 50, 80, 100, 30, "Natal");
    controlador.cadastrarTransporte("Navio 1", 'B', 200, 60, 500, 60, "Recife");

    // Cadastrar Passageiros
    controlador.cadastrarPassageiro("João", "Natal");
    controlador.cadastrarPassageiro("Maria", "Recife");
    controlador.cadastrarPassageiro("Pedro", "São Paulo");

    // Relatórios
    controlador.relatarPassageiros();
    controlador.relatarTransportes();
    controlador.relatarViagensEmAndamento();
    controlador.relatarCidadesMaisVisitadas();

    return 0;
}
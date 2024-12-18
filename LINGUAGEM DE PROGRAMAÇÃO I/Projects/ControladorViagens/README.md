# Controlador de Viagens

Este projeto simula um sistema de transporte entre cidades, onde é possível cadastrar cidades, trajetos, transportes e passageiros. Também é possível iniciar viagens, avançar o tempo de viagem e gerar relatórios sobre o status atual das viagens.

## Funcionalidades

- **Cadastro de Cidades**: Permite cadastrar cidades no sistema.
- **Cadastro de Trajetos**: Permite cadastrar trajetos entre duas cidades, incluindo o tipo (aquático ou terrestre) e a distância.
- **Cadastro de Transportes**: Permite cadastrar diferentes transportes (ônibus, navios, etc.), com informações como capacidade, velocidade, e detalhes sobre paradas para descanso.
- **Cadastro de Passageiros**: Permite cadastrar passageiros, associando-os a uma cidade de origem.
- **Gestão de Viagens**: Permite iniciar viagens, avançar o tempo (simulando o percurso), e registrar a chegada aos destinos.
- **Relatórios**: Gera relatórios detalhados sobre a localização de passageiros e transportes, viagens em andamento e as cidades mais visitadas.

## Como Rodar

1. Compile os arquivos `main.cpp`, `ControladorViagens.cpp`, e `ControladorViagens.h`. Para compilar, execute o seguinte comando no terminal:
    ```bash
    g++ main.cpp ControladorViagens.cpp -o ControladorViagens
    ```
2. Após a compilação, execute o programa gerado:
    ```bash
    ./ControladorViagens
    ```

3. O sistema irá permitir que você interaja com o programa através do console. Você poderá cadastrar cidades, trajetos, transportes, passageiros e iniciar viagens.

### Requisitos

- **Compilador C++** (como o **g++** ou **Clang**) deve estar instalado no seu sistema.
    - Para instalar o **g++**, use o seguinte comando (em sistemas baseados no Debian, como Ubuntu):
        ```bash
        sudo apt install g++
        ```
    - Para compilar e rodar o código no Windows, você pode usar o **MinGW** ou configurar o **Cygwin**.

## Estrutura do Código

- **ControladorViagens.h**: Declaração das classes e suas funções, incluindo o cabeçalho para a implementação das funcionalidades de cadastro e gestão de viagens.
- **ControladorViagens.cpp**: Implementação das classes e funções, onde a lógica de manipulação dos dados (cidades, trajetos, transportes, etc.) é processada.
- **main.cpp**: Arquivo principal que gerencia a execução do sistema, recebendo comandos do usuário via console e interagindo com as classes do controlador.

## Relatórios Gerados

O sistema pode gerar os seguintes relatórios:

1. **Relatório de Passageiros**: Exibe a lista de passageiros cadastrados e suas cidades de origem.
2. **Relatório de Transportes**: Mostra os transportes disponíveis e suas cidades atuais.
3. **Relatório de Viagens em Andamento**: Exibe as viagens que estão em andamento, com detalhes sobre os transportes e cidades de origem e destino.
4. **Relatório de Cidades Mais Visitadas**: Mostra uma lista de cidades cadastradas e a quantidade de vezes que elas foram visitadas (ou outras métricas que você desejar implementar).
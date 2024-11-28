# Projeto 1b - Gestão de Cargas Portuárias

## 📖 Introdução
Este projeto tem como objetivo desenvolver uma aplicação em linguagem **C** que utiliza a estrutura de dados **Fila**, implementada com lista encadeada, para simular a gestão de cargas portuárias. O sistema organiza e prioriza o carregamento e descarregamento de cargas, garantindo eficiência e agilidade nas operações.

---

## 📋 Requisitos do Projeto
O sistema implementará as seguintes funcionalidades:
1. Utilização da estrutura de dados **Fila**, com lista encadeada, para gerenciar as cargas.
2. Implementação das operações básicas:
   - Inserção de cargas.
   - Remoção de cargas com base na prioridade.
   - Busca de cargas específicas pelo **ID**.
   - Exibição das cargas na fila.
3. Suporte para carregamento inicial de dados de um arquivo **.csv**.
4. Opção para adicionar novas cargas manualmente.
5. Modularização do código-fonte para maior organização.

---

## 🗃️ Estrutura de Dados
Cada carga é representada por uma estrutura contendo os seguintes atributos:
- **ID**: Identificador único da carga.
- **Tipo de carga**: Container, granel sólido, granel líquido, etc.
- **Peso**: Valor em quilogramas.
- **Prioridade**: Baixa, normal ou alta.
- **Descrição**: Detalhes adicionais sobre a carga.

---

## 🛠️ Operações Implementadas

### 1. Inserção de Carga
- As cargas são adicionadas ao final da fila, respeitando a ordem de chegada.
- O sistema valida os atributos obrigatórios antes da inserção.
- Novas cargas podem ser adicionadas manualmente ou carregadas de um arquivo **.csv**.

### 2. Remoção de Carga com Prioridade
As regras para remoção são:
1. Localizar a primeira carga na fila com prioridade **Alta**.
2. Se houver múltiplas cargas com prioridade Alta, remover a mais antiga (ordem de chegada).
3. Caso não existam cargas de prioridade Alta, remover a carga no início da fila.

### 3. Busca de Carga
- Permite ao usuário buscar uma carga pelo ID.
- Exibe todos os atributos da carga encontrada.

### 4. Exibição de Cargas
- Lista todas as cargas da fila em ordem de chegada.

## **🚀 Funcionamento Geral**

1. O sistema carrega os dados iniciais a partir de um arquivo .csv.
2 O usuário interage com o sistema por meio de um menu para:
- Visualizar as cargas na fila.
- Adicionar novas cargas.
- Processar a próxima carga.
3. Após o processamento, a carga removida é exibida, e a fila é reorganizada.
4. O sistema exibe mensagens claras para cada operação.

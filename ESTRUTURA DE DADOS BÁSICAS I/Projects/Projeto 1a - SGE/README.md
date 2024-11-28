# Sistema de Gerenciamento de Estoque

## 1. Introdução

Este projeto tem como objetivo desenvolver um sistema de gerenciamento de estoque de produtos utilizando:

- Uma lista sequencial para armazenar os dados dos produtos;
- Manipulação de arquivos para persistir os dados; e
- Redimensionamento dinâmico de vetor para lidar com o crescimento do estoque.

---

## 2. Objetivos

O sistema de gerenciamento de estoque permitirá:

- Inserir novos produtos no estoque;
- Remover produtos do estoque;
- Buscar produtos por código;
- Atualizar a quantidade e o preço de produtos;
- Listar todos os produtos cadastrados;
- Gravar os dados do estoque em um arquivo;
- Carregar os dados do estoque a partir de um arquivo;
- Redimensionar o vetor de produtos dinamicamente quando o número de produtos ultrapassar a capacidade inicial.

---

## 3. Funcionalidades

### 3.1. Cadastro de Produto
- O sistema permite o cadastro de novos produtos, que incluem:
  - **Código**: Um número inteiro único que identifica o produto.
  - **Nome**: Uma string com o nome do produto.
  - **Quantidade**: Um número inteiro representando a quantidade disponível do produto.
  - **Preço**: Um valor em ponto flutuante representando o preço do produto.

Os produtos serão armazenados em um vetor dinâmico que será redimensionado automaticamente ao atingir sua capacidade máxima.

### 3.2. Inserção de Produto
- Ao inserir um novo produto, o sistema verifica se o vetor está cheio.
- Caso esteja cheio, o vetor será redimensionado, dobrando sua capacidade atual.

### 3.3. Remoção de Produto
- O sistema permite a remoção de produtos identificados pelo código.
- Após a remoção, os produtos subsequentes serão reorganizados para manter a lista sequencial.

### 3.4. Busca de Produto
- Busca por código, retornando as informações do produto (nome, quantidade e preço) ou uma mensagem indicando que ele não foi encontrado.

### 3.5. Atualização de Produto
- Permite alterar a quantidade e o preço de um produto já cadastrado, utilizando o código do produto.

### 3.6. Listagem de Produtos
- Exibe todos os produtos cadastrados no estoque de forma organizada.

### 3.7. Persistência de Dados
- Os dados do estoque são gravados e carregados de um arquivo de texto:
  - **Gravação**: Todos os produtos do estoque são gravados em um arquivo.
  - **Leitura**: Os produtos são carregados do arquivo ao iniciar o sistema.

---

## 4. Estrutura de Dados

### 4.1. Vetor Dinâmico
Os produtos serão armazenados em um vetor dinâmico com as seguintes características:
- **Capacidade inicial**: Definida pelo usuário ou por um valor padrão.
- **Redimensionamento**: Dobra a capacidade ao atingir o limite máximo.
- **Tamanho atual**: Controla a quantidade de produtos armazenados.

---

## 5. Operações

### 5.1. Inserção de Produto
- Verifica se a lista está cheia.
- Redimensiona o vetor, dobrando sua capacidade, caso necessário.
- Insere o novo produto na lista.

### 5.2. Remoção de Produto
- Busca o produto pelo código.
- Remove o produto e reorganiza a lista, caso encontrado.

### 5.3. Busca de Produto
- Percorre a lista em busca do produto pelo código.
- Retorna as informações do produto ou uma mensagem de erro.

### 5.4. Atualização de Produto
- Busca o produto pelo código.
- Atualiza a quantidade e o preço, caso encontrado.

---

## 6. Manipulação de Arquivos

### 6.1. Gravação em Arquivo
Os dados dos produtos são gravados em um arquivo de texto, incluindo:
- Código do produto;
- Nome do produto;
- Quantidade disponível;
- Preço do produto.

### 6.2. Leitura de Arquivo
Ao iniciar o sistema, os produtos salvos anteriormente são carregados do arquivo, garantindo a continuidade do gerenciamento do estoque.

---

## 7. Redimensionamento do Vetor

Quando o vetor de produtos atinge sua capacidade máxima, ele é redimensionado:

- A capacidade é dobrada.
- O conteúdo do vetor original é copiado para o novo vetor.
- O vetor antigo é liberado da memória.

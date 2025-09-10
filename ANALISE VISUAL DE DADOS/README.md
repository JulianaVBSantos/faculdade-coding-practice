# 📊 Análise de Desempenho de Jogadores Brasileiros no Valorant (VCT 2024)

## 📌 Sobre o Projeto
Este projeto tem como objetivo analisar o **desempenho de jogadores brasileiros** nos torneios oficiais do **Valorant Champions Tour 2024 (VCT)**.  
A análise será feita com base em estatísticas de jogadores em diferentes competições:

- 🏆 VCT International  
- 🎮 VCT Game Changers  
- ⚔️ VCT Challengers
---

## 📂 Estrutura do Projeto
projeto-valorant 

┣ 📄 Stats-Valorant.xlsx # Planilha com todas as abas (Challengers, Game Changer, International)

┣ 📄 vct-challengers.csv # Dados convertidos (Kaggle → CSV)

┣ 📄 vct-game-changer.csv

┣ 📄 vct-international.csv

┣ 📄 conversorJsonCSV.csv # Script para converter JSON → CSV

┣ 📄 Stats.py # Organização do dataset em dataframe para futuras manipulações e filtros de dados

┗ 📄 README.md # Documentação do projeto

---

## 📊 Fontes de Dados
Os dados foram obtidos do Kaggle:  
🔗 [Valorant Champions Tour 2024 Dataset](https://www.kaggle.com/datasets/sauurabhkr/valorant-champions-tour-2024)

---

## 🛠️ Tecnologias Utilizadas
- **Python 3.10+**
- **Pandas** → manipulação de dados
- **OpenPyXL** → leitura de Excel
- **JSON** → leitura de dados originais
- **Matplotlib / Seaborn** → (para visualização, etapas futuras)

---

## 🚀 Como Executar
1. Clone o repositório ou baixe os arquivos.
2. Instale as dependências:
   ```bash
   pip install pandas openpyxl

---

📈 Possíveis Análises

Comparar rating médio dos jogadores brasileiros por torneio.

Ver ACS (average combat score) entre os times brasileiros.

Comparar jogadores de destaque (ex: Aspas, mwzera, qck).

Evolução da performance entre Challengers → International.

Distribuição de headshot % por jogador.

---

👥 Equipe

Juliana Vieira B. Santos

Bernardo Paiva da Monte

---

📌 Status do Projeto

--> Coleta e organização dos dados

--> Análises estatísticas e gráficos (em andamento)

-->️ Conclusões finais (a desenvolver)

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
┣ 📄 converter.py # Script para converter JSON → CSV

┣ 📄 jogbrasileiros.py # Script para filtrar jogadores brasileiros

┣ 📄 Stats-Valorant.xlsx # Planilha com todas as abas (Challengers, Game Changer, International)

┣ 📄 vct-challengers.csv # Dados convertidos (Kaggle → CSV)

┣ 📄 vct-game-changer.csv

┣ 📄 vct-international.csv

┣ 📄 jogadores_brasileiros.csv # Resultado com filtro de players BR

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
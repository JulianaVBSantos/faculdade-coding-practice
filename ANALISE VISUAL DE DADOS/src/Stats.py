# Add cada dataframe pelo nome da aba --> Futuras manipulacoes de dados

import pandas as pd

caminho_arquivo = 'Stats-Valorant.xlsx'

todos_os_dados = pd.read_excel(caminho_arquivo, sheet_name=None)

df_international = todos_os_dados['vct-international']
df_game_changer = todos_os_dados['vct-game-changer']
df_challengers = todos_os_dados['vct-challengers']

# exibe as 5 primeiras linhas
print("--- Aba: vct-international ---")
print(df_international.head())

print("\n--- Aba: vct-game-changer ---")
print(df_game_changer.head())

print("\n--- Aba: vct-challengers ---")
print(df_challengers.head())
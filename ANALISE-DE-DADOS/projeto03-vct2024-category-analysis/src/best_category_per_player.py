import pandas as pd

df = pd.read_excel("valorant_players_filter01.xlsx")

df["rating"] = pd.to_numeric(df["rating"], errors="coerce")
df["average_combat_score"] = pd.to_numeric(df["average_combat_score"], errors="coerce")
df["kill_deaths"] = pd.to_numeric(df["kill_deaths"], errors="coerce")


df["performance_index"] = (
    df["rating"] +
    df["average_combat_score"] +
    df["kill_deaths"]
)

df = df.sort_values(by="performance_index", ascending=False)


df_melhores = df.drop_duplicates(subset="playerName", keep="first")


df_melhores.to_excel("Statistics-Valorant-Unid03-MELHORES.xlsx", index=False)

print("Jogadores duplicados tratados com sucesso!")
print(f"Registros originais: {len(df)}")
print(f"Registros finais (1 por jogador): {len(df_melhores)}")

import pandas as pd

df = pd.read_excel("Statistics-Valorant-Unid03.xlsx")

df["rating"] = pd.to_numeric(df["rating"], errors="coerce")
df["average_combat_score"] = pd.to_numeric(df["average_combat_score"], errors="coerce")
df["kill_deaths"] = pd.to_numeric(df["kill_deaths"], errors="coerce")


df_limpo = df[
    (df["rating"].notnull()) & (df["rating"] != 0) &
    (df["average_combat_score"].notnull()) & (df["average_combat_score"] != 0) &
    (df["kill_deaths"].notnull()) & (df["kill_deaths"] != 0)
]

df_limpo.to_excel("Statistics-Valorant-Unid03-LIMPO.xlsx", index=False)

print("Dados limpos com sucesso!")
print(f"Registros originais: {len(df)}")
print(f"Registros após limpeza: {len(df_limpo)}")
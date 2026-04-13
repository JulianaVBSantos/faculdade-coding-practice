import pandas as pd

file_path = "UniquePlayers-BestCategory.xlsx"

df = pd.read_excel(file_path)

df["performance_index"] = pd.to_numeric(df["performance_index"], errors="coerce")
df["rating"] = pd.to_numeric(df["rating"], errors="coerce")
df["average_combat_score"] = pd.to_numeric(df["average_combat_score"], errors="coerce")
df["kill_deaths"] = pd.to_numeric(df["kill_deaths"], errors="coerce")

df = df.dropna(subset=["playerCategory", "playerName", "performance_index"])

top5_por_categoria = {}

for categoria in df["playerCategory"].unique():
    top5 = (
        df[df["playerCategory"] == categoria]
        .sort_values(by="performance_index", ascending=False)
        .head(5)
    )
    
    top5_por_categoria[categoria] = top5

for categoria, top5 in top5_por_categoria.items():
    print(f"\n🏷️ Categoria: {categoria}")
    print("-" * 60)
    print(top5[[
        "playerName",
        "rating",
        "average_combat_score",
        "kill_deaths",
        "performance_index"
    ]].to_string(index=False))

import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

df = pd.read_excel("Statistics-Valorant-Unid03.xlsx")

df = df.fillna(0)

df["rating"] = pd.to_numeric(df["rating"], errors="coerce")
df["average_combat_score"] = pd.to_numeric(df["average_combat_score"], errors="coerce")
df["kill_deaths"] = pd.to_numeric(df["kill_deaths"], errors="coerce")

df = df.fillna(0)

rating = df["rating"]
acs = df["average_combat_score"]
kd = df["kill_deaths"]

fig = plt.figure(figsize=(10, 7), facecolor="#0F1923")  # fundo escuro
ax = fig.add_subplot(111, projection='3d')

valorant_red = "#FF4655"
valorant_cyan = "#00E5E5"
valorant_grey = "#A8B2BA"

ax.scatter(
    rating, acs, kd,
    s=60,
    c=valorant_red,
    edgecolor=valorant_cyan,
    linewidth=1.2,
    alpha=0.9
)

ax.set_xlabel("Rating", color=valorant_cyan, fontsize=12, labelpad=10)
ax.set_ylabel("ACS", color=valorant_cyan, fontsize=12, labelpad=10)
ax.set_zlabel("K/D", color=valorant_cyan, fontsize=12, labelpad=10)

ax.set_title(
    "Relação 3D entre Rating, ACS e K/D\n(Estilo VALORANT)",
    color=valorant_red,
    fontsize=15,
    pad=20
)

ax.tick_params(colors=valorant_grey, labelsize=10)

ax.xaxis.set_pane_color((0.05, 0.1, 0.15, 0.95))
ax.yaxis.set_pane_color((0.05, 0.1, 0.15, 0.95))
ax.zaxis.set_pane_color((0.05, 0.1, 0.15, 0.95))

ax.xaxis.line.set_color(valorant_grey)
ax.yaxis.line.set_color(valorant_grey)
ax.zaxis.line.set_color(valorant_grey)

ax.grid(color=valorant_grey, linestyle="dotted", alpha=0.2)

plt.tight_layout()
plt.show()
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from adjustText import adjust_text
from matplotlib.lines import Line2D

FILE_PATH = "UniquePlayers-BestCategory.xlsx"
TOP_N = 15 

BG_COLOR = "#ffffff"
PRIMARY = "#ff4655"
TEXT = "#111111"
GRID = "#dddddd"

CATEGORY_COLORS = {
    "Duelist": "#ff4655",
    "Controller": "#00F0FF",
    "Initiator": "#7CFF00",
    "Sentinel": "#FFD700",
    "Unknown": "#555555"
}

CATEGORY_MARKERS = {
    "vct-challengers": "s",     # quadrado
    "vct-international": "o",   # círculo
    "vct-game-changers": "*"    # estrela
}


df = pd.read_excel(FILE_PATH)

df["playerCategory"] = df["playerCategory"].fillna("Unknown")

fig, ax = plt.subplots(figsize=(15, 9))

fig.patch.set_facecolor(BG_COLOR)
ax.set_facecolor(BG_COLOR)

top = df.sort_values(by="performance_index", ascending=False).head(TOP_N)
others = df.drop(top.index)

ax.scatter(
    others["kill_deaths"],
    others["rating"],
    c="#bcbcbc",
    s=40,
    alpha=0.6,
    label="Others"
)

edgecolors = [CATEGORY_COLORS.get(cat, "#555555") for cat in top["playerCategory"]]

for categoria in top["playerCategory"].unique():

    subset = top[top["playerCategory"] == categoria]

    sc = ax.scatter(
        subset["kill_deaths"],
        subset["rating"],
        c=subset["average_combat_score"],
        cmap="plasma",
        s=260,
        marker=CATEGORY_MARKERS.get(categoria, "o"),
        edgecolors=[CATEGORY_COLORS.get(cat, "#555555") for cat in subset["playerCategory"]],
        linewidths=2.5,
        zorder=5,
        label=categoria
    )


mean_kd = df["kill_deaths"].mean()
mean_rating = df["rating"].mean()

ax.axvline(mean_kd, color="#666666", linestyle="--", alpha=0.6)
ax.axhline(mean_rating, color="#666666", linestyle="--", alpha=0.6)

ax.text(mean_kd, ax.get_ylim()[1], " Mean K/D", color="#444444", fontsize=10, ha="left", va="top")
ax.text(ax.get_xlim()[1], mean_rating, " Mean Rating", color="#444444", fontsize=10, ha="right", va="bottom")

x = df["kill_deaths"]
y = df["rating"]

coef = np.polyfit(x, y, 1)
poly = np.poly1d(coef)
xs = np.linspace(x.min(), x.max(), 100)

ax.plot(xs, poly(xs), color=PRIMARY, linewidth=2, linestyle="-.", alpha=0.9)


texts = []

for i, (_, row) in enumerate(top.iterrows(), 1):
    txt = ax.text(
        row["kill_deaths"],
        row["rating"],
        f"""#{i} {row['playerName']} ({row['playerCategory']})
K/D: {row['kill_deaths']:.2f} | ACS: {row['average_combat_score']:.0f}""",
        fontsize=11,
        fontweight="bold",
        color=TEXT,
        bbox=dict(
            facecolor="white",
            edgecolor=CATEGORY_COLORS.get(row['playerCategory'], "#333333"),
            boxstyle="round,pad=0.4",
            alpha=0.95
        ),
        zorder=10
    )
    texts.append(txt)

adjust_text(
    texts,
    expand_text=(1.4, 1.6),
    expand_points=(1.3, 1.5),
    force_text=(0.5, 0.8),
    force_points=(0.3, 0.5),
    arrowprops=dict(arrowstyle="-", color=PRIMARY, lw=1.2)
)

ax.set_title(
    "VCT PERFORMANCE — TOP 15 PLAYERS\nRating vs K/D (ACS as color | Category as border)",
    color=TEXT,
    fontsize=18,
    fontweight="bold",
    pad=20
)

ax.set_xlabel("K/D Ratio", color=TEXT, fontsize=13, fontweight="bold")
ax.set_ylabel("Rating", color=TEXT, fontsize=13, fontweight="bold")
ax.tick_params(colors=TEXT)

for spine in ax.spines.values():
    spine.set_color("#444444")

ax.grid(color=GRID, linestyle="-", alpha=0.5)

cbar = plt.colorbar(sc, ax=ax)
cbar.set_label("Average Combat Score (ACS)", color=TEXT, fontweight="bold")
cbar.outline.set_edgecolor(PRIMARY)

legend_elements = [
    Line2D([0], [0], marker='s', color='w', label='VCT Challengers',
           markerfacecolor='white', markeredgecolor='#ff4655',
           markersize=11, markeredgewidth=2),

    Line2D([0], [0], marker='o', color='w', label='VCT International',
           markerfacecolor='white', markeredgecolor='#0077ff',
           markersize=11, markeredgewidth=2),

    Line2D([0], [0], marker='*', color='w', label='VCT Game Changers',
           markerfacecolor='white', markeredgecolor='#00aa55',
           markersize=14, markeredgewidth=2),
]


ax.legend(handles=legend_elements, title="Player Category", loc="lower right")

plt.tight_layout()
plt.show()
import pandas as pd
import matplotlib.pyplot as plt

FILE_PATH = "UniquePlayers-BestCategory.xlsx"
TOP_N = 5

df = pd.read_excel(FILE_PATH)

def plot_category(category, data, top_n):

    fig, ax = plt.subplots(figsize=(14, 8))

    top = data.sort_values(by="performance_index", ascending=False).head(top_n)

    others = data.drop(top.index)

    ax.scatter(
        others["kill_deaths"],
        others["rating"],
        c="lightgray",
        s=60,
        alpha=0.5,
        label="Others"
    )

    scatter = ax.scatter(
        top["kill_deaths"],
        top["rating"],
        c=top["average_combat_score"],
        cmap="plasma",
        s=180,
        edgecolors="black",
        linewidths=1.2,
        label="Top 5"
    )

    for _, row in top.iterrows():
        ax.text(
            row["kill_deaths"] + 0.02,
            row["rating"] + 0.02,
            f"{row['playerName']}\n"
            f"K/D: {row['kill_deaths']:.2f}\n"
            f"ACS: {row['average_combat_score']:.0f}",
            fontsize=10,
            fontweight="bold",
            bbox=dict(boxstyle="round,pad=0.3", fc="white", ec="black", alpha=0.9)
        )

    ax.set_title(f"Rating vs K/D — {category.upper()} (Top {top_n})", fontsize=16, fontweight="bold")
    ax.set_xlabel("K/D Ratio", fontsize=12)
    ax.set_ylabel("Rating", fontsize=12)
    ax.grid(alpha=0.3)

    cbar = plt.colorbar(scatter, ax=ax)
    cbar.set_label("Average Combat Score (ACS)", fontsize=12)

    ax.legend()
    plt.tight_layout()
    plt.show()

for category, cat_data in df.groupby("playerCategory"):
    plot_category(category, cat_data, TOP_N)
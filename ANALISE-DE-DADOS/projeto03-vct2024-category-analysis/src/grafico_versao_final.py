import matplotlib.pyplot as plt
import numpy as np
from adjustText import adjust_text
from matplotlib.lines import Line2D

players = [
    ("Confident", 1.96, 1.72, 342, "vct-challengers"),
    ("Cina", 1.55, 1.42, 328, "vct-game-changer"),
    ("florescent", 1.69, 1.52, 307, "vct-game-changer"),
    ("Kouf", 1.48, 1.85, 298, "vct-challengers"),
    ("consz", 1.84, 1.58, 297, "vct-challengers"),
    ("natty", 1.30, 1.33, 291, "vct-game-changer"),
    ("stizzy", 1.34, 1.39, 288, "vct-challengers"),
    ("SpiritZ1", 1.23, 1.18, 286, "vct-challengers"),
    ("weyvcode", 1.31, 1.74, 284, "vct-game-changer"),
    ("flow3r", 1.23, 1.45, 282, "vct-game-changer"),
    ("zekken", 1.19, 1.13, 255.3, "vct-international"),
    ("primmie", 1.15, 1.16, 249.9, "vct-international"),
    ("N4RRATE", 1.17, 1.16, 233.2, "vct-international"),
    ("Cryocells", 1.20, 1.14, 230.1, "vct-international"),
    ("Jemkin", 1.22, 1.13, 227.5, "vct-international"),
]

np.random.seed(0)
bg_x = np.random.normal(0.8, 0.3, 700)
bg_y = bg_x * 0.9 + np.random.normal(0, 0.08, 700)

marker_map = {
    "vct-challengers": "s",
    "vct-international": "o",
    "vct-game-changer": "*"
}

symbol_map = {
    "vct-challengers": "■",
    "vct-international": "●",
    "vct-game-changer": "★"
}

edge_map = {
    "vct-challengers": "red",
    "vct-international": "dodgerblue",
    "vct-game-changer": "green"
}

fig, ax = plt.subplots(figsize=(18, 10))

ax.scatter(bg_x, bg_y, alpha=0.3, color="gray")

ax.axvline(np.mean(bg_x), ls="--", color="gray")
ax.axhline(np.mean(bg_y), ls="--", color="gray")
ax.text(2.0, np.mean(bg_y) + 0.01, "Mean Rating", color="gray", ha="right")
ax.text(np.mean(bg_x) + 0.01, 1.9, "Mean K/D", color="gray", rotation=90, va="top")

coef = np.polyfit(bg_x, bg_y, 1)
line_x = np.linspace(0, 2, 100)
line_y = coef[0] * line_x + coef[1]
ax.plot(line_x, line_y, "r--", alpha=0.6)

texts = []
acs_values = [p[3] for p in players]
vmin, vmax = min(acs_values), max(acs_values)

sc_main = ax.scatter([], [], c=[], cmap="plasma", vmin=vmin, vmax=vmax)

for i, (name, kd, rating, acs, category) in enumerate(players, 1):
    marker = marker_map[category]
    edge = edge_map[category]
    symbol = symbol_map[category]

    ax.scatter(
        kd, rating,
        c=acs,
        cmap="plasma",
        vmin=vmin,
        vmax=vmax,
        s=260,
        marker=marker,
        edgecolors=edge,
        linewidths=2,
        zorder=5
    )

    if i == 1:
        ax.scatter(
            kd, rating,
            s=420,
            facecolors="yellow",
            edgecolors="red",
            linewidths=2.5,
            marker=marker,
            zorder=10
        )

    label = f"#{i} {symbol} {name} ({category})\nK/D: {kd:.2f} | ACS: {acs}"

    txt = ax.text(
        kd, rating, label,
        fontsize=10,
        bbox=dict(boxstyle="round,pad=0.3", fc="white", ec="black", alpha=0.9)
    )

    texts.append(txt)

adjust_text(texts, arrowprops=dict(arrowstyle="-", color="red", lw=1.2))

cbar = plt.colorbar(sc_main, ax=ax)
cbar.set_label("Average Combat Score (ACS)")

legend_elements = [
    Line2D([0], [0], marker='o', color='w', label='Others',
           markerfacecolor='gray', alpha=0.5, markersize=10),

    Line2D([0], [0], marker='o', color='w', label='Top Player',
           markerfacecolor='yellow', markeredgecolor='red',
           markeredgewidth=2, markersize=12),

    Line2D([0], [0], linestyle='--', color='red', label='Trend line'),

    Line2D([0], [0], marker="s", color='w', label='■ VCT Challengers',
           markerfacecolor='none', markeredgecolor='red', markersize=12, markeredgewidth=2),

    Line2D([0], [0], marker="o", color='w', label='● VCT International',
           markerfacecolor='none', markeredgecolor='dodgerblue', markersize=12, markeredgewidth=2),

    Line2D([0], [0], marker="*", color='w', label='★ VCT Game Changers',
           markerfacecolor='none', markeredgecolor='green', markersize=14, markeredgewidth=2)
]

ax.legend(
    handles=legend_elements,
    title="Legend",
    loc="lower right",
    frameon=True
)

ax.set_xlabel("K/D Ratio", fontsize=12)
ax.set_ylabel("Rating", fontsize=12)

ax.set_title(
    "VCT PERFORMANCE — TOP 15 PLAYERS\n"
    "Rating vs K/D (ACS as color | Category as border)",
    fontsize=16,
    fontweight="bold"
)

ax.grid(alpha=0.2)
plt.tight_layout()
plt.show()

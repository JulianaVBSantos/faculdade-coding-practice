# Verificar a proporção entre ACS, K/D e rating de maneira separada:

# rating x ACS
# rating x K/D
# ACS x K/D

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_excel("Statistics-Valorant-Unid03.xlsx")

df.columns = df.columns.str.strip().str.lower()
print("Colunas encontradas:", df.columns.tolist())

df["rating"] = pd.to_numeric(df["rating"], errors="coerce").fillna(0)
df["average_combat_score"] = pd.to_numeric(df["average_combat_score"], errors="coerce").fillna(0)
df["kill_deaths"] = pd.to_numeric(df["kill_deaths"], errors="coerce").fillna(0)

rating = df["rating"].to_numpy()
acs = df["average_combat_score"].to_numpy()
kd = df["kill_deaths"].to_numpy()

def correlacao(x, y):
    return np.corrcoef(x, y)[0,1]

corr_rating_acs = correlacao(rating, acs)
corr_rating_kd = correlacao(rating, kd)
corr_acs_kd = correlacao(acs, kd)

print(f"Correlação Rating ↔ ACS: {corr_rating_acs:.3f}")
print(f"Correlação Rating ↔ K/D: {corr_rating_kd:.3f}")
print(f"Correlação ACS ↔ K/D: {corr_acs_kd:.3f}")

def regressao_linear(x, y):
    x_mean = np.mean(x)
    y_mean = np.mean(y)
    b1 = np.sum((x - x_mean)*(y - y_mean)) / np.sum((x - x_mean)**2)
    b0 = y_mean - b1*x_mean
    return b0, b1

b0_ra, b1_ra = regressao_linear(rating, acs)
b0_rk, b1_rk = regressao_linear(rating, kd)
b0_ak, b1_ak = regressao_linear(acs, kd)

print("\nRegressão Rating→ACS:", f"ACS = {b0_ra:.2f} + {b1_ra:.2f} * Rating")
print("Regressão Rating→K/D:", f"K/D = {b0_rk:.2f} + {b1_rk:.2f} * Rating")
print("Regressão ACS→K/D:  ", f"K/D = {b0_ak:.2f} + {b1_ak:.2f} * ACS")


plt.scatter(rating, acs)
plt.plot(rating, b0_ra + b1_ra * rating)
plt.title("Relação entre Rating e ACS")
plt.xlabel("Rating")
plt.ylabel("ACS")
plt.show()

plt.scatter(rating, kd)
plt.plot(rating, b0_rk + b1_rk * rating)
plt.title("Relação entre Rating e K/D")
plt.xlabel("Rating")
plt.ylabel("K/D")
plt.show()

plt.scatter(acs, kd)
plt.plot(acs, b0_ak + b1_ak * acs)
plt.title("Relação entre ACS e K/D")
plt.xlabel("ACS")
plt.ylabel("K/D")
plt.show()

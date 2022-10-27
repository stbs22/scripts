import matplotlib as mpl
import numpy as np
import pandas as pd

from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
from matplotlib import pyplot as plt 
from plotnine import *
from sklearn import datasets
from sklearn.decomposition import PCA
import seaborn as sns

dataframe = pd.read_excel("/home/laptop_eh/scripts/data-mining/entrega1/MicroCredit.xlsx", sheet_name="MicroCredit")
df_hist = dataframe["Cred_Hist"]
df_Vig = dataframe["Cred_Vig"]
df_mora = dataframe["Mora_Max"] 
df_vencido = dataframe["Defaulter"]

df = pd.concat([df_hist, df_Vig, df_mora, df_vencido], axis=1)

# Configuracion Entorno Plot
sns.set(rc={'figure.figsize':(5.27,5.27)})

plt.hist(df_hist)
plt.title("Fercuencia Edades", fontsize = 20)
plt.show()
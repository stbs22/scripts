import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter
import csv


data = pd.read_csv("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD/datap1.csv", sep=",")
country = pd.read_csv("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD/datacountry.csv", sep=",")

#print(data["NOC"].value_counts())
#print(country["Three_Letter_Country_Code"].value_counts())

prueba = []
for a in data["NOC"]:
    if (a not in prueba):
        prueba.append(a)

base = []
for a in country["Three_Letter_Country_Code"]:
    if (a not in base):
        base.append(a)

sin = [] #elementos de base q no tan en prueba
for a in base:
    if (a not in prueba):
        sin.append(a)

p = []
for a in prueba:
    if (a not in base):
        p.append(a)

for i in range(0,len(p)):
    print(p[i])

print(len(prueba), len(base), len(sin) )


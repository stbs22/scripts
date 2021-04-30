import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
data = pd.read_csv("datap1.csv",sep=",") 
#data = pd.read_csv("datap1.csv",sep=",")

edad = data["Age"]

limpio = edad[edad.notna()]

print("Promedio:",edad.mean())

#plt.boxplot(limpio, vert = False)
plt.hist(limpio,bins=40)
    
#plt.xlim(0,100)

plt.show()


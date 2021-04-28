import pandas as pd
import matplotlib.pyplot as plt
data = pd.read_csv("/home/_init_/Documentos/Data/FCD/datap1.csv",sep=",")
#data = pd.read_csv("/home/_init_/Documentos/Data/FCD/data.csv",sep=";")

edad = data["Age"]

limpio = edad[edad.notna()]

print("Promedio:",edad.mean())
print("Promedio:",limpio.mean())

#plt.boxplot(limpio, vert = False)
plt.hist(limpio,bins=40)
    
#plt.xlim(0,100)

plt.show()


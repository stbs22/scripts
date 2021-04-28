import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter
import csv

#Lectura del csv
data = pd.read_csv("/home/_init_/Documentos/Data/FCD/datap1.csv", sep=",")
df = data["Age"]

#Creamos linea para mostrar la mediana
plt.hist(df,bins=40)
plt.axvline(df.median(), color='k', linestyle='-', linewidth=1)
plt.axvline(df.mean(), color='r', linestyle='dashed', linewidth=1)

#Añadimos el texto en la linea de la mediana
min_ylim, max_ylim = plt.ylim()
plt.text(df.median()*1.02, max_ylim*0.9, 'Mediana'.format(df.median()))
plt.text(df.mean()*1.02, max_ylim*0.8, 'Promedio'.format(df.mean()),color='r')

#Funcion para cambiar el formato del eje y
def lblFormat(n, pos):
    if (n==0):
        return str(int(n*10))
    elif (n!=0):
        return str((int(n / 1e3)))+"*10^3"

#Cambiamos formato de eje y
plt.gca().yaxis.set_major_formatter(lblFormat)
plt.xticks([0 ,10 ,20 ,30 ,40 ,50 ,60 ,70 ,80 ,90,100])

#Mostrar el Histograma
plt.show()
plt.close('data')
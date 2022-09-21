# -*- coding: utf-8 -*-

'''@author: Andres C. Medina'''

'''Modulos Utiles'''
from scipy.stats import chi2
import numpy as np
import pandas as pd
import warnings

'''Omite warnings por desactualizacion u otro'''
warnings.simplefilter("ignore")

'''Implementa Distancia Mahalanobis'''

def mahalanobis(x = None, data = None, cov = None):
    # Centro los datos 
    x_mu = x - np.mean(data)
    if not cov:
        cov = np.cov(data.values.T)
    # Calculo la inversa de la matriz de covarianza
    inv_covmat = np.linalg.inv(cov)
    # Calculo la parte izquierda de la formula 
    left = np.dot(x_mu, inv_covmat)
    # Calculo la parte derecha de la formula 
    mahal = np.dot(left, x_mu.T)
    # Retorno la distancia de Mahalanobis
    return mahal.diagonal()

'''Datos Artificiales'''
data = {'puntos': [91, 93, 72, 87, 86, 73, 68, 87, 78, 99, 95, 76, 84, 96, 76, 80, 83, 84, 73, 74],
        'horas': [16, 6, 3, 1, 2, 3, 2, 5, 2, 5, 2, 3, 4, 3, 3, 3, 4, 3, 4, 4],
        'prep': [3, 4, 0, 3, 4, 0, 1, 2, 1, 2, 3, 3, 3, 2, 2, 2, 3, 3, 2, 2],
        'grado': [70, 88, 80, 83, 88, 84, 78, 94, 90, 93, 89, 82, 95, 94, 81, 93, 93, 90, 89, 89]
        }

df = pd.DataFrame(data,columns=['puntos', 'horas', 'prep','grado'])
print(df.head())

'''Calculo Distancia Mahalanobis'''
df['mahalanobis'] = mahalanobis(x=df, data=df[['puntos', 'horas', 'prep','grado']])
print(df.head(5))

'''Calculo del pvalue en la distancia de mahalanobis'''
df['p'] = 1 - chi2.cdf(df['mahalanobis'], 3)
print(df.head())

'''
Tipicamente, un pvalue menor a 0.001 es considerado como 
un outliers. Por lo tanto, podemos ver que la primera 
observacion es un outlier en el conjunto de datos ya que el 
pvalue < 0.001.
'''
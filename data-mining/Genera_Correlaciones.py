#!/usr/bin/env python 
# -*- coding: utf-8 -*-

'''
@autor: Andres C. Medina
Aprendizaje No Supervisado: Generacion V.A.
'''

'''Modulos Utiles'''
#from re import template
from matplotlib import pyplot as plt 
from scipy.stats import norm, pearsonr
import numpy as np
import seaborn as sns
import warnings

'''Configuracion de Seaborn'''
sns.set_style('darkgrid')
sns.set(rc={'figure.figsize':(5.27,5.27)})

'''Omite warnings por desactualizacion u otro'''
warnings.simplefilter("ignore")

'''Generacion de Variables Aleatorias'''
x = norm.rvs(size = 5000, loc = 0, scale = 1)
y = norm.rvs(size = 5000, loc = 0, scale = 1)

'''Matriz de Varianza / Covarianza'''
M = np.stack((x, y), axis=0)
print(np.cov(M))

'''Correlacion de Pearson'''
r, p = pearsonr(x,y)
print(f"Correlación Pearson: r={r}, p-value={p}")

'''Plot JointGrid'''
g = sns.JointGrid(x,y)
g.plot_joint(sns.scatterplot, s=10, alpha=.5)
g.plot_marginals(sns.histplot, kde=False, bins=100)
plt.show()

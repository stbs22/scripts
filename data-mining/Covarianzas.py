#!/usr/bin/env python 
# -*- coding: utf-8 -*-

'''
@autor: Andres C. Medina
Aprendizaje No Supervisado: Distancia Mahalanobis y Cov.
'''

from scipy.stats import multivariate_normal
from matplotlib import pyplot as plt
import numpy as np

def ejemplos_distribuciones_normales():
    x, y = np.mgrid[-1:1:0.01, -1:1:0.01]
    posicion = np.dstack((x,y))
    
    rv1 = multivariate_normal(mean=[0, 0], cov=[[0.1, 0],[0, 0.1]])
    rv2 = multivariate_normal(mean=[0, 0], cov=[[1, 0],[0, 1]])
    rv3 = multivariate_normal(mean=[0.5, -1], cov=[[1, 0],[0, 1]])
    
    rv4 = multivariate_normal(mean=[0, 0], cov=[[1, 0],[0, 1]])
    rv5 = multivariate_normal(mean=[0, 0], cov=[[1, 0.5],[0.5, 1]])
    rv6 = multivariate_normal(mean=[0, 0], cov=[[1, 0.9],[0.9, 1]])
       
    rv7 = multivariate_normal(mean=[0, 0], cov=[[1, 0],[0, 1]])
    rv8 = multivariate_normal(mean=[0, 0], cov=[[1, -0.5],[-0.5, 1]])
    rv9 = multivariate_normal(mean=[0, 0], cov=[[1, -0.9],[-0.9, 1]])    
        
    fig, ([ax1,ax2,ax3],[ax4,ax5,ax6],[ax7,ax8,ax9]) = plt.subplots(3, 3, figsize=(10,10))
    
    # Primera Fila
    ax1.contourf(x, y, rv1.pdf(posicion), cmap='jet')
    ax1.set_title('$\mu=0$, $\Sigma=[0.1, 0]$', fontsize=15)
    ax2.contourf(x, y, rv2.pdf(posicion), cmap='jet')
    ax2.set_title('$\mu=0$, $\Sigma=[1, 0]$', fontsize=15)
    ax3.contourf(x, y, rv3.pdf(posicion), cmap='jet')
    ax3.set_title('$\mu=[0.5, -1]$, $\Sigma=[1, 0]$', fontsize=15)
    
    # Segunda Fila 
    ax4.contourf(x, y, rv4.pdf(posicion), cmap='jet')
    ax4.set_title('$\mu=0$, $\Sigma=[1, 0]$', fontsize=15)
    ax5.contourf(x, y, rv5.pdf(posicion), cmap='jet')
    ax5.set_title('$\mu=0$, $\Sigma=[1, 0.5]$', fontsize=15)
    ax6.contourf(x, y, rv6.pdf(posicion), cmap='jet')
    ax6.set_title('$\mu=0$, $\Sigma=[1, 0.9]$', fontsize=15)
    
    # Tercera Fila 
    ax7.contourf(x, y, rv7.pdf(posicion), cmap='jet')
    ax7.set_title('$\mu=0$, $\Sigma=[1, 0]$', fontsize=15)
    ax8.contourf(x, y, rv8.pdf(posicion), cmap='jet')
    ax8.set_title('$\mu=0$, $\Sigma=[1, -0.5]$', fontsize=15)
    ax9.contourf(x, y, rv9.pdf(posicion), cmap='jet')
    ax9.set_title('$\mu=0$, $\Sigma=[1, -0.9]$', fontsize=15)
    plt.tight_layout()
    plt.show()

ejemplos_distribuciones_normales()


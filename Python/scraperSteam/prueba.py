from logging import exception
from selenium import webdriver

import time
import sys
import os

superaro = '\x1B[35m'
raro = '\x1B[34m'
comun = '\x1B[32m'
reset = '\x1B[0m'


#limpiar vacios de lista con elementos de tipo WebElement
def limpiar(lista):   
     
    new_lista = []

    for i in lista:
        if(len(i.text) != 0):
            new_lista.append(i)

    return new_lista


pagina = "https://store.steampowered.com/specials#p=0&tab=TopSellers"

path_driver = "/home/_init_/chromedriver"

try:
    driver = webdriver.Chrome(path_driver)
    driver.minimize_window()

    driver.get(pagina)

    time.sleep(3)

    ofertas = limpiar(driver.find_elements_by_class_name("tab_item"))

    time.sleep(3)

    os.system("clear")

    lista = ofertas

    for i in lista:
        nodo = i.text.split("\n")

        print("\n--------")
        print("nombre",nodo[3])

        valor = int(nodo[0][1]+nodo[0][2])

        print(valor+1)

        if(valor >= 81):
            print("oferta: ",superaro,nodo[0],reset)
        if(valor < 81 & valor >= 51):
            print("oferta: ",raro,nodo[0],reset)
        if(valor < 51):
            print("oferta: ",comun,nodo[0],reset)

        print("\nprecio original de: ",nodo[1]," --> ",nodo[2])
        print("--------")

        x = input("\n$$Presione enter para continuar, {q} para salir: ")

        if (x == "q"):
            break
        
    driver.close()

except:

    print("ta malo feo qlo... ", sys.exc_info()[0])
    driver.close()
from logging import exception
from selenium import webdriver

import time
import sys
import os

superaro = '\x1B[35m'
raro = '\x1B[36m'
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
    ofertas = limpiar(driver.find_elements_by_class_name("tab_item"))

    time.sleep(3)

    os.system("clear")

    lista = ofertas

    for i in lista:
        os.system("clear")
        nodo = i.text.split("\n")

        print("\n--------")
        print("Juego: ",nodo[3])
        
        valor = int(nodo[0][1]+nodo[0][2])
        if (valor >= 90):
            print("oferta: ","\x1B[33m",nodo[0],"\n\t!!!!!!!!!")
        if(valor >= 75 and valor < 90):
            print("oferta: ",superaro,nodo[0],"\n\t********",reset)
        if(valor < 75 and valor >= 45):
            print("oferta: ",raro,nodo[0],"\n\t  *****",reset)
        if(valor < 45 and valor >= 0):
            print("oferta: ",comun,nodo[0],"\n\t   **",reset)


        print("\nprecio original de: ",nodo[1]," --> ",nodo[2],reset)
        print("--------")

        x = input("\n$$Presione enter para continuar, {q} para salir: ")

        if (x == "q"):
            os.system("clear")
            print("escapando")
            break
        
    driver.close()

except:

    print("salio mala la wea xd... ", sys.exc_info()[0])
    driver.close()
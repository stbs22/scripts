
from logging import exception
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

import webbrowser
import time
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


def salida_q(x,driver):

    if (x == "q"):
        os.system("clear")
        driver.close()
        print("escapando")
        exit(1)
    return


pagina = "https://store.steampowered.com/specials#p=0&tab=TopSellers"

path_driver = "/home/_init_/chromedriver"

try:
    
    driver = webdriver.Chrome(path_driver)
    driver.minimize_window()
    driver.get(pagina)

    sales = []
    valores = []
    names = []
    urls = []
    precioantes = []
    preciodespues = []

    x = int(input("Cantidad de páginas a buscar: "))
    solicitado = int(input("Descuento mínimo: "))

    for n in range(0,x):
        os.system("clear")

        print("Registrando páginas: ",n+1,"/",x)
        print("cargando")

        ofertas = limpiar(driver.find_elements_by_class_name("tab_item"))

        for i in ofertas:

            nodo = i.text.split("\n")
            valor = int(nodo[0][1]+nodo[0][2])

            if(valor >= solicitado):
                names.append(nodo[3])
                valores.append(valor)
                sales.append(nodo[0])
                urls.append(i.get_attribute('href'))
                precioantes.append(nodo[1])
                preciodespues.append(nodo[2])

        driver.find_element_by_xpath("//*[@id=\"TopSellers_btn_next\"]").click()
        time.sleep(1.15)

    os.system("clear")
    driver.close()

    for i in range(0,len(names)):

        os.system("clear")
        print("\n--------\nRegistrado",len(names),"juegos en total\n---> Juego n°",i+1,": ",names[i])
        print("Descuento: ",sales[i])
        print("\nPrecio original de: ",precioantes[i]," --> ",preciodespues[i],"\n--------")

        x = input("\n$$Presione enter para continuar {q} para salir\n{p} para abrir enlace de juego: ")

        if (x == "q"):
            os.system("clear")
            print("escapando")
            exit(1)

        if (x == "p"):

            webbrowser.open_new(urls[i])
            
            x = input("\n$$Presione enter para continuar {q} para salir")

            if (x == "q"):
                os.system("clear")
                print("escapando")
                exit(1)


except Exception as e:
    
    print("\n",e)
    time.sleep(2)
    driver.close()
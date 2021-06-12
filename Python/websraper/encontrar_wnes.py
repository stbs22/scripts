from logging import exception
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

import webbrowser
import time
import os

pagina = "https://www.nombrerutyfirma.com/"

path_driver = "/home/_init_/chromedriver"

def buscar_name(nombre, driver):
    boton = driver.find_elements_by_class_name("nav-link")
    boton[0].click()
    barra = driver.find_element_by_xpath("/html/body/div[1]/div/div[1]/div/div[1]/form/div/input")
    barra.send_keys(nombre)
    barra.send_keys(Keys.ENTER)

def buscar_rut(key, driver):
    boton = driver.find_elements_by_class_name("nav-link")
    boton[1].click()
    barra = driver.find_element_by_xpath("/html/body/div[1]/div/div[1]/div/div[2]/form/div/input")
    barra.send_keys(key)
    barra.send_keys(Keys.ENTER)


try:
    driver = webdriver.Chrome(path_driver)
    driver.minimize_window()
    driver.get(pagina)
    x = int(input("\nQ teni pa sapear?\n\n1. Nombre\n2. Rut\n\n>>"))
    if (x == 1):
        txt = input("\nIngrese nombre a buscar: ")
        buscar_name(txt,driver)
    
    elif (x == 2):
        txt = input("\nIngrese rut a buscar: ")
        buscar_rut(txt,driver)
    
    lista_nombres = driver.find_elements_by_tag_name("tr")


    nombre1 = lista_nombres[1].find_elements_by_tag_name("td")[0].text
    rut1 = lista_nombres[1].find_elements_by_tag_name("td")[1].text
    data1 = lista_nombres[1].find_elements_by_tag_name("td")

    if nombre1 == txt and x == 1:
        print("\n\nSe encontró a",nombre1,"\n\n-->RUT: ",rut1,"\n\n-->Comuna:",data1[4].text,"\n\n-->Dirección:",data1[3].text)
        time.sleep(2)
        driver.close()

    if rut1 == txt and x == 2:
        print("\n\nSe encontró rut",rut1,"\n\n-->Nombre: ",nombre1,"\n\n-->Comuna:",data1[4].text,"\n\n-->Dirección:",data1[3].text)
        time.sleep(2)
        driver.close()

    else:
        for i in range(1,len(lista_nombres)):
            print(i,":",lista_nombres[i].find_elements_by_tag_name("td")[0].text)
        
        x = int(input("Ingrese Numero del susodicho: "))

        persona = lista_nombres[x].find_elements_by_tag_name("td")

        print("\n\n--> Nombre:",persona[0].text,"\n\n--> RUT:",persona[1].text,"\n\n-->Comuna:",persona[4].text,"\n\n-->Dirección:",persona[3].text)

    
    time.sleep(10)

    driver.close()

except Exception as e:
    
    print("\n",e)
    time.sleep(2)
    driver.close()
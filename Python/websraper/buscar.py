from logging import exception
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import webbrowser
import time
import os

pagina = "https://www.google.com/?hl=es"

path_driver = "/home/_init_/chromedriver"

try:
    driver = webdriver.Chrome(path_driver)
    driver.get(pagina)
    barra = driver.find_element_by_xpath("/html/body/div[1]/div[3]/form/div[1]/div[1]/div[1]/div/div[2]/input")
    driver.minimize_window()    

    barra.send_keys(str(input("Ingrese lo que desea buscar: ")))
    driver.maximize_window()

    barra.send_keys(Keys.ENTER)
    

except Exception as e:
    
    print("\n",e)
    time.sleep(2)
    driver.close()
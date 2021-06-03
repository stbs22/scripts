from logging import exception
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import webbrowser
import time
import os

pagina = "https://orteil.dashnet.org/cookieclicker/"

path_driver = "/home/_init_/chromedriver"

try:
    driver = webdriver.Chrome(path_driver)
    driver.get(pagina)
    galletaxd = driver.find_element_by_id("bigCookie")
    
    while(True):
        galletaxd.click()


except Exception as e:
    
    print("\n",e)
    time.sleep(2)
    driver.close()
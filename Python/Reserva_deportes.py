from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

import rsa
import time
import os

id = "ctl00_ContentPlaceHolder1_wucReservas_GrdReservas_ctl00__17"

def encontrar(reserva):
  
    #Inspeccionar elemento y cambiar por ID
    #Hacer click en reservar  (clase : btn-Reservar)
    #Reserva = gimnasio.find_element_by_class_name("btn-Reservar")
  
  try:
    
    Reserva = reserva.find_element( value="btn-Reservar", by=By.CLASS_NAME)
    
    print("yessss")
    
    Reserva.click()
    
    boolean = False
   
    os.system("notify-send \"Encontrado compadre\" -t 10000")
    
  except Exception: 
    boolean = True


  return boolean

URL = 'https://pregrado.uai.cl/WebPages/Deporte/Reservas.aspx'
path = "/home/laptop_eh/Aplications/chromedriver_96"
#'C:/Drivers/chromedriver.exe'

#################
usuario = 'eshernandez@alumnos.uai.cl'
contraseña = '7Tofilijones20193804%;Parangari'
#################

try:
  driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))

  driver.get(URL)
  
  time.sleep(1)

  driver.find_element(value='//*[@id="wucLogin1_tUsnNm"]', by=By.XPATH).send_keys(usuario)
  driver.find_element(value='//*[@id="tUsrPaswd"]', by=By.XPATH).send_keys(contraseña)
  
  driver.find_element(value='//*[@id="wucLogin1_LoginButton"]', by=By.XPATH).click()

  time.sleep(1)

  driver.get(URL)
  time.sleep(3)

  gimnasio = driver.find_element( value=id, by=By.ID )
  print("Intentando Suscribir:\n "+str(gimnasio.text))

  while ( encontrar(gimnasio) ): #and ("Gimnasio" in gimnasio.text) ):
    driver.refresh()

  print("fuera de while")
  time.sleep(3)
  driver.close()

except Exception as e:

    print("Algo salió Mal:\n",e)

    driver.close()

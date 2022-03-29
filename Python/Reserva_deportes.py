from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

def encontrar(driver):
  
  #Inspeccionar elemento y cambiar por ID
  id = "ctl00_ContentPlaceHolder1_wucReservas_GrdReservas_ctl00__25"
  
  gimansio = driver.find_element_by_id(id)

  try:

    #Hacer click en reservar  (clase : btn-Reservar)
    Reserva = gimansio.find_element_by_class_name("btn-Reservar")

    print("yessss")
    
    Reserva.click()
    
    boolean = False

  except Exception as e: 
    
    print("no",end="")

    boolean = True


  return boolean

URL = 'https://pregrado.uai.cl/WebPages/Deporte/Reservas.aspx'
path = 'C:/Drivers/chromedriver.exe'

#################
usuario = ''
contraseña = ''
#################

try:
    
  driver = webdriver.Chrome(path)
  driver.get(URL)
  
  time.sleep(1)

  driver.find_element_by_xpath('//*[@id="wucLogin1_tUsnNm"]').send_keys(usuario)
  driver.find_element_by_xpath('//*[@id="tUsrPaswd"]').send_keys(contraseña)
  
  driver.find_element_by_xpath('//*[@id="wucLogin1_LoginButton"]').click()

  time.sleep(1)

  driver.get(URL)

  while ( encontrar(driver) ):
   driver.refresh()

  input()
  time.sleep(3)
  driver.close()

except Exception as e:

    print("Algo salió Mal:\n",e)

    driver.close()

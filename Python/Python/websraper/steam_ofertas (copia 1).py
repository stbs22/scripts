from logging import exception
from selenium import webdriver
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

    time.sleep(3)

    os.system("clear")
    #x = int(input("Cantidad de páginas a revisar: "))
    print("Cantidad de páginas a revisar: 3")
    x = 3
    sales = []
    descuentos = []
    names = []
    urls = []

    precioantes = []
    preciodespues = []
    opinion = []
    opinion_dict = {"Negative":1,"Mostly Negative":2,"Mixed":3,"Mostly Positive":4,"Positive":5,"Very Positive":6,"Overwhelmingly Positive":7}

    for n in range(0,x+1):
        print("guardando página:",n)

        ##OFERTA
        ofertas = limpiar(driver.find_elements_by_class_name("tab_item"))
        for i in ofertas:

            nodo = i.text.split("\n")
            print(nodo)

            if(nodo[0][0] != "C"):

                descuento = int(nodo[0][1]+nodo[0][2])
                names.append(nodo[3])
                descuentos.append(descuento)
                sales.append(nodo[0])
                urls.append(i.get_attribute('href'))
                precioantes.append(nodo[1])
                preciodespues.append(nodo[2])

        ##VALORACION

        lista_hover = driver.find_element_by_id("global_hover_content")
        valoraciones = lista_hover.find_elements_by_tag_name("div")

        for i in valoraciones:
            driver.execute_script("arguments[0].style.display = 'block';",i)
            
        siguiente = driver.find_element_by_xpath("//*[@id=\"TopSellers_btn_next\"]")
        siguiente.click()

        # print("\n--------\n---> Pagina n°",n+1,"y Juego n°",numero,"\n\nJuego: ",nodo[3])

        # valor = int(nodo[0][1]+nodo[0][2])
        # if (valor >= 90):
        #     print("oferta: ","\x1B[33m",nodo[0],"\n\t!!!!!!!!!")
        # if(valor >= 75 and valor < 90):
        #     print("oferta: ",superaro,nodo[0],"\n\t********",reset)
        # if(valor < 75 and valor >= 45):
        #     print("oferta: ",raro,nodo[0],"\n\t  *****",reset)
        # if(valor < 45 and valor >= 0):
        #     print("oferta: ",comun,nodo[0],"\n\t   **",reset)

        # print("\nPrecio original de: ",nodo[1]," --> ",nodo[2],reset,"\n--------")

        # x = input("\n$$Presione enter para continuar {q} para salir\n{e} para abrir enlace de juego: ")
        # salida_q(x,driver)

        # if (x == "e"):
        #     webbrowser.open_new(i.get_attribute('href'))
            
        #     x = input("\n$$Presione enter para continuar {q} para salir")
        #     salida_q(x,driver)
                
        # os.system("clear")

        print("cargando siguiente página...")
        time.sleep(2)
        print("listo")

    driver.close()

except Exception as e:
    
    print("\n",e.with_traceback,"\n",e)
    time.sleep(2)
    driver.close()
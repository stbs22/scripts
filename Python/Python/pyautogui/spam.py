import pyautogui as auto 

def str_escribir(txt):
    auto.sleep(1)
    
    while(True):

        auto.typewrite(txt)
        auto.press("enter")
        auto.sleep(0.5)


def esperar(seg):
    
    for i in range(0,seg):
        print("restante: ",seg-i)
        auto.sleep(1)


def escribir_fichero(x):   

    esperar(5)
    for i in x:
        auto.typewrite(i)
        auto.press("enter")


guion = open("/home/_init_/Escritorio/Scripts/GIT/scripts/Python/pyautogui/shrek.txt","r")

escribir_fichero(guion)

import pyautogui as auto 

def esperar(seg):
    
    for i in range(0,seg):
        print("restante: ",seg-i)
        auto.sleep(1)


def escribir(x):   

    esperar(5)
    for i in x:
        auto.typewrite(i)
        auto.press("enter")

guion = open("/home/_init_/Escritorio/Scripts/GIT/scripts/Python/pyautogui/shrek.txt","r")

escribir(guion)



import pandas as pd

txt = "Proyeccion de Usuarios ,1 año ,2 año ,3 año ,4 año ,5 año ,6 año ,7 año ,8 año ,9 año ,10 año-Santiago 1,414 2,828 4,241 4,241 4,241 4,241 4,241 4,241 4,241 4,241-Providencia 561 1,123 1,684 1,684 1,684 1,684 1,684 1,684-Las Condes 1,006 2,012 3,018 3,018 3,018 3,018 3,018-La Reina 343 686 1,029 1,029 1,029 1,029-Ñuñoa 715 1,429 2,144 2,144 2,144-Cantidad Total Demanda 1,414 2,828 4,803 6,370 8,280 10,344 11,401 12,116 12,116 12,116-"
#print(txt.split("-"))
for i in range(1, len(txt.split("-"))):
    for j in range(0, len(txt.split("-")[i].split(" "))):
        print(str(txt.split("-")[i].split(" ")[j])+"; ", end="")
    print("")

import lib as hx


##imprimir lista con pisos enteros para cada elemento
def print_lab(laberinto):
  
  print("\t",end="")

  for i in range(len(laberinto[0])):
    
    print("[",i,"]",end="\t")

  print("\n")
  n = 0

  for i in range(len(laberinto)):
    print("[",n,"]  ",end="")

    for j in range(len(laberinto[i])):

      if(laberinto[i][j]):
        #print("\033[92m",laberinto[i][j],"\033[0m",end = "\t")
        print("\033[92m",[i,j],"\033[0m",end = "")

      else:
        print("\033[91m",laberinto[i][j],"\033[0m",end = "\t")
        
    n += 1
    print("\n")

def print_all():
  print_lab( hx.Leer_Laberinto("input_hard.txt") )
  print("\n\t--" )
  print_lab( hx.Leer_Laberinto("input.txt"))
  print("\n\t--" )
  print_lab( hx.Leer_Laberinto("input_simple.txt"))
  print("\n\t--" )
  print_lab( hx.Leer_Laberinto("input_caso.txt"))
  print("\n\t--" )
  print_lab( hx.Leer_Laberinto("input_largo.txt"))
  print("\n\t--" )

def conteo(N):
  yield from range(0,N)

from functools import reduce

# LENGUAJES Y PARADIGMAS DE LA PROGRAMACION
# TICS200 Seccion_01 2021 App 3 

# Andres Guevara.
# Esteban Hernández.
# Matías Hermosilla.

class Index_Listas:
  
  def __init__(self,inicio):
    self.current = inicio

  def __iter__(self):
    return self

  def __next__(self):
    self.current += 1
    return self.current - 1

  def back(self):
    self.current -= 1
    return self.current + 1


def pos_look(pos,camino,huellas):

  def dict_add(_pos):
    _movimiento[tuple(_pos)] = tuple(_pos) in camino and tuple(_pos) not in huellas
    return

  _movimiento = {}
  [ dict_add(ls) for ls in [ [pos[0]+1,pos[1]], [pos[0],pos[1]+1], [pos[0]-1,pos[1]], [pos[0],pos[1]-1] ] ]

  return tuple( filter(lambda x:_movimiento[x], [i for i in _movimiento] )) 


def set_mapa(lab,filas,columnas):

  def __iterar(n,m, i,j, _lab, _mapa):
    try:
      i = next(n)
      _mapa[(j,i)] = _lab[j][i]
      __iterar(n, m, i, j, _lab, _mapa)
    except StopIteration:
      try:
        n = iter( z for z in range( i+1 ) )
        j = next(m)
        __iterar(n, m, i, j, _lab, _mapa)
      except StopIteration:
        return

  mapa = {}
  __iterar( (z for z in range(columnas)), (z for z in range(filas)), 0, 0, lab , mapa)
  return mapa


def Leer_Laberinto(archivo):
  trans_int = lambda lista: [int(i) == 0 for i in lista]

  filas =  open(archivo,"r").read().split("\n")
  lista_str = list( map(lambda x:x.split(" "), filas))
  
  return [trans_int(i) for i in lista_str]

def len_lista(lista):
  return reduce(lambda acum,iter:acum+1,lista,0)

def get_pos(pos):
  return list( map(lambda x: x.current, pos))


def len_columnas(lista):
  return reduce(lambda x,y: x+y, [1 for x in lista[1]])

def len_filas(lista):
  return reduce(lambda x,y: x+y, [1 for x in lista])


def get_inicio(laberinto, filas):
  try:
    return list( [ laberinto[i][0] for i in range(0,filas) ] ).index(True)
  except ValueError:
    return -1

def get_final(laberinto, filas, columnas):
  try:
    iter = [ laberinto[i][4] for i in range(0,filas) ]
    return list( iter ).index(True)

  except ValueError:
    return -1

#####################################################################
##imprimir lista proceduralmente con pisos enteros para cada elemento

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

#####################################################################

if __name__ == '__main__':

  laberinto = Leer_Laberinto("input.txt")

  columnas = len_columnas(laberinto)
  filas = len_filas(laberinto)

  print("\n[",filas,"x",columnas,"]\n")

  print_lab(laberinto)

  inicio = get_inicio(laberinto,filas)
  start = (inicio, 0)

  final = get_final(laberinto,filas,columnas)
  end = ( final, columnas - 1 )

  mapa = set_mapa(laberinto, filas, columnas)

  andamiaje = tuple( filter(lambda x:mapa[x], [i for i in mapa] )) 

  largo = lambda lista:reduce(lambda acum,iter:acum+1,lista,0)



  caminos = [ [] ]

  #FALTO DESARROLLAR
  def registrar_caminos(pos, caminos, huellas, it):

    def varios(_pos,caminos,huellas,it):
      huellas = caminos[it.current]
      registrar_caminos(_pos, caminos, huellas, it)

      return None

    caminos[it.current].append(pos)

    _next = pos_look(pos, andamiaje, caminos[it.current])

    if largo(_next) > 1:
      [ varios(ls,caminos,huellas,it) for ls in _next ] 
    if largo(_next) == 1:
      registrar_caminos(_next[0], caminos, huellas, it)
    else:
      caminos.append(huellas)
      del huellas
      next(it) 
      return None

  registrar_caminos( start, caminos, [], Index_Listas(0) )

  print("\n\nRespuesta-->",caminos)


  #####################
  #####################
  #####################

  print("\nCaso hipotético de planteamiento:")

  huellas = [start,(3,1),(2,1),(2,2)]
  print("\nRecorrido hasta posición: ",huellas)

  pos = (2,3)
  print("Parado en: ",pos)

  look = pos_look(pos, andamiaje, huellas)
  print("Se puede mover a:", look, "\n")

from functools import reduce 

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



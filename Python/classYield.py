#Tarea 2 Paradigmas
#TICS200 Sección 1
#
#Integrantes:
# -Andres Guevara
# -Esteban Hernández
# -Matias Hermosilla
#
#Profesor:
# -Felipe Aguilera


class CountDown:
  def __init__(self, since):
    self.current = since

  def __iter__(self):
    return self

  def __next__(self):
    if self.current<=0:
      raise StopIteration
    else:
      self.current -= 1
      return self.current+1

def countar(i,f):
  for i in range(i,f):
    yield i

def pyswap(lista,x,y):
  lista[x], lista[y] = lista[y], lista[x]

def select_sort(Lista):

  for i in countar(0,len(Lista)): #recorrer lista
      min = i #Menor Elemento
      for j in countar( i+1, len(Lista) ):

          if Lista[min] > Lista[j]:
              min = j #cambiar indice por el minimo si es que existe

      yield Lista[min]
      pyswap(Lista,i,min)

if __name__ == '__main__':

  lista = [99,1,5,3,6,8,5,56,89,34,123,155,68,125]
  
  for i in select_sort(lista):
    print(i)


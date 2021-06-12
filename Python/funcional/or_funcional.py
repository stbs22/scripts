import math
from functools import reduce 


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



def count_untill(N):
  yield from range(0,N)

def print_list(list):
    print(i for i in list)

var = [count_untill(10)]

print(type(var))
print(var)
print_list(var)

# print([x for x in a])

# lista2 = [x for x in a if x < 10]
# print(lista2)


# for i in range(10,0,-1):
#   print(i)


# c2 = CountDown(10)
# lista = [x for x in map(math.sqrt, c2)]
# print(lista)

# c3 = CountDown(10)
# mifuncion = lambda x:x+1
# lista2 = [x for x in map(mifuncion, c3)]
# print(lista2)

# c4 = CountDown(10)
# mifuncion2 = lambda x,y:x if x < y else y
# resultado = reduce(mifuncion2, c4)
# print(resultado)

# c5 = CountDown(10)
# mifuncion = lambda x:x>5
# lista2 = [x for x in filter(mifuncion, c3)]
# print(lista2)
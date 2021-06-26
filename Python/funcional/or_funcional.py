import math
from functools import reduce 

print("!=!=!=!=!=\n")

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

def mifuncion_def(x,y):
  return(x+y)

mifuncion_lamda = lambda x,y: x+y

print("1+2+3+4 =",reduce(mifuncion_lamda, [1, 2, 3, 4]))

print("con 5,4: ",mifuncion_def(5,4)," == ",mifuncion_lamda(5,4))

def count_untill(N):
  yield from range(0,N)

def print_list(list):
    print(i for i in list)


var = [count_untill(10)]

print(type(var))
print(var)
print_list(var)

print("\n!=!=!=!=!=")

class Persona(object):

    def __init__(self,edad): #Contructor
        self.__edad = edad

    @property #evitar el uso de parentesis
    def edad(self): #getter
        return self.__edad

    @edad.setter
    def edad(self,edad):
        if edad > 120:
            raise Exception("Edad es muy grande")

        print("Pasando de",self.__edad,"a",edad)
        self.__edad = edad

    def print_edad(self):
        print("Edad:",self.__edad)


if __name__ == '__main__':
    
    objeto = Persona(25) #crear objeto de clase Persona
    print("\nObjeto: ",objeto)

    try:
        objeto.edad = 119 # en vez de "p.edad(200)"
        objeto.print_edad
        print("La edad actual es:",objeto.edad)

    except Exception as e:
        print("Ocurrió un error:",e)
        print(objeto.edad)
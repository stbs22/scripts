EJEMPLO1xsl = read_excel(file.choose())
EJEMPLO2csv = read.csv(file.choose())

###########################################CLASE 1#####################################################################

##instalar paquete solo una ves (listo)
install.packages('readxl')

##importar la libreria instalada
install.packages("rmarkdown")
library(readxl)
library(hyper)
##directorio de trabajo
setwd("C:/Users/ESTEBAN/OneDrive - Universidad Adolfo Ibanez/Documentos Uai/TERCER SEMASTRE/Estadística y prob/LEC")

##Importar el archivo para abrir tabla en environment                                    
DBAUTOS = read_excel(file.choose())
csvDBAUTOS = read.csv(file.choose())

DBAUTOS[1,3]
DBAUTOS[1,]
DBAUTOS[,3]
DBAUTOS[1:3,"modelo"]
DBAUTOS[1:3,c("marca","modelo")]
## C para expresarlo como vector
##csv es más accesible que xl

#########################################CLASE 2##############################################

DBPRODUCCION = read.csv(file.choose())
install.packages(c("agricolae", "e1071"))

##header(tirulos de las columnas) ##sep(marca de separacion de datos)
dbautos <- read.csv("DB - PRODUCCION.CSV", header = TRUE, sep =",")
## T = TRUE

##Cambiar nombre de columnas
colnames(DBPRODUCCION) = c("marca", "produccion")

DBPRODUCCION ##llamar al csv en la consola

DBPRODUCCION$marca

marca <- DBPRODUCCION$marca
marca

dtmarca <- as.data.frame(DBPRODUCCION$marca)
dtmarca

###

summary(DBPRODUCCION)
##resumen para saber datos estadisticos

mean(DBPRODUCCION$produccion)
##promedio

table(DBPRODUCCION$produccion)
##repeticion de datos

moda1 <- names(table(DBPRODUCCION$produccion)[which.max(table(DBPRODUCCION$produccion))])

library("e1071")

kurtosis(DBPRODUCCION$produccion, type = 2)
 ## f1 help instantaneo 

skewness(DBPRODUCCION$produccion, type = 2)


## CREAR HISTOGRAMAS

#paso 1 : encontrar anchos de intervalos
width <- (max(DBPRODUCCION$produccion)-min(DBPRODUCCION$produccion))/nclass.Sturges(DBPRODUCCION$produccion)
width

#paso 2 : crear vector con intervalos
clases <- seq(from = 51, to = 70, by = width) #vector con los intervalos
clases #seq (crear secuencia de numeros)
seq(1,30)

#paso 3 : generar histograma
hist(DBPRODUCCION$produccion, breaks = clases)
    ## en la consola, indexan una función y con tab se accede a los parametros

h <- hist(DBPRODUCCION$produccion, breaks = clases, labels = TRUE, col = "#bcdb21", ylim = c(0,25), xlim = c(51,70), xlab = "Intervalos de produccion", ylab = "Frecuencia", main = "Histograma de la produccion")
h

###########################################CLASE 3#####################################################

Tcsv = read.csv(file.choose())
Tcsv
summary(Tcsv)

str(Tcsv)
##caracteristicas de las columnas

as.character(Tcsv$Tipo.de.Cliente)
##trabajar con caracteres
as.integer(Tcsv$Tipo.de.Cliente)
##numeros
as.factor(Tcsv$Tipo.de.Cliente)
##niveles

mean(as.integer(Tcsv$Tipo.de.Cliente))
##Promedio de clientes

quantile(Tcsv$Total.Facturado..dolares., probs =c(0,0.25,0.5,0.75,1))
## el 25% de los datos son mayores al valor

## RANGO intercuartilico
RI = q3 -q1
min = q1 + 1.5(RI)
## min : cualquier valor de los datos menor que el min será un valor atipico leve


table(Tcsv$Sexo)
##frecuencia de los resultados

table(Tcsv$Sexo,Tcsv$Tipo.de.Cliente)
##P(A/B)

boxplot(Tcsv$Articulos.comprados)


boxplot(Tcsv$Articulos.comprados, horizontal = T,
        col = "red", main = "Boxplot artículos comprados",
        xlab = "Cantidad de artículos comprados", outline = F)

table(Tcsv$Articulos.comprados,Tcsv$Modo.de.Pago)

data = read.csv(file.choose())
boxplot(Tcsv$Articulos.comprados~Tcsv$Modo.de.Pago , col=rainbow(4))
## ~ :comportamiento respecto a:

barplot(table(Tcsv$Estado.Civil,Tcsv$Total.Facturado..dolares.),col=rainbow(2))
summary(Tcsv)
table(Tcsv)

library(readxl)
datos = read.csv(file.choose())
boxplot(datos$VentasActual,datos$SueldoBase, horizontal = T)
which
#############################Clase 5######################################################

##Suponga un juego en donde usted lanza un dado. Usted es el único juagdor.
##Gana cada vez que obtiene un 5.

####PROBABILIDAD TEORICA 

# p(x=5) = 1/6

####Probabilidad Empírica

#se lanza un dado 300 veces 
set.seed(4)
n = 100
dado_100 = sample(1:6, n, replace = T)
dado_100
(length(which(dado_100 == 2))/n)+(length(which(dado_100 == 4))/n)+(length(which(dado_100 == 6))/n)

#veces que dió 5
(length(which(dado_300 == 5))/300)

##
n = 10000
dado_1000 <- sample(1:6, n, replace = TRUE) #generates 1000 random numbers from 1 to 6 with replacement
dado_1000
tablita = (which(dado_1000 == 5)) ## tabla con casillas con un 5
tablita
c = length(tablita) ##cantidad de datos en la tabla
c
c/n
probabilidad = (c/n)
probabilidad
##

#probabilidades 
prop.table(table(dado_300))
barplot(prop.table(table(dado_300)))
####
## debería dar 1/6 c/u , mientras más veces se tire el dado más nos acercamos
## a la probabilidad teórica

##se selecciónan 90 instrumentos de una fabrica, 0.04 de probabilidad que séa defectuoso 

# Esperanza B~(90,0.04)
90*0.04

# Varianza B~(90,0.04)
90*0.04*(1-0.04)


r_bin_1500 = rbinom(1500, size =90, prob = 0.04) ##tienes 1500 y se evaluan 90
r_bin_1500
mean(r_bin_1500) ## tiende a la esperanza
var(r_bin_1500) ## tiende a la varianza

## probabilidad que se saquen 2 y al menos esos dos salgan defectuosos
## P(X<=2)
pbinom(2, size = 90, prob = 0.04 ,lower.tail=T)

### acceso funciones

##distribución de poisson de 100 ejemplos

r_pois_100 = rpois(100, lambda = 75)
r_pois_100

ppois(60,lambda = 75, lower.tail = T)

length(which(r_pois_100 <= 60))/300

##################################
n = 1000  #ejemplares que siguen el modelo

##ACUMULADA DISCRETA
#x = seq( from = 0 , to = 100 , by = 1)
#x
#sum(funcion con X=x)

######BINOMIAL#########
dbinom(x, n , P , log = FALSE)

######Hipergeometrica######
dhyper(5,30,70,20,log = F) # N=100
dhyper( x , k , N-k , n , log=F)

x = seq( from = 0 , to = 2 , by = 1)
x
sum(dhyper( x , 35 , 65 , 10 , log=F))
##relación con cuaderno

######POISSE#########
dpois(x,5,log=F)
1-sum(dpois(x,5,log=F))
ppois()

######################################## CLASE 6 ##################################################

## GAMMA f( x ; a , b )

rgamma(n = 170, shape =3 , scale = 2) ## distribución (n random) 


dhyper(8,30,70,20,log = F)
x = seq( from = 0 , to = 1, by = 1)
x
dhyper(x,5,30,10,log = F)
sum(dhyper(x,5,30,10,log = F))
1-dhyper(0,5,30,10,log = F)-dhyper(1,5,30,10,log = F)
dhyper(x,5,30,10,log = F)
######################################Clase Extra#######################################

set.seed(0) ##numeros iguales para cualquier R
sample(1:10, size = 5)

## limpieza de datos

print(a)

###########################Clase 12

install.packages("corrplot")
install.packages("car")
library(lmtest)
library(corrplot)
library(car)
datacrear <- data.frame(gravedad = c(35,40,43) , presion = c(21,5,3.4), temp = c(20,25,23))

corrplot(cor(datacrear))

#Esteban Hern�ndez Control Lec N�2
#Secci�n 05


#Pregunta 1
set.seed(2020)
selecci�n = sample(1:8,55,replace =T)
selecci�n
p_perder = 1 - length(which(selecci�n == 4))/55
p_perder


#Pregunta 2
# mean = 70  
# sd = 10
# P(x<=100) - P(x<=76)
pnorm( 100 , 70 , 10 , lower.tail = T , log.p = F ) - pnorm( 76 , 70 , 10 , lower.tail = T , log.p = F )
q()
#Pregunta 3
# 1 a�o = 365 D�as = 8760 horas
pweibull(8760,1,1000)


#Pregunta 4
set.seed(2020)
muestra = rbinom(800,18,0.1)
#Varianza teorica en binomial = n*p*(1-p)
18*0.1*0.9
#varianza emp�rica
var(muestra)


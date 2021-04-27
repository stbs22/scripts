library(readxl)


setwd()

base_csv = read.csv2(file.choose())  ##buscar BD csv
base_xls = read_excel("BD_xls.xlsx") ##buscar BD excel

base_1 = base_xls


IDCaso
Area
Area_COD
Estado
#ESTADO_PET_COD
#MotivoArchivado_COD
MontoSolicitado
#Edad
GÉNERO_COD
GÉNERO
EVAL_CASO_COD
EvalCaso
Servicio
Presupuesto
MONTO_DESCONTADO_PRESUPUESTO
Comuna
Habitantes
Pobreza
CesantíaTotal
CesantíaHombre
CesantíaMujer
IDH
Provincia
IDRegión
Región
ED_COD


### Ideas

## sustracción exacta
summary(base_1)
base_arreglada = base_1[-c(1:14886),]
base_arreglada


## sustracción aleatoria
set.seed(0)
base_arreglada = base_3[-c(sample( 1:nrow(base_3) , (nrow(base_3)-1200)) ) ,]##



## datos Atipicos
boxplot.stats(base_1$Edad)$out
length(boxplot.stats(base_1$MontoSolicitado)$out)
boxplot(base_1$MontoSolicitado, horizontal = T)


## presupuestos mayores al promedio
mejorespresupuestos = subset( base_1, (base_1$Presupuesto > (sum(base_1$Presupuesto)/nrow(base_1))) )
sum(base_1$Presupuesto)/nrow(base_1) ##Promedio
mejorespresupuestos

##cuantiles
quantile(base_xls$Presupuesto, probs = c(0, 0.25, 0.5, 0.75, 1) )




#################################### Limpieza ########################################################################################


View(base_1)

###### Estado # motivo_archivo

table(base_1$Estado) ##borrar 1093 datos + 15 sin sentido
table(  base_1$MotivoArchivado_COD , base_1$Estado  )## Aprobado pero con motivo de archivo
table(base_1$MotivoArchivado_COD , base_1$Estado) 
sum(table(  base_1$MotivoArchivado_COD , base_1$Estado  )[,1]) ##borrar 15 datos

base_2 <- subset(base_1 , (base_1$Estado == "APROBADO" & is.na(base_1$MotivoArchivado_COD) ))

table(base_2$Estado)

## retorna a base_2



View(base_2)
##### Edad # Edad_codificada

## eliminar menores de 18
## eliminar edades mayores a 81 (Debido a ED_COD valores de 8 fuera de intervalo) 

as.data.frame(table(base_2$Edad))

boxplot.stats(base_2$Edad)$out ## eliminar 1
sum(table(base_2$Edad,base_2$ED_COD)[82:104 , 8]) ## eliminar 516 valores u
sum(table(base_2$Edad[which(base_2$Edad < 18)])) ## eliminar 1388 menores de edad

base_3 <- subset(base_2, (base_2$Edad >= 18) & (base_2$Edad <= 80))

as.data.frame(table(base_3$Edad))
table(base_3$Edad,base_3$ED_COD) ## particiones ED_COD igualadas hasta 80 

## retorna base_3




View(base_3)
##### evaluación caso 3

table(base_3$EVAL_CASO_COD) #sacar 1165 datos de contingencia sin sentido 
base_4 <- subset(base_3, base_3$EVAL_CASO_COD != 3)

## retorna base_4



View(base_4)
##### sacar montos descontados desiguales 

table(base_4$MontoSolicitado == base_4$MONTO_DESCONTADO_PRESUPUESTO)

table(table(which(base_4$MontoSolicitado != base_4$MONTO_DESCONTADO_PRESUPUESTO)))
## eliminar 4705

base_5 = subset(base_4 , base_4$MontoSolicitado == base_4$MONTO_DESCONTADO_PRESUPUESTO)

## retorna base_5




View(base_5)
##sacar datos atipicos solo en monto solicitado

length(boxplot(base_5$MontoSolicitado)$out)

base_6 = subset(base_aux, (base_5$MontoSolicitado <= min(boxplot.stats(base_5$MontoSolicitado)$out)))

## retorna base_6



View(base_6)
## Sacar IDcaso repetida
table(base_6$IDCaso)
table(table(base_6$IDCaso))
## conciderar la cantidades de las frecuencias

rownames(as.data.frame(which(table(base_6$IDCaso) != 1)) == base_6$IDCaso)
(table(rownames(as.data.frame(which(table(base_6$IDCaso) != 1)) == base_6$IDCaso)))

!(duplicated(base_6$IDCaso))

base_7 = subset(base_6, ( !( duplicated(base_6$IDCaso) ) ))

table(table(base_7$IDCaso))






View(base_7)
##sacar valores aleatorios de los datas limpios

base_final = base_7[-c(sample( 1:nrow(base_7) , (nrow(base_7)-1200)) ),]

## retorna base_final


write.csv(base_final, file = "Base_Limpia.csv")

###############################################################################################################


######## GRAFICOS USADOS ##################

a = base_final ##para no escribir base_final una y otra vez


#####Frecuencia Pobreza

hist(table(a$Pobreza), freq = F, ylim = c(0,0.1),col = "lightblue", main = "Densidad Frecuencia de Pobreza",xlab= "Pobreza",ylab = "Densidad")
lines(density(table(a$Pobreza)),lwd = 2 , col = "red" )

#aprox
plot(density(table(a$Pobreza)),lwd = 2 , col = "red")
lines(density(rlnorm(1200, meanlog = 2, sdlog = 0.8)))

mean(a$Pobreza)
var(a$Pobreza)**0.5

#####Edad

hist((a$Edad),freq = F,col = "yellow",main= "Densidad de Edades",
     xlab="Edad", ylab = "Densidad",xlim = c(10,80))

lines(( density(a$Edad) ), lwd = 2 , col = "red" )

#Aprox
plot(density(a$Edad) , lwd = 2 , col = "red" ,ylim= c(0,0.04) )
lines(( density(rnorm(1200 , mean(a$Edad) , var(a$Edad)**0.5)) ), lwd = 2 ,  )

mean(a$Edad)
var(a$Edad)**0.5


#####Monto solicitado

hist((a$MontoSolicitado),freq = F,col = "green",main= "Densidad Montos Solicitados",
     xlab="Montos", ylab = "Densidad")

lines(( density(a$MontoSolicitado) ), lwd = 2 , col = "blue" )

#Aprox
lines( density(rweibull(1200 ,shape = 1.5 ,scale = mean(a$MontoSolicitado)) ) , lwd = 2 , col = "red" )
mean(a$MontoSolicitado)
var(a$MontoSolicitado)**0.5


#####Presupuesto
boxplot(a$Presupuesto, outline = F, horizontal = T, notch=T, col = 445, main = "Boxplot Presupuesto de Servicios")
boxplot.stats(a$Presupuesto)

mean((a$Presupuesto))
var(a$Presupuesto)




##Pobreza 

boxplot(base_7$Pobreza, horizontal = T, main = 'Indice de pobreza', col= rainbow(1) , xlab = "Porcentaje %")
median(base_7$Pobreza)
boxplot.stats(base_final$Pobreza)$stats


##Evaluación casos

pie((prop.table(table(a$EvalCaso))*100),col = c("red","green","yellow"),main = "Evaluación de casos")

##Genero

pie((prop.table(table(a$Genero))*100), labels = c("Femenino 73%","Masculino 27%") 
    ,col = c("magenta","cyan"),main = "Género de Solicitantes")

prop.table(table(a$Genero))*100



#########################################################################################




table(base_4$IDRegion,base_4$Region)

table(base_3$Genero,base_3$GENERO_COD)#
table(base_3$Area,base_3$AREA_COD)#
table(base_4$EvalCaso,base_4$EVAL_CASO_COD)#


table(base_3$MontoSolicitado == base_3$MONTO_DESCONTADO_PRESUPUESTO) ##sacar los montos que no son iguales a los descontados

table(base_3$MontoSolicitado) ## sacar valores sin sentido

length(boxplot(base_3$MontoSolicitado)$out) ### 

table(base_3$EvalCaso) ### contingencia y baja


table(base_3$Pobreza > 10)
table(base_3$IDH)

table(base_5$EvalCaso)/table(base_4$EvalCaso)

##################################################################################





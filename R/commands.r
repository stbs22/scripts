install.packages("readxl")
library(readxl)
options(max.print = 9999999)

setwd("/home/_init_/Documentos/Scripts/GIT/scripts/Data/FCD/"); base = read.csv("datap1.csv", sep = ",")

setwd("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD"); base = read.csv("datap1.csv", sep = ",")

colnames(base)

mean(base$Age)

limpia = subset(base,!(is.na(base$Age)))

typeof(table(limpia$Age))

as.data.frame(sort(table(limpia$Team)))
mean(subset(limpia, limpia$Team == "United States")$Age)
mean(subset(limpia, limpia$Team == "France")$Age)
mean(subset(limpia, limpia$Team == "Great Britain")$Age)
mean(subset(limpia, limpia$Team == "Italy")$Age)

barplot(table(limpia$Medal))
mean(subset(limpia, limpia$Medal == "Gold")$Age)
mean(subset(limpia, limpia$Medal == "Silver")$Age)
mean(subset(limpia, limpia$Medal == "Bronze")$Age)
mean(subset(limpia, is.na(limpia$Medal))$Age)

as.data.frame(sort(table(limpia$Sport)))

df = as.data.frame(),
`colnames<-`(df,"CTM")
df[4] = 4
df

dep = as.data.frame(names(sort(table(limpia$Sport))) )
dep

lista = list()
as.data.frame(lista)
lista 

typeof(sample(1:10))
typeof( mean(subset(limpia, limpia$Sport == dep[1])$Age) )

as.data.frame(lista, row.names = dep)
table(sort(boxplot.stats(base$Age)$out))

length(table(base$Name))

limpia$Age
barplot(table(limpia$Age), main = "Frecuencia Edades", col = rainbow(2))

mean(subset(limpia, limpia$Sport == dep)$Age)

for(i in 1:66){
  print(mean(subset(limpia, limpia$Sport == dep)$Age))
  lista[i] = mean(subset(limpia, limpia$Sport == dep[i])$Age)
}

lista[66]
barplot(base$games, horizontal = T, main = 'EDAD', col= rainbow(1) )

install.packages("readxl")
library(readxl)

setwd("/home/_init_/Documentos/Scripts/GIT/scripts/Data/FCD/"); base = read.csv("datap1.csv", sep = ",")

setwd("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD"); base = read.csv("C:/Users/ESTEBAN/Desktop/datacountry.csv", sep = ",")

colnames(base)

table(base$Games)
mean(base$Age)

limpia = subset(base,!(is.na(base$Age)))

typeof(table(limpia$Age))
sort(table(limpia$Team))
mean(subset(limpia, limpia$Team == "United States")$Age)
mean(subset(limpia, limpia$Team == "France")$Age)
mean(subset(limpia, limpia$Team == "Great Britain")$Age)
mean(subset(limpia, limpia$Team == "Italy")$Age)

barplot(table(limpia$Medal))
mean(subset(limpia, limpia$Medal == "Gold")$Age)
mean(subset(limpia, limpia$Medal == "Silver")$Age)
mean(subset(limpia, limpia$Medal == "Bronze")$Age)

length(sort(table(limpia$Sport)))
dep = names(sort(table(limpia$Sport)))
lista = list()


for(i in 1:66){
  print(dep[i])
  print(mean(subset(limpia, limpia$Sport == dep[i])$Age))
  lista[i] = mean(subset(limpia, limpia$Sport == dep[i])$Age)
}

lista[66]
barplot(base$games, horizontal = T, main = 'EDAD', col= rainbow(1) )

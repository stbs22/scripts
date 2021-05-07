install.packages("readxl")

library(readxl)
options(max.print = 9999999)

setwd("/home/_init_/Documentos/Scripts/GIT/scripts/Data/FCD/"); base_na = read.csv("datap1.csv", sep = ","); base = subset(base,!(is.na(base_na$Age)))

setwd("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD"); base_na = read.csv("datap1.csv", sep = ","); base = subset(base,!(is.na(base_na$Age)))

colnames(base)

mean(base$Age)


typeof(table(base$Age))

as.data.frame(sort(table(base$Team)))
mean(subset(base, base$Team == "United States")$Age)
mean(subset(base, base$Team == "France")$Age)
mean(subset(base, base$Team == "Great Britain")$Age)
mean(subset(base, base$Team == "Italy")$Age)

barplot(table(base$Medal))
mean(subset(base, base$Medal == "Gold")$Age)
mean(subset(base, base$Medal == "Silver")$Age)
mean(subset(base, base$Medal == "Bronze")$Age)
mean(subset(base, is.na(base$Medal))$Age)

table(base$Year)

min(subset(base, base$Year == "1896")$Age)

(length(names(sort(table(base$Year)))))
for(i in 1:(length(names(sort(table(base$Year))))) ){
  print(names(sort(table(base$Year)[i])))
  print(min(subset(base, base$Year == names(sort(table(base$Year)[i])))$Age))
}

as.data.frame(sort(table(base$Sport)))



lista = list()
as.data.frame(lista)
lista 

typeof(sample(1:10))
typeof( mean(subset(base, base$Sport == dep[1])$Age) )

as.data.frame(lista, row.names = dep)
table(sort(boxplot.stats(base$Age)$out))

length(table(base$Name))

base$Age
barplot(table(base$Age), main = "Frecuencia Edades", col = rainbow(2))

dep = (names(sort(table(base$Sport))) )
dep

mean(subset(base, base$Sport == dep)$Age)

(length(names(sort(table(base$Sport)))))
for(i in 1:(length(names(sort(table(base$Sport))))) ){
  print(names(sort(table(base$Sport)[i])))
  print(mean(subset(base, base$Sport == names(sort(table(base$Sport)[i])))$Age))
}

lista[66]
barplot(base$games, horizontal = T, main = 'EDAD', col= rainbow(1) )

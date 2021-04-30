install.packages("readxl")
library(readxl)

setwd("/home/_init_/Documentos/Scripts/GIT/scripts")

base = read.csv("Data/FCD/datap1.csv", sep = ",")

a = c(1,2,3,4,5,6,7,8,9,10)
a = a +1
a

table(base$Games)[a + 50]


base$Games
table(base$Games,base$Year)
summary(base)

colnames(base)

boxplot(base$Age, horizontal = T, main = 'EDAD', col= rainbow(1) )

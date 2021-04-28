install.packages("readxl")
library(readxl)

setwd("/home/_init_/Documentos/Data/FCD/")

base = read.csv("/home/_init_/Documentos/Data/FCD/datap1.csv", sep = ",")

summary(base)


colnames(base)

boxplot(base$Age, horizontal = T, main = 'EDAD', col= rainbow(1) )

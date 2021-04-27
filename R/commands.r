install.packages("readxl")
library(readxl)

setwd("/home/_init_/Documentos/Data/FCD/")

base = read.csv(file.choose(),sep = ";")

summary(base)

colnames(base)

boxplot(base$height, horizontal = T, main = 'Peso', col= rainbow(1) )

install.packages("readxl")
library(readxl)

setwd("/home/_init_/Documentos/Scripts/GIT/scripts")
setwd("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD")

base = read.csv("C:/Users/ESTEBAN/Desktop/datacountry.csv", sep = ",")
basep = read.csv("datap1.csv", sep = ",")
base_noc = base$Three_Letter_Country_Code
table(base$Games)[a + 50]


base$Games
table(base$Games,base$Year)
summary(base)

noc = table(base$NOC)
nom = names(noc)

write.table(nom, file ="noc.txt", sep = " ", row.names = FALSE, fileEncoding = "")

boxplot(base$Age, horizontal = T, main = 'EDAD', col= rainbow(1) )

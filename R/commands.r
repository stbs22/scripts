install.packages("readxl")

library(readxl)
options(max.print = 9999999)

setwd("/home/_init_/Documentos/Scripts/GIT/scripts/Data/FCD/"); base_na = read.csv("datap1.csv", sep = ","); 
base = subset(base_na,!(is.na(base_na$Age)))

setwd("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD"); base_na = read.csv("datap1.csv", sep = ","); base = subset(base_na,!(is.na(base_na)))

colnames(base)

eval = {
  #base$ID
  #base$Name
  #base$Sex
  #base$Age
  #base$Height
  #base$Weight
  #base$Team
  base$NOC
  #base$Games
  #base$Year
  #base$Season
  #base$City
  #base$Sport
  #base$Event
  #base$Medal
}

table(eval)

sort(table(eval))

length(table(eval))

for(i in 1:(length(names(sort(table(eval))))) ){
  print(names(sort(table(eval)[i])))
  print(mean(subset(base, eval == names(sort(table(eval)[i])))$Age))
}

mean(subset(base, eval == names(sort(table(eval)[i])))$Age)
mean(subset(base, eval == "KUW")$Age)

names(table(sort(boxplot.stats(base$Age)$out)))
table(sort(boxplot.stats(base$Age)$out))

barplot(table(base$Age), main = "Frecuencia Edades", col = rainbow(2))


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


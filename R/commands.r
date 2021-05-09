install.packages("readxl")

library(readxl)
options(max.print = 9999999)

setwd("/home/_init_/Documentos/Scripts/GIT/scripts/Data/FCD/"); base_na = read.csv("Data_limpio.csv", sep = ","); 
setwd("/home/_init_/Documentos/Scripts/GIT/scripts/Data/FCD/"); base_na = read.csv("datap1.csv", sep = ","); 

setwd("C:/Users/ESTEBAN/Documents/Scripts_U/git/scripts/Data/FCD"); base_na = read.csv("datap1.csv", sep = ","); 

colnames(base)
"Name"   "Sex" "Team"   "NOC"    "Games" "Season" "City"   "Sport" "Event"  "Medal"
eval = {  
  #base$ID
  base$Name
  #base$Sex
  #base$Age
  #base$Height
  #base$Weight
  #base$Team
  #base$NOC
  #base$Games
  #base$Year
  #base$Season
  #base$City
  #base$Sport
  #base$Event
  #base$Medal
}

################################################################################

length(table(eval))

table(eval)

names(tail(sort(table(eval)),n= 10))

table(sort(boxplot.stats(base$Age)$out))

for(i in 1:(length(names(sort(table(eval))))) ){
  print(names(sort(table(eval)[i])))
  print(mean(subset(base, eval == names(sort(table(eval)[i])))$Age))
}

################################################################################

caso = list("Alfred James Munnings"  ,  "Johann \"Hans\" Sauter" ,"Michel Mathiot" ,"Alfrd (Arnold-) Hajs (Guttmann-)", "Andreas Wecker" ,"Jean Lucien Nicolas Jacoby" ,"Takashi Ono" ,"Joseph \"Josy\" Stoffel" ,"Heikki Ilmari Savolainen"  ,"Robert Tait McKenzie" )

for(i in 1:length(caso)){
  print(caso[[i]])
  print(mean((subset(base, eval == caso[[i]]))$Age))
  print(var((subset(base, eval == caso[[i]]))$Age))
  print((subset(base, eval == caso[[i]]))$Age)
  print(table((subset(base, eval == caso[[i]]))$Sport))
  print("\n---------")
}

mean((subset(base, eval == caso))$Age)

var((subset(base, eval == caso))$Age)

(subset(base, eval == caso))$Age

table((subset(base, eval == caso))$Sport)

View(subset(base, eval == caso))


################################################################################

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


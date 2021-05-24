library(readxl)

df = read.csv(file.choose(),sep=";")
View(df)

colnames(df)

max(boxplot.stats(df$weight)$out) #datos atípicos

df1 = df$weight

boxplot(df1, horizontal = T, main = 'Peso', col= rainbow(1) )

boxplot.stats(df1)$stats

quantile(df1)

mean(df1)

View(df1)

df_error1 = subset(df,df$ap_hi<df$ap_lo)

df_error2 = subset(df ,df$ap_hi<0|df$ap_lo<0)

View(df_error2)
table(df$cardio)

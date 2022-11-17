import pandas as pd
df = pd.read_csv("DataCredit.csv",sep=";")

print(df.describe)

print(df["edad"])

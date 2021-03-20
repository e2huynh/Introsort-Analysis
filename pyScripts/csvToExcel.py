import pandas as pd

df = pd.read_csv('./cpp/data.csv')
df.to_excel('./excel/output.xlsx', 'Runtimes', index=False)
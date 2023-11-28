import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

data = pd.read_csv("test.csv")
dataset = data.head(1000)

missing_values = dataset.isnull().any(axis = 1)
print(missing_values)

df_processed = dataset.copy()

num_cols = 4
num_rows = int(np.ceil(len(df_processed.columns) / num_cols))

plt.figure(figsize=(15, 6))
subplots = 0

for column_name in df_processed.columns:
    if df_processed[column_name].dtype != object:
        subplots += 1
        plt.subplot(num_rows, num_cols, subplots)
        if subplots > 1:
            sns.boxplot(x=df_processed[column_name])
        else:
            sns.countplot(x=df_processed[column_name])
        plt.title(f'График для {column_name}')

for column_name in df_processed.columns:
    if df_processed[column_name].dtype != object:

        Q1 = df_processed[column_name].quantile(0.25)
        Q3 = df_processed[column_name].quantile(0.75)
        IQR = Q3 - Q1
        lower_bound = Q1 - 1.5 * IQR
        upper_bound = Q3 + 1.5 * IQR

        mean_value = df_processed[column_name].mean()
        df_processed.loc[df_processed[column_name] == 0, column_name] = int(mean_value)

        df_processed.loc[df_processed[column_name] < lower_bound, column_name] = int(mean_value)
        df_processed.loc[df_processed[column_name] > upper_bound, column_name] = int(mean_value)

plt.subplot(num_rows, num_cols, subplots + 1)
plt.title('Ящик с усами (после обработки выбросов)')
sns.boxplot(data=df_processed)
plt.xticks(rotation=45, ha='right')
plt.tight_layout()

plt.show()


room_counts = dataset['Rooms'].value_counts()

print("Количество квартир по числу комнат:")
print(room_counts)

pivot_table = pd.pivot_table(dataset, values='Id', index='DistrictId', columns='Rooms', aggfunc='count', fill_value=0)

print("Сводная таблица:")
print(pivot_table)

df_processed.to_csv("vdovenko.csv", index=False)
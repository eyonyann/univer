import numpy as np
import matplotlib.pyplot as plt

# Заданный интервал
x_values = np.linspace(3.5, 25.5, int((25.5 - 3.5) / 0.75) + 1)
a_values = np.arange(3.5, 25.75, 0.75)

# Функция f(x)
def f(x, a):
    return 1 / np.tan(x**3) + 2.24 * a * x

# Создание массива значений функции
y_values = f(x_values, a_values)

# Вывод значений аргумента и значения функции
for x, y in zip(x_values, y_values):
    print(f"x: {x:.4f}, f(x): {y:.4f}")

# Нахождение наибольшего, наименьшего и среднего значений
max_value = np.max(y_values)
min_value = np.min(y_values)
mean_value = np.mean(y_values)

print(f"\nНаибольшее значение: {max_value:.4f}")
print(f"Наименьшее значение: {min_value:.4f}")
print(f"Среднее значение: {mean_value:.4f}")

# Количество элементов в массиве
num_elements = len(y_values)
print(f"Количество элементов в массиве: {num_elements}")

# Сортировка массива по убыванию
sorted_indices = np.argsort(y_values)[::-1]
sorted_x_values = x_values[sorted_indices]
sorted_y_values = y_values[sorted_indices]

# Вывод отсортированных значений аргумента и значения функции
print("\nОтсортированный по убыванию массив: \n")
for x, y in zip(sorted_x_values, sorted_y_values):
    print(f"x: {x:.4f}, f(x): {y:.4f}")


# Построение графиков
plt.figure(figsize=(10, 6))

# График функции
plt.plot(x_values, y_values, label='f(x)', marker='o', linestyle='-', color='blue')

# График прямой со средним значением
mean_line = np.full_like(x_values, fill_value=mean_value)
plt.plot(x_values, mean_line, label=f'Mean Value ({mean_value:.4f})', linestyle='--', color='red')

# Оформление графика
plt.title('График функции и прямой со средним значением')
plt.xlabel('Значения x')
plt.ylabel('Значения f(x)')
plt.legend()
plt.grid(True)

plt.show()

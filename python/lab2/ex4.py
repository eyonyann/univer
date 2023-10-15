try:
    numerator = 10
    denominator = 0
    result = numerator / denominator
except ZeroDivisionError:
    print("Деление на ноль!")
finally:
    print("Блок finally всегда выполняется")

print("Программа продолжает выполнение после блока try-except-finally")

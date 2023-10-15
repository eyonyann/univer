def process_input(input_arg):
    if isinstance(input_arg, tuple):
        return len(input_arg)
    elif isinstance(input_arg, list):
        sum_before_zero = 0
        for num in input_arg:
            if num == 0:
                break
            sum_before_zero += num
        return sum_before_zero
    elif isinstance(input_arg, int):
        return int(str(input_arg)[::-1])
    elif isinstance(input_arg, str):
        word_list = input_arg.split()
        max_char = max(set(input_arg), key=input_arg.count)
        return f"Количество слов: {len(word_list)}, Символ, который встречается чаще всего: {max_char}"
    else:
        return "Неподдерживаемый тип данных"

print(process_input((1, 2, 3, 4)))  # Для кортежа
print(process_input([1, 2, 3, 0, 4, 5]))  # Для списка
print(process_input(12345))  # Для числа
print(process_input("Это пример строки"))  # Для строки

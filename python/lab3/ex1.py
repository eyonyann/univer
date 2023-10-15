
with open('F1.txt', 'w') as f1:
    print("Введите данные построчно в файл F1. Введите пустую строку для завершения.")
    while True:
        line = input()
        if line == "":
            break
        f1.write(line + '\n')

with open('F1.txt', 'r') as f1, open('F2.txt', 'w') as f2:
    word_count = 0
    for line in f1:
        if line.strip().startswith('А') or line.strip().startswith('а'):
            f2.write(line)
            word_count += len(line.split())

print(f"Файл F2 создан. Количество слов в F2: {word_count}")

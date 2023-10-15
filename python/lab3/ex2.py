results = []
with open('CompetitionResults.txt', 'r', encoding='utf-8') as file:
    for line in file:
        parts = line.strip().split()
        if len(parts) == 2:
            name, result = parts[0], int(parts[1])
            results.append((name, result))

sorted_results = sorted(results, key=lambda x: x[1])

if len(sorted_results) >= 3:
    first_place = sorted_results[0]
    second_place = sorted_results[1]
    third_place = sorted_results[2]

    print("Первое место: {} с результатом {}".format(first_place[0], first_place[1]))
    print("Второе место: {} с результатом {}".format(second_place[0], second_place[1]))
    print("Третье место: {} с результатом {}".format(third_place[0], third_place[1]))
else:
    print("Недостаточно данных для определения первого, второго и третьего места.")


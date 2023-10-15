def find_max_element_index(matrix):
    max_element = matrix[0][0]
    max_row, max_col = 0, 0

    for row in range(len(matrix)):
        for col in range(len(matrix[row])):
            if matrix[row][col] > max_element:
                max_element = matrix[row][col]
                max_row, max_col = row, col

    return max_row, max_col

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

max_row, max_col = find_max_element_index(matrix)
print(f"Индексы первого вхождения максимального элемента: ({max_row}, {max_col})")

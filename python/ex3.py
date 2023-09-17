from math import fabs


def is_any_odd_elements(numbers):
    for number in numbers:
        if number % 2 != 0:
            return True
    return False


def get_max_odd_element(numbers):
    max_odd = None  # Initialize to None
    for number in numbers:
        if number % 2 != 0:
            if max_odd is None or number > max_odd:
                max_odd = number
    return max_odd


def get_min_mod_element(numbers):
    min_mod = fabs(numbers[0])
    for number in numbers:
        if fabs(number) < min_mod:
            min_mod = fabs(number)
    return int(min_mod)

def get_positive_int():
    while True:
        try:
            input_str = input()
            number = int(input_str)
            if number > 0:
                break
            else:
                print("The number should be greater than zero.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")
    return number

def get_int():
    while True:
        try:
            input_str = input()
            number = int(input_str)
            break
        except ValueError:
            print("Invalid input. Please enter a valid number.")
    return number


def main():
    print('Enter list size: ')
    size = get_positive_int()
    numbers = []

    for element in range(size):
        print(f'Enter {element + 1} element: ')
        number = get_int()
        numbers.append(number)
    if not is_any_odd_elements(numbers):
        print('There are no odd elements in this list')
    else:
        max_odd = get_max_odd_element(numbers)
        if max_odd is not None:
            print(f'Max odd element is {max_odd}')
        else:
            print('There are no odd elements in this list')

        print(f'Min mod element is {get_min_mod_element(numbers)}')


if __name__ == "__main__":
    main()

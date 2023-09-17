def get_numbers(string):
    numbers = []
    for symbol in string:
        if symbol.isdigit():
            numbers.append(symbol)
    return numbers

def main():
    string = input('Enter string: \n')
    print(get_numbers(string))

if __name__ == "__main__":
    main()

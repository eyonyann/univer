def get_element_occurrences(symbol, string):
    count = 0
    for item in string:
        if symbol == item:
            count += 1
    return count

def main():
    string = 'Enjoy every moment'
    dictionary = dict()
    for item in string:
        dictionary[f'{item}'] = get_element_occurrences(item, string)

    print(dictionary)

if __name__ == "__main__":
    main()
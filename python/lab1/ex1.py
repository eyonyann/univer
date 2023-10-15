def is_prime(number):
    for i in range(2, number):
        if number % i == 0:
            return False
    return True

def get_prime_number(number):
    counter = 0
    num = 2
    while counter != number:
        if is_prime(num):
            counter += 1
        num += 1
    return num

def main():
    number = 1001
    print(get_prime_number(number))

if __name__ == "__main__":
    main()

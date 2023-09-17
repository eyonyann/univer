def get_sum_of_cortege(cortege):
    sum = 0
    for item in cortege:
        sum += item
    return sum

def main():
    C_1 = (35, 78, 21, 37, 2, 98, 6, 100, 231)
    C_2 = (45, 21, 124, 76, 5, 23, 91, 234)

    print(f"\nСумма первого кортежа равна {get_sum_of_cortege(C_1)}")
    print(f"Сумма второго кортежа равна {get_sum_of_cortege(C_2)}")

    if(get_sum_of_cortege(C_1) > get_sum_of_cortege(C_2)):
        print(f"\nСумма первого кортежа больше второго")
    else:
        print(f"\nСумма второго кортежа больше первого")

if __name__ == "__main__":
    main()
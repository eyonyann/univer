class Example:
    static_var1 = 10
    static_var2 = 5

    def __init__(self, dynamic_var1, dynamic_var2):
        self.dynamic_var1 = dynamic_var1
        self.dynamic_var2 = dynamic_var2

    def method1(self):
        new_variable = "Hello, I am a new variable!"
        print(new_variable)

    def method2(self):
        return Example.static_var1 + Example.static_var2

    def method3(self):
        return self.dynamic_var1 ** self.dynamic_var2

obj = Example(dynamic_var1=3, dynamic_var2=2)

obj.method1()
result_method2 = obj.method2()
result_method3 = obj.method3()

print("Результат метода 2 (сумма статических переменных):", result_method2)
print("Результат метода 3 (возведение в степень динамических переменных):", result_method3)

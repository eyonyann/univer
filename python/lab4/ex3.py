class Car:
    def __init__(self, speed, color, name, is_police=False):
        self.speed = speed
        self.color = color
        self.name = name
        self.is_police = is_police

    def go(self):
        print(f"The {self.color} {self.name} is now moving.")

    def stop(self):
        print(f"The {self.color} {self.name} has stopped.")

    def turn(self, direction):
        print(f"The {self.color} {self.name} turned {direction}.")

    def show_speed(self):
        print(f"The speed of {self.color} {self.name} is {self.speed} km/h.")


class TownCar(Car):
    def show_speed(self):
        super().show_speed()
        if self.speed > 60:
            print("Warning: Speed limit exceeded!")


class SportCar(Car):
    pass


class WorkCar(Car):
    def show_speed(self):
        super().show_speed()
        if self.speed > 40:
            print("Warning: Speed limit exceeded!")


class PoliceCar(Car):
    def __init__(self, speed, color, name):
        super().__init__(speed, color, name, is_police=True)


town_car = TownCar(speed=70, color='blue', name='CityCar')
sport_car = SportCar(speed=120, color='red', name='Speedster')
work_car = WorkCar(speed=45, color='yellow', name='Truck')
police_car = PoliceCar(speed=80, color='black and white', name='PoliceInterceptor')

town_car.go()
town_car.show_speed()

sport_car.turn('left')
sport_car.show_speed()

work_car.stop()
work_car.show_speed()

police_car.go()
police_car.turn('right')
police_car.show_speed()

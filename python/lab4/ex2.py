class Room:
    def __init__(self, length, width, height, num_windows, num_doors):
        self.length = length
        self.width = width
        self.height = height
        self.num_windows = num_windows
        self.num_doors = num_doors

    def calculate_wall_area(self):
        total_wall_area = 2 * (self.length + self.width) * self.height
        return total_wall_area - self.calculate_window_area() - self.calculate_door_area()

    def calculate_window_area(self):
        window_area = self.num_windows * Window.width * Window.height
        return window_area

    def calculate_door_area(self):
        door_area = self.num_doors * Door.width * Door.height
        return door_area


class Window:
    width = 1.5
    height = 1.0


class Door:
    width = 0.9
    height = 2.0


room_dimensions = {'length': 5.0, 'width': 4.0, 'height': 2.7}
num_windows = 2
num_doors = 1

my_room = Room(room_dimensions['length'], room_dimensions['width'], room_dimensions['height'], num_windows, num_doors)

total_wall_area = my_room.calculate_wall_area()
print(f"Общая площадь стен для оклейки обоями: {total_wall_area} кв. м.")

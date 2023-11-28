import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
x, y = np.meshgrid(x, y)

def function1(x, y):
    x_powered = np.sqrt(np.maximum(0, x))
    y_powered = np.sqrt(np.maximum(0, y))
    return x_powered + y_powered

def function2(x, y):
    return x**2 - y**2

def function3(x, y):
    return 2*x + 3*y

def function4(x, y):
    return x**2 + y**2

def function5(x, y):
    return 2 + 2*x + 2*y - x**2 - y**2

z1 = function1(x, y)
z2 = function2(x, y)
z3 = function3(x, y)
z4 = function4(x, y)
z5 = function5(x, y)

fig, axs = plt.subplots(2, 3, figsize=(15, 10))
fig.suptitle('Графики функций')

ax1 = fig.add_subplot(2, 3, 1, projection='3d')
ax1.plot_surface(x, y, z1, cmap='viridis')
ax1.set_title('z = x^(0.25) + y^(0.25)')

ax2 = fig.add_subplot(2, 3, 2, projection='3d')
ax2.plot_surface(x, y, z2, cmap='viridis')
ax2.set_title('z = x^2 - y^2')

ax3 = fig.add_subplot(2, 3, 3, projection='3d')
ax3.plot_surface(x, y, z3, cmap='viridis')
ax3.set_title('z = 2x + 3y')

ax4 = fig.add_subplot(2, 3, 4, projection='3d')
ax4.plot_surface(x, y, z4, cmap='viridis')
ax4.set_title('z = x^2 + y^2')

ax5 = fig.add_subplot(2, 3, 5, projection='3d')
ax5.plot_surface(x, y, z5, cmap='viridis')
ax5.set_title('z = 2 + 2x + 2y - x^2 - y^2')

# Убрать пустые подграфики
fig.delaxes(fig.axes[5])

plt.show()
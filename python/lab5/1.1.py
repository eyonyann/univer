import numpy as np

# Given values
x_value = 0.24
a_value = 5.8

# Calculate each part of the expression
part1 = np.arctan(x_value**2)
part2 = np.sqrt(x_value + 1.43**3)
part3 = np.cos(np.pi / (2 * a_value))**3
part4 = np.abs(x_value - a_value**(1/5))

# Calculate the final result
z_result = part1 - part2 + part3 / part4

# Print the result
print("The result of the expression is:", z_result)

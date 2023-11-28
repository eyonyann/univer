import numpy as np

# Set random seed for reproducibility
np.random.seed(42)

# Generate random data
X1 = np.ones(12)  # First column filled with 1
X2 = np.random.randint(2, 15, 12)  # Second column with random integers from 2 to 14
X3 = np.random.randint(60, 83, 12)  # Third column with random integers from 60 to 82
Y = np.random.uniform(13.5, 18.6, 12)  # Random values for Y

# Create the design matrix X
X = np.column_stack((X1, X2, X3))

# Calculate the coefficients using the least squares method
A = np.linalg.inv(X.T @ X) @ X.T @ Y

# Check the obtained coefficients
Y_predicted = A[0] + A[1] * X[:, 1] + A[2] * X[:, 2]

# Print the original Y values and the predicted Y values
print("Original Y values:", Y)
print("Predicted Y values:", Y_predicted)

# Check the difference between original and predicted Y values
difference = np.abs(Y - Y_predicted)
print("Difference between original and predicted Y values:", difference)

# Optionally, you can also print the obtained coefficients
print("Regression Coefficients (A):", A)

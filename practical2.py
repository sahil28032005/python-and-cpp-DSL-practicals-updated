#problem statement:2. Write python program for to compute the following computation on matrix

# A. Addition of two matrices
# B. Subtraction of two matrices
# C. Multiplication of two
# D. Transpose of matrix

# Get the number of rows and columns for both matrices
rows = int(input("Enter the number of rows: "))
cols = int(input("Enter the number of columns: "))

def custom_len(arr):
    length = 0
    while True:
        try:  # here we have performed exception handeling for certain amout of inputs it gets out of index so we have habdeled it via exception handeling code
            _ = arr[length]
            length += 1
        except (
            IndexError
        ):  # this block is useed to catch exception and prevents interpreter to throw error
            break
    return length

# Input matrix 1
print("Enter elements for matrix 1:")
matrix1 = [[0] * cols for _ in range(rows)]
for i in range(rows):
    print(f"Enter row {i + 1} (separated by space):")
    row_input = input().split()
    if custom_len(row_input) != cols:
        print("Error: Please enter exactly", cols, "elements in each row.")
        exit(1)

    for j in range(cols):
        matrix1[i][j] = int(row_input[j])

# Input matrix 2
print("Enter elements for matrix 2:")
matrix2 = [[0] * cols for _ in range(rows)]
for i in range(rows):
    print(f"Enter row {i + 1} (separated by space):")
    row_input = input().split()
    if custom_len(row_input) != cols:
        print("Error: Please enter exactly", cols, "elements in each row.")
        exit(1)

    for j in range(cols):
        matrix2[i][j] = int(row_input[j])

# Initialize result matrices with zeros
result_addition = [[0] * cols for _ in range(rows)]
result_subtraction = [[0] * cols for _ in range(rows)]
result_multiplication = [[0] * cols for _ in range(rows)]
result_transpose = [[0] * rows for _ in range(cols)]

# Matrix addition
for i in range(rows):
    for j in range(cols):
        result_addition[i][j] = matrix1[i][j] + matrix2[i][j]

# Matrix subtraction
for i in range(rows):
    for j in range(cols):
        result_subtraction[i][j] = matrix1[i][j] - matrix2[i][j]

# Matrix multiplication
for i in range(rows):
    for j in range(cols):
        result_multiplication[i][j] = matrix1[i][j] * matrix2[i][j]

# Transpose of Matrix
for j in range(cols):
    for i in range(rows):
        result_transpose[j][i] = matrix1[i][j]

# Display results
# Print Matrix Addition
print("Matrix Addition:")
i = 0
while i < rows:
    j = 0
    while j < cols:
        print(result_addition[i][j], end=" ")
        j += 1
    print()
    i += 1

# Print Matrix Subtraction
print("\nMatrix Subtraction:")
i = 0
while i < rows:
    j = 0
    while j < cols:
        print(result_subtraction[i][j], end=" ")
        j += 1
    print()
    i += 1

# Print Matrix Element-wise Multiplication
print("\nMatrix Element-wise Multiplication:")
i = 0
while i < rows:
    j = 0
    while j < cols:
        print(result_multiplication[i][j], end=" ")
        j += 1
    print()
    i += 1

# Print Transpose of Matrix
print("\nTranspose of Matrix:")
i = 0
while i < cols:
    j = 0
    while j < rows:
        print(result_transpose[i][j], end=" ")
        j += 1
    print()
    i += 1

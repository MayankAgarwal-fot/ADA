def add(n, A, B):
    C = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] + B[i][j]
    return C

def multiply(n, A, B):
    if n == 1:
        return [[A[0][0] * B[0][0]]]

    newSize = n // 2

    # Split matrices into quadrants
    def split(matrix):
        return (
            [row[:newSize] for row in matrix[:newSize]],  # top-left
            [row[newSize:] for row in matrix[:newSize]],  # top-right
            [row[:newSize] for row in matrix[newSize:]],  # bottom-left
            [row[newSize:] for row in matrix[newSize:]]   # bottom-right
        )

    A11, A12, A21, A22 = split(A)
    B11, B12, B21, B22 = split(B)

    # Recursive multiplications
    C11 = add(newSize, multiply(newSize, A11, B11), multiply(newSize, A12, B21))
    C12 = add(newSize, multiply(newSize, A11, B12), multiply(newSize, A12, B22))
    C21 = add(newSize, multiply(newSize, A21, B11), multiply(newSize, A22, B21))
    C22 = add(newSize, multiply(newSize, A21, B12), multiply(newSize, A22, B22))

    # Combine submatrices
    C = [[0] * n for _ in range(n)]
    for i in range(newSize):
        for j in range(newSize):
            C[i][j] = C11[i][j]
            C[i][j + newSize] = C12[i][j]
            C[i + newSize][j] = C21[i][j]
            C[i + newSize][j + newSize] = C22[i][j]
    return C

def printMatrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))


if __name__ == "__main__":
    n = int(input("Enter size of square matrices (power of 2): "))

    print("Enter matrix A:")
    A = [[int(input()) for _ in range(n)] for _ in range(n)]

    print("Enter matrix B:")
    B = [[int(input()) for _ in range(n)] for _ in range(n)]

    C = multiply(n, A, B)

    print("Result matrix C:")
    printMatrix(C)
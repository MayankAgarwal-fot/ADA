def matrix_multiplication(X, Y):
    r1, c1 = len(X), len(X[0])
   
    r2, c2 = len(Y), len(Y[0])

    # initializing result matrix
    # the dimension of resultant matrix: r1 x c2
    result = []
    for i in range(r1):

        result.append([0]*c2)

    # matrix multiplication
    # iterate through rows of X
    for i in range(r1):
       # iterate through columns of Y
       for j in range(c2):
           # iterate through rows of Y
           for k in range(r2):
               result[i][j] += X[i][k] * Y[k][j]
    return result

X = [
    [12,7,3],
    [4 ,5,6],
    [7 ,8,9]
]

Y = [
    [5,8,1,2],
    [6,7,3,0],
    [4,5,9,1]
]

result = matrix_multiplication(X,Y)

for r in result:
   print(r)

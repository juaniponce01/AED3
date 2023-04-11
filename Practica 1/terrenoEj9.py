M = []
n = 3
m = 3
A = [[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]

for i in range(m):
    M.append([-1 for j in range(n)])

def terreno(i, j):
    global A, M
    if M[i][j] != -1:
        return M[i][j]
    if i == m-1 and j == n-1:
        M[i][j] = max(0, -A[i][j]) + 1
    else:
        if j == n-1:
            M[i][j] = max(0, terreno(i+1, j) - A[i][j])
        elif i == m-1:
            M[i][j] = max(0, terreno(i, j+1) - A[i][j])
        else:
            M[i][j] = max(0, min(terreno(i+1, j), terreno(i, j+1)) - A[i][j])
    return M[i][j]

# print(terreno(0, 0))

# bottom-up
if (n < m):
    B = [max(0, -A[m-1][j]) + 1 for j in range(n)]
else:
    B = [max(0, -A[i][n-1]) + 1 for i in range(m)]

def terreno2(i, j):
    global A, B, n, m
    if (len(B) == n):
        if i == m-1:
            return B[j]
        for k in range(m-2, i-1, -1):
            B[n-1] = B[n-1] - A[k][n-1]
            for j in range(n-2, -1, -1):
                B[j] = max(0, min(B[j], B[j+1]) - A[k][j])
        return B[j]
    else:
        if j == n-1:
            return B[i]
        for k in range(n-2, j-1, -1):
            B[m-1] = B[m-1] - A[m-1][k]
            for i in range(m-2, -1, -1):
                B[i] = max(0, min(B[i], B[i+1]) - A[i][k])
        return B[i]
    
print(terreno2(0, 0))


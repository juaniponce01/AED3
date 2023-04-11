import copy

def sumanLoMismo(C):
    sumas = []
    for i in range(len(C)):
        sumas.append(sum(C[i]))
    for i in range(len(C)):
        sumas.append(sum([C[j][i] for j in range(len(C))]))
    sumas.append(sum([C[i][i] for i in range(len(C))]))
    sumas.append(sum([C[i][len(C)-1-i] for i in range(len(C))]))
    return len(set(sumas)) == 1    

squares = []

def cuadradoMagico(C, i, j, e):
    result = 0
    if i == len(C):
        if sumanLoMismo(C):
            squares.append(C)
            return 1
    else:
        if sum(C[i]) > (len(C)**3+len(C))/2 or sum([C[k][j] for k in range(len(C))]) > (len(C)**3+len(C))/2:
            return 0
        C_new = copy.deepcopy(C)
        for k in e:
            C_new[i][j] = k
            if j+1 == len(C):
                result += cuadradoMagico(C_new, i+1, 0, e-{k})
            else:
                result += cuadradoMagico(C_new, i, j+1, e-{k})
    return result

C = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
print(cuadradoMagico(C, 0, 0, set([1, 2, 3, 4, 5, 6, 7, 8, 9])))
# a = [[9, 8, 7],
#      [6, 5, 4],
#      [3, 2, 1]]
# print(sumanLoMismo(a))
for square in squares:
    for row in square:
        print(row)
    print("====================================")
    print("====================================")

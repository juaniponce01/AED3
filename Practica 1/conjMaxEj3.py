k = 3
M = [[0, 10, 10, 1],
     [10, 0, 5, 2],
     [10, 5, 0, 1],
     [1, 2, 1, 0]]
cMax = set()

def sumaSubIndices(c):
    suma = 0
    for i in c:
        for j in c:
            suma += M[i][j]
    return suma

def subconjuntoMaximo(c, i):
    global cMax
    global k
    if i == len(M) and len(c) == k:
        if sumaSubIndices(c) > sumaSubIndices(cMax):
            cMax = c
    elif i == len(M):
        return
    else:
        c1 = c.copy()
        subconjuntoMaximo(c1, i+1)
        c2 = c.copy()
        c2.add(i)
        subconjuntoMaximo(c2, i+1)

subconjuntoMaximo(set(), 0)  
print(cMax)



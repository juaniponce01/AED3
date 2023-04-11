l = 10
c = {2, 4, 7}

def noHayElementos(i, j):
    global c
    for k in c:
        if (k > i and k < j):
            return False
    return True

M = [[-1 for i in range(l+1)] for j in range(l+1)]

q = 1000000
def corte(i, j):
    global c, q
    if M[i][j] != -1:
        return M[i][j]
    if (noHayElementos(i, j)):
        return 0
    else:
        for k in c:
            if (k > i and k < j):
                q = min(q, (j-i) + corte(i, k) + corte(k, j))
        M[i][j] = q
        return q
    

print(corte(0, l))
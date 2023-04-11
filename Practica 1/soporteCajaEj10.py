w = [19, 7, 5, 6, 1]
s = [15, 13, 7, 8, 2]
n = len(w)

def soporta(caja):
    suma = 0
    for i in range(caja):
        if sum(w[i:caja+1]) > s[i]:
            return False
    return True

def pilaMasGrande(caja):
    if caja == n+1:
        return 0
    if not soporta(caja):
        return -sum(w)
    
    
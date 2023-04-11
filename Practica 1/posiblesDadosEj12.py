k = 4

def sumaDados(n, s):
    if n == 0:
        if s == 0:
            return 1
        else:
            return 0
    if s < 0:
        return 0
    else:
        suma = 0
        for i in range(1, k+1):
            suma += sumaDados(n-1, s-i) 
        return suma
    
print(sumaDados(3, 6))


def sumaDadosIndistinguibles(n, s, k):
    if n == 0:
        if s == 0:
            return 1
        else:
            return 0
    if s < 0:
        return 0
    else:
        suma = 0
        for i in range(k-1, -1, -1):
            suma += sumaDadosIndistinguibles(n-1, s-i, k-i)
        return suma
    
print(sumaDadosIndistinguibles(3, 6, 4))
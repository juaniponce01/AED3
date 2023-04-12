def maximoParejas(p1, p2):
    cant = 0
    i, j = 0, 0
    while i < len(p1) and j < len(p2):
        if abs(p1[i] - p2[j]) <= 1:
            cant += 1
            i += 1
            j += 1
        elif p1[i] > p2[j]:
            j += 1
        else:
            i += 1
    return cant



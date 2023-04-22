import random
import time
import pandas as pd
import matplotlib.pyplot as plt
indices = []

def maxHora(x):
	res = 0
	for i in x:
		if res < i[1]:
			res = i[1]
	return res

def insertionSort(b):
    for i in range(1, len(b)):
        up = b[i]
        j = i - 1
        while j >= 0 and b[j] > up: 
            b[j + 1] = b[j]
            j -= 1
        b[j + 1] = up     
    return b     
              
def bucketSort(x):
    arr = []
    slot_num = maxHora(x) 
    for i in range(slot_num):
        arr.append([])
          
    # Put array elements in different buckets 
    for j in x:
        index_b = int(j[1])-1 
        arr[index_b].append(j)
      
    # Sort individual buckets 
    for i in range(slot_num):
        arr[i] = insertionSort(arr[i])
          
    # concatenate the result
    k = 0
    for i in range(slot_num):
        for j in range(len(arr[i])):
            x[k] = arr[i][j]
            k += 1
    return x

def cantidadMaximaActividades(x):
	max_ = 1
	ultima = x[0][1]
	global indices
	for i in x:
		if i[0] >= ultima:
			indices = indices + [i[2]]
			max_ += 1
			ultima = i[1]
	return max_

def generarInputRandom(size):
  #Crea un array de actividades con longitud lenght 
	with open('../inputs/input_' + str(size) + '.csv', 'w') as f: 
		for i in range(size):
			y = random.randint(1, 2*size)
			x = random.randint(0, y)
			f.write(str(x) + " " + str(y) + "\n")

def main():
	df = pd.DataFrame(columns=['longitud', 'tiempo'])
	for i in range(500, 10001, 500):
		generarInputRandom(i)

main()
print("Los input fueron generados correctamente")
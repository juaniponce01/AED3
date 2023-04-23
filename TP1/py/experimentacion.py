import random

def generarInputRandom(size):
  #Crea un array de actividades con longitud size 
	with open('../inputs/random_' + str(size) + '.csv', 'w') as f: 
		for i in range(size):
			y = random.randint(1, 2*size)
			x = random.randint(0, y)
			f.write(str(x) + " " + str(y) + "\n")
   
def generarInputPeorCaso(size):
  #Crea un array de actividades con longitud size 
  with open('../inputs/peorCaso_' + str(size) + '.csv', 'w') as f: 
    for i in range(size):
      y = 2*size - i
      x = y - 1
      f.write(str(x) + " " + str(y) + "\n")
      
def generarInputMejorCaso(size):
  #Crea un array de actividades con longitud size 
  with open('../inputs/mejorCaso_' + str(size) + '.csv', 'w') as f: 
    x = 0
    for i in range(1, size+1):
      y = i
      f.write(str(x) + " " + str(y) + "\n")

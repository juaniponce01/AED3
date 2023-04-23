## TP1: Técnicas Algorítmicas

El proyecto esta compuesto por 3 archivos cpp: `ejercicio1.cpp`, `ejercicio2.cpp` y `ejercicio3.cpp`. Cada uno de ellos corresponde a un ejercicio del TP1. Además, se incluyen tres archivos cpp adicionales: `funciones.cpp`, `tests.cpp` y `experimentacion.cpp`. 

`funciones.cpp` y `tests.cpp` contienen las funciones y los tests para los ejercicios 2 y 3 respectivament. \
`experimentacion.cpp` contiene el código para realizar las experimentaciones del ejercicio 3.

### Instrucciones para correr el programa
Para correr cada uno de los ejercicios por separado y los tests en Clion solo se debe cargar el archivo `CMakeLists.txt` ya existente en el proyecto, que se encuentra dentro de la carpeta `src`. Luego, se debe seleccionar el ejercicio que se desea correr (EJ1, EJ2 o EJ3) y presionar el botón de `Run`.

Para correr los archivos en la terminal se debe localizar en el directorio donde se encuentra el archivo `CMakeLists.txt` y ejecutar los siguientes comandos:

```bash
cmake CMakeLists.txt
make
```

Esto generará un ejecutable para cada uno de los archivos cpp dentro de la carpeta `cmake-build-debug`. Como ejemplo para correr el primer ejercicio, localizarse en la carpeta donde se encuentran los ejecutables y escribir el siguiente comando:

```bash
./EJ1
```

Lo mismo sucede con el resto de los ejercicios y los tests: `./EJ2`, `./EJ3` y `./Tests`.

### Instrucciones para correr las experimentaciones
Para correr las experimentaciones podemos utilizar directamente el notebook de la carpeta `py` llamado `experimentos.ipynb`. En este notebook se encuentra todo lo necesario para correr las experimentaciones y los gráficos de los resultados. 
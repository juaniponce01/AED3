## TP1: Técnicas Algorítmicas

El proyecto esta compuesto por 3 archivos cpp: `ejercicio1.cpp`, `ejercicio2.cpp` y `ejercicio3.cpp`. Cada uno de ellos corresponde a un ejercicio del TP1. Además, se incluye dos archivos cpp adicionales: `funciones.cpp` y `tests.cpp`. Estos archivos contienen las funciones de los ejercicios 2 y 3 y los tests para los ejercicios 2 y 3 respectivamente.

### Instrucciones para correr el programa
Para correr cada uno de los ejercicios por separado y los tests en Clion solo se debe cargar el archivo `CMakeLists.txt` ya existente en el proyecto. Luego, se debe seleccionar el archivo que se desea correr y presionar el botón de `Run`.

Para correr los archivos en la terminal se debe localizar en el directorio donde se encuentra el archivo `CMakeLists.txt` y ejecutar los siguientes comandos:

```bash
cmake CMakeLists.txt
make
```

Esto generará un ejecutable para cada uno de los archivos cpp. Para correr el primer ejercicio se debe ejecutar el siguiente comando:

```bash
./ejercicio1
```

Lo mismo sucede con el resto de los ejercicios. Para correr los tests se debe ejecutar el siguiente comando:

```bash
./tests
```
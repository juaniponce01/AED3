#include "funciones.h"
#include "funciones.cpp"

using namespace std;

void testsEjercicio2(){
    // Unit test 1: Trivial
    N = 10;
    resto = 1;
    divisor = 3;
    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DP.clear(); // borra la matriz DP del caso anterior para reiniciar todos los valores
    DP.resize(N+1, vector<int>(divisor, -1));
    for (int j = 0; j < divisor; j++) {  // inicializo los casos base de la matriz DP
        DP[N][j] = resto == j;
    }
    assert(operadores(1, v[0]));
    cout << "Test 1: OK!" << endl;

    // Unit test 2: Demo 1
    N = 3;
    resto = 1;
    divisor = 100000;
    v = {4, 4, 7};
    DP.clear(); // borra la matriz DP del caso anterior para reiniciar todos los valores
    DP.resize(N+1, vector<int>(divisor, -1));
    for (int j = 0; j < divisor; j++) {  // inicializo los casos base de la matriz DP
        DP[N][j] = resto == j;
    }
    assert(operadores(1, v[0]));
    cout << "Test 2: OK!" << endl;

    // Unit test 3: Demo 2
    N = 4;
    resto = 10;
    divisor = 100000;
    v = {7, 10, 10, 50};
    DP.clear(); // borra la matriz DP del caso anterior para reiniciar todos los valores
    DP.resize(N+1, vector<int>(divisor, -1));
    for (int j = 0; j < divisor; j++) {  // inicializo los casos base de la matriz DP
        DP[N][j] = resto == j;
    }
    assert(operadores(1, v[0]));
    cout << "Test 3: OK!" << endl;

    // Unit test 4: Demo 3
    N = 3;
    resto = 10;
    divisor = 100000;
    v = {1, 1, 1};
    DP.clear(); // borra la matriz DP del caso anterior para reiniciar todos los valores
    DP.resize(N+1, vector<int>(divisor, -1));
    for (int j = 0; j < divisor; j++) {  // inicializo los casos base de la matriz DP
        DP[N][j] = resto == j;
    }
    assert(!operadores(1, v[0]));
    cout << "Test 4: OK!" << endl;

    // Unit test 5: Demo 4
    N = 54;
    resto = 33628;
    divisor = 100002;
    v = {88472, 60854, 36154, 74532, 69510, 4492, 12168, 78418, 7760, 55462, 52800, 22034, 28944,
         66346, 29004, 80098, 73322, 44878, 71080, 79028, 19358, 9654, 91248, 56968, 25036, 39500,
         62660, 76228, 79168, 35920, 28974, 88888, 47846, 7606, 22928, 694, 11714, 33058, 92682, 66918,
         5588, 58498, 19764, 70872, 85464, 52542, 81402, 73756, 13422, 70910, 18856, 74264, 88122, 93774};
    DP.clear(); // borra la matriz DP del caso anterior para reiniciar todos los valores
    DP.resize(N+1, vector<int>(divisor, -1));
    for (int j = 0; j < divisor; j++) {  // inicializo los casos base de la matriz DP
        DP[N][j] = resto == j;
    }
    assert(operadores(1, v[0]));
    cout << "Test 5: OK!" << endl;

    // Unit test 6: Demo 5
    N = 54;
    resto = 33627;
    divisor = 100002;
    v = {88472, 60854, 36154, 74532, 69510, 4492, 12168, 78418, 7760, 55462, 52800, 22034, 28944,
         66346, 29004, 80098, 73322, 44878, 71080, 79028, 19358, 9654, 91248, 56968, 25036, 39500,
         62660, 76228, 79168, 35920, 28974, 88888, 47846, 7606, 22928, 694, 11714, 33058, 92682, 66918,
         5588, 58498, 19764, 70872, 85464, 52542, 81402, 73756, 13422, 70910, 18856, 74264, 88122, 93774};
    DP.clear(); // borra la matriz DP del caso anterior para reiniciar todos los valores
    DP.resize(N+1, vector<int>(divisor, -1));
    for (int j = 0; j < divisor; j++) {  // inicializo los casos base de la matriz DP
        DP[N][j] = resto == j;
    }
    assert(!operadores(1, v[0]));
    cout << "Test 6: OK!" << endl;

}


void testsEjercicio3(){
    vector<tuple<int, int, int>> A, S;
    vector<int> indices_esperados;

    // Unit test 1: No trivial
    A = {{6,7,1}, {1,4,2}, {0,3,3}, {4,10,4}, {3,6,5}, {5,8,6}, {2,5,7}, {9,11,8}, {8,9,9}, {7,8,10}};
    S = {{0,3,3}, {3,6,5}, {6,7,1}, {7,8,10}, {8,9,9}, {9,11,8}};
    assert(subconjuntoMaximoActividades(A) == S);
    cout << "Test 1: OK!" << endl;

    // Unit test 2: Una sola actividad
    A = {{1, 2, 1}};
    S = {{1, 2, 1}};
    assert(subconjuntoMaximoActividades(A) == S);
    cout << "Test 2: OK!" << endl;

    // Unit test 3: Dos actividades no superpuestas
    A = {{1, 2, 1}, {3, 4, 2}};
    S = {{1, 2, 1}, {3, 4, 2}};
    assert(subconjuntoMaximoActividades(A) == S);
    cout << "Test 3: OK!" << endl;

    // Unit test 4: Dos actividades superpuestas
    A = {{1, 3, 1}, {2, 4, 2}};
    S = {{1, 3, 1}};
    assert(subconjuntoMaximoActividades(A) == S);
    cout << "Test 4: OK!" << endl;

    // Unit test 5: Tres actividades, solapadas en distintos órdenes
    A = {{3, 5, 3}, {2, 4, 2}, {1, 3, 1}};
    S = {{1, 3, 1}, {3, 5, 3}};
    assert(subconjuntoMaximoActividades(A) == S);
    cout << "Test 5: OK!" << endl;

    // Unit test 6: Actividades en orden inverso al tiempo inicial
    A = {{5, 6, 1}, {3, 4, 2}, {1, 2, 3}};
    S = {{1, 2, 3}, {3, 4, 2}, {5, 6, 1}};
    assert(subconjuntoMaximoActividades(A) == S);
    cout << "Test 6: OK!" << endl;
}

int main(){

    cout << "Tests Ejercicio 2:" << endl;
    testsEjercicio2();

    cout << endl;

    cout << "Tests Ejercicio 3:" << endl;
    testsEjercicio3();

    cout << "Pasaron todos los tests!" << endl;

    return 0;
}

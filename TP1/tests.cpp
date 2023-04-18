#include "funciones.h"
#include "funciones.cpp"

using namespace std;

int main(){
    vector<tuple<int, int, int>> A;
    vector<int> indices_esperados;

    // Unit test 1: No hay actividades
//    assert(cantidadMaximaActividades(A) == 0);
//    assert(indices.size() == 0);

    // Unit test 2: Una sola actividad
    A = {{1, 2, 1}};
    assert(cantidadMaximaActividades(A) == 1);
    indices_esperados = {1};
    assert(indices == indices_esperados);

    // Unit test 3: Dos actividades no superpuestas
    A = {{1, 2, 1}, {3, 4, 2}};
    indices.clear();
    assert(cantidadMaximaActividades(A) == 2);
    indices_esperados = {1, 2};
    assert(indices == indices_esperados);

    // Unit test 4: Dos actividades superpuestas
    A = {{1, 3, 1}, {2, 4, 2}};
    indices.clear();
    assert(cantidadMaximaActividades(A) == 1);
    indices_esperados = {1};
    assert(indices == indices_esperados);

    // Unit test 5: Tres actividades, solapadas en distintos órdenes
    A = {{1, 3, 1}, {2, 4, 2}, {3, 5, 3}};
    indices.clear();
    assert(cantidadMaximaActividades(A) == 2);
    indices_esperados = {1, 3};
    assert(indices == indices_esperados);

    // Unit test 6: Actividades en orden inverso al tiempo inicial
    A = {{5, 6, 1}, {3, 4, 2}, {1, 2, 3}};
    indices.clear();
//    sort(A.begin(), A.end(), [](auto a, auto b){ return get<0>(a) < get<0>(b); });
    assert(cantidadMaximaActividades(A) == 3);
    indices_esperados = {3, 2, 1};
    assert(indices == indices_esperados);

    cout << "All test cases passed!" << endl;

    return 0;
}

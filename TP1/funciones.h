#ifndef TP1_FUNCIONES_H
#define TP1_FUNCIONES_H

#include <iostream>
#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
#include <algorithm>

using namespace std;

vector<int> indices;

int findMax(vector<tuple<int, int, int>>& A);

void bucketSort(vector<tuple<int, int, int>>& A);

int cantidadMaximaActividades(vector<tuple<int, int, int>>& A);


#endif //TP1_FUNCIONES_H

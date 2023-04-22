#ifndef TP1_FUNCIONES_H
#define TP1_FUNCIONES_H

#include <iostream>
#include <vector>
#include <tuple>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;


// Funciones y variables del ejercicio 1

long long N, divisor, resto; // parametros de entrada
vector<vector<int>> DP; // resto x N
vector<long long> v; // vector de numeros

long long mod(long long a, long long b);

long long expBS(long long b, long long e);

bool operadores(long long i, long long t);


// Funciones y variables del ejercicio 3

vector<int> indices;

int findMax(vector<tuple<int, int, int>>& A);

void bucketSort(vector<tuple<int, int, int>>& A);

vector<tuple<int, int, int>> subconjuntoMaximoActividades(vector<tuple<int, int, int>>& A);


#endif //TP1_FUNCIONES_H

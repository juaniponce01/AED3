#include "funciones.h"

// ------------------------ Funciones Ejercicio 2 ------------------------

long long mod(long long a, long long b){
    return (b + (a % b)) % b;
}

long long a;
long long expBM(long long b, long long e){
    if (e == 0){
        return 1;
    } else {
        if (e % 2 == 0){
            a = expBM(b,e/2) % divisor;
            return (a * a) % divisor;
        } else {
            a = expBM(b,(e-1)/2) % divisor;
            return (b * a * a) % divisor;
        }
    }
}

bool operadores(long long i, long long t){
    /*
     Devuelve true si existe una combinacion de operadores que, a partir del i-esimo
     elemento del vector v, permita obtener el resto t con modulo divisor.
     */
    if (DP[i][t] == -1) {
        DP[i][t] = (operadores(i+1, (t % divisor + v[i] % divisor) % divisor) ||
                    operadores(i+1, (t % divisor * v[i] % divisor) % divisor) ||
                    operadores(i+1, expBM(t % divisor, v[i] % divisor)) ||
                    operadores(i+1, mod((t % divisor) - (v[i] % divisor), divisor)));
    }
    return DP[i][t];
}

// ------------------------ Funciones Ejercicio 3 ------------------------

int findMax(vector<tuple<int, int, int>>& A){
    // encuentra el maximo valor de la segunda componente de la tupla
    int max = 0;
    for (auto & act : A){
        if (get<1>(act) > max){
            max = get<1>(act);
        }
    }
    return max;
}

void bucketSort(vector<tuple<int, int, int>>& A){
    // ordena de menor a mayor con bucket sort segun el segundo valor de la tupla
    int max = findMax(A);
    vector<vector<tuple<int, int, int>>> buckets(max);
    for (auto & i : A){
        buckets[get<1>(i)-1].push_back(i);
    }
    int k = 0;
    for (int i = 0; i < max; i++){
        for (auto & j : buckets[i]){
            A[k] = j;
            k++;
        }
    }
}

vector<tuple<int, int, int>> subconjuntoMaximoActividades(vector<tuple<int, int, int>>& A){
    bucketSort(A);
    vector<tuple<int, int, int>> S = {A[0]};
    int ultima = get<1>(A[0]);
    for (int i = 1; i < A.size(); i++){
        if (get<0>(A[i]) >= ultima){
            ultima = get<1>(A[i]);
            S.push_back(A[i]);
        }
    }
    return S;
}
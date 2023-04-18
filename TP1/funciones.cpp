#include "funciones.h"

int findMax(vector<tuple<int, int, int>>& A){
    int max = 0;
    for (int i = 0; i < A.size(); i++){
        if (get<1>(A[i]) > max){
            max = get<1>(A[i]);
        }
    }
    return max;
}

void bucketSort(vector<tuple<int, int, int>>& A){
    // ordena de menor a mayor con bucket sort segun el segundo valor de la tupla
    int max = findMax(A);
    vector<vector<tuple<int, int, int>>> buckets(max);
    for (int i = 0; i < A.size(); i++){
        buckets[get<1>(A[i])-1].push_back(A[i]);
    }
    int k = 0;
    for (int i = 0; i < max; i++){
        for (int j = 0; j < buckets[i].size(); j++){
            A[k] = buckets[i][j];
            k++;
        }
    }
}

int cantidadMaximaActividades(vector<tuple<int, int, int>>& A){
    bucketSort(A);
    int max = 0, ultima = get<1>(A[0]);
    indices.push_back(get<2>(A[0]));
    max++;
    for (int i = 1; i < A.size(); i++){
        if (get<0>(A[i]) >= ultima){
            indices.push_back(get<2>(A[i]));
            max++;
            ultima = get<1>(A[i]);
        }
    }
    return max;
}

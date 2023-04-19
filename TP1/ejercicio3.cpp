#include <iostream>
#include <vector>
#include <ctime>
#include <tuple>

using namespace std;

int findMax(vector<tuple<int, int, int>>& A){
    int max = 0;
    for (auto & i : A){
        if (get<1>(i) > max){
            max = get<1>(i);
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

int main(){
    cout << "Ejercicio Algoritmo Goloso: Actividades" << endl;
    int N;
    cin >> N;
    if (N == 0){
        cout << "0" << endl;
        return 0;
    }

    unsigned t0, t1;

    t0 = clock();
    vector<tuple<int, int, int>> A(N);
    for (int i = 0; i < N; i++){
        cin >> get<0>(A[i]) >> get<1>(A[i]);
        get<2>(A[i]) = i+1;
    }
//    cout << "Actividades de A: ";
//    for (int i = 0; i < N; i++){
//        cout << "(" << get<0>(A[i]) << ", " << get<1>(A[i]) << ") ";
//    }
//    cout << endl;
    vector<tuple<int, int, int>> S = subconjuntoMaximoActividades(A);
    t1 = clock();

    cout << S.size() << endl;
    for (auto & i : S){
        cout << get<2>(i) << " ";
    }
//    cout << "Actividades de S: ";
//    cout << endl;
//    for (auto & i : S){
//        cout << "(" << get<0>(i) << ", " << get<1>(i) << ") ";
//    }
    cout << endl;
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    return 0;
}
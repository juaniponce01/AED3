#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

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
    // Devuelve un vector de tuplas con las actividades que maximizan la cantidad de actividades
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
    int N;
    cin >> N;

    vector<tuple<int, int, int>> A(N);
    for (int i = 0; i < N; i++){
        cin >> get<0>(A[i]) >> get<1>(A[i]);
        get<2>(A[i]) = i+1;
    }

    vector<tuple<int, int, int>> S = subconjuntoMaximoActividades(A);

    cout << S.size() << endl;
    for (auto & i : S){
        cout << get<2>(i) << " ";
    }

    return 0;
}
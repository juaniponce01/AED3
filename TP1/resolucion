#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

vector<vector<int>> cuadradoK; // Cuadrado magico K-esimo
int cant_cuadrados = 0; // Indica el numero de cuadrados magicos encontrados
bool encontrado = false; // Indica si se encontro el cuadrado magico
int N, K; // parametros de entrada
vector<int> col_suma, fila_suma; // suma de cada fila y columna de la matriz
int diag_suma = 0, diag2_suma = 0; // Suma de diagonal principal y diagonal secundaria
int numero_magico;

bool sumasActuales(int& i, int& j, int& elem){
    /*
     */
    if (fila_suma[i] + elem > numero_magico){return false;}
    if (col_suma[j] + elem > numero_magico){return false;}
    if (i == j && diag_suma + elem > numero_magico){return false;}
    if (N-1-i == j && diag2_suma + elem > numero_magico){return false;}
    fila_suma[i] = fila_suma[i] + elem;
    col_suma[j] = col_suma[j] + elem;
    if (i == j){diag_suma = diag_suma + elem;}
    if (N-1-i == j){diag2_suma = diag2_suma + elem;}
    return true;
}

void cuadradoMagicoK(vector<vector<int>>& C, int i, int j, vector<int>& e){
    // i es fila
    // j es columna :)
    // 'e' representa el conjunto de elementos disponibles
    if (j == C.size()){
        if (i == C.size()-1 && diag_suma == numero_magico && diag2_suma == numero_magico){
            cant_cuadrados++;
            encontrado = (cant_cuadrados == K);
            if (encontrado){cuadradoK = C;}
        } else {
            if (fila_suma[i] != numero_magico){return;}
            cuadradoMagicoK(C, i+1, 0, e);
        }
    } else {
        for (int k = 0; k < e.size(); k++){
            if (encontrado){return;}
            if (!sumasActuales(i, j, e[k])){return;}

            C[i][j] = e[k];
            e.erase(e.begin()+k);
            cuadradoMagicoK(C, i, j+1, e);

            e.emplace(e.begin()+k, C[i][j]);
            C[i][j] = 0;
            fila_suma[i] = fila_suma[i] - e[k];
            col_suma[j] = col_suma[j] - e[k];
            if (i == j){diag_suma = diag_suma - e[k];}
            if (C.size()-1-i == j){diag2_suma = diag2_suma - e[k];}
        }
    }
}

int main(){
    cout << "Ejercicio Backtracking: Orden lexicografico de cuadrados magicos" << endl;
    cin >> N >> K;
//    N = 3;
//    K = 2;
    unsigned t0, t1;
    vector<int> elementos;
    for (int i = 1; i <= N*N; i++){
        elementos.push_back(i);
    }
    for (int i = 0; i < N; i++){
        col_suma.push_back(0);
    }
    for (int i = 0; i < N; i++){
        fila_suma.push_back(0);
    }
    vector<vector<int>> M(N, vector<int>(N, 0));
    numero_magico = (N*N*N + N)/2;
    t0 = clock();
    cuadradoMagicoK(M, 0, 0, elementos);
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    if (cuadradoK.empty()){
        cout << -1 << endl;
    }
    for (auto row : cuadradoK){
        for (auto element : row){
            cout << element << " ";
        }
        cout << endl;
    }
    cout << "Execution Time: " << time << " seg" << endl;


    return 0;
}

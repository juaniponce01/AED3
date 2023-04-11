#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

vector<vector<vector<int>>> squares; // Lista de cuadrados magicos
vector<vector<int>> cuadradoK; // Cuadrado magico K-esimo
int cant_cuadrados = 0; // Indica el numero de cuadrados magicos encontrados
bool encontrado = false; // Indica si se encontro el cuadrado magico
int N, K;
vector<int> col_suma, fila_suma;
int diag_suma = 0, diag2_suma = 0; // Suma de cada fila, diagonal principal y diagonal secundaria
int numero_magico;


int sumaFila(vector<vector<int>> C, const int i){
    int result = 0;
    for (int j = 0; j < C.size(); j++){
        result = result + C[i][j];
    }
    return result;
}

int sumaColumna(vector<vector<int>> C, const int j){
    int result = 0;
    for (int i = 0; i < C.size(); i++){
        result = result + C[i][j];
    }
    return result;
}

int sumaDiagonalPrincipal(vector<vector<int>> C){
    int result = 0;
    for (int i = 0; i < C.size(); i++){
        result = result + C[i][i];
    }
    return result;
}

int sumaDiagonalSecundaria(vector<vector<int>> C){
    int result = 0;
    for (int i = 0; i < C.size(); i++){
        result = result + C[i][C.size()-1-i];
    }
    return result;
}

bool sumanLoMismo(vector<vector<int>> C){
    /*
     Verifica que las sumas de las filas, columnas y diagonales de la matriz C
     sean iguales.
     */
    int suma = sumaFila(C, 0);
    for (int i = 1; i < C.size(); i++){
        if (sumaFila(C, i) != suma){return false;}
    }
    for (int j = 0; j < C.size(); j++){
        if (sumaColumna(C, j) != suma){return false;}
    }
    if (sumaDiagonalPrincipal(C) != suma){return false;}
    if (sumaDiagonalSecundaria(C) != suma){return false;}
    return true;
}

bool sumasParciales(const vector<vector<int>>& C, int i, int j){
    /*
     Verifica que las sumas parciales de la matriz C hasta la posicion (i, j)
     no superen el numero magico.
     */
    int n = C.size();
    double numeroMagico = (pow(n, 3)+n)/2;
    for (int k = 0; k < i; k++){
        if (sumaFila(C, k) > numeroMagico){return false;}
    }
    for (int k = 0; k < j; k++){
        if (sumaColumna(C, k) > numeroMagico){return false;}
    }
    if (sumaDiagonalPrincipal(C) > numeroMagico){return false;}
    if (sumaDiagonalSecundaria(C) > numeroMagico){return false;}
    return true;
}

bool sumasActuales(unsigned long n, int i, int j, int elem){
    /*
     */
    if (fila_suma[i] + elem > numero_magico){return false;}
    if (col_suma[j] + elem > numero_magico){return false;}
    if (i == j && diag_suma + elem > numero_magico){return false;}
    if (n-1-i == j && diag2_suma + elem > numero_magico){return false;}
    fila_suma[i] = fila_suma[i] + elem;
    col_suma[j] = col_suma[j] + elem;
    if (i == j){diag_suma = diag_suma + elem;}
    if (n-1-i == j){diag2_suma = diag2_suma + elem;}
    return true;
}

void cuadradoMagicoK(vector<vector<int>> C, int i, int j, vector<int> e){
    // i es fila
    // j es columna :)
    // 'e' representa el conjunto de elementos disponibles
    if (j == C.size()){
        if (i == C.size()-1){
            cant_cuadrados++;
            encontrado = (cant_cuadrados == K);
            if (encontrado){cuadradoK = C;}
        } else {
            if (fila_suma[i] != numero_magico){return;}
            return cuadradoMagicoK(C, i+1, 0, e);
        }
    } else {
        //if (!sumasParciales(C, i, j)){return;}
        for (int k = 0; k < e.size(); k++){
            if (encontrado){return;}
            if (!sumasActuales(C.size(), i, j, e[k])){return;}
            /*
            if (fila_suma + e[k] > numero_magico){return;}
            if (col_suma[j] + e[k] > numero_magico){return;}
            if (i == j && diag_suma + e[k] > numero_magico){return;}
            if (C.size()-1-i == j && diag2_suma + e[k] > numero_magico){return;}
            C[i][j] = e[k];
            fila_suma = fila_suma + e[k];
            col_suma[j] = col_suma[j] + e[k];
            if (i == j){diag_suma = diag_suma + e[k];}
            if (C.size()-1-i == j){diag2_suma = diag2_suma + e[k];}
            */
            C[i][j] = e[k];
            vector<int> e2 = e;
            e2.erase(e2.begin()+k);
            cuadradoMagicoK(C, i, j+1, e2);
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
    numero_magico = (N*N*N + N)/2;
    t0 = clock();
    cuadradoMagicoK(vector<vector<int>>(N, vector<int>(N, 0)), 0, 0, elementos);
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

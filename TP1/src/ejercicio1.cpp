#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<vector<int>> cuadradoK; // Cuadrado magico K-esimo
int cant_cuadrados = 0; // Indica el numero de cuadrados magicos encontrados
bool encontrado = false; // Indica si se encontro el cuadrado magico
int N, K; // parametros de entrada
vector<int> col_suma, fila_suma; // suma de cada fila y columna de la matriz
int diag_suma = 0, diag2_suma = 0; // Suma de diagonal principal y diagonal secundaria
int numero_magico;
vector<bool> used; // Indica si un elemento ya fue usado

bool sumasActuales(int& i, int& j, int& elem){
    /*
     Realiza el chequeo de las sumas de las filas, columnas y diagonales
     en un punto dado cualquiera de la matriz para ver que no nos estemos
     pasando del numero magico.
     */
    if (fila_suma[i] + elem > numero_magico){return false;}
    if (col_suma[j] + elem > numero_magico){return false;}
    if (i == j && diag_suma + elem > numero_magico){return false;}
    if (N-1-i == j && diag2_suma + elem > numero_magico){return false;}

    return true;
}

bool sumasParciales(int& i, int& j, int& elem){
    /*
    Realiza el chequeo de las sumas de las filas, columnas y diagonales
    solo cuando se llega a la ultima fila o columna de la matriz para
     corroborar que la suma sea igual al numero magico.
     */
    if (j == N-1){
        if (i == N-1 && diag_suma + elem != numero_magico){return false;} // chequeo diagonal principal
        if ((fila_suma[i]+elem) != numero_magico){return false;}
    }
    if (i == N-1){
        if (j == 0 && diag2_suma + elem != numero_magico){return false;} // chequeo diagonal secundaria
        if((col_suma[j]+elem) != numero_magico){return false;}
    }

    return true;
}

void cuadradoMagicoK(vector<vector<int>>& C, int i, int j){
    if (j == N){
        if (i == N-1){
            cant_cuadrados++;
            encontrado = (cant_cuadrados == K);
            if (encontrado){cuadradoK = C;}
        } else {
            cuadradoMagicoK(C, i+1, 0);
        }
    } else {
        for (int k = 1; k <= N * N; k++){
            // nos fijamos si ya encontramos el cuadrado magico k-esimo
            if (encontrado){break;}
            // en caso de que supere el numero magico, no hace falta probar con numeros mas grandes
            // por lo que podemos terminar la iteracion
            if (!sumasActuales(i, j, k)){break;}
            // en caso de que la suma parcial de la fila, columna o diagonal sea distinto al numero magico
            // entonces puede pasar que exista otro valor mas grande que al sumarlo me de el numero magico
            if (!sumasParciales(i, j, k)){continue;}
            // si el elemento ya fue usado, no lo vuelvo a usar
            if (used[k-1]){continue;}

            C[i][j] = k;
            used[k-1] = true;
            fila_suma[i] = fila_suma[i] + k;
            col_suma[j] = col_suma[j] + k;
            if (i == j){diag_suma = diag_suma + k;}
            if (N-1-i == j){diag2_suma = diag2_suma + k;}


            cuadradoMagicoK(C, i, j+1);

            used[k-1] = false;
            fila_suma[i] = fila_suma[i] - k;
            col_suma[j] = col_suma[j] - k;
            if (i == j){diag_suma = diag_suma - k;}
            if (N-1-i == j){diag2_suma = diag2_suma - k;}
        }
    }
}

int main(){
    cin >> N >> K;
    unsigned t0, t1;
    // inicializo el vector de elementos usados
    for (int i =1; i<= N*N; i++){
        used.push_back(false);
    }
    // inicializo el vector de suma de columnas
    for (int i = 0; i < N; i++){
        col_suma.push_back(0);
    }
    // inicializo el vector de suma de filas
    for (int i = 0; i < N; i++){
        fila_suma.push_back(0);
    }
    // inicializo el cuadrado magico con ceros
    vector<vector<int>> M(N, vector<int>(N, 0));
    // calculo el numero magico
    numero_magico = (N*N*N + N)/2;

    cuadradoMagicoK(M, 0, 0);

    if (cuadradoK.empty()){
        cout << -1 << endl;
    }
    for (auto & row : cuadradoK){
        for (auto & elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

long long N, divisor, resto; // parametros de entrada
vector<vector<int>> DP; // resto x N
vector<long long> v; // vector de numeros

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

int main(){
    int casos;
    cin >> casos;

    vector<bool> resultados(casos, false); // guarda los resultados de cada caso
    vector<double> tiempos(casos, 0); // guarda los tiempos de cada caso

    for (int i = 0; i < casos; i++){
        cin >> N >> resto >> divisor;

        v.resize(N);
        for (int j = 0; j < N; j++){
            cin >> v[j];
        }

        DP.clear(); // borra la matriz DP del caso anterior para reiniciar todos los valores
        DP.resize(N+1, vector<int>(divisor, -1));

        for (int j = 0; j < divisor; j++) {  // inicializo los casos base de la matriz DP
            DP[N][j] = resto == j;
        }

        unsigned t0, t1;
        t0 = clock();
        resultados[i] = operadores(1, v[0]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        tiempos[i] = time;
    }
    for (bool caso:resultados){
        if (caso){
            cout<<"Si"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
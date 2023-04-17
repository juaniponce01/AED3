#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;
long long N, divisor, resto; // parametros de entrada
//bool suma, mult, expo, res; // suma, multiplicacion, exponenciacion, resta
bool corta = false;
vector<vector<int>> DP; // resto x N
vector<long long> v; // vector de numeros

long long mod(long long a, long long b){
    return (b + (a % b)) % b;
}

long long a;
long long expBS(long long b, long long e){
    if (e == 0){
        return 1;
    } else {
        if (e % 2 == 0){
            a = expBS(b,e/2) % divisor;
            return (a * a) % divisor;
        } else {
            a = expBS(b,(e-1)/2) % divisor;
            return (b * a * a) % divisor;
        }
    }
}

//bool operadores(long long i, long long t){
//    bool suma, mult, expo, res; // suma, multiplicacion, exponenciacion, resta
//    if (DP[i][t] != -1) {
//        if (DP[i][t]==1){
//            corta = true;
//        }
//    } else {
//        if (corta){
//            DP[i][t] = 1;
//            return true;
//        }
//
//        suma = operadores(i+1, (t % divisor + v[i] % divisor) % divisor);
//        mult = operadores(i+1, (t % divisor * v[i] % divisor) % divisor);
//        expo = operadores(i+1, expBS(t % divisor, v[i] % divisor));
//        res = operadores(i+1, mod((t % divisor) - (v[i] % divisor), divisor));
//
//        DP[i][t] = (suma || mult || expo || res);
//    }
//    return DP[i][t];
//}

bool operadoresBU(long long i, long long t){  // bottom up
    bool suma, mult, expo, res; // suma, multiplicacion, exponenciacion, resta
    for (int j = i-1; j >= 0; j--){
        suma = DP[j+1][mod((t % divisor) - (v[j] % divisor), divisor)];
        mult = DP[j+1][(t % divisor) / (v[j] % divisor) % divisor];
        expo = DP[j+1][expBS(t % divisor, v[j] % divisor)];
        res = DP[j+1][(t % divisor + v[j] % divisor) % divisor];
        DP[j][t] = (suma || mult || expo || res);
    }
    return DP[0][0];
}

bool operadores2(long long i, long long t){
    if (DP[i][t] == -1) {
        DP[i][t] = (operadores2(i+1, (t % divisor + v[i] % divisor) % divisor) ||
                    operadores2(i+1, (t % divisor * v[i] % divisor) % divisor) ||
                    operadores2(i+1, expBS(t % divisor, v[i] % divisor)) ||
                    operadores2(i+1, mod((t % divisor) - (v[i] % divisor), divisor)));
    }
    return DP[i][t];
}

int main(){
    cout << "Ejercicio Programacion Dinamica: Operadores" << endl;
    int casos;
    cin >> casos;
    vector<bool> existe(casos, false);
    vector<double> tiempos(casos, 0);
    for (int i = 0; i < casos; i++){
        cin >> N >> resto >> divisor;
        unsigned t0, t1;
        v.resize(N);
        corta = false;

        for (int j = 0; j < N; j++){
            cin >> v[j];
        }

        DP.clear();
        DP.resize(N+1, vector<int>(divisor, -1));

        for (int j = 0; j < divisor; j++) {
            DP[N][j] = resto == j;
        }

        t0 = clock();
        existe[i] = operadores2(0, 0);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        tiempos[i] = time;
    }
    for (bool caso:existe){
        if (caso){
            cout<<"Si"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}

#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

int N, divisor, resto; // parametros de entrada
int suma, mult, expo, res; // suma, multiplicacion, exponenciacion, resta
vector<int> v; // vector de numeros


bool operadores(int i, int t){
    if (i == N){
        if (t % divisor == resto){
            return true;
        } else {
            return false;
        }
    } else {
        suma = operadores(i+1, (t+v[i]) % divisor);
        mult = operadores(i+1, (t*v[i]) % divisor);
//        expo = operadores(i+1, pow(t, v[i]) % divisor);
        res = operadores(i+1, t-v[i]);

        return suma or mult or expo or res;
    }
}

vector<string> split(string str, string separador){
    vector<string>result;
    while(str.size()){
        int index = str.find(separador);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+separador.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

int main(){
    cout << "Ejercicio Programacion Dinamica: Operadores" << endl;
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++){
        cin >> N >> resto >> divisor;


        for (int j = 0; j < N; j++){
            cin >> v[j];
        }

        unsigned t0, t1;

        t0 = clock();
        operadores(0, 0);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << " seg" << endl;
    }
    cout << casos << endl;
    cout << numeros << endl;
    return 0;
}

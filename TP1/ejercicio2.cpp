#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

void operadores(int i, int t){
    if (i == N){
        if (t % divisor == resto){
            cout << "Si" << endl;
        }else{
            cout << "No" << endl;
        }
    } else {
        s = operadores(i+1, t+v[i]);
        m = operadores(i+1, t*v[i]);
        e = operadores(i+1, t**v[i]);
        r = operadores(i+1, t-v[i]);

        return s or m or e or r;
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
    cin >> casos;
    for (int i = 0, i < casos, i++){
        cin >> N >> resto >> divisor;
        cin >> numeros;

        v = split(numeros, " ");

        unsigned t0, t1;

        t0 = clock();
        operadores(0, 0);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << " seg" << endl;
    }

    return 0;
}

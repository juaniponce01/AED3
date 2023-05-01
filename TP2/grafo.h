#ifndef TP2_GRAFO_H
#define TP2_GRAFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <utility>

using namespace std;

class Grafo {
public:
    // Constructor de la clase Grafo a partir de un archivo
    explicit Grafo(const string& test_path);

    // Constructor de la clase Grafo a partir de un input
    Grafo(int n, int m, vector<pair<int, int>> aristas);

    // Destructor de la clase Grafo
    ~Grafo();

    [[nodiscard]] int n() const;
    [[nodiscard]] int m() const;
    vector<vector<int>>& ma();
    vector<vector<int>>& la();
    vector<int> vecinos(int v); //vecinos de v
    unsigned int grado(int v); //cant vecinos de v
    bool perteneceACiclo(int v); //si v pertenece a un ciclo

private:
    int n_{}; // cantidad de vertices
    int m_{}; // cantidad de aristas
    vector<pair<int, int>> aristas_; //aristas del grafo
    vector<vector<int>> la_; //lista de adyacencia
    vector<vector<int>> ma_; //matriz de adyacencia
    bool perteneceACicloAux(int u, int v, vector<bool> visitados, int anterior); //funcion auxiliar para perteneceACiclo

};


#endif //TP2_GRAFO_H

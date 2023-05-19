#ifndef TP2_GRAFO_H
#define TP2_GRAFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <utility>
#include <set>

using namespace std;

class Grafo {
public:
    // Constructor de la clase Grafo a partir de un archivo
    explicit Grafo(const string& test_path);

    // Constructor de la clase Grafo a partir de un input
    Grafo(int n, int m, vector<pair<int, int>> aristas);

    // Destructor de la clase Grafo
    ~Grafo();

    int n() const;
    int m() const;
    vector<vector<int>>& ma();
    vector<set<int>>& la();
    set<int> vecinos(int v); //vecinos de v
    unsigned int grado(int v); //cant vecinos de v
    bool esPuente(int u, int v); //si la arista (u,v) es puente
//    bool perteneceACiclo(int v); //si v pertenece a un ciclo
    vector<int> cantidadDeVerticesPorCiclo();
    void dfs(int v, vector<bool>& visitados, vector<int>& num_ciclo, int next);
    bool pertenecenAlMismoCiclo(int u, int v);

private:
    int n_; // cantidad de vertices
    int m_; // cantidad de aristas
    vector<pair<int, int>> aristas_; //aristas del grafo
    vector<set<int>> la_; //lista de adyacencia
    vector<vector<int>> ma_; //matriz de adyacencia
//    bool perteneceACicloAux(int u, int v, vector<bool> visitados, int anterior); //funcion auxiliar para perteneceACiclo
};

class ArbolDFS {
public:
    // Constructor de la clase ArbolDFS a partir de un archivo
    explicit ArbolDFS(const string& test_path);

    // Constructor de la clase ArbolDFS a partir de un input
    ArbolDFS(int r, Grafo G);

    // Destructor de la clase ArbolDFS
    ~ArbolDFS();

    int n() const;
    set<pair<int, int>> back_edges(); //vecinos de v
    set<pair<int, int>> aristas(); //cant vecinos de v
    int raiz(); // raiz del arbol
    set<int> hijos(int v); // hijos de v
    int padre(int v); // padre de v
    int altura(); // altura del arbol
    int nivel(int v); // nivel de v
    bool esHoja(int v); // si v es hoja
    bool esRaiz(int v); // si v es raiz
    bool esAncestro(int u, int v); // si u es ancestro de v
    bool esDescendiente(int u, int v); // si u es descendiente de v

private:
    set<pair<int, int>> back_edges_;
    vector<set<int>> aristas_;
    int raiz_;
    int n_; // cantidad de vertices
    vector<int> pred_;
    vector<int> orden_;
    int h_;
    Grafo g_;
    vector<int> cubren_;
};

//class ArbolBFS {
//public:
//    // Constructor de la clase ArbolBFS a partir de un archivo
//    explicit ArbolBFS(const string& test_path);
//
//    // Constructor de la clase ArbolBFS a partir de un input
//    ArbolBFS(int r, Grafo g);
//
//    // Destructor de la clase ArbolBFS
//    ~ArbolBFS();
//
//    int n() const;
//    int m() const;
//    vector<vector<int>>& ma();
//    vector<set<int>>& la();
//    set<int> vecinos(int v); //vecinos de v
//    unsigned int grado(int v); //cant vecinos de v
//    bool perteneceACiclo(int v); //si v pertenece a un ciclo
//
//private:
//    set<pair<int, int>> cross_edges;
//    set<pair<int, int>> aristas_;
//    int raiz_;
//    int h_;
//    int n_; // cantidad de vertices
//    vector<int> cubren_;
//};


#endif //TP2_GRAFO_H

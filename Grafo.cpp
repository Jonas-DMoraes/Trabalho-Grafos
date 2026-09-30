#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e) {
    if (matriz_adj_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
}

void Grafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "remove_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (tem_aresta(e)) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (int v = 0; v < num_vertices_; v++) {
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) {
            if (matriz_adj_[v][u] != 0) {
                cout << " " << u;
            }
        }
        cout << "\n";
    }
}

void Grafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}

bool Grafo::eh_passeio(int seq_verts[], int tam_seq_verts){
    for(int i = 0; i < tam_seq_verts - 1; i++){
        Aresta a(seq_verts[i], seq_verts[i+1]);
        if(!tem_aresta(a)){
            return false;
        }   
    }
    return true;
}
bool Grafo::eh_caminho(int seq_verts[], int tam_seq_verts){
    if(!eh_passeio(seq_verts, tam_seq_verts)){
        return false;
    }
    for(int i = 0; i < tam_seq_verts; i++){
        for(int j = i + 1; j < tam_seq_verts; j++){
           if(seq_verts[i] == seq_verts[j]){
            return false;
           }
        }
    }
    return true;
}

bool Grafo::caminho(int v, int w) {
    try {
        valida_vertice(v);
        valida_vertice(w);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "caminho(int, int): vertice invalido!"));
    }

    // O vetor marcado eh criado e inicializado (com zeros) antes do
    // metodo caminho_rec ser chamado pela primeira vez.
    vector<int> marcado(num_vertices_, 0);

    return caminho_rec(v, w, marcado, 0);
}

bool Grafo::caminho_rec(int v, int w, vector<int> &marcado,
        int profundidade) {
    // Exercicio 1: imprime a linha "caminho(v, w)" indentada de acordo
    // com a profundidade da chamada recursiva (2 caracteres '-' por
    // nivel, em relacao ao nivel anterior).
    cout << string(profundidade * 2, '-') << "caminho(" << v << ", " << w
        << ")\n";

    if (v == w) {
        return true;
    }

    marcado[v] = 1;

    for (int u = 0; u < num_vertices_; u++) {
        if (matriz_adj_[v][u] != 0) {
            if (marcado[u] == 0) {
                if (caminho_rec(u, w, marcado, profundidade + 1)) {
                    return true;
                }
            }
        }
    }

    return false;
}

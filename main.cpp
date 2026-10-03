#include "Aresta.h"
#include "Grafo.h"
#include <iostream>
#include <vector>
using namespace std;

/*
 * Trabalho 1 - Time to Live
 *
 * GEN505 - Grafos - 2026/2
 *
 * Nome: Jonas de Moraes   Matricula: 20240017592
 * Nome: Kauã de Liz Oliveira Matricula: 20250019699
 */

int main() {
    int N, C, O;
    cin >> N >> C;
    Grafo g(N, C);

    for (int i = 0; i < C; i++) {
        int u, v;
        cin >> u >> v;
        g.insere_aresta(Aresta(u, v));
    }

    cin >> O;
    vector<int> marcado(N);

    for (int i = 0; i < O; i++) {
        int origem, ttl;
        cin >> origem >> ttl;
        g.nao_recebem_mensagem(origem, marcado, ttl);
    }

    return 0;
}
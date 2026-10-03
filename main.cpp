#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
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



void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
   try {
        int N, C;
        /// N = número de nós //  C = conexões
        if (cin >> N >> C) {
            Grafo g(N, C);

            // 
            for (int i = 0; i < C; i++) {
                int u, v;
                cin >> u >> v;
                g.insere_aresta(Aresta(u, v));
            }

            int O;
           //O = número de operações 
            if (cin >> O) {
                vector<int> marcado(g.num_vertices());

                // Execução de cada consulta de TTL
                for (int i = 0; i < O; i++) {
                    int origem, ttl;
                    cin >> origem >> ttl;
                    g.nao_recebem_mensagem(origem, marcado, ttl);
                }
            }
        }
    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
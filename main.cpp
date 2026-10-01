#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>
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
        //Teste 1
        Grafo g(6,6);

        g.insere_aresta(Aresta(2, 5));
        g.insere_aresta(Aresta(0, 4));
        g.insere_aresta(Aresta(3, 5));
        g.insere_aresta(Aresta(1, 3));
        g.insere_aresta(Aresta(0, 5));
        g.insere_aresta(Aresta(2, 4));

        vector<int> marcado(g.num_vertices());
        g.nao_recebem_mensagem(4,marcado,3);
    }
    catch (const exception &e) {
        print_exception(e);
    }



    return 0;
}

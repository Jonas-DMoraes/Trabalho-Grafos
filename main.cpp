#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

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
        Grafo g(4);

        g.insere_aresta(Aresta(0, 2));

        g.imprime();

        g.insere_aresta(Aresta(-1, -2));
        g.insere_aresta(Aresta(5, 7));
        g.insere_aresta(Aresta(5, 1));
        g.insere_aresta(Aresta(0, 4));

        g.imprime();
    }
    catch (const exception &e) {
        print_exception(e);
    }

 
    try {
        Grafo g2(6);

        g2.insere_aresta(Aresta(0, 1));
        g2.insere_aresta(Aresta(0, 2));
        g2.insere_aresta(Aresta(0, 5));
        g2.insere_aresta(Aresta(2, 3));
        g2.insere_aresta(Aresta(2, 4));
        g2.insere_aresta(Aresta(2, 5));
        g2.insere_aresta(Aresta(3, 4));
        g2.insere_aresta(Aresta(3, 5));

        cout << "\nGrafo de teste (matriz de adjacencias):\n";
        g2.imprime();

        cout << "\nBusca por um caminho entre v0 e v4:\n";
        bool existe = g2.caminho(0, 4);
        cout << "\nExiste caminho entre 0 e 4? "
            << (existe ? "sim" : "nao") << "\n";
    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}

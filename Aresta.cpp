#include "Aresta.h"
#include <string>
using namespace std;


/*
 * Trabalho 1 - Time to Live
 *
 * GEN505 - Grafos - 2026/2
 *
 * Nome: Jonas de Moraes   Matricula: 20240017592
 * Nome: Kauã de Liz Oliveira Matricula: 20250019699
 */



Aresta::Aresta(int v1, int v2) : v1(v1), v2(v2) {
}

string Aresta::to_string() {
    return std::to_string(v1) + " " + std::to_string(v2);
}

#ifndef ARESTA_H

#define ARESTA_H

#include <string>

/*
 * Trabalho 1 - Time to Live
 *
 * GEN505 - Grafos - 2026/2
 *
 * Nome: Jonas de Moraes   Matricula: 20240017592
 * Nome: Kauã de Liz Oliveira Matricula: 20250019699
 */



class Aresta {
public:
    const int v1;
    const int v2;

    Aresta(int v1, int v2);

    std::string to_string();
};

#endif /* ARESTA_H */

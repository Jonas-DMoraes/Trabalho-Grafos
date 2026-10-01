#ifndef GRAFO_H
#define GRAFO_H
#include "Aresta.h"
#include <vector>

/*
 * Trabalho 1 - Time to Live
 *
 * GEN505 - Grafos - 2026/2
 *
 * Nome: Jonas de Moraes   Matricula: 20240017592
 * Nome: Kauã de Liz Oliveira Matricula: 20250019699
 */


class Grafo {
public:
   
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);

   
    void insere_aresta(Aresta e);

    
    void remove_aresta(Aresta e);

    void imprime();

    bool caminho(int v, int w);

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;

    void valida_vertice(int v);
    void valida_aresta(Aresta e);
    bool eh_passeio(int seq_verts[], int tam_seq_verts);
    bool eh_caminho(int seq_verts[], int tam_seq_verts);

    bool caminho_rec(int v, int w, std::vector<int> &marcado,
        int profundidade);

    void busca_larg(int v, std::vector<int> &marcado, int decremento);

    void nao_recebem_mensagem(int origem, int ttl);
};


#endif /* GRAFO_H */

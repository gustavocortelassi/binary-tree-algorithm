#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>

// cria a estrutura da data
struct DataHora{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
    char nomeEvento[50];
};

// cria a estrutura do no, puxando a data
struct No{
    struct DataHora dataHora;
    struct No *esq;
    struct No *dir;
};

// apelido no para struct No || apelido para *ArvBin
typedef struct No no;
typedef no *ArvBin;

// declaracoes de funcoes
ArvBin* criarArvBin();
int comparaEvento(struct DataHora dataHora1, struct DataHora dataHora2);
void liberarMemoria(ArvBin *raiz);
int insereArvore(ArvBin *raiz, struct DataHora dataHora);

#endif ARVORE_H
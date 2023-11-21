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

#endif ARVORE_H
#include <stdio.h>

#include "Project\src\arvore.h"
#include "Project\include\arvore.c"

int main(){
    ArvBin *raiz = criarArvBin();
    struct DataHora novaDataHora;

    printf("Informe a nova data (DD MM AAAA) e o novo horario (HH MM SS): \n");
    scanf("%d %d %d", &novaDataHora.dia, &novaDataHora.mes, &novaDataHora.ano, &novaDataHora.hora, &novaDataHora.minuto, &novaDataHora.segundo);

    insereArvore(raiz, novaDataHora);
    
    liberarMemoria(raiz);

    return 0;
}
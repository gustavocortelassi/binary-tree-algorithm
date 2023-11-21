#include <stdio.h>

#include "Project\src\arvore.h"
#include "Project\include\arvore.c"

int main(){
    ArvBin *raiz = criarArvBin();
    struct DataHora novaDataHora;

    printf("Informe o nome do evento");
    fgets(novaDataHora.nomeEvento, 50, stdin);

    printf("Informe a data (DD MM AAAA): \n");
    scanf("%d %d %d", &novaDataHora.dia, &novaDataHora.mes, &novaDataHora.ano);

    printf("Informe o horario (HH MM SS): ");
    scanf("%d %d %d", &novaDataHora.hora, &novaDataHora.minuto, &novaDataHora.segundo);


    insereArvore(raiz, novaDataHora);
    
    liberarMemoria(raiz);

    return 0;
}
#include <stdio.h>

#include "Project\src\arvore.h"
#include "Project\include\arvore.c"

int main(){
    ArvBin *raiz = criarArvBin();
    struct DataHora novaDataHora;

    int op;

    do{
        printf("SISTEMA DE GERENCIAMENTO DE EVENTOS\n");
        printf("Informe a operacao que deseja realizar:\n");
        printf("1 - Cadastrar novo evento\n");
        printf("2 - Exibir eventos cadastrados\n");
        printf("0 - Sair");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Informe o nome do evento");
                fgets(novaDataHora.nomeEvento, 50, stdin);

                printf("Informe a data (DD MM AAAA): \n");
                scanf("%d %d %d", &novaDataHora.dia, &novaDataHora.mes, &novaDataHora.ano);

                printf("Informe o horario (HH MM SS): ");
                scanf("%d %d %d", &novaDataHora.hora, &novaDataHora.minuto, &novaDataHora.segundo);


                insereArvore(raiz, novaDataHora);
                liberarMemoria(raiz);
            break;

            case 2:
                printf("Eventos cadastrados:\n");
                imprimeEventos(*raiz);
                liberarMemoria(raiz);
            break;

            case 0:
            break;
    default:
        break;
    }
    } while (op != 0);

    return 0;
}
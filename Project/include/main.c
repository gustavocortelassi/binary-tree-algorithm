#include <stdio.h>

#include "arvore.h"
// #include "arvore.c"

int main(){
    ArvBin *raiz = criarArvBin();
    struct DataHora novaDataHora;

    int op;

    do{
        printf("SISTEMA DE GERENCIAMENTO DE EVENTOS\n");
        printf("Informe a operacao que deseja realizar:\n");
        printf("1 - Cadastrar novo evento\n");
        printf("2 - Exibir eventos cadastrados\n");
        printf("3 - Editar eventos cadastrados\n");
        printf("4 - Deletar eventos cadastrados\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Informe o nome do evento: \n");
                fgets(novaDataHora.nomeEvento, 50, stdin);
                fflush(stdin);

                printf("Informe a data (DD MM AAAA): \n");
                scanf("%d %d %d", &novaDataHora.dia, &novaDataHora.mes, &novaDataHora.ano);

                printf("Informe o horario (HH MM SS): \n");
                scanf("%d %d %d", &novaDataHora.hora, &novaDataHora.minuto, &novaDataHora.segundo);

                insereArvore(raiz, novaDataHora);

            break;

            case 2:
                printf("Eventos cadastrados:\n");
                imprimeEventos(*raiz);
            break;

            case 3:
                    printf("Informe o nome do evento a ser atualizado: \n");
                    scanf("%s", novaDataHora.nomeEvento);

                    if (atualizaEventoPorNome(raiz, novaDataHora.nomeEvento, novaDataHora)) {
                        printf("Evento atualizado com sucesso!\n");
                    } else {
                        printf("Evento nao encontrado!\n");
                    }
            break;

            case 4:

            break;

            case 0:
            break;

            liberarMemoria(raiz);
    default:
        break;
    }
    } while (op != 0);

    return 0;
}
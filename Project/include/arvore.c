#include "../src/arvore.h"

// cria arvore
ArvBin* criarArvBin() {
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if (raiz != NULL) {
        *raiz = NULL;
    } else {
        printf("Erro na alocacao de memoria...\n");
        exit(0);
    }
    return raiz;
}

// metodo para comparar se as datas sao iguais na hora de inserir
int comparaEvento(struct DataHora dataHora1, struct DataHora dataHora2){
    if (dataHora1.ano < dataHora2.ano) return -1;
    if (dataHora1.ano > dataHora2.ano) return 1;

    if (dataHora1.mes < dataHora2.mes) return -1;
    if (dataHora1.mes > dataHora2.mes) return 1;

    if (dataHora1.dia < dataHora2.dia) return -1;
    if (dataHora1.dia > dataHora2.dia) return 1;

    if (dataHora1.hora < dataHora2.hora) return -1;
    if (dataHora1.hora > dataHora2.hora) return 1;

    if (dataHora1.minuto < dataHora2.minuto) return -1;
    if (dataHora1.minuto > dataHora2.minuto) return 1;

    if (dataHora1.segundo < dataHora2.segundo) return -1;
    if (dataHora1.segundo > dataHora2.segundo) return 1;

    return 0; // datas e horas são iguais
}

// metodo para liberar a memória
void liberarMemoria(ArvBin *raiz) {
    if (*raiz != NULL) {
        liberarMemoria(&(*raiz)->esq); // libera subarvore a esquerda
        liberarMemoria(&(*raiz)->dir); // libera subarvore a direita
        free(*raiz); // liberar o no atual
        *raiz = NULL; // aponta para null
    }
}

// metodo para inserir na arvore binaria
int insereArvore(ArvBin *raiz, struct DataHora dataHora){
    no *novo = (no *) malloc (sizeof(no)); // aloca novo elemento
    if(novo == NULL){
        printf("Erro na alocacao do elemento...\n");
        exit(0);
    }
    
    novo->dataHora = dataHora;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL){ // se a arvore estiver vazia, insere o primeiro no
        *raiz = novo;
        return 1;
    } else {
        no *atual = raiz;
        no *ant = NULL;

        while(atual != NULL){ // se a arvore tiver um elemento
            ant = atual;
            
            int comparacao = comparaEvento(dataHora, atual->dataHora); // realiza a comparacao entre o novo elemento e o atual 

            if(comparacao == 0){ // igual
                printf("Evento com datas iguais!\n");
                free(novo);
                return 0;
            } else if(comparacao < 0){ // menor, esquerda
                atual = atual->esq;
            } else if(comparacao > 0){ // maior, direita
                atual = atual->dir;
            }
        }

        int comparacao = comparaEvento(dataHora, atual->dataHora); 
        if(comparacao < 0){ // menor, esquerda
                ant->esq = novo;
            } else if(comparacao > 0){ // maior, direita
                ant->dir = novo;
            }
        return 1;        
    }
}

// metodo para imprimir no cmd
void imprimeEventosRec(no *raiz) {
    if (raiz != NULL) { // se a arvore tiver conteudo
        imprimeEventosRec(raiz->esq); // imprime ate o fim da esquerda
        printf("Data: %d/%d/%d Hora: %d:%d:%d Nome do Evento: %s\n", 
               raiz->dataHora.dia, raiz->dataHora.mes, raiz->dataHora.ano,
               raiz->dataHora.hora, raiz->dataHora.minuto, raiz->dataHora.segundo,
               raiz->dataHora.nomeEvento);
        imprimeEventosRec(raiz->dir); // imprime ate o fim da direita
        
    }
}

void imprimeEventos(ArvBin raiz) { // auxiliar recursiva
    imprimeEventosRec(raiz);
}

int atualizaEventoPorNomeRec(no *raiz, const char* nomeEvento, struct DataHora novaDataHora) {
    if (raiz == NULL) {
        return 0;
    }

    int comparacao = strcmp(nomeEvento, raiz->dataHora.nomeEvento);

    if (comparacao < 0) {
        return atualizaEventoPorNomeRec(raiz->esq, nomeEvento, novaDataHora);
    } else if (comparacao > 0) {
        return atualizaEventoPorNomeRec(raiz->dir, nomeEvento, novaDataHora);
    } else {
        raiz->dataHora = novaDataHora;
        return 1;
    }
}

int atualizaEventoPorNome(ArvBin *raiz, const char* nomeEvento, struct DataHora novaDataHora) {
    if (raiz == NULL || *raiz == NULL) {
        // Árvore vazia ou raiz nula
        return 0;
    }

    return atualizaEventoPorNomeRec(*raiz, nomeEvento, novaDataHora);
}
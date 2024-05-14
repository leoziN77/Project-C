#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da fila
struct st_fila {
    int senha;
    struct st_fila* prox;
};

typedef struct st_fila Fila;
Fila* inicio = NULL;
Fila* fim = NULL;

// Função para criar um novo nó na fila
Fila* criarNo(int senha) {
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->senha = senha;
    novo->prox = NULL;
    return novo;
}

// Função para adicionar um elemento na fila
void enqueue(int senha) {
    Fila* novo = criarNo(senha);
    if (inicio == NULL) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
    printf("Cliente com senha %d inserido na fila.\n", senha);
}

// Função para remover um elemento da fila
int dequeue() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return -1;
    } else {
        Fila* temp = inicio;
        int senha = temp->senha;
        inicio = inicio->prox;
        free(temp);
        if (inicio == NULL) {
            fim = NULL;
        }
        return senha;
    }
}

// Função para exibir todos os elementos da fila
void exibe() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
    } else {
        Fila* temp = inicio;
        while (temp != NULL) {
            printf("Senha: %d\n", temp->senha);
            temp = temp->prox;
        }
    }
}

// Função para ordenar a fila usando Bubble Sort
void bubbleSort() {
    if (inicio == NULL) {
        return;
    }
    int trocou;
    Fila* ptr1;
    Fila* lptr = NULL;
    do {
        trocou = 0;
        ptr1 = inicio;
        while (ptr1->prox != lptr) {
            if (ptr1->senha > ptr1->prox->senha) {
                int temp = ptr1->senha;
                ptr1->senha = ptr1->prox->senha;
                ptr1->prox->senha = temp;
                trocou = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (trocou);
}

// Função para limpar a fila
void clear() {
    Fila* temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
    fim = NULL;
    printf("Fila limpa.\n");
}

int main() {
    int op, senha;

    do {
        system("cls");
        printf("Selecione a opcao:\n");
        printf("[1] - Inserir na fila (enqueue)\n");
        printf("[2] - Remover da fila (dequeue)\n");
        printf("[3] - Exibir fila\n");
        printf("[4] - Ordenar fila\n");
        printf("[5] - Limpar fila\n");
        printf("[0] - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite a senha do cliente: ");
                scanf("%d", &senha);
                enqueue(senha);
                break;
            case 2:
                senha = dequeue();
                if (senha != -1) {
                    printf("Cliente com senha %d foi atendido.\n", senha);
                }
                break;
            case 3:
                exibe();
                break;
            case 4:
                bubbleSort();
                printf("Fila ordenada.\n");
                break;
            case 5:
                clear();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        system("pause");
    } while (op != 0);

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mem.h>
#include "lista.h"

// Variáveis globais, com o preço da primeira e as demais horas
float valor_priHora;
float valor_restHora;

struct lista {
    struct lista *prox;
    Veiculo vei;
};

float valor_cobrado(int hora_vei, int min_vei)
{
    int hora[2];
    float tempo = 0;
    float valor=0;
    horaAtual(hora);

    hora[0] = hora[0]-hora_vei;
    hora[1] = hora[1]-min_vei;
    tempo += hora[1]/60;
    tempo += hora[0];
    if (tempo > 1) {
        tempo--;
        valor = tempo*valor_restHora;
        valor += valor_priHora;
        return valor;
    } else {
        return valor_priHora;
    }

}


//Cria a Lista
Lista* lista_cria(float priHora, float restHora)
{
    valor_priHora = priHora;
    valor_restHora = restHora;
    Lista *li = (Lista*) malloc(sizeof(Lista));
    *li = NULL;
    return li;
}

//Insere na Lista
int lista_insere(Lista *li, Veiculo vei)
{
    Node *no = (Node*)malloc(sizeof(Node));
    no->vei = vei;
    no->prox = NULL;
    if (li == NULL) return 0;
    if (*li==NULL) {// insere na primeira pos
        *li = no;
    } else {
        Node *aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

//Consulta para verificar se uma placa está na listta
int lista_consulta(Lista *li, char *placa)
{
    int e = 0;
    if (li == NULL)
        return 0;
    Node *aux = *li;
    while (aux != NULL) {
        if (strcmp(aux->vei.placa, placa) == 0) {
            vei_imprimi(aux->vei);
            e = 1;
        }
        aux = aux->prox;
    }
    if (e == 0) {
        printf("\tEsse veículo não foi cadastrado!\n");
    }
    return 1;
}

int lista_retira(Lista *li, char *placa)
{
    int hora_vei[2];
    if (li == NULL) {
        return 0;
    } else {
        Node *aux = *li;
        Node *ant = *li;
        while (aux != NULL && strcmp(aux->vei.placa, placa) != 0) {
                ant = aux;
                aux = aux->prox;
            }
        hora_vei[0] = aux->vei.hora[0];
        hora_vei[1] = aux->vei.hora[1];
        if (aux == NULL) {
            printf("Veículo não está cadastrado!");
            return 0;
        }

        /* Caso o elemento da busca seja a cabeça da lista, passa a cabeça para o próximo elemento
         Se não a posição anterior, passa a apontar para próxima posição depois da posição atual*/
        if (aux == *li) {
            *li = aux->prox;
        } else {
            ant->prox = aux->prox;
        }
        //free(aux);
        system("cls");
        printf("\tO valor total é de: R$%.2f\n\t", valor_cobrado(hora_vei[0], hora_vei[1]));
        system("pause");
        system("cls");
        return 1;
    }
}

// Imprimi Lista
int lista_imprimi(Lista *li)
{
    if (*li == NULL)
        return 0;

    Node *aux = *li;
    while (aux != NULL) {
        printf("\n");
        vei_imprimi(aux->vei);
        aux = aux->prox;
    }
    system("pause");
    system("cls");
    return 1;
}

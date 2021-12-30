#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "lista.h"

int hora[2];

void horaAtual(int *Hora) // Função que pega o horário atual e insere junto do TAD
{
    time_t t;
    struct tm* tInfo;
    time(&t);
    tInfo = localtime(&t);
    *Hora = tInfo->tm_hour;
    Hora++;
    *Hora = tInfo->tm_min;
}
//Função que transforma a hora em String
const char * hora_toString(int Hor, int Min)
{
    char Hora_Hor[5];
    char Hora_Min[5];
    char *Buf = (char*) malloc(1 + sizeof(char));

    if (Hor < 10) {
        sprintf(Hora_Hor, "0%i", Hor);
    } else {
        sprintf(Hora_Hor, "%i", Hor);
    }
    if (Min < 10) {
        sprintf(Hora_Min, ":0%i", Min);
    } else {
        sprintf(Hora_Min, ":%i", Min);
    }
    strncat(Hora_Hor, Hora_Min, 3);
    strcpy(Buf, Hora_Hor);
    return Buf;

}

Veiculo* vei_cria()
{
    Veiculo* vei = (Veiculo*) malloc(sizeof(Veiculo));
    return vei;
}

int vei_insere(char placa[7], char marca[25], char modelo[30], char cor[25], Veiculo * vei)
{
    if (vei == NULL)
        return 0;
    strcpy(vei->placa, placa);
    strcpy(vei->marca, marca);
    strcpy(vei->modelo, modelo);
    strcpy(vei->cor, cor);
    horaAtual(hora); // Pega a hora atual
    vei->hora[0] = hora[0];
    vei->hora[1] = hora[1];
    return 1;
}

void vei_imprimi(Veiculo vei)
{
    printf("\tPlaca: %s\n", vei.placa);
    printf("\tMarca: %s\n", vei.marca);
    printf("\tModelo: %s\n", vei.modelo);
    printf("\tCor: %s\n", vei.cor);
    printf("\tHora de entrada: %s\n", hora_toString(vei.hora[0], vei.hora[1]));
}

void vei_libera(Veiculo* vei)
{
   vei = NULL;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"
#include <string.h>

int main()
{

    setlocale(LC_ALL, "portuguese");
     printf("+---------------------------------------+\n");
        printf("  ESTACIONAMENTO JUQUINHA DO HIMALAYAS\n");
        printf("+---------------------------------------+\n\n");


    float primeira_hora;
        printf("Qual o valor da primeira hora: ");
        scanf("%f", &primeira_hora);

    float demais_horas;
        printf("Qual o valor das demais horas: ");
        scanf("%f", &demais_horas);
        Lista *li = lista_cria(primeira_hora, demais_horas);
        Veiculo* vei = vei_cria();



int e;

    char placa[8];
    char marca[15];
    char modelo[20];
    char cor[15];
    int loop = 0;

    while (loop == 0)
    {
        char useroption;
        system("cls");
        printf("+---------------------------------------+\n");
        printf("  ESTACIONAMENTO JUQUINHA DO HIMALAYAS\n");
        printf("+---------------------------------------+\n\n");
        printf("a) Entrada de veículo\n");
        printf("b) Saída de veículo\n");
        printf("c) Consulta de veículo\n");
        printf("d) Lista de veículo\n\n");
        printf("e) Sair\n\n");

        printf("Selecione a opção desejada: ");
        useroption = getch ();

        if (useroption == 'a' || useroption == 'A')
        {
            system("cls");
            printf("+---------------------------------------+\n");
            printf("  ESTACIONAMENTO JUQUINHA DO HIMALAYAS\n");
            printf("+---------------------------------------+\n\n");

            printf("Digite a placa do veículo: ");
            fflush(stdin);
            scanf("%s", &placa);

            printf("Digite a marca do veículo: ");
            fflush(stdin);
            scanf("%s", &marca);

            printf("Digite o modelo do veículo: ");
            fflush(stdin);
            scanf("%s", &modelo);

            printf("Digite a cor do veículo: ");
            fflush(stdin);
            scanf("%s", &cor);

            e = vei_insere(placa, marca, modelo, cor, vei);
            e = lista_insere(li, *vei);

            printf("Parabéns, veículo cadastrado com sucesso!\n");
            system("pause");
        }

        else if (useroption == 'b' || useroption == 'B')
        {
            system("cls");
            printf("+---------------------------------------+\n");
            printf("  ESTACIONAMENTO JUQUINHA DO HIMALAYAS\n");
            printf("+---------------------------------------+\n\n");

            printf("Digite a placa do veículo: ");
            fflush(stdin);
            scanf("%s", &placa);

            e = lista_retira(li, placa);

        }

        else if (useroption == 'c' || useroption == 'C')
        {
            system("cls");
            printf("+---------------------------------------+\n");
            printf("  ESTACIONAMENTO JUQUINHA DO HIMALAYAS\n");
            printf("+---------------------------------------+\n\n");

            printf("Digite a placa do veículo: ");
            fflush(stdin);
            scanf("%s", &placa);

            e = lista_consulta(li, placa);
            system ("pause");

        }

        else if (useroption == 'd' || useroption == 'D')
        {
            system("cls");
            printf("+---------------------------------------+\n");
            printf("  ESTACIONAMENTO JUQUINHA DO HIMALAYAS\n");
            printf("+---------------------------------------+\n\n");

            e = lista_imprimi(li);
            system ("pause");

        }

        else if (useroption == 'e' || useroption == 'E')
        {
            system("cls");
            printf("+---------------------------------------+\n");
            printf("  ESTACIONAMENTO JUQUINHA DO HIMALAYAS\n");
            printf("+---------------------------------------+\n\n");

            loop = 1;
            system ("pause");

        }

/*
    e = vei_insere("LUL4S13","Ferrari","F100","Rosa tremedera", vei);
    e = lista_insere(li, *vei);
    e = vei_insere("DIL4M13","Chevrollet","Corsa","Vermelho PT",  vei);
    e = lista_insere(li, *vei);
    e = vei_insere("PCB0102","Ferrari","F100","Rosa tremedera", vei);
    e = lista_insere(li, *vei);
    e = vei_insere("DIL4M13","Chevrollet","Corsa","Vermelho PT",  vei);
    e = lista_insere(li, *vei);
    e = vei_insere("EXI0504","Ferrari","F100","Rosa tremedera", vei);
    e = lista_insere(li, *vei);
    e = lista_consulta(li, "PCB0102");
    e = lista_retira(li, "EXI0504");
    printf("%i", e);

    e = lista_imprimi(li);
*/
    }
    return 0;
}




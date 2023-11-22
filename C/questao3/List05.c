#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void tempoExperimento(int sec)
{

    int horas = (sec / 3600);
    int minutos = ((sec % 3600) / 3600);
    int segundos = ((sec % 3600) % 3600);

    printf("%dh %dm %ds", horas, minutos, segundos);

}

int main(int argc, char **argv)
{

    int horas, minutos, segundos;

    printf("Digite o tempo de duracao do procedimento em segundos: ");

    scanf("%d", &segundos);

    tempoExperimento(segundos);

    return SUCESSO;
}


#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int idadeDias(int anos, int meses, int dias){
    int diasTotais;

    diasTotais = ((anos * 365) + (meses * 30) + dias);

    return(diasTotais);
}

int main(int argc, char** argv){

    int anos, meses, dias, diasTot;

    printf("Digite a quantidade de anos, meses e dias da sua idade: \n");

    printf("Anos: ");
    scanf("%i", &anos);

    printf("\nMeses: ");
    scanf("%i", &meses);

    printf("\nDias: ");
    scanf("%i", &dias);

    diasTot = idadeDias(anos, meses, dias);

    printf("Dias totais: %d", diasTot);

    return SUCESSO;
}
#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    int exercicioEscolhido = 0;
	printf("Escolha um exercício de 1 ao 6");
	scanf("%i", &exercicioEscolhido);

    switch (exercicioEscolhido){
    case '1':
        int n=0;

        printf("Digite o valor que deseja calcular seu fatorial: ")
        scanf("%i");

        for (int i = 0; i < exercicioEscolhido; i++)
        {
            exercicioEscolhido = exercicioEscolhido
            exercicioEscolhido--;
        }
        

        break;
    default:
        break;
    }


    return SUCESSO;
}
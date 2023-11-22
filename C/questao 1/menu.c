#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


float soma(float n1, float n2){

    return(n1 + n2);
}

float produto(float n1, float n2){

    return(n1 * n2);
}


float quociente(float n1, float n2){

    return(n1 / n2);
}

int main(int argc, char** argv){

    float n1, n2, totSoma, totMultiplicacao, totdivisao;
    int opcao, opcaoMenu, contador = 1;

    while (contador != 0)
    {
        printf("---------------------------------------");
        printf("\n1 | Soma");
        printf("\n2 | Produto");
        printf("\n3 | Quociente");
        printf("\n0 | Sair");

        printf("\nEscolha a opcao desejada:");

        scanf("%i", &opcao);
        printf("\n---------------------------------------");

        switch (opcao)
        {
        case 1:

            printf("\nDigite dois numeros para obter a soma entre eles:");

            printf("\nNumero 1:");
            scanf("%f", &n1);

            printf("\nNumero 2:");
            scanf("%f", &n2);

            totSoma = soma(n1, n2);

            printf("\nO resultado e: %f\n", totSoma);

            break;
        case 2:

            printf("\nDigite dois numeros para obter a multiplicacao deles:");

            printf("\nNumero 1:");
            scanf("%f", &n1);

            printf("\nNumero 2:");
            scanf("%f", &n2);

            totMultiplicacao = produto(n1, n2);

            printf("\nO resultado e: %f\n", totMultiplicacao);

            break;
        case 3:

            printf("\nDigite dois numeros para obter a divisao deles:");

            printf("\nNumero 1:");
            scanf("%f", &n1);

            printf("\nNumero 2:");
            scanf("%f", &n2);

            totdivisao = quociente(n1, n2);

            printf("\nO resultado e: %f\n", totdivisao);

            break;
        case 0:
            contador = 0;
            break;
        default:
            printf("\nOpcao invalida, favor escolher numeros entre 0 e 3: ");
            break;
        }
    }
    
    return SUCESSO;
}
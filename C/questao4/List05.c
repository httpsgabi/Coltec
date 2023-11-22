#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int ePrimo(n1){

    int i = 0;

    for(i >=0; i <= n1; i++){

        int contador = n1 / i;
    }

    if ((i <= 1)&&(i > 2))
    {
        printf("%n1 nao e primo", n1);
    }
    else{
        printf("%n1 e primo", n1);
    }
    
    return (ePrimo);
}

int main(int argc, char **argv)
{
    int n1;

    printf("Digite o numero para verificar se eh primo ou nao: ");
    scanf("%i", n1);

    ePrimo(n1);

    return SUCESSO;
}

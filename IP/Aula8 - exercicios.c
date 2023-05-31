// Aula 8 Subrotinas (Funções e Procedimentos), exercício 1

#define Sucesso 0
#include <stdio.h>
#include <stdlib.h>

float soma(float num1, float num2) {

	return (num1 + num2);
}

float produto(float num1, float num2) {

	return (num1 * num2);
}

float quociente(float num1, float num2) {

	return (num1 / num2);
}

int main(int agrc, char** argv) {

	int escolhido;
	float num1, num2, resultadoFinal;

	resultadoFinal = 0;

	do {

		printf("Escolha uma dentre as opcoes para realizar a operacao desejada\n");
		printf("(1)Soma\n");
		printf("(2)Produto\n");
		printf("(3)Quociente\n");
		printf("(4)Sair\n");
		scanf("%d", &escolhido);

		if ((escolhido >= 1) && (escolhido <= 3)) {

			printf("(Em caso de numeros decimais utilizar ponto e NAO virgula para separar as casas, assim permite o programa funcionar normalmente)\n\n\n");
			printf("Digite dois numeros que se deseja realizar uma operacao:");
			scanf("%f %f", &num1, &num2);
			
			switch (escolhido) {
			case 1:
				resultadoFinal = soma(num1, num2);
				printf("O Resultado da operacao eh: %f\n", resultadoFinal);
				break;
			case 2:
				resultadoFinal = produto(num1, num2);
				printf("O Resultado da operacao eh: %f\n", resultadoFinal);
				break;
			case 3:
				resultadoFinal = quociente(num1, num2);
				printf("O Resultado da operacao eh: %f\n", resultadoFinal);
				break;
			case 4:	return resultadoFinal;
				break;
			default:
				printf("Escolha uma opcao valida\n");
			}
		}
		else
			printf("O resultado da operacao eh de : %f\n", resultadoFinal);
	} 	while (escolhido != 4);

	return Sucesso;

}

// Aula 8 Subrotinas (Funções e Procedimentos), exercício 2

#define SUCESSO 0
#define DIAS_DO_ANO (365)
#define DIAS_DO_MES (30)
#include <stdio.h>
#include <stdlib.h>

int tempoTOTAL(int num1, int num2, int dias) {

	return ((num1 * DIAS_DO_ANO)+(num2 * DIAS_DO_MES)+dias);
}

int main(int argc, char**  argv ) {

	int num1 = 0, num2 = 0, dias = 0;
	

	printf("Ola, iremos calcular sua idade em dias, por favor digite a sua idade em anos, meses e dias:\n");
	scanf("%d %d %d", &num1, &num2, &dias);

	tempoTOTAL(num1,num2, dias);

	printf("Sua idade total em dias eh %d dias de vida",tempoTOTAL(num1, num2, dias));

	return SUCESSO;

}
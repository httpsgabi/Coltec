//Exercício1

#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char** argv) {

	int exercicioEscolhido = 0;
	printf("Escolha um exercício de 1 ao 5");
	scanf("%i", &exercicioEscolhido);

	switch (exercicioEscolhido)
	{
	case '1':

		int num1, num2, num3, num4, num5, soma;

		printf("Digite cinco valores inteiros separando-os por linha para soma-los");
		scanf("%d \n", &num1);
		scanf("%d \n", &num2);
		scanf("%d \n", &num3);
		scanf("%d \n", &num4);
		scanf("%d \n", &num5);

		soma = num1 + num2 + num3 + num4 + num5;
		printf("A soma dos valores eh: %d \n", soma);

		break;
	case '2':

		float v1, v2, v3, v4, v5, v6, soma, media;

		printf("Digite seis numeros separando-os por linha \n");
		scanf("%d \n", &v1);
		scanf("%d \n", &v2);
		scanf("%d \n", &v3);
		scanf("%d \n", &v4);
		scanf("%d \n", &v5);
		scanf("%d \n", &v6);

		media = (v1 + v2 + v3 + v4 + v5 + v6) / 6;

		printf("A media aritmetica eh: %f \n"), media;

		break;
	case '3':

		float H, resultado;
		H = 1 + 1 / 2 + 1 / 3 + 1 / 4 + 1 / 5;

		printf("Vamos obter o valor de H = 1 + 1/2 + 1/3 + 1/4 + 1/5; \n");

		resultado = 1 + 1.0f / 2 + 1.0f / 3 + 1.0f / 4 + 1.0f / 5;

		printf("O valor de H eh: %f \n", resultado);

		break;
	case '4':

		float sAtual, aumento, porcetagem, novoSalario;

		printf("Digite o valor de seu salario atual(separando as casas decimais por virgula) e na proxima a porcentagem de aumento \n");
		scanf("%f \n", &sAtual);
		scanf("%f \n", &porcetagem);

		aumento = sAtual * (porcetagem / 100);
		novoSalario = sAtual + aumento;

		printf("Seu aumento salarial foi de %f reais e seu novo salario eh de %f \n", aumento, novoSalario);

		break;
	case '5':

		float prova1, prova2, prova3, media;

		printf("Digite as notas das 3 provas para obter a media ponderada do aluno (uma por linha) \n");
		scanf("%f \n", &prova1);
		scanf("%f \n", &prova2);
		scanf("%f \n", &prova3);

		media = ((prova1 * 4) + (prova2 * 3) + (prova3 * 3)) / 4 + 3 + 3;
		printf("A media das notas eh: %f \n", media);

		break;
	default:
		printf("Opcao invalida");
		break;
	}

	return SUCESSO;
}
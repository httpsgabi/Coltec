#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

	int exercicioEscolhido = 0;
	printf("Escolha um exercício de 1 ao 6");
	scanf("%i", &exercicioEscolhido);

	switch (exercicioEscolhido)
	{
	case '1':

		int ePar;
		int numero;

		printf("Digite um numero inteiro para saber se ele eh impar ou par \n");
		scanf("%d", &numero);

		ePar = (numero % 2) == 0;

		if (ePar) {
			printf("O numero %d eh PAR.\n", numero);
		}
		else {
			printf("O numero %d eh IMPAR.\n", numero);
		}

		break;
	case '2':

		int a, b, maior, menor, igual;

		printf("Digte dois numeros A e B para saber eh o maior entre eles ou se sao iguais \n");
		scanf("%d \n", &a);
		scanf("%d \n", &b);

		maior = (a > b);
		igual = a == b;
		menor = (a < b);

		if (igual) {
			printf(" o numero %d eh igual a %d \n", a, b);
		}
		else if (maior) {
			printf("o numero %d eh maior que %d", a, b);

		}
		else if (menor) {
			printf(" o numero %d eh menor que %d", a, b);

		}

		break;
	case '3':

		int diaSemana;

		printf("Digite um numero de 1 a 7 para saber seu dia da semana, considerando 1 como domingo e assim sucessivamente \n");
		scanf("%d \n", &diaSemana);

		switch (diaSemana) {
		case 1:
			printf("O dia da semana eh domingo \n");
		break;
		case 2:
			printf("O dia da semana eh segunda \n");
		break;
		case 3:
			printf("O dia da semana eh terça \n");
		break;
		case 4:
			printf("O dia da semana eh quarta \n");
		break;
		case 5:
			printf("O dia da semana eh quinta \n");
		break;
		case 6:
			printf("O dia da semana eh sexta \n");
		break;
		case 7:
			printf("O dia da semana eh sabado \n");
		break;
		default:
			printf("Dia da semana invalido, digite um valor de 1 a 7 \n");
		break;
		}

		break;
	case '4':

		float a, b, resultado;
		char operador;

		printf("Digite dois numeros (A e B) e a operaçao entre eles ( + - * ou / ) para saber o resultado \n");
		printf("A conta nao sera executada caso o operdor seja invalido ou numa divisao (b) ter valor 0 para qualquer valor de (a)\n");
		scanf("%f %c %f", &a, &operador, &b);

		switch (operador) {
		case '+':
			printf("%f %c %f = %f \n", a, operador, b, (a + b));
		break;
		case '-':
			printf("%f %c %f = %f \n", a, operador, b, (a - b));
		break;
		case '*':
			printf("%f %c %f = %f \n", a, operador, b, (a * b));
		break;
		case '/':
			printf("%f %c %f = %f \n", a, operador, b, (a / b)); 
		default:("Alguma das restriçoes descrita acima");
		break;
		}

		break;
	case '5':

		float x, y, z, condicao;

		printf("Digite os 3 lados do triangulo para saber se ele existe ou nao \n");
		scanf("%f", &x);
		scanf("%f", &y);
		scanf("%f", &z);

		condicao = (x < y + z) && (y < x + z) && (z < x + y);

		if (condicao) {
			printf("A condiçao de existencia diz que o triangulo eh verdadeiro \n");
		} 
		else { 
			printf("A condiçao de existencia diz que o triangulo eh falso \n");
		}

			break;
	case '6':

		float altura, peso, pesoIdeal;
		char sexo;

		// Obtem os dados
		printf("Digite sua altura em metros: ");
		scanf("%f", &altura);
		printf("Digite seu peso atual em kg: ");
		scanf("%f", &peso);
		printf("Digite seu sexo (M ou F): ");
		scanf(" %c", &sexo);

		// Calcula o peso ideal
		if ((sexo == 'M') || (sexo == 'm')) {
			pesoIdeal = (72.7f * altura) - 58;
		}
		else {
			pesoIdeal = (62.1f * altura) - 44.7f;
		}

		// Verifica a situação dela e informa
		printf("Seu peso ideal eh %.2f e esta pesando %.2f. ", pesoIdeal, peso);
		if (peso > pesoIdeal) {
			printf("Voce esta acima do peso.\n");
		}
		else {
			printf("Voce esta no pesoa ideal ou abaixo.\n");
		}

		break;
	default:
		printf("Opcao invalida");
		break;
	}

	return SUCESSO;
}
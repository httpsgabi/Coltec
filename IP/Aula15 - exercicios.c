//Exercício 1 

#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void intervaloAeB(int a, int b) {

	printf("%d ", a);

	if (a > b)
	{
		printf("Erro, o primeiro numero eh maior que o segundo");
		return;
	}
	else if (a<b) {
		intervaloAeB(a + 1, b);
	}
	else{
		printf("\n");

	}

	printf("%d ", a);
}

int main(int argc, char** argv) {

	int a, b;

	printf("Digite dois numeros para imprimir o intervalo entre eles: \n");
	scanf("%d\n", &a);
	scanf("%d", &b);

	intervaloAeB(a, b);

	return SUCESSO;
}






//Exercício 2 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0 
#define TAM_MAX_VETOR (50 + 1)
#define MIN (0)

int elemento_max_vetor(int vetor[], int max_vetor) {

	int totalElementos;

	if (max_vetor == 0) {
		return MIN;
	}

	totalElementos = elemento_max_vetor(&vetor[1], max_vetor - 1);

	if (vetor[0] < max_vetor) {
		return max_vetor;
	}
	else {
		return vetor[0];
	}

}

int soma_elementos_vetor(int vetor[], int min_vetor) {


	if (min_vetor == 0) {
		return MIN;
	}

	for (int i = 0; i < TAM_MAX_VETOR; i++)
	{

		return vetor[0] + soma_elementos_vetor(&vetor[i], min_vetor - 1);

	}

}

float media_elementos_vetor(int vetor[], int media_vetor, int posicaoinicial) {

	if (media_vetor == 0) {
		return 0.0f;
	}

	return vetor[0] / ((1.0f) * posicaoinicial) + media_elementos_vetor(&vetor[1], media_vetor - 1, posicaoinicial);

	float mediaA1(int vetor[], int posicaoinicial); {
		return media_elementos_vetor(vetor, posicaoinicial, posicaoinicial);
	}

	float mediaA2(int vetor[], int posicaoinicial); {
		return soma_elementos_vetor(vetor, posicaoinicial) / ((1.0f) * posicaoinicial);
	
	}

}



int main(int argc, char** argv) {

	int vetorUsuario[TAM_MAX_VETOR]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50 };
	int opcaoescolhida;

	printf("Digite a operacao que quer realizar:\n\n");
	printf("(1) O elemento maximo do vetor;\n");
	printf("(2) A soma dos elementos do vetor;\n");
	printf("(3) Media aritmetica dos elementos do vetor\n");

	scanf("%d", &opcaoescolhida);

	switch (opcaoescolhida)
	{
	case 1:
		//elemento_max_vetor;

		printf("O elemento maximo do vetor eh: %d\n"), elemento_max_vetor(vetorUsuario, (sizeof(vetorUsuario) / sizeof(int)));

		break;
	case 2:
		//soma_elementos_vetor;
		printf("A soma dos elementos do vetor eh: %d\n"), soma_elementos_vetor(vetorUsuario, (sizeof(vetorUsuario) / sizeof(int)));

		break;
	case 3:
		//media_elementos_vetor;
		
		printf("A media dos elementos do vetor V1 eh: %f\n", mediaA1(vetorUsuario, (sizeof(vetorUsuario) / sizeof(int))));
		printf("A media dos elementos do vetor V2 eh: %f\n", mediaA2(vetorUsuario, (sizeof(vetorUsuario) / sizeof(int))));

		break;
	default:
		printf("Numero invalido digite novamente");
		break;
	}

	return SUCESSO;
}




//Exercício 3

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0


int fibonacci_N(int n) {

	if ((n<=1)||(n==2))
	{
		return 1;
	}
		return n = fibonacci_N((n - 1) + (n - 2));
}


int main(int argc, char** argv) {

	int n;

	printf("Digite n para calcular o n-esimo na sequencia fibonacci: \n\n");
	scanf("%d", &n);

	printf("Na posicao %d, o n-esimo numero eh: %d", n, fibonacci_N(n));

	return SUCESSO;
}

//Exercício 4

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

int quantidade_digitos(int num) {

	if (num < 10) {
		return 1;
	}

	return 1 + quantidade_digitos(num/10);
}

int main(int argc, char** argv) {

	int num;

	printf("Digite o numero para saber quantos caracteres: \n\n");
	scanf("%d", &num);

	printf("A quantidade de digitos de %d eh: %d\n\n",num, quantidade_digitos(num));

	return SUCESSO;
}

//Exercício 5





//Exercício 1(Segunda parte)
/*
	A principal diferença entre a pesquisa linear e a pesquisa binária é que a pesquisa binária leva menos tempo para pesquisar 
um elemento da lista classificada de elementos. Assim, infere-se que a eficiência do método de pesquisa binária é maior que a pesquisa linear.
	A busca binária é um eficiente algoritmo para encontrar um item em uma lista ordenada de itens. 
Ela funciona dividindo repetidamente pela metade a porção da lista que deve conter o item, até reduzir as localizações possíveis a apenas uma. 
Nós usamos a busca binária em um jogo de adivinhação no tutorial introdutório.

*/


//Exercício 2(Segunda parte)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SUCESSO 0
#define TAM_VETOR (10+1)

int buscabinaria(int vet[], int tamvetor, int numero) {

	int inicio = 0;
	int final = tamvetor - 1;
	int meio;

	while (inicio <= final)
	{
		meio = (inicio + final) / 2;
		if (numero < vet[meio])
		{
			return buscabinaria(vet, numero, final = meio - 1);
		}
		else if (numero > vet[meio]) {

			return buscabinaria(vet, numero, inicio = meio + 1);
		}
		else return buscabinaria(vet, numero, meio);


	}

}


int main(int argc, char** argv) {

	int vet[TAM_VETOR] = { 1,3,5,7,9,11,13,15,17,19 };
	int tamvetor = sizeof(vet) / sizeof(int);
	int numero;

	printf("Digite o numero que quer procurar no vetor: \n");
	scanf("%d", &numero);

	buscabinaria(vet, numero, sizeof(int));

	printf("O numero %d esta na posicao %d do vetor ", numero, buscabinaria(vet, numero, sizeof(tamvetor)/sizeof(int)));

	return SUCESSO;
}
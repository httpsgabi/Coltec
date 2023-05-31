//Trabalho02 de IP - Restaurante

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define NUM_INGREDIENTES_MASSA  (20 + 1)
#define QUANTIDADE_INGREDIENTES (20 + 1) 

typedef struct ingredientes_s {

	char massa[QUANTIDADE_INGREDIENTES][NUM_INGREDIENTES_MASSA];

} ingredientes;

typedef struct receita_s {

	int lista[QUANTIDADE_INGREDIENTES];
	int quantidadeReceitas;
	float peso[QUANTIDADE_INGREDIENTES];

} receita;


int main(int argc, char** argv) {

	ingredientes ingr;
	receita* quantreceitas;
	
	int listaIngr = 0;
	int quantidadeReceita = 0;
	int a, n;
	

	char massa[NUM_INGREDIENTES_MASSA][QUANTIDADE_INGREDIENTES] = { "farinha", "ovos", "leite", "molho", "queijo", "preseunto", "calabresa",
	"oregano", "azeitona", "tomate", "fermento", "cebola", "pimentao", "milho", "bacon", "azeitonaPreta", "azeite", "cogumelo",
	"peperoni", "louro", "pimenta" };

	printf("\n LISTA DE INGREDIENTES \n");
	for (int i = 0; i < QUANTIDADE_INGREDIENTES; i++)
	{
		strcpy(ingr.massa[i], massa[i]);
		printf("\n %d -- %s", i, ingr.massa[i]);
	}

	printf("\nDigite a quantidade de receitas: ");
	scanf("%i", &quantidadeReceita);

	quantreceitas = (receita*) calloc (quantidadeReceita, sizeof(receita));

	printf("Digite a quantidade de ingredientes que tera na sua receita: \n ");
	scanf("%i", &listaIngr);

	for (int b = 0; b < quantidadeReceita; b++)
	{

		for (a = 0; a < listaIngr; a++)
		{

			printf("\nDigite o numero do seu ingrediente: ");
			scanf("%i", &quantreceitas[b].lista[a]);

				if ((quantreceitas[b].lista[a] < 0) || (quantreceitas[b].lista[a] > 20))
				{
					printf("Numero invalido\n");
				}
				else
				{

					printf("\nDigite  a quantidade em gramas: ");
					scanf("%f", &quantreceitas[a].peso[a]);
					
				}

			}

		printf("\nEssa eh a receita numero %i\n", (b+1));
	}

	printf("Qual receita deseja imprimir: ");
	scanf("%i", quantidadeReceita );

	printf("%i", quantidadeReceita);

	
	free(quantreceitas);
	return SUCESSO;

}
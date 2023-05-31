#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SUCESSO 0
#define TAM_MAX_INGR	(30 + 1)
#define INGR_DESC_TAM_MAX	(100+1)
#define RECEITA_DESC_TAM_MAX	(100+1)
#define TAM_MAX_INGR_NA_RECEITA		(50+1)

typedef struct ingr_s
{
	char nome[TAM_MAX_INGR];
	int codigo;
	int medida;
	char descricao[INGR_DESC_TAM_MAX];
}
ingr_t;

typedef struct receita_s
{
	int nIngredientesReceita;
	ingr_t* listaIngredientes;
	int codigoReceita;
	char descricaoReceita[RECEITA_DESC_TAM_MAX];

}
receita_t;

void imprimeReceitasOrdenadoPorDescricao(receita_t* receitas, int nReceitas)
{
	for (int i = 0; i < receitas->nIngredientesReceita; i++)
	{
		for (int j = 0; j < receitas->nIngredientesReceita; j++)
		{
			if (strcmp(receitas->listaIngredientes[i].descricao, receitas->listaIngredientes[j].descricao) < 0);
			{
				ingr_t aux = receitas->listaIngredientes[i];
				receitas->listaIngredientes[i] = receitas->listaIngredientes[j];
				receitas->listaIngredientes[j] = aux;
			}

			printf("(%i) | (%s)\n"), receitas[i].listaIngredientes[j].codigo, receitas[i].listaIngredientes[j].nome;
		}
	}
}

void imprimeReceitasOrdenadoPorCadastro(receita_t* receitas, int nReceitas){
	for (int i = 0; i < nReceitas; i++)
	{
		
		for (int j = 0; j < receitas[i].nIngredientesReceita; j++)
		{
			if (receitas[j].codigoReceita, receitas[j + 1].codigoReceita > 0); //(receitas[i].codigoReceita < receitas[j].codigoReceita);
			{
				receita_t aux = receitas[i];
				receitas[i] = receitas[j];
				receitas[j] = aux;
			}
		}
		printf("(%d) | (%s) | ", receitas[i].codigoReceita, receitas[i].listaIngredientes[i].nome);
	}
}

void imprimeIngredientesOrdenadoPorCodigo(ingr_t* ingredientes, int nIngredientes)
{
	for (int i = 0; i < nIngredientes; i++)
	{
		for (int j = 0; j < nIngredientes; j++)
		{
			if (strcmp(ingredientes[j].nome, ingredientes[j + 1].nome) > 0);
			{
				ingr_t aux = ingredientes[i];
				ingredientes[i] = ingredientes[j];
				ingredientes[j] = aux;

				ingredientes[i] = ingredientes[i + 1];
				ingredientes[i + 1] = aux;
			}
		}

		printf("%d | %s\n", ingredientes[i].codigo, ingredientes[i].nome);
	}
}

void imprimeIngredientesOrdenadoPorDescricao(ingr_t* ingredientes, int nIngredientes)
{
	int i, j;

	for (i = 0; i < (nIngredientes - 1); i++) {
		for (j = 0; j < (nIngredientes - 1); j++) {
			
			if (ingredientes[i].codigo < ingredientes[j].codigo)
			{
				ingr_t aux = ingredientes[i];
				ingredientes[i] = ingredientes[j];
				ingredientes[j] = aux;
			}

			printf("%d | %s\n", ingredientes[i].codigo, ingredientes[i].nome);
			
		}
	}
}


int main(int argc, char** argv){

	receita_t* receitas;
	int quantidadeReceitas;
	FILE* arquivo_ingredientes, * arquivo_receitas;
	ingr_t* ingredientesPossiveis;
	int quantidadeIngredientesPossiveis;
	char lixo;

	arquivo_ingredientes = fopen("Ingredientes do Restaurante.txt", "r");
	arquivo_receitas = fopen("Receitas do restaurante.txt", "r");

	if (arquivo_ingredientes == NULL) {

		arquivo_ingredientes = fopen("Ingredientes do restaurante.txt", "w");

		ingredientesPossiveis = (ingr_t*)calloc(TAM_MAX_INGR, sizeof(ingr_t));

		for (int i = 0; i < TAM_MAX_INGR; i++)
		{
			memcpy(ingredientesPossiveis[i].nome, arquivo_ingredientes, TAM_MAX_INGR);
		}

		fwrite(ingredientesPossiveis, sizeof(ingredientesPossiveis), TAM_MAX_INGR, arquivo_ingredientes);


		fclose(arquivo_ingredientes);
		free(ingredientesPossiveis);

	}

	if (arquivo_receitas == NULL) {

		arquivo_receitas = fopen("Receitas do restaurante.txt", "w");

		ingredientesPossiveis = (ingr_t*)calloc(TAM_MAX_INGR, sizeof(ingr_t));
		receitas = (receita_t*)calloc(TAM_MAX_INGR_NA_RECEITA, sizeof(receita_t));

		for (int i = 0; i < TAM_MAX_INGR_NA_RECEITA; i++)
		{
			memcpy(ingredientesPossiveis[i].nome, arquivo_receitas , TAM_MAX_INGR_NA_RECEITA);
		}

		fwrite(receitas, sizeof(receitas), TAM_MAX_INGR_NA_RECEITA, arquivo_receitas);

		fclose(arquivo_receitas);
		free(receitas);
		free(ingredientesPossiveis);
		

	}

	printf("OLA, IREMOS CADASTRAR NOVOS INGREDIENTES, POR FAVOR DIGITE A QUANTIDADE DESEJADA:\n\n*Obs: A quantidade deve ser maior que 20\n\n");
	scanf("%i%c", &quantidadeIngredientesPossiveis, &lixo);

	printf("\n-----------------------------------------------------\n");

	//if (quantidadeIngredientesPossiveis < 20){
		//printf("Numero menor que 20, tente novamente");
	//}
	//else {


	ingredientesPossiveis = (ingr_t*)calloc(quantidadeIngredientesPossiveis, sizeof(ingr_t));

	for (int a = 0; a < quantidadeIngredientesPossiveis; a++)
	{
		printf("\nDigite o nome do ingrediente (%i): ", a);
		fgets(ingredientesPossiveis[a].nome, TAM_MAX_INGR, stdin);

		printf("Digite o codigo do ingrediente (%i): ", a);
		scanf("%i%c", &ingredientesPossiveis[a].codigo, &lixo);


	}

	printf("\n-----------------------------------------------------\n");

	for (int i = 0; i < quantidadeIngredientesPossiveis; i++)
	{
		printf("(%i) | %s", ingredientesPossiveis[i].codigo, ingredientesPossiveis[i].nome);
	}

	printf("\n-----------------------------------------------------");

	printf("\n\nDigite a quantidade de receitas que deseja cadastrar: ");
	scanf("%i%c", &quantidadeReceitas, &lixo);

	receitas = (receita_t*)calloc(quantidadeReceitas, sizeof(receita_t));
	int a;

	for (int i = 0; i < quantidadeReceitas; i++)
	{
		printf("\n\nDigite o codigo da receita: ");
		scanf("%i%c", &receitas[i].codigoReceita, &lixo);

		printf("\nDigite a quantidade de ingredientes que a receita possui:\n");
		scanf("%i%c", &receitas[i].nIngredientesReceita, &lixo);

		receitas[i].listaIngredientes = (ingr_t*)calloc(receitas[i].nIngredientesReceita, sizeof(ingr_t));
		
		for (int j = 0; j < receitas[i].nIngredientesReceita; j++)
		{
		
			printf("\n\nDigite o nome do ingrediente (%i): ", j);

			fgets(receitas[j].listaIngredientes[j].nome, TAM_MAX_INGR, stdin);

			printf("Digite o codigo do ingrediente (%i): ", j);
			scanf("%i%c", &receitas[j].listaIngredientes[j].codigo, &lixo);

			printf("Digite a medida do ingrediente (%i) para a receita: ", j);
			scanf("%i%c", &ingredientesPossiveis[j].medida, &lixo);

		}

		printf("\n-----------------------------------------------------\n");
		printf("\nESSA EH A RECEITA NUMERO (%i) DE: (%i)\n", (i + 1), quantidadeReceitas);
	}

	int opcao;

	do
	{
		printf("\n-----------------------------------------------------\n");

		printf("\n\n\nDigite o que deseja imprimir:\n");
		printf("(1) | Imprimir a lista de ingredientes por ordem de cadastro\n");
		printf("(2) | Imprimir a lista de ingredientes por ordem de descricao\n");
		printf("(3) | Imprimir a lista de ingredientes por ordem de codigo\n");
		printf("(4) | Cadastrar um novo ingrediente\n\n");
		printf("(5) | Imprimir a lista de receitas por ordem de descricao\n");
		printf("(6) | Imprimir a lista de receitas por ordem de cadastro\n");
		printf("(7) | Cadastrar uma nova receita\n");
		printf("(0) | Sair\n\n\n");
		printf("Opcao: ");
		scanf("%i%c", &opcao, &lixo);
		printf("\n-----------------------------------------------------\n");

		switch (opcao)
		{
		case 1:

			for (int i = 0; i < quantidadeIngredientesPossiveis; i++)
			{
				printf("\n(%i) | %s", ingredientesPossiveis[i].codigo, ingredientesPossiveis[i].nome);
			}

			break;
		case 2:
			imprimeIngredientesOrdenadoPorDescricao(ingredientesPossiveis, quantidadeIngredientesPossiveis);
			break;
		case 3:
			imprimeIngredientesOrdenadoPorCodigo(ingredientesPossiveis, quantidadeIngredientesPossiveis);
			break;
		case 4:
			int h;

			printf("\n\nIremos cadastrar os ingredientes, digite a quantidade desejada:\n");
			scanf("%i%c", &h, &lixo);

			ingredientesPossiveis = (ingr_t*)calloc(h, sizeof(ingr_t));

			for (int i = 0; i < h; i++)
			{
				printf("\n\nDigite o nome do ingrediente: ");
				fgets(ingredientesPossiveis[i].nome, TAM_MAX_INGR, stdin);

				printf("\nDigite o codigo do ingrediente: ");
				scanf("%i%c", &ingredientesPossiveis[i].codigo);

				ingredientesPossiveis = (ingr_t*)calloc(ingredientesPossiveis[i].codigo, sizeof(ingr_t));

				printf("\nDigite a medida do ingrediente: ");
				scanf("%i%c", &ingredientesPossiveis[i].medida, &lixo);


			}
			free(ingredientesPossiveis);
			break;
		case 5:
			//imprimeReceitasOrdenadoPorDescricao(receitas, quantidadeReceitas);
			break;
		case 6:
			imprimeReceitasOrdenadoPorCadastro(receitas, quantidadeReceitas);

			for (int i = 0; i < quantidadeReceitas; i++)
			{

			printf:("Quantidade: % i", &ingredientesPossiveis[i].medida);

			}

			break;
		case 7:
			printf("\n\nDigite a quantidade de receitas que deseja cadastrar:\n\n");
			scanf("%i%c", &quantidadeReceitas, &lixo);

			receitas = (receita_t*)calloc(quantidadeReceitas, sizeof(receita_t));

			for (int i = 0; i < quantidadeReceitas; i++)
			{
				printf("\n\nDigite o codigo da receita:\n");
				scanf("%i%c", &receitas[i].codigoReceita, &lixo);

				printf("\nDigite a quantidade de ingredientes que a receita possui:\n");
				scanf("%i%c", &receitas[i].nIngredientesReceita, &lixo);

				receitas[i].listaIngredientes = (ingr_t*)calloc(receitas[i].nIngredientesReceita, sizeof(ingr_t));

				for (int j = 0; j < receitas[i].nIngredientesReceita; j++)
				{
					printf("\n\nDigite o nome do ingrediente %i:\n", j);
					fgets(receitas[i].listaIngredientes[j].nome, TAM_MAX_INGR, stdin);

					printf("\nDigite o codigo do ingrediente:\n");
					scanf("%i%c", &receitas[i].listaIngredientes[j].codigo, &lixo);

				}
			}
			break;
		case 0:
			break;
		default:
			printf("Opcao invalida\n");
		}
		free(receitas);
		free(ingredientesPossiveis);
	} while (opcao != 0);
	

	free(ingredientesPossiveis);
	free(receitas);
	
	return SUCESSO;
}
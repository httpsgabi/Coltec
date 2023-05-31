//Bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definicoes e constantes:

#define SUCESSO 0
#define TAM_MAX_TITULO_LIVRO (50 + 1)
#define TAM_MAX_EDITORA (30 + 1)
#define TAM_MAX_NOME (50 + 1)
#define TAM_MAX_NACIONALIDADE (25 + 1)
#define TAM_MAX_OBSERVACOES (1000 + 1)
#define TAM_DATA (3)
#define TAM_MAX_ISBN (15 + 1)
#define TAM_MAX_AUTORES_NO_LIVRO (10)

//Estruturas:

typedef struct dados_livros_s {

	int  codigo_livro, edicao_livro;
	char titulo_livro[TAM_MAX_TITULO_LIVRO];
	int lancamento_livro[TAM_DATA];
	char isbn[TAM_MAX_ISBN];
	char editora_livro[TAM_MAX_TITULO_LIVRO];
	char observacoes_livro[TAM_MAX_OBSERVACOES];

}dados_livros_t;

typedef struct dados_autor_s {

	int id_autor;
	char nome_autor[TAM_MAX_NOME];
	char nacionalidade_autor[TAM_MAX_NACIONALIDADE];
	int nascimento_autor[TAM_DATA];
	char observacoes_autor[TAM_MAX_OBSERVACOES];


}dados_autor_t;

typedef struct associacoes_s {

	int id_autor_associacoes;
	int livros_autor[TAM_MAX_AUTORES_NO_LIVRO];

}associacoes_t;

//Funcoes de cadastro

int funcao_cadastrar_livros(dados_livros_t*, int quantidade_livros) {

	dados_livros_t* dados_livros;
	char lixo;

	printf("Digite a quantidade de livros que quer cadastrar:\nR: ");
	scanf("%i%c", &quantidade_livros, &lixo);

	dados_livros = (dados_livros_t*)calloc(quantidade_livros, sizeof(dados_livros_t));

	for (int l = 0; l < quantidade_livros; l++)
	{

		printf("\nDigite o codigo do livro: ");
		scanf("&i%c", &dados_livros[l].codigo_livro, &lixo);
		printf("\nDigite o titulo do livro: ");
		fgets(dados_livros[l].titulo_livro, TAM_MAX_TITULO_LIVRO, stdin);
		printf("\nDigite a edicao do livro: ");
		scanf("&i%c", &dados_livros[l].edicao_livro, &lixo);
		printf("\nDigite a data do lancamento do livro divido em DD-MM-AAAA: ");
		scanf("&i%c", &dados_livros[l].lancamento_livro[0], &lixo);
		scanf("&i%c", &dados_livros[l].lancamento_livro[1], &lixo);
		scanf("&i%c", &dados_livros[l].lancamento_livro[2], &lixo);
		printf("\nDigite o ISBN do livro: ");
		fgets(dados_livros[l].isbn, TAM_MAX_ISBN, stdin);
		printf("\nDigite a editora do livro: ");
		fgets(dados_livros[l].editora_livro, TAM_MAX_EDITORA, stdin);
		printf("\nDigite o autor do livro: ");

		printf("\nDigite as observacoes do livro");
		scanf("%i%c", &dados_livros[l].observacoes_livro, &lixo);

		printf("Esse eh o livro Nº: %i", l);

	}
	free(dados_livros);

	return SUCESSO;
}

int funcao_cadastrar_autores(dados_autor_t*, int quantidade_autores) {

	dados_autor_t* dados_autor;
	char lixo;

	printf("\n\nDigite a quantidade de autores que deseja cadastar:\nR: ");
	scanf("%i", &quantidade_autores);

	dados_autor = (dados_autor_t*)calloc(quantidade_autores, sizeof(dados_autor_t));

	for (int k = 0; k < quantidade_autores; k++)
	{
		printf("\nDigite o ID do autor: ");
		scanf("%i%c", &dados_autor[k].id_autor, &lixo);
		printf("\nDigite o nome do autor: ");
		fgets(dados_autor[k].nome_autor, TAM_MAX_NOME, stdin);
		printf("\nDigite a nacionalidade do autor: ");
		fgets(dados_autor[k].nacionalidade_autor, TAM_MAX_NACIONALIDADE, stdin);
		printf("\nDigite a data do nascimento do autor divido em DD-MM-AAAA: ");
		scanf("%i%i%i", &dados_autor[k].nascimento_autor[0], &dados_autor[k].nascimento_autor[1], &dados_autor[k].nascimento_autor[2]);
		printf("\nDigite as observacoes do autor: ");
		scanf("%i", &dados_autor[k].observacoes_autor);

		printf("Este eh o livro Nº: %i", k);

	}
	free(dados_autor);

	return SUCESSO;
}

//Funcoes de criacao dos arquivos

void funcao_arquivo_autores() {

	FILE* arquivo_autores;
	dados_autor_t* dados_autor;
	int quantidade_autores = 0;

	arquivo_autores = fopen("Lista de Autores.txt", "w");

	if (arquivo_autores == NULL) {

		dados_autor = (dados_autor_s*)calloc(quantidade_autores, sizeof(dados_autor_s));

		fwrite(dados_autor, sizeof(dados_autor), quantidade_autores, arquivo_autores);

		fclose(arquivo_autores);
		free(dados_autor);
	}

	return;

}

void funcao_arquivo_livros() {

	FILE* arquivo_livros;
	dados_livros_t* dados_livros;
	int quantidade_livros = 0;

	arquivo_livros = fopen("Lista de Livros.txt", "w");

	if (arquivo_livros == NULL) {

		dados_livros = (dados_livros_s*)calloc(quantidade_livros, sizeof(dados_livros_s));

		fwrite(dados_livros, sizeof(dados_livros), quantidade_livros, arquivo_livros);

		fclose(arquivo_livros);
		free(dados_livros);
	}

	return;
}

void funcao_arquivo_associar() {

	FILE* arquivo_associacoes;
	associacoes_t buffer, * associacoes;

	int nAssociacoes = 0;

	arquivo_associacoes = fopen("Arquivo de Associacoes.bin", "rb");

	if (arquivo_associacoes == NULL) {

		printf("\nErro na abertura");
		arquivo_associacoes = fopen("Arquivo de Associacoes.bin", "wb");
		fclose(arquivo_associacoes);
		return;
	}

	while (!feof(arquivo_associacoes))
	{
		fread(&buffer, sizeof(associacoes_t), 1, arquivo_associacoes);
		nAssociacoes++;
	}

	fclose(arquivo_associacoes);

	associacoes = (associacoes_t*)calloc((nAssociacoes + 1), sizeof(associacoes_t));

	arquivo_associacoes = fopen("Arquivo de Associacoes.bin", "rb");

	fread(associacoes, sizeof(associacoes_t), nAssociacoes, arquivo_associacoes);

	return;

	//1º perguntar o usuario os codigos do livro e do autor que devera ser associado (na funcao)
	//2º pergar as respostas do usuario e comparar com a variavel associacoes no campo no livro(da struct)
	//se o codigo do livro for igual a um existente associar +1 ao vetor
	//Se o codigo nao exitir criar mais 1 campo
}

//Funcoes de ordenacao:

void ordernar_livros_por_codigo(dados_livros_t* dados_livros, int quantidade_livros) {

	int a, b;
	dados_livros_t* tmp;

	for (a = 0; a < (quantidade_livros - 1); a++) {
		for (b = 0; b < (quantidade_livros - 1); b++) {
			// Se estiver fora de ordem...
			if ((dados_livros[b].codigo_livro, dados_livros[b + 1].codigo_livro) > 0) {
				// ... troca de posicao
				tmp = dados_livros;
				dados_livros[b] = dados_livros[b + 1];
				dados_livros[b + 1] = *tmp;
			}
		}

		printf("%i | %s | %i/%i/%i ", dados_livros[a].codigo_livro, dados_livros[a].titulo_livro, dados_livros[a].lancamento_livro[0], dados_livros[a].lancamento_livro[1], dados_livros[a].lancamento_livro[2]);
	}
	return;
}
void ordernar_livros_por_titulo(dados_livros_t* dados_livros, int quantidade_livros) {

	int c, d;
	dados_livros_t* tmp = 0;

	for (c = 0; c < (quantidade_livros - 1); c++) {
		for (d = 0; d < (quantidade_livros - 1); d++) {
			// Se estiver fora de ordem...
			if (strcmp(dados_livros[d].titulo_livro, dados_livros[d + 1].titulo_livro) > 0) {
				// ... troca de posicao
				*tmp = dados_livros[d];
				dados_livros[d] = dados_livros[d + 1];
				dados_livros[d + 1] = *tmp;
			}
		}

		printf("%i | %s | %i/%i/%i ", dados_livros[c].codigo_livro, dados_livros[c].titulo_livro, dados_livros[c].lancamento_livro[0], dados_livros[c].lancamento_livro[1], dados_livros[c].lancamento_livro[2]);
	}
	return;
}
void ordernar_livros_por_lancamento(dados_livros_t* dados_livros, int quantidade_livros) {

	int e, f;
	dados_livros_t* tmp = 0;

	for (e = 0; e < (quantidade_livros - 1); e++) {
		for (f = 0; f < (quantidade_livros - 1); f++) {
			// Se estiver fora de ordem...
			if (dados_livros[f].lancamento_livro, dados_livros[f + 1].lancamento_livro)  {
				// ... troca de posicao
				*tmp = dados_livros[f];
				dados_livros[f] = dados_livros[f + 1];
				dados_livros[f + 1] = *tmp;
			}
		}
		printf("%i | %s | %i/%i/%i ", dados_livros[e].codigo_livro, dados_livros[e].titulo_livro, dados_livros[e].lancamento_livro[0], dados_livros[e].lancamento_livro[1], dados_livros[e].lancamento_livro[2]);
	}
	return;
}
void ordernar_autores_por_id(dados_autor_t* dados_autor, int quantidade_autores) {

	int g, h;
	dados_autor_t* tmp = 0;

	for (g = 0; g < (quantidade_autores - 1); g++) {
		for (h = 0; h < (quantidade_autores - 1); h++) {
			// Se estiver fora de ordem...
			if ((dados_autor[h].id_autor, dados_autor[h + 1].id_autor) > 0) {
				// ... troca de posicao
				*tmp = dados_autor[h];
				dados_autor[h] = dados_autor[h + 1];
				dados_autor[h + 1] = *tmp;
			}
		}
		printf("%i | %s | %i/%i/%i ", dados_autor[g].id_autor, dados_autor[g].nome_autor, dados_autor[g].nascimento_autor[0], dados_autor[g].nascimento_autor[1], dados_autor[g].nascimento_autor[2]);
	}
	return;
}
void ordernar_autores_por_nome(dados_autor_t* dados_autor, int quantidade_autores) {

	int g, h;
	dados_autor_t* tmp = 0;

	for (g = 0; g < (quantidade_autores - 1); g++) {
		for (h = 0; h < (quantidade_autores - 1); h++) {
			// Se estiver fora de ordem...
			if (strcmp(dados_autor[h].nome_autor, dados_autor[h + 1].nome_autor) > 0) {
				// ... troca de posicao
				*tmp = dados_autor[h];
				dados_autor[h] = dados_autor[h + 1];
				dados_autor[h + 1] = *tmp;
			}
		}
		printf("%i | %s | %i/%i/%i ", dados_autor[g].id_autor, dados_autor[g].nome_autor, dados_autor[g].nascimento_autor[0], dados_autor[g].nascimento_autor[1], dados_autor[g].nascimento_autor[2]);
	}
	return;
}
void ordernar_autores_por_nascimento(dados_autor_t* dados_autor, int quantidade_autores) {

	int i, j;
	dados_autor_t* tmp = 0;

	for (i = 0; i < (quantidade_autores - 1); i++) {
		for (j = 0; j < (quantidade_autores - 1); j++) {
			// Se estiver fora de ordem...
			if (dados_autor[j].nascimento_autor, dados_autor[j + 1].nascimento_autor) {
				// ... troca de posicao
				*tmp = dados_autor[j];
				dados_autor[j] = dados_autor[j + 1];
				dados_autor[j + 1] = *tmp;
			}
		}
		printf("%i | %s | %i/%i/%i ", dados_autor[i].id_autor, dados_autor[i].nome_autor, dados_autor[i].nascimento_autor[0], dados_autor[i].nascimento_autor[1], dados_autor[i].nascimento_autor[2]);
	}
	return;
}

//Main:

int main(int agrc, char** argv) {

	dados_livros_t* dados_livros = 0;
	dados_autor_t* dados_autor = 0;
	FILE* arquivo_autores, * arquivo_livros;


	int opcao, opcao2, opcao3, quantidade_livros = 0, quantidade_autores = 0;
	char lixo;


	printf("BEM VINDO A LIVRARIA IMPERIO DOS LIVROS");

	do
	{
		printf("\nEscolha a opcao ao qual deseja acessar:");
		printf("\n-----------------------------------------------------");
		printf("\n1 | CADASTRAR AUTOR(S)\n2 | CADASTRAR LIVRO(S)");
		printf("\n-----------------------------------------------------\n");
		printf("3 | IMPRIMIR O CADASTRO DO(S) LIVRO(S)\n4 | IMPRIMIR O CADASTRO DO(S) AUTOR(S)");
		printf("\n-----------------------------------------------------");
		printf("\n0 | SAIR\nR:");
		scanf("%i%c", &opcao, &lixo);

		printf("Se desejar finalizar, basta apenas sair (0)");

		switch (opcao) {
		case 1:

			funcao_cadastrar_autores(dados_autor, quantidade_autores);

			break;
		case 2:
			funcao_cadastrar_livros(dados_livros, quantidade_livros);
			break;
		case 3:

			printf("\n\n1 | IMPRIMIR OS LIVROS POR ORDEM DE CODIGO\n");
			printf("2 | IMPRIMIR OS LIVROS POR ORDEM DE TITULO\n");
			printf("3 | IMPRIMIR OS LIVROS POR ORDEM DE LANCAMENTO\n");
			printf("0 | SAIR\nR: ");
			scanf("%i%c", &opcao2, &lixo);

			do
			{
				switch (opcao2)
				{
				case 1:
					ordernar_livros_por_codigo;
					break;
				case 2:
					ordernar_livros_por_titulo;
					break;
				case 3:
					ordernar_livros_por_lancamento;
					break;
				case 0:
					break;
				default:
					printf("OPCAO INVALIDA");
					break;
				}
			} while (opcao2 != 0);
			break;
		case 4:

			printf("\n\n1 | IMPRIMIR OS AUTORES POR ORDEM DE ID\n");
			printf("2 | IMPRIMIR OS AUTORES POR ORDEM DE NOME\n");
			printf("3 | IMPRIMIR OS AUTORES POR ORDEM DE NASCIMENTO\n");
			printf("0 | SAIR\nR: ");
			scanf("%i%c", &opcao3, &lixo);

			do
			{
				switch (opcao3)
				{
				case 1:
					ordernar_autores_por_id;;
					break;
				case 2:
					ordernar_autores_por_nome;
					break;
				case 3:
					ordernar_autores_por_nascimento;
					break;
				case 0:
					break;
				default:
					printf("OPCAO INVALIDA");
					break;
				}
			} while (opcao3 != 0);
			break;
		case 0:
			break;
		default:
			printf("OPCAO INVALIDA");
			break;
		}

	} while (opcao != 0);

	funcao_arquivo_autores;
	funcao_arquivo_livros;
	funcao_arquivo_associar;

	return SUCESSO;
}

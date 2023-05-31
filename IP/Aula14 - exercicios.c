//Aula 14- Exercício 1 

#define SUCESSO 0
#define TAM_MAX_ARQUIVO (100 + 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int leituraDoArquivo(FILE* ArquivoLeitura) {

	int primeiraPosicao, Numlinhas = 0;
	char charParaLinha;

	primeiraPosicao = ftell(ArquivoLeitura);
	ArquivoLeitura = fopen("ArquivoLeitura.txt", "r");

	fseek(ArquivoLeitura, 0, SEEK_SET);

	while (!feof(ArquivoLeitura))
	{
		fscanf(ArquivoLeitura, "%s", &charParaLinha);
		if (charParaLinha == '\n') {
			Numlinhas++;
		}
	}

	fclose(ArquivoLeitura);

	return Numlinhas;
}

int main(int argc, char** argv) {

	char ArquivoPLeitura[TAM_MAX_ARQUIVO];
	int Numlinhas = 0;

	FILE* ArquivoLeitura[TAM_MAX_ARQUIVO];

	printf("Digite o arquivo o qual quer abrir: ");

	fgets(ArquivoPLeitura, TAM_MAX_ARQUIVO, stdin);


	ArquivoLeitura[TAM_MAX_ARQUIVO] = fopen(ArquivoPLeitura, "r");

	if (ArquivoPLeitura[TAM_MAX_ARQUIVO] == NULL)
	{
		printf("\n\nFalha ao abrir, tente novamente\n");
	}
	else
	{
		Numlinhas = leituraDoArquivo(ArquivoLeitura[TAM_MAX_ARQUIVO]);
		fclose(ArquivoLeitura[TAM_MAX_ARQUIVO]);
	}

	printf("Seu arquivo possui %d linhas", &Numlinhas);


	return SUCESSO;
}


//Aula 14- Exercício 1 (binario)

#define SUCESSO 0
#define TAM_MAX_ARQUIVO (100 + 1)

#define VERDADEIRO (1==1)
#define FALSO (!VERDADEIRO)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef long int bool_t;

int leituraDoArquivo(FILE* ArquivoLeitura) {

	int primeiraPosicao, Numlinhas = 0;
	char charParaLinha;

	bool_t ulimaPosicaoArquivo = FALSO;
	bool_t leuAlgoArquivo = 0;

	primeiraPosicao = ftell(ArquivoLeitura);
	ArquivoLeitura = fopen("ArquivoLeitura.txt", "rb");

	fseek(ArquivoLeitura, 0, SEEK_SET);


	for(;;)
		if (fread(&charParaLinha, sizeof(char), 1, ArquivoLeitura) != 1) {

			if ((leuAlgoArquivo)) Numlinhas++;
			break;
		}
	

	else {
		leuAlgoArquivo = VERDADEIRO;
		if (charParaLinha == '\n') {
			Numlinhas++;
		}
		else {
		
		}
	}

	fclose(ArquivoLeitura);

	return Numlinhas;
}

int main(int argc, char** argv) {

	char ArquivoPLeitura[TAM_MAX_ARQUIVO];
	int Numlinhas = 0;

	FILE* ArquivoLeitura[TAM_MAX_ARQUIVO];

	printf("Digite o arquivo o qual quer abrir: ");

	fgets(ArquivoPLeitura, TAM_MAX_ARQUIVO, stdin);


	ArquivoLeitura[TAM_MAX_ARQUIVO] = fopen(ArquivoPLeitura, "rb");

	if (ArquivoPLeitura[TAM_MAX_ARQUIVO] == NULL)
	{
		printf("\n\nFalha ao abrir, tente novamente\n");
	}
	else
	{
		Numlinhas = leituraDoArquivo(ArquivoLeitura[TAM_MAX_ARQUIVO]);
		fclose(ArquivoLeitura[TAM_MAX_ARQUIVO]);
	}

	printf("Seu arquivo possui %d linhas", &Numlinhas);


	return SUCESSO;
}

//Aula 14 - Exercício 2

#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS	

#define TAM_MAX_ARQ ( 100 + 1 ) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_caracter_arquivo(FILE* ArquivoLeitura) {

	int primeiraPosicao;
	char charParaLinha;

	ArquivoLeitura = fopen("ArquivoLeitura.txt", "r");

	primeiraPosicao = ftell(ArquivoLeitura);
	fseek(ArquivoLeitura, 0, SEEK_SET);

	while (!feof(ArquivoLeitura))
	{
		fscanf(ArquivoLeitura, "%c", &charParaLinha);
		if ((charParaLinha == ' ') || (charParaLinha == '\n'));
		charParaLinha++;
		
	}

	fclose(ArquivoLeitura);
	return charParaLinha;
}


int main(int argc, char** argv) {

	char DigitadopeloUsuario[TAM_MAX_ARQ], charParaLinha;
	FILE* ArquivoLeitura;

	printf("Digite o arquivo o qual quer abrir :  ");
	fgets(DigitadopeloUsuario,TAM_MAX_ARQ, stdin);

	ArquivoLeitura = fopen(DigitadopeloUsuario, "r");

	if (DigitadopeloUsuario == NULL);
	{
		printf("\n\nErro, arquivo nao encontrado ou nao existente");
	}
	if(DigitadopeloUsuario != NULL){

		charParaLinha = conta_caracter_arquivo(ArquivoLeitura);
	}

	fclose(ArquivoLeitura);

	return SUCESSO;
}



//Aula 14 - Exercício 2 (binario)

#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS	

#define TAM_MAX_ARQ ( 100 + 1 ) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_caracter_arquivo(FILE* ArquivoLeitura) {

	int primeiraPosicao;
	char charParaLinha;

	ArquivoLeitura = fopen("ArquivoLeitura.txt", "rb");

	primeiraPosicao = ftell(ArquivoLeitura);
	fseek(ArquivoLeitura, 0, SEEK_SET);

	for (;;) {
		if (fread(&charParaLinha, sizeof(char), 1, ArquivoLeitura) != 1) 
		
			break;
		else {
			if ((charParaLinha == '\n') || (charParaLinha == '\r') || (charParaLinha == ' '));
			charParaLinha++;
		}
	}

	fclose(ArquivoLeitura);
	return charParaLinha;
}


int main(int argc, char** argv) {

	char DigitadopeloUsuario[TAM_MAX_ARQ], charParaLinha;
	FILE* ArquivoLeitura;

	printf("Digite o arquivo o qual quer abrir :  ");
	fgets(DigitadopeloUsuario,TAM_MAX_ARQ, stdin);

	ArquivoLeitura = fopen(DigitadopeloUsuario, "rb");

	if (DigitadopeloUsuario == NULL);
	{
		printf("\n\nErro, arquivo nao encontrado ou nao existente");
	}
	if(DigitadopeloUsuario != NULL){

		charParaLinha = conta_caracter_arquivo(ArquivoLeitura);
	}

	fclose(ArquivoLeitura);

	return SUCESSO;
}


//Aula 14 - Exercício 3

#define SUCESSO 0
#define _CRT_SECURE_NO_WARNINGS
#define TAM_MAX_ARQ (100+1)
#define MAX_NOME (100 + 1)
#define QUANTIDADE_NOTAS (2)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InfoAlunos_s {

	char nome[MAX_NOME];
	float notas[QUANTIDADE_NOTAS];

};

typedef struct InfoAluno_s InfoAlunos_t;

void funcao_pegar_notas(FILE* ArquivoUsuario) {

	int primeiraposicao = 0, nota1 = 0, nota2 = 0, quantidadeAlunos;
	char DadosAlunos[TAM_MAX_ARQ], nome[MAX_NOME];

	struct InfoAlunos_t;

	ArquivoUsuario = fopen(DadosAlunos, "r");
	if (ArquivoUsuario == NULL) {
		fprintf(stderr, "Erro, arquivo %s nao encontrado ou nao existente. Tente novamente\n", &DadosAlunos);

		return;
	}

	fscanf(ArquivoUsuario, "%d\n", &nRegistros);

	primeiraposicao = ftell(ArquivoUsuario);

	ArquivoUsuario = fopen(DadosAlunos, "r");

	fseek(ArquivoUsuario, 0, SEEK_SET);


	fgets(nome, MAX_NOME, ArquivoUsuario);


	fscanf(ArquivoUsuario, "%f\n", &nota1);
	fscanf(ArquivoUsuario, "%f\n", &nota2);


	fclose(ArquivoUsuario);
}

int calcular_media_alunos(float num1, float num2, float media) {

	num1 = 0;
	num2 = 0;

	return (num1 + num2) / QUANTIDADE_NOTAS == media;

}

int main(int argc, char** argv) {

	FILE* ArquivoUsuario;
	struct InfoAlunos_t;

	char DadosAlunos[TAM_MAX_ARQ];
	float num1, num2, media;



	printf("Digite o arquivo o qual quer abrir:\n\n");
	fgets(DadosAlunos, TAM_MAX_ARQ, stdin);

	ArquivoUsuario = fopen(DadosAlunos, "r");

	if (DadosAlunos[TAM_MAX_ARQ] == NULL);
	{
		printf("Erro, arquivo nao encontrado ou nao existente. Tente novamente\n");
	}
	{

		do {



			calcular_media_alunos(num1, num2, media);

		} while (!feof(ArquivoUsuario));

		return SUCESSO;
	}
}
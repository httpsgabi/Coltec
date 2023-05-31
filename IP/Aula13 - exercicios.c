//Aula 13 - IP - Structs
//Exercício 1 

#define SUCESSO 0 
#define TAM_MAX_NOME_E_CURSO (50 + 1)

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef struct dados_aluno_s { 

	char nome[TAM_MAX_NOME_E_CURSO];
	char curso[TAM_MAX_NOME_E_CURSO];
	int idade;

} dados_aluno ;


int main(int argc, char ** argv) {

	dados_aluno d1;

	printf("Digite seu nome :\n");
	fgets(d1.nome, TAM_MAX_NOME_E_CURSO, stdin);
	printf("Digite seu curso :\n");
	fgets(d1.curso, TAM_MAX_NOME_E_CURSO, stdin);
	printf("Digite sua idade : \n", d1.idade);
	scanf("%i", &d1.idade);
		
	printf("Seu nome eh :");
	fputs(d1.nome, stdout);
	printf("Seu curso eh :");
	fputs(d1.curso, stdout);
	printf("Seu nome eh : %i", d1.idade);

	return Sucesso;
}





//Aula 13 - IP - Structs
//Exercício 2 

#define Sucesso 0 
#define TAM_MAX_NOME_E_CURSO (50 + 1)
#define NUMERO_PROVAS 3

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef struct dados_aluno_s { 

	char nome[TAM_MAX_NOME_E_CURSO];
	char curso[TAM_MAX_NOME_E_CURSO];
	int idade;
	float notas_provas[NUMERO_PROVAS];

} dados_aluno ;


int main(int argc, char ** argv) {

	dados_aluno d1;
	float media_provas = 0;

	printf("Digite seu nome :\n");
	fgets(d1.nome, TAM_MAX_NOME_E_CURSO, stdin);
	printf("Digite seu curso :\n");
	fgets(d1.curso, TAM_MAX_NOME_E_CURSO, stdin);
	printf("Digite sua idade : \n", d1.idade);
	scanf("%i", &d1.idade);
		
	printf("Seu nome eh :");
	fputs(d1.nome, stdout);
	printf("Seu curso eh :");
	fputs(d1.curso, stdout);
	printf("Seu nome eh : %i", d1.idade);

	for (int i = 0; i < NUMERO_PROVAS; i++) {

		printf("\nDigite a nota da prova %i:", i);
		scanf("%f", &d1.notas_provas[i]);

		media_provas += d1.notas_provas[i];
	}

	media_provas = media_provas / NUMERO_PROVAS;

	if (media_provas >= 60) {
		printf("A sua media das provas foi : %f , e voce foi aprovado", media_provas);
	}
	else if (media_provas <= 60) {
		printf("A sua media das provas foi : %f , e voce nao foi aprovado", media_provas);
	}
		
	return Sucesso;
}



//Aula 13 - IP - Structs
//Exercício 3

#define SUCESSO 0 
#define TAM_MAX_NOME_E_CURSO (50 + 1)
#define NUMERO_PROVAS 3

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef struct dados_aluno_s {

	char nome[TAM_MAX_NOME_E_CURSO];
	char curso[TAM_MAX_NOME_E_CURSO];
	int idade;
	float notas_provas[NUMERO_PROVAS];
	float media_provas = 0;
	float media_turma = 0;

} dados_aluno;


int main(int argc, char** argv) {

	dados_aluno* d1;
	int numero_alunos = 0;

	printf("Digite o numero de alunos :");
	scanf("%i", &numero_alunos);

	d1 = (dados_aluno*)calloc(numero_alunos, sizeof(dados_aluno));


	for (int n = 0; n < numero_alunos; n++) {


		printf("\n\nDigite seu nome :");
		fgets(d1[n].nome, TAM_MAX_NOME_E_CURSO, stdin);
		scanf("%s", &d1[n].nome);
		printf("Digite seu curso :");
		fgets(d1[n].curso, TAM_MAX_NOME_E_CURSO, stdin);
		scanf("%s", &d1[n].curso);
		printf("Digite sua idade : ", d1[n].idade);
		scanf("%i", &d1[n].idade);

		printf("\n\nSeu nome eh :");
		fputs(d1[n].nome, stdout);
		printf("\nSeu curso eh :");
		fputs(d1[n].curso, stdout);
		printf("\nSua idade eh : %i", d1[n].idade);

	}

	for (int i = 0; i < NUMERO_PROVAS; i++) {

		printf("\nDigite a nota da prova %i:", i);
		scanf("%f", &d1[i].notas_provas[i]);

		d1[i].media_provas += d1[i].notas_provas[i];
	}

	d1->media_provas = d1->notas_provas[NUMERO_PROVAS] / NUMERO_PROVAS;

	if (d1->media_provas >= 60) {
		printf("A sua media das provas foi : %f , e voce foi aprovado", d1->media_provas);
	}
	else if (d1->media_provas <= 60) {
		printf("A sua media das provas foi : %f , e voce nao foi aprovado", d1->media_provas);
	}

	d1->media_provas += d1->media_turma;

	printf("\n\nA media da turma foi: %f ", d1->media_turma );
	free(d1);

	return SUCESSO;
}

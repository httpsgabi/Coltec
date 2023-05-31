#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define SUCESSO 0
#define TAM_MAX_NOME (40 + 1)
#define NUM_PRE_ING (25)
#define NUM_PRE_REC (5)
#define NUM_MAX_ING (15)
#define PRECO_BASE_REC (20)

typedef uint16_t counter;

typedef struct modulo_ingredientes {

	int codigo;
	char nome[TAM_MAX_NOME];
	time_t data_de_criação;
	float preco;
	int quantidade;

} mod_ingredientes;

typedef struct modulo_receitas {

	int codigo;
	char nome[TAM_MAX_NOME];
	time_t data_de_criação;
	float preco;
	mod_ingredientes ingredientes_receita[NUM_MAX_ING];

} mod_receitas;


//Funções principais;
void pre_cad(void);
void cad_ing(void);
void cad_rec(void);
void list_ing(int);
void list_rec(int);

//Funções secundárias;
int save_num_ing(int);
int save_num_rec(int);
void ordena_ing(mod_ingredientes* , int, int);
void print_ing(mod_ingredientes*, int);
void ordena_rec(mod_receitas*, int, int);
void print_rec(mod_receitas*, int);



int main(int argc, char** argv) {
	int type = 2, user = 0, user_answer = 0;

	pre_cad();

	printf("BEM VINDO A PIZARIA VECTOR\n\nSelecione a opcao que corresponde ao seu nivel de acesso:\n");
	printf("1\tCliente\n2\tFuncionario\n");
	scanf("%i", &user);

	if (user == 1)
	{

		printf("\n\nOla querido cliente.");


		do{

			printf("\nSelecione o que voce deseja fazer : \n\n");
			printf("1\tCadastrar nova receita\n2\tListar Ingredientes\n3\tListar Receitas\n");
			scanf("%i", &user_answer);


			switch (user_answer)
			{
			case 1:
				cad_rec();

				break;
			case 2:
				printf("\nSelecione a ordem em que os ingredientes devem ser listados:\n");
				printf("1\tOrdem de nome\n2\tOrdem de codigo\n3\tOrdem de preco\n4\tOrdem de criacao\n");
				scanf("%i", type);

				if (type > 0 && type <= 4)
				{
					list_ing(type);
				}
				else {
					printf("\nERRO: ORDEM INVALIDA\n");
				}

				break;
			case 3:
				printf("\nSelecione a ordem em que as receitas devem ser listadas:\n");
				printf("1\tOrdem de nome\n2\tOrdem de codigo\n3\tOrdem de preco\n4\tOrdem de criacao\n");
				scanf("%i", type);

				if (type > 0 && type <= 4)
				{
					list_rec(type);
				}
				else {
					printf("\nERRO: ORDEM INVALIDA\n");
				}

				break;
			default:
				break;
			}

		} while (user_answer != 0);
	}
	else if (user == 2) {

		printf("\n\nOla funcionario.\n");

		do
		{
			printf("\nSelecione o que voce deseja fazer : \n\n");
			printf("0\tSair do programa\n1\tCadastrar nova receita\n2\tCadastrar novo ingrediente\n3\tListar Ingredientes\n4\tListar Receitas\n");
			scanf("%i", &user_answer);

			switch (user_answer)
			{
			case 1:
				cad_rec();

				break;
			case 2:
				cad_ing();

				break;
			case 3:
				printf("\nSelecione a ordem em que os ingredientes devem ser listados:\n");
				printf("1\tOrdem de nome\n2\tOrdem de codigo\n3\tOrdem de preco\n4\tOrdem de criacao\n");
				scanf("%i", &type);

				if (type > 0 && type <= 4)
				{
					list_ing(type);
				}
				else {
					printf("\nERRO: ORDEM INVALIDA\n");
				}

				break;
			case 4:
				printf("\nSelecione a ordem em que as receitas devem ser listadas:\n");
				printf("1\tOrdem de nome\n2\tOrdem de codigo\n3\tOrdem de preco\n4\tOrdem de criacao\n");
				scanf("%i", &type);

				if (type > 0 && type <= 4)
				{
					list_rec(type);
				}
				else {
					printf("\nERRO: ORDEM INVALIDA\n");
				}

				break;
			default:
				break;
			}

		} while (user_answer != 0);
	}
	

	return SUCESSO;
}


/*Função que cadastra as receitas e ingredientes pré - existentes uma única vez;
* OBS: Ficou bastantante grande esse módulo pois precisei inicializar e cadastrar
* todas as receitas e ingredientes que serão pré-existentes no programa. 
*/
void pre_cad(void) {

	FILE* arquivo_ing, *arquivo_rec;
	mod_ingredientes* ingredientes;
	mod_receitas *receitas;
	counter i, j, k, l, m, n;
	time_t buffer_time;
	float buffer_preco;


	//Gera um arquivo único contendo os ingredientes.
	arquivo_ing = fopen("ing_restaurante.bin", "rb");
	arquivo_rec = fopen("rec_restaurante.bin", "rb");

	if (arquivo_ing == NULL)
	{
		arquivo_ing = fopen("ing_restaurante.bin", "wb");

		ingredientes = (mod_ingredientes*)calloc(NUM_PRE_ING , sizeof(mod_ingredientes));


		memcpy(ingredientes[0].nome, "Mussarela", 10);
		ingredientes[0].preco = 0.03;

		memcpy(ingredientes[1].nome, "Calabresa", 10);
		ingredientes[1].preco = 0.02;

		memcpy(ingredientes[2].nome, "Presunto", 9);
		ingredientes[2].preco = 0.024;

		memcpy(ingredientes[3].nome, "Parmesao", 9);
		ingredientes[3].preco = 0.055;

		memcpy(ingredientes[4].nome, "Bacon", 6);
		ingredientes[4].preco = 0.04;

		memcpy(ingredientes[5].nome, "Atum", 5);
		ingredientes[5].preco = 0.4;

		memcpy(ingredientes[6].nome, "Cebola", 7);
		ingredientes[6].preco = 0.02;

		memcpy(ingredientes[7].nome, "Tomate", 7);
		ingredientes[7].preco = 0.01;

		memcpy(ingredientes[8].nome, "Frango", 7);
		ingredientes[8].preco = 0.012;

		memcpy(ingredientes[9].nome, "Milho", 6);
		ingredientes[9].preco = 0.01;

		memcpy(ingredientes[10].nome, "Tomate", 7);
		ingredientes[10].preco = 0.01;

		memcpy(ingredientes[11].nome, "Ervilha", 8);
		ingredientes[11].preco = 0.012;

		memcpy(ingredientes[12].nome, "Champignon", 11);
		ingredientes[12].preco = 0.035;

		memcpy(ingredientes[13].nome, "Requeijao", 10);
		ingredientes[13].preco = 0.04;

		memcpy(ingredientes[14].nome, "Palmito", 8);
		ingredientes[14].preco = 0.065;

		memcpy(ingredientes[15].nome, "Cheddar", 8);
		ingredientes[15].preco = 0.032;

		memcpy(ingredientes[16].nome, "Manjericao", 11);
		ingredientes[16].preco = 0.02;

		memcpy(ingredientes[17].nome, "Molho de tomate", 5);
		ingredientes[17].preco = 0.012;

		memcpy(ingredientes[18].nome, "Almondegas", 11);
		ingredientes[18].preco = 0.02;

		memcpy(ingredientes[19].nome, "Azeitona", 9);
		ingredientes[19].preco = 0.024;

		memcpy(ingredientes[20].nome, "Pepperoni", 10);
		ingredientes[20].preco = 0.08;

		memcpy(ingredientes[21].nome, "Molho de pimenta", 17);
		ingredientes[21].preco = 0.025;

		memcpy(ingredientes[22].nome, "Molho barbecue", 15);
		ingredientes[22].preco = 0.02;

		memcpy(ingredientes[23].nome, "Molho verde", 12);
		ingredientes[23].preco = 0.01;

		memcpy(ingredientes[24].nome, "Pimentao", 9);
		ingredientes[24].preco = 0.01;


		for ( i = 0; i < NUM_PRE_ING; i++)
		{
			ingredientes[i].codigo = (i + 1);
		}

		for (j = 0; j < NUM_PRE_ING; j++)
		{

			 time(&buffer_time);
			 ingredientes[j].data_de_criação = buffer_time;

		}

		fwrite(ingredientes, sizeof(mod_ingredientes), NUM_PRE_ING, arquivo_ing);

		
		fclose(arquivo_ing);

		save_num_ing(NUM_PRE_ING);


	//Gera um arquivo único contendo as receitas.
		arquivo_rec = fopen("rec_restaurante.bin", "wb");

		receitas = (mod_receitas*)calloc(NUM_PRE_ING , sizeof(mod_receitas));


		memcpy(receitas[0].nome, "Tradicional", 12);
		memcpy(receitas[1].nome, "Bacon", 6);
		memcpy(receitas[2].nome, "Calabresa", 10);
		memcpy(receitas[3].nome, "Marguerita", 11);
		memcpy(receitas[4].nome, "Vegetariana", 12);
		
		for (k = 0; k < NUM_PRE_REC; k++)
		{
			receitas[k].codigo = (k + 1);
		}

		for (l = 0; l < NUM_PRE_REC; l++)
		{

			time(&buffer_time);
			receitas[l].data_de_criação = buffer_time;

		}


		receitas[0].ingredientes_receita[0] = ingredientes[0];
		receitas[0].ingredientes_receita[0].quantidade = 100;
		receitas[0].ingredientes_receita[1] = ingredientes[2];
		receitas[0].ingredientes_receita[1].quantidade = 50;
		receitas[0].ingredientes_receita[2] = ingredientes[7];
		receitas[0].ingredientes_receita[2].quantidade = 20;
		receitas[0].ingredientes_receita[3] = ingredientes[17];
		receitas[0].ingredientes_receita[3].quantidade = 50;

		receitas[1].ingredientes_receita[0] = ingredientes[0];
		receitas[1].ingredientes_receita[0].quantidade = 100;
		receitas[1].ingredientes_receita[1] = ingredientes[2];
		receitas[1].ingredientes_receita[1].quantidade = 50;
		receitas[1].ingredientes_receita[2] = ingredientes[4];
		receitas[1].ingredientes_receita[2].quantidade = 30;
		receitas[1].ingredientes_receita[3] = ingredientes[17];
		receitas[1].ingredientes_receita[3].quantidade = 50;

		receitas[2].ingredientes_receita[0] = ingredientes[0];
		receitas[2].ingredientes_receita[0].quantidade = 100;
		receitas[2].ingredientes_receita[1] = ingredientes[1];
		receitas[2].ingredientes_receita[1].quantidade = 50;
		receitas[2].ingredientes_receita[2] = ingredientes[17];
		receitas[2].ingredientes_receita[2].quantidade = 50;

		receitas[3].ingredientes_receita[0] = ingredientes[0];
		receitas[3].ingredientes_receita[0].quantidade = 100;
		receitas[3].ingredientes_receita[1] = ingredientes[2];
		receitas[3].ingredientes_receita[1].quantidade = 50;
		receitas[3].ingredientes_receita[2] = ingredientes[3];
		receitas[3].ingredientes_receita[2].quantidade = 80;
		receitas[3].ingredientes_receita[3] = ingredientes[7];
		receitas[3].ingredientes_receita[3].quantidade = 30;
		receitas[3].ingredientes_receita[4] = ingredientes[16];
		receitas[3].ingredientes_receita[4].quantidade = 30;
		receitas[3].ingredientes_receita[5] = ingredientes[17];
		receitas[3].ingredientes_receita[5].quantidade = 50;

		receitas[4].ingredientes_receita[0] = ingredientes[0];
		receitas[4].ingredientes_receita[0].quantidade = 100;
		receitas[4].ingredientes_receita[1] = ingredientes[7];
		receitas[4].ingredientes_receita[1].quantidade = 30;
		receitas[4].ingredientes_receita[2] = ingredientes[9];
		receitas[4].ingredientes_receita[2].quantidade = 40;
		receitas[4].ingredientes_receita[3] = ingredientes[14];
		receitas[4].ingredientes_receita[3].quantidade = 40;
		receitas[4].ingredientes_receita[4] = ingredientes[17];
		receitas[4].ingredientes_receita[4].quantidade = 50;
		receitas[4].ingredientes_receita[5] = ingredientes[19];
		receitas[4].ingredientes_receita[5].quantidade = 30;


		for (m = 0;  m < NUM_PRE_REC; m++)
		{
			
			buffer_preco = 0;

			for (n = 0; n < NUM_MAX_ING; n++)
			{
				buffer_preco += (receitas[m].ingredientes_receita[n].quantidade * receitas[m].ingredientes_receita[n].preco);
			}

			receitas[m].preco = PRECO_BASE_REC + buffer_preco;

		}



		fwrite(receitas, sizeof(mod_receitas), NUM_PRE_REC, arquivo_rec);
		

		save_num_rec(NUM_PRE_REC);

		free(ingredientes);
		free(receitas);
		fclose(arquivo_rec);
	}		



	fclose(arquivo_ing);
	fclose(arquivo_rec);
	return;
}




//Função que permite ao usuário cadastrar novos ingredientes;
void cad_ing(void) {

	FILE* arquivo_ing;
	int n;
	counter a;
	mod_ingredientes * buf_ingredientes;
	time_t buffer_time;

	printf("Voce deseja cadastrar quantos ingredientes: ");
	scanf("%i", &n);

	buf_ingredientes = (mod_ingredientes*)calloc(n, sizeof(mod_ingredientes));

	
	arquivo_ing = fopen("ing_restaurante.bin", "ab");



	for (a = 0; a < n; a++)
	{
		printf("\n\nIngrediente %i\n", a);


		printf("Digite o nome do ingrediente: ");
		getchar();
		fgets(buf_ingredientes[a].nome, TAM_MAX_NOME, stdin);

		printf("\nDigite o codigo do ingrediente (obs: nao digite um codigo ja existente) : ");
		scanf("%i", &buf_ingredientes[a].codigo);

		printf("\nDigite o preco do ingrediente por grama: ");
		scanf("%f", &buf_ingredientes[a].preco);

		time(&buffer_time);
		buf_ingredientes[a].data_de_criação = buffer_time;

	}

	fwrite(buf_ingredientes, sizeof(mod_ingredientes), n, arquivo_ing);

	free(buf_ingredientes);
	fclose(arquivo_ing);

	save_num_ing(n);

	return;
}




//Função que permite ao usuário cadastrar novas receitas;
void cad_rec(void) {
	int n, num_ing = 0, buf_cod;
	FILE* arquivo_rec, *arquivo_ing;
	mod_receitas* buf_receitas;
	mod_ingredientes* buf_ing;
	counter a, b = 1, c, e; 
	time_t buffer_time;
	float buffer_preco;

	num_ing = save_num_ing(0);
	arquivo_ing = fopen("ing_restaurante.bin", "rb");
	buf_ing = (mod_ingredientes*)calloc(num_ing, sizeof(mod_ingredientes));

	fread(buf_ing, sizeof(mod_ingredientes), num_ing, arquivo_ing);

	fclose(arquivo_ing);




	printf("\nVoce deseja cadastrar quantas receitas: ");
	scanf("%i", &n);

	buf_receitas = (mod_receitas*)calloc(n, sizeof(mod_receitas));

	arquivo_rec = fopen("rec_restaurante.bin", "ab");

	for (a = 0; a < n; a++)
	{
		printf("\n\nReceita %i\n", a);

		printf("Digite o nome da receita: ");
		getchar();
		fgets(buf_receitas[a].nome, TAM_MAX_NOME, stdin);


		printf("\nDigite o codigo da receita (obs: nao digite um codigo ja existente) : ");
		scanf("%i", &buf_receitas[a].codigo);

		time(&buffer_time);
		buf_receitas[a].data_de_criação = buffer_time;



		list_ing(2);
		do
		{
			printf("\nDigite o codigo do ingrediente %i (obs: O codigo digitado deverar ja existir \nou digite 0 para parar de digitar ingredientes) : ", b);
			scanf("%i", &buf_cod);

			for ( c = 0; c < num_ing; c++)
			{
				if (buf_cod == buf_ing[c].codigo)
				{
					buf_receitas[a].ingredientes_receita[b] = buf_ing[c];

					printf("\nDigite a quantidade em gramas desse ingrediente: ");
					scanf("%i", &buf_receitas[a].ingredientes_receita[b].quantidade);
				}
			}


			b++;
		
		} while (buf_cod != 0 && b <= NUM_MAX_ING);



		buffer_preco = 0;

		for (e = 0; e < NUM_MAX_ING; e++)
		{
			buffer_preco += (buf_receitas[a].ingredientes_receita[e].quantidade * buf_receitas[a].ingredientes_receita[e].preco);
		}

		buf_receitas[a].preco = PRECO_BASE_REC + buffer_preco;
	}


	fwrite(buf_receitas, sizeof(mod_receitas), n, arquivo_rec);

	save_num_rec(n);

	free(buf_ing);
	free(buf_receitas);
	fclose(arquivo_rec);

	return;
}




//Função que lista os ingredientes na ordem pedida;
void list_ing(int type) {
	FILE* arquivo_ing;
	mod_ingredientes* buf_ingredientes;
	int num_ing;

	num_ing = save_num_ing(0);

	buf_ingredientes = (mod_ingredientes*)calloc(num_ing, sizeof(mod_ingredientes));
	arquivo_ing = fopen("ing_restaurante.bin", "rb");

	fread(buf_ingredientes, sizeof(mod_ingredientes), num_ing, arquivo_ing);

	ordena_ing(buf_ingredientes, num_ing, type);

	print_ing(buf_ingredientes, num_ing);

	fclose(arquivo_ing);
	
	return;
}




//Função que lista as receitas na ordem pedida;
void list_rec(int type) {
	FILE* arquivo_rec;
	mod_receitas* buf_receitas;
	int num_rec;

	num_rec = save_num_rec(0);

	buf_receitas = (mod_receitas*)calloc(num_rec, sizeof(mod_receitas));
	arquivo_rec = fopen("rec_restaurante.bin", "rb");

	fread(buf_receitas, sizeof(mod_receitas), num_rec, arquivo_rec);

	ordena_rec(buf_receitas, num_rec, type);

	print_rec(buf_receitas, num_rec);

	fclose(arquivo_rec);

	return;


	return;
}




int save_num_ing(int num) {
	FILE* arquivo_num;
	int buffer_num = 0;


	arquivo_num =  fopen("arq_num_ing.bin", "rb");
	if (arquivo_num == NULL)
	{
		arquivo_num = fopen("arq_num_ing.bin", "wb");

		fwrite(&num, sizeof(int), 1, arquivo_num);
	}
	fread(&buffer_num, sizeof(int), 1, arquivo_num);
	fclose(arquivo_num);

	buffer_num += num;

	arquivo_num = fopen("arq_num_ing.bin", "wb");
	fwrite(&buffer_num, sizeof(int), 1, arquivo_num);
	fclose(arquivo_num);

	buffer_num = 0;
	arquivo_num = fopen("arq_num_ing.bin", "rb");
	fread(&buffer_num, sizeof(int), 1, arquivo_num);
	fclose(arquivo_num);

	return buffer_num;
}

int save_num_rec(int num) {
	FILE* arquivo_num;
	int buffer_num = 0;


	arquivo_num = fopen("arq_num_rec.bin", "rb");
	if (arquivo_num == NULL)
	{
		arquivo_num = fopen("arq_num_rec.bin", "wb");

		fwrite(&num, sizeof(int), 1, arquivo_num);
	}
	fread(&buffer_num, sizeof(int), 1, arquivo_num);
	fclose(arquivo_num);

	buffer_num += num;

	arquivo_num = fopen("arq_num_rec.bin", "wb");
	fwrite(&buffer_num, sizeof(int), 1, arquivo_num);
	fclose(arquivo_num);

	buffer_num = 0;
	arquivo_num = fopen("arq_num_rec.bin", "rb");
	fread(&buffer_num, sizeof(int), 1, arquivo_num);
	fclose(arquivo_num);

	return buffer_num;


}


void ordena_ing(mod_ingredientes* ingredientes, int num_ing, int type) {
	counter a, b;
	mod_ingredientes buffer;


	//Ordena por nome;
	if (type == 1)
	{
		
		for (a = 0; a < (num_ing - 1); a++) {
			for (b = 0; b < (num_ing - 1); b++) {
				// Se estiver fora de ordem...
				if (strcmp(ingredientes[b].nome, ingredientes[b + 1].nome) > 0) {
					// ... troca de posicao
					buffer = ingredientes[b];
					ingredientes[b] = ingredientes[b + 1];
					ingredientes[b + 1] = buffer;
				}
			}
		}



	}
	//Ordena por código;
	else if (type == 2) {

		for (a = 0; a < (num_ing - 1); a++) {
			for (b = 0; b < (num_ing - 1); b++) {
				// Se estiver fora de ordem...
				if (ingredientes[b].codigo > ingredientes[b + 1].codigo) {
					// ... troca de posicao
					buffer = ingredientes[b];
					ingredientes[b] = ingredientes[b + 1];
					ingredientes[b + 1] = buffer;
				}
			}
		}

	}
	//Ordena por preço;
	else if (type == 3) {

		for (a = 0; a < (num_ing - 1); a++) {
			for (b = 0; b < (num_ing - 1); b++) {
				// Se estiver fora de ordem...
				if (ingredientes[b].preco > ingredientes[b + 1].preco) {
					// ... troca de posicao
					buffer = ingredientes[b];
					ingredientes[b] = ingredientes[b + 1];
					ingredientes[b + 1] = buffer;
				}
			}
		}

	}
	//Ordena por data;
	else
	{
		for (a = 0; a < (num_ing - 1); a++) {
			for (b = 0; b < (num_ing - 1); b++) {
				// Se estiver fora de ordem...
				if (ingredientes[b].data_de_criação > ingredientes[b + 1].data_de_criação) {
					// ... troca de posicao
					buffer = ingredientes[b];
					ingredientes[b] = ingredientes[b + 1];
					ingredientes[b + 1] = buffer;
				}
			}
		}

	}

	

	return;
}

void print_ing(mod_ingredientes* ing, int num_ing) {
	counter a;

	printf("\n\nLISTA DE INGREDIENTES");
	printf("\n\nCodigo\t\tPreco por grama\t\tNome ing.\n\n");

	for (a = 0; a < num_ing; a++)
	{
		printf("%i\t\t", ing[a].codigo);
		printf("RS%.2f\t\t\t", ing[a].preco);
		fputs(ing[a].nome, stdout);
		printf("\n\n");
		
	}

	return;
}


void ordena_rec(mod_receitas* receitas, int num_rec, int type) {
	counter a, b;
	mod_receitas buffer;
	int type2 = 2;


	//Ordena por nome;
	if (type == 1)
	{

		for (a = 0; a < (num_rec - 1); a++) {
			for (b = 0; b < (num_rec - 1); b++) {
				// Se estiver fora de ordem...
				if (strcmp(receitas[b].nome, receitas[b + 1].nome) > 0) {
					// ... troca de posicao
					buffer = receitas[b];
					receitas[b] = receitas[b + 1];
					receitas[b + 1] = buffer;
				}
			}
		}



	}
	//Ordena por código;
	else if (type == 2) {

		for (a = 0; a < (num_rec - 1); a++) {
			for (b = 0; b < (num_rec - 1); b++) {
				// Se estiver fora de ordem...
				if (receitas[b].codigo > receitas[b + 1].codigo) {
					// ... troca de posicao
					buffer = receitas[b];
					receitas[b] = receitas[b + 1];
					receitas[b + 1] = buffer;
				}
			}
		}

	}
	//Ordena por preço;
	else if (type == 3) {

		for (a = 0; a < (num_rec - 1); a++) {
			for (b = 0; b < (num_rec - 1); b++) {
				// Se estiver fora de ordem...
				if (receitas[b].preco > receitas[b + 1].preco) {
					// ... troca de posicao
					buffer = receitas[b];
					receitas[b] = receitas[b + 1];
					receitas[b + 1] = buffer;
				}
			}
		}

	}
	//Ordena por data;
	else
	{
		for (a = 0; a < (num_rec - 1); a++) {
			for (b = 0; b < (num_rec - 1); b++) {
				// Se estiver fora de ordem...
				if (receitas[b].data_de_criação > receitas[b + 1].data_de_criação) {
					// ... troca de posicao
					buffer = receitas[b];
					receitas[b] = receitas[b + 1];
					receitas[b + 1] = buffer;
				}
			}
		}

	}

	printf("\nSelecione a ordem em que os ingredientes devem ser listadas:\n");
	printf("1\tOrdem de nome\n2\tOrdem de codigo\n3\tOrdem de preco\n4\tOrdem de criacao\n");
	scanf("%i", &type2);

	for ( a = 0; a < num_rec; a++)
	{
		ordena_ing(receitas[a].ingredientes_receita, NUM_MAX_ING, type2);
		
	}

	return;
}

void print_rec(mod_receitas* receitas, int num_rec) {
	counter a, b;

	printf("\n\nLISTA DE RECEITAS\n");


	for (a = 0; a < num_rec; a++)
	{
		printf("\n\n");
		fputs(receitas[a].nome, stdout);
		printf("\n\n");

		for ( b = 0; b < NUM_MAX_ING; b++)
		{
			if (receitas[a].ingredientes_receita[b].quantidade != 0)
			{
				printf("%ig de ", receitas[a].ingredientes_receita[b].quantidade);
				fputs(receitas[a].ingredientes_receita[b].nome, stdout);
				printf("\n");
			}
		}
		printf("Preco: RS%.2f\n", receitas[a].preco);
	}

	return;
}
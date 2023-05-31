//Trabalho de Recuperacao 2021 - IP(Ajuda do Gabriel com erros)

#include <stdio.h>

//Essas 3 bibliotecas são desnecessárias nesse caso
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SUCESSO 0

#define CRT_SECURE_NO_WARNINGS

int main(int agrc, char** argv) {

	int escolhido, quantidade;

	//Em C e na maioria das linguagens de programação, não é recomendado usar variaveis com caracteres especiais ('ç' por exemplo)
	//Por padrão, o compilador de C pode não reconhecer esses caracteres e podem ocorrer alguns erros
	float precoAtual, precoFinal, total, descontoFinal, desconto;
	char pagamento;

	quantidade = 1;

	//Por padrão, as variaveis dos tipos int e float já são definidas como 0. Então, nesse caso, definir como 0 novamente é desnecessário
	precoAtual = 0;
	precoFinal = 0;

	printf("Ola, exibimos o cardapio. Digite o numeral em parenteses para escolher em sequencia o que deseja.\n\n");
	printf("(1) Agua.......................$ 2,00\n");
	printf("(2) Suco de laranja............$ 4,00\n");
	printf("(3) Refrigerante de guarana....$ 4,00\n");
	printf("(4) Refrigerante de cola.......$ 4,00\n\n");
	printf("(5) Pao de queijo..............$ 2,00\n");
	printf("(6) Coxinha....................$ 1,50\n");
	printf("(7) Empada de frango...........$ 1,50\n\n");
	printf("(8) Bombom de chocolate........$ 1,00\n");
	printf("(9) Trident....................$ 1,30\n\n");
	printf("(0) Total\n");

	printf("Digite a opcao:\n");
	scanf("%d", &escolhido);


	/*
	=====================================================================
	C é linguagem de tipagem fraca, ou seja, os tipos não precisam ser seguidos a risca, de forma que é possivel atribuir o valor de um char à uma variavei inteira e fazer esse tipo de verificação if(int == char)

	Dessa forma, quando verificamos:
		if (escolhido == '0') 
	não estamos verificando se escolhido é igual a 0, mas sim se é igual ao valor do caracter '0' em inteiros de acordo com a tabela ASCII (no caso, '0' = 48)
	Por isso, quando vamos comparar inteiros, podemos colocar diretamente o numero, sem necessitar de aspas. Assim
	if (escolhido == 0)

	======================================================================
	Podemos adicionar valores em uma variavel inteira de algumas formas:
		int exemplo;

		exemplo = 10; -> define exemplo como 10. Caso exemplo tenha algum outro valor, ele será trocado por 10;	
		exemplo += 10; -> aumenta 10 no valor de exemplo. Caso a variavel já tenha algum valor, 10 vai ser somado a ele.
		exemplo -= 10; -> subtrai 10 no valor de exemplo. Caso a variavel já tenha algum valor, 10 vai ser subtraido dele.

	É menos usual, mas também podemos fazer operações desse tipo com multiplicação e divisão.

	======================================================================
	Outra coisa é que quando atribuimos valores quebrados a uma variavel do tipo float, as casas decimais devem ser separados por ponto final (.) e não por virgula.
	Pois, separando com virgula, o compilador entende que apenas o primeiro valor que deve ser adicionado. Exemplo:
		
		float t;
		t = 1,5;

		float t1;
		t1 = 1.5;

		printf("t = %f \nt1 = %f", t, t1);

	Nesse caso a saida será:
		t = 1.000000
		t1 = 1.500000
	Pois, como dito antes, o compilador apenas atribui o primeiro valor.

	======================================================================
	Nesse caso, para reduzir a quantidade de if-elses, vc pode usar a estrutura switch-case
	switch (escolhido)
	{
		case 0:
			precoAtual = 0;
			printf("O valor final eh %f\n", precoFinal);
		break;

		case 1:
			precoAtual = 2.00;
		break;

		default:
			printf("NUMERO INVALIDO, DIGITE NOVAMENTE \n");
		break;
		....
	}
	*/

	if (escolhido == 0) 
	{  
		precoAtual += 0; 
		printf("O valor final eh %f\n", precoFinal);
	}
	else if (escolhido == 1) // troca do '1' por apenas 1
	{
		precoAtual += 2; // dessa forma, a operação feita foi -> precoAtual = precoAtual + 2;
	}
	else if (escolhido == 2) 
	{
		precoAtual += 4;
	}
	else if (escolhido == 3) 
	{
		precoAtual += 4;
	}
	else if (escolhido == 4) 
	{
		precoAtual += 4;
	}
	else if (escolhido == 4) 
	{
		precoAtual += 2;
	}
	else if (escolhido == 6) 
	{
		precoAtual += 1.5;
	}
	else if (escolhido == 7) 
	{
		precoAtual += 1.5;
	}
	else if (escolhido == 8) 
	{
		precoAtual += 1;
	}
	else if (escolhido == 9) 
	{
		precoAtual += 1.30;
	}


	do {
		printf("A quantidade eh de: %d\n\n", quantidade);
		printf("Digite mais uma opcao:\n");
		scanf("%d", &escolhido);

		if (escolhido == 0) 
		{
			precoFinal += 0;
			printf("O valor final eh %f\n", precoFinal);
		}
		else if (escolhido == 1) 
		{
			precoAtual += 2;
		}
		else if (escolhido == 2) 
		{ 
			precoFinal += 4;
		}
		else if (escolhido == 3) 
		{
			precoFinal += 4;
		}
		else if (escolhido == 4) 
		{
			precoFinal += 4;
		}
		else if (escolhido == 5)
		{
			precoFinal += 2;
		}
		else if (escolhido == 6) 
		{
			precoFinal += 1.5;
		}
		else if (escolhido == 7) 
		{
			precoFinal += 1.5;
		}
		else if (escolhido == 8) 
		{
			precoFinal += 1;
		}
		else if (escolhido == 9) 
		{
			precoFinal += 1.30;
		}

		total = precoAtual + precoFinal;
		quantidade++;

	} while ((1 <= escolhido) && (9 >= escolhido));
		


	//Preco Final e forma de pagamento
	printf("Digite a forma de pagamento, (d para dinheiro) (c para cartao)");
	scanf("%c", &pagamento);

	if ((pagamento == 'd') || (pagamento == 'D')) {

		desconto = (total * 7 / 100);
		descontoFinal = (total - desconto);

		printf("Preco Normal: %f\n", descontoFinal);
		printf("Com desconto: %f\n", descontoFinal);
	}
	else{
		printf("O valor a ser pago eh de: %f", total);
	}

	// E se o usuário digitar um caracter que não seja nem C nem D?

	return SUCESSO;
}





    
	
	
	
	
	
	
	
	
	
	
	
	










// Trablho de Recuperação 2021 com alguns ajustes e ESTA COMPILANDO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SUCESSO 0

#define CRT_SECURE_NO_WARNINGS

int main(int agrc, char** argv) {

	int escolhido, quantidade;

	float precoAtual, precoFinal, total, descontoFinal, desconto;
	char pagamento, lixo;

	precoAtual = 0.00;
	precoFinal = 0.00;

	printf("Ola, exibimos o cardapio. Digite o numeral em parenteses para escolher em sequencia o que deseja.\n\n");
	printf("(1) Agua.......................$ 2,00\n");
	printf("(2) Suco de laranja............$ 4,00\n");
	printf("(3) Refrigerante de guarana....$ 4,00\n");
	printf("(4) Refrigerante de cola.......$ 4,00\n\n");
	printf("(5) Pao de queijo..............$ 2,00\n");
	printf("(6) Coxinha....................$ 1,50\n");
	printf("(7) Empada de frango...........$ 1,50\n\n");
	printf("(8) Bombom de chocolate........$ 1,00\n");
	printf("(9) Trident....................$ 1,30\n\n");
	printf("(0) Total\n");

	printf("Digite a opcao:\n");
	scanf("%d%c", &escolhido, &lixo);
	printf("Digite a quantidade:\n");
	scanf("%d%c", &quantidade, &lixo);


	switch (escolhido)
	{
	case 0:
		precoAtual += 0*quantidade;
		printf("O valor final eh %f\n", precoFinal + precoAtual);
		break;
	case 1:
		precoAtual += 2 * quantidade;
		break;
	case 2:
		precoAtual += 4 * quantidade;
		break;
	case 3:
		precoAtual += 4 * quantidade;
		break;
	case 4:
		precoAtual += 4 * quantidade;
		break;
	case 5:
		precoAtual += 2 * quantidade;
		break;
	case 6:
		precoAtual += 1.50 * quantidade;
		break;
	case 7:
		precoAtual += 1.50 * quantidade;
		break;
	case 8:
		precoAtual += 1.00 * quantidade;
		break;
	case 9:
		precoAtual += 1.30 * quantidade;
		break;
	default:
		printf("Numero invalido, digite novamente\n");
		break;
	}


	do {
		printf("A quantidade eh de: %d\n\n", quantidade);
		printf("Digite mais uma opcao:\n");
		scanf("%d%c", &escolhido, &lixo);
		printf("Digite a quantidade:\n");
		scanf("%d%c", &quantidade, &lixo);

		total = precoAtual + precoFinal;

		if (escolhido == 0)
		{
			precoFinal += 0;
			printf("O valor final eh %f\n", total);
		}
		else if (escolhido == 1)
		{
			precoAtual += 2;
		}
		else if (escolhido == 2)
		{
			precoFinal += 4;
		}
		else if (escolhido == 3)
		{
			precoFinal += 4;
		}
		else if (escolhido == 4)
		{
			precoFinal += 4;
		}
		else if (escolhido == 5)
		{
			precoFinal += 2;
		}
		else if (escolhido == 6)
		{
			precoFinal += 1.5;
		}
		else if (escolhido == 7)
		{
			precoFinal += 1.5;
		}
		else if (escolhido == 8)
		{
			precoFinal += 1;
		}
		else if (escolhido == 9)
		{
			precoFinal += 1.30;
		}

		total = precoAtual + precoFinal;
	
	} while ((1 <= escolhido) && (9 >= escolhido));


	desconto = (total * 7 / 100);
	descontoFinal = (total - desconto);


	//Preco Final e forma de pagamento
	printf("Digite a formade pagamento em letra minuscula, (d para dinheiro) (c para cartao):\n");
	scanf("%c%c", &pagamento, &lixo);

	switch (pagamento) {
	case 'd':
		printf("Preco Normal: %f\n", total);
		printf("Com desconto: %f\n", descontoFinal);
		break;
	case 'c':
		printf("O valor a ser pago eh de: %f", total);
		break;
	default:
		printf("Letra invalida ou digite em letra minuscula\n");
		break;
	}


	return SUCESSO;
	
		// Comentários para a melhoria do programa:

	//			1°- stdlib, string e math.h não tem nenhuma utilização no caso DESSE PROGRAMA.

	//			2°- Ao invés de usar valores diretamente, criar uma variável com o nome do produto ( ela não será inútil pois o valor pode mudar ao longo do programa,
	//  (exemplo: o valor da coxinha ser alterada para 2.00) e atribuir os valor 

	//			3° -No caso de opções, substituir o if e else if por switch case para o caso de um valor digitado ser diferente de 1 até 9 ( Para simplificação e correção de falhas)

	//			4° -Repetir as opções para o caso do cliente não voltar ate o começo para ter que olhar ( como um exemplo um programa com muitas linhas e etapas).

	//			5° -Adicionar marcações e comentários para que o programa mesmo após muito tempo faça sentido ( Ou seja durável).

	//			6° -Continuar usando [char lixo] para que meu buff nao se atribua a 0.

	//			7° -Ja que separei os produtos por categoria e consequentemente adicionei espaço, tambem poderia adicionar uma nomeclatura para que naoo fique confuso
	//	para o cliente e nem para quem for ler o programa.
}
/*
 ============================================================================
 Name        : Revisao.c
 Author      : João Pedro Mattos Lott
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
int Soma();
float Subtrair();
float Multiplicar();
float Dividir();

int main(void) {
	setbuf(stdout, NULL);
	printf("\n APOSTILA 5 - FUNCOES\n");
	menu();
	return 0;
}

void menu() {
	int op;

	do {
		printf("\n Informe a operacao desejada \n");
		printf("\n 1 - Somar dois numeros inteiros");
		printf("\n 2 - Subtrair um numero real e um inteiro");
		printf("\n 3 - Multiplicar dois numeros reais");
		printf("\n 4 - Dividir um numero real por um inteiro");
		printf("\n 0 - Sair \n");
		scanf("%d", &op);

		switch (op) {
		case 1:
			printf("\n A soma dos valores vale: %d \n", Soma());
			break;
		case 2:
			printf("\n A subtracao dos valores vale: %f \n", Subtrair());
			break;
		case 3:
			printf("\n A multiplicacao dos valores vale: %f \n", Multiplicar());
			break;
		case 4:
			printf("\n A divisao dos valores vale: %f \n", Dividir());
			break;
		case 0:
			break;
		default:
			printf("Opcao Invalida. \n");
			break;
		}
	} while (op != 0);
}

int Soma() {
	int num1, num2, soma;

	printf("\n Somar \n");
	printf("Informe um nuemro inteiro: ");
	scanf("%d", &num1);
	printf("Informe outro numero inteiro: ");
	scanf("%d", &num2);

	soma = num1 + num2;
	return soma;
}

float Subtrair() {
	int num2;
	float num1, subtrair;

	printf("\n Subtrair \n");
	printf("Informe um nuemro real: ");
	scanf("%f", &num1);
	printf("Informe um nuemro inteiro : ");
	scanf("%d", &num2);

	subtrair = num1 - num2;

	return subtrair;
}

float Multiplicar() {
	float num1, num2, multiplicacao;

	printf("\n Multiplicar \n");
	printf("Informe um nuemro real: ");
	scanf("%f", &num1);
	printf("Informe outro nuemro real: ");
	scanf("%f", &num2);

	multiplicacao = num1 * num2;

	return multiplicacao;
}

float Dividir() {
	float num1, divisao;
	int num2;

	printf("\n Dividir \n");
	printf("Informe um nuemro real: ");
	scanf("%f", &num1);
	printf("Informe um nuemro inteiro : ");
	scanf("%d", &num2);

	divisao = num1 / num2;

	return divisao;
}


/*
----------- LISTA REVISAO PONTEIROS --------------

1) O que é um ponteiro? Qual a sua utilização?

Um ponteiro é uma variavel que armazena a localizacao na memoria de uma outra variavel que esteja sendo apontada por ele. Serve para
alocar a memoria dinamicamente, passar parametros por referencia, etc.


2) Quais das seguintes instruções são corretas para declarar um ponteiro?
a) int ponteiro x;
b) int *ponteiro;
c) &int ponteiro;
d) *x;

Letra B


3) Na expressão double *ponteiro, o que é do tipo double?
a) A variável ponteiro
b) O endereço de ponteiro
c) A variável apontada por ponteiro
d) O conteúdo armazenado por ponteiro

Letra C


4) Assumindo que o endereço de numero foi atribuído a um ponteiro ponteiroNumero, quais
das seguintes expressões são verdadeiras?
a) numero == & ponteiroNumero
b) numero == * ponteiroNumero
c) ponteiroNumero == * numero
d) ponteiroNumero == & numero

Letras B e D


5) Assumindo que queremos ler o valor de x, e o endereço de x foi atribuído a px, a
instrução seguinte é correta? Porque?
scanf(“%d”, *px);

É errada, pois o scanf pede o endereco de memoria, para isso teria de colocar sacnf("%d", px) para termos o endereco de memoria

	int x, *px;
	(ponteiro aponta para x)
	px = &x;

	(não *px aponta para o valor, nao para o endereço)
	scanf("%d", *px);

	(armazena a variavel no endereco de memoria de x)
	scanf("%d", &x);


6) Qual é a instrução que deve ser adicionada ao programa seguinte para que ele trabalhe
corretamente?
	int main() {
		int j, *pj;
		*pj = 3;
		return 0;
	}
(Fazer o ponteiro apontar para J)
int main() {
	int j, *pj;
	*pj = &j;
	return 0;
	}


7) Qual o valor das seguintes expressões:
int i = 3, j = 5;
int *p = &i, *q = &j;
a) p == &i
b) *p - *q
c) **&p

a) verdadeiro
b) -2
c) 3

**&p == *p (os comandos * e o & se anulam)


8) Explique a diferença entre
	p++;
	(*p)++;
 	*(p++);

p++ considerando que p é um ponteiro que aponta para uma variavel, apos o comando p++, ele apontara para o proximo
endereco de memoria, exemplo: vetor,
(*p)++, o valor da variavel apontada vai receber +1,
*(p++) o ponteiro vai trazer o que se encontra dentro da memoria, e passa para o proximo endereco de memoria, um valor,
um lixo aleatorio.


9) O significa *(p+10);?

o ponteiro vai apontar para o endereco de memoria e para 10 enderecos a sua frente, dando valores aleatorios encontrados
naquele endereço


10) Se i e j são variáveis inteiras, p e q são ponteiros para inteiros, quais das seguintes
expressões de atribuição são ilegais?
a) p = &i;
b) *q = &j;
c) p = &*&i;
d) i = (*&)j;
e) i = *&*&j;
f) q = &p;
g) i = (*p) ++ + *q;

b) *q = &j;
f) q = &p;


11) Seja a seguinte sequencia de instruções em um programa C
int *pti;
int i = 10;
pti = &i;
Qual afirmativa é falsa?
a) pti armazena o endereço de i
b) *pti é igual a 10
c) ao se executar *pti = 20, i passará a ter o valor de 20
d) ao se alterar de i, *pti será modificado
e) pti é igual a 20

Letra E


12) Diga quais expressoes abaixo são válidas.Considere as declarações:
int vetor[10];
int *ponteiro;
a) vetor = vetor + 2;
b) vetor++;
c) vetor = ponteiro;
d) ponteiro = vetor;
e) ponteiro = vetor+2;

Letra B


13)
#include <stdio.h>
#include <stdlib.h>

char CalculoDaNota(float nota1, float nota2, float nota3,
				int numFaltas, int numAulas, float *pmedia);

int main(void) {
	float nota1, nota2, nota3, media;
	int numFaltas, numAulas;
	char resp;

	printf("\n Media do Aluno \n");

	// Entrada de dados
	printf("Informe a primeira nota: \n");
	scanf("%f", &nota1);
	printf("Informe a segunda nota: \n");
	scanf("%f", &nota2);
	printf("Informe a terceira nota: \n");
	scanf("%f", &nota3);

	printf("Informe o numero de faltas: \n");
	scanf("%d", &numFaltas);
	printf("Informe o numero de aulas da disciplina: \n");
	scanf("%d", &numAulas);

	// Chama a funcao
	resp = CalculoDaNota(nota1, nota2, nota3, numFaltas, numAulas, &media);

	return 0;
}

char CalculoDaNota(float nota1, float nota2, float nota3,
				int numFaltas, int numAulas, float *pmedia){

	*pmedia = (nota1 + nota2 + nota3) / 3;

	if (numFaltas > (numAulas*25)/100) {
		printf("Aluno reprovado por faltas.");
		return 'F';
	} else {
		if (*pmedia >= 60) {
			printf("Aluno aprovado.");
			return 'A';
		} else {
			printf("Aluno reprovado.");
			return 'R';
		}
	}
}
 */


/*
---------- LISTA TEORICA ------------

1) Errado

2) Letra C

3) Errado

4) Errado

5) Letra A

6) Errado

7) Letra B

8)

9) Letra B

10) Letra D

11) Letra B

12) Errado

13) Certo

14) Certo

15) Errado

16) Letra A
*/





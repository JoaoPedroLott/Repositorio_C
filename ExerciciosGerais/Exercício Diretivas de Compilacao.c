/*
 ============================================================================
 Name        : Exercício.c
 Author      : João Pedro Mattos Lott
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define num(a) (a % 2 == 0) ? (1) : (0)
#define triplo(a) (a * 3)
#define soma(a,b) (a + b)
#define troca(a,b)

void par();
void multi();
void somaNum();
void invert();

int main(void) {
	int op;

	do {
		printf("\nEXERCICIOS #DEFINE\n");
		printf("1- Descubra se o número é par.\n");
		printf("2- Calcular o triplo de um valor.\n");
		printf("3- Somar 2 valores.\n");
		printf("4- Inverter valores.\n");
		printf("0- Sair.\n");

		fflush(stdin);
		scanf("%d", &op);

		switch (op) {
		case 1:
			par();
			break;
		case 2:
			multi();
			break;
		case 3:
			somaNum();
			break;
		case 4:
			invert();
			break;
		default:
			printf("\nOpcao Inválida.\n");
			break;
		}
	} while (op != 0);

	return 0;
}

void par() {
	int numero;
	for (;;) {
		if (num(numero) == 0) {
			printf("\n O Número informado é ímpar\n");
			break;
		} else
			printf("\n O número informado é par.\n");
	}
}

void multi() {
	int numero;
	printf("\nO tríplo do número informado vale %d\n", triplo(numero));
}

void somaNum() {
	int numero1, numero2;
	printf("\nA soma dos números informados vale %d\n", soma(numero1, numero2));
}
/*
 1. Escreva uma macro que retorne 1 se o
 número for par e 0 ser o número for ímpar.
 Desative-a após encontrar um número ímpar.


 2. Implemente macros para:
 a) Calcular o triplo de um valor
 b) Somar a e b.

 3. Escreva a macro troca(x, y) que troca o
 conteúdo de seus argumentos inteiros.
 */


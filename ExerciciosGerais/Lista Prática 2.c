/*
 ============================================================================
 Name        : Lista.c
 Author      : João Pedro Lott --- Robert Hanck
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// ALUNOS:
// JOAO PEDRO MATTOS LOTT
// ROBERT HANCK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void recebe();
void concatenar();
void vetores();
void concatenarSemFuncao();
void recebeNum();
void binario();

int main(void) {
	setbuf(stdout, NULL);

	menu();

	return 0;
}

void menu() {
	int op, num;
	char str1[50], str2[50];

	do {
		printf("\n --- LISTA PRATICA 2 --- \n");
		printf("1- Exercício 1\n");
		printf("2- Exercício 1.2\n");
		printf("3- Exercício 2\n");
		printf("4- Exercício 3\n");
		printf("0 - SAIR\n");

		fflush(stdin);
		scanf("%d", &op);

		switch (op) {
		case 1:
			recebe(str1, str2);
			concatenar();
			break;
		case 2:
			recebe(str1, str2);
			concatenarSemFuncao();
			break;
		case 3:
			vetores();
			break;
		case 4:
			recebeNum(num);
			binario();
			break;
		case 0:
			break;
		default:
			printf("\n Opção inválida. \n");
			break;
		}
	} while (op != 0);
}

void recebe(char *str1, char*str2) {

	printf("\n Informe uma string: \n");
	fflush(stdin);
	gets(str1);

	printf("\n Informe outra string: \n");
	fflush(stdin);
	gets(str2);
}

void recebeNum(int num) {

	do {
		printf("\n Infrome um número: \n");
		fflush(stdin);
		scanf("%d", &num);
		if (num <= 0) {
			printf("\n Informe um número positivo.\n");
		}
	} while (num <= 0);
}

void concatenar(char *str1, char*str2) {

	strcat(str1, str2);

	printf("As strings concatenadas são:  %s\n", str1);
}

void concatenarSemFuncao(char *str1, char *str2) {

	printf("As strings concatenadas são:  %s%s\n", str1, str2);
}

void vetores() {
	int i, a, b, c;
	char *vtr1, *vtr2, *vtr3;

	printf("\n Informe o tamanho do primeiro vetor: \n");
	fflush(stdin);
	scanf("%d", &a);
	printf("\n Informe o tamanho do segundo vetor: \n");
	fflush(stdin);
	scanf("%d", &b);

	vtr1 = (char*) malloc(a * sizeof(char));
	vtr2 = (char*) malloc(b * sizeof(char));

	for (i = 0; i < a; i++) {
		printf("\n Informe o primeiro vetor na posicao %d: \n", i);
		fflush(stdin);
		scanf("%c", &vtr1[i]);
	}

	for (i = 0; i < b; i++) {
		printf("\n Informe o segundo vetorna posicao %d: \n", i);
		fflush(stdin);
		scanf("%c", &vtr2[i]);
	}

	c = a + b;

	for (i = 0; i < c; i++) {
		if (strcmp(vtr1[i], vtr2[i]) == 0) {
			vtr3[i] = vtr1[i];
		}
	}

	vtr3 = (char*) malloc(c * sizeof(char));

	for (i = 0; i < c; i++) {
		printf("%c", vtr3[i]);
	}
}

void binario(int num) {
	char valor[50], tmp;
	int cont = 0, divisao, i = 0, cont2;

	while (i != 1) {
		divisao = num / 2;
		if (divisao < 2) {
			i = 1;
			if (num % 2 == 0) {
				valor[cont] = '0';
			} else {
				valor[cont] = '1';
			}
			if (divisao == 0) {
				valor[cont + 1] = '0';
			} else {
				valor[cont + 1] = '1';
			}
			valor[cont + 2] = '\0';
		} else {
			if (num % 2 == 0) {
				valor[cont] = '0';
			} else {
				valor[cont] = '1';
			}
		}
		cont++;
		num = divisao;
	}
	cont2 = strlen(valor) - 1;
	for (cont = 0; cont == cont2 || cont < cont2; cont++) {
		tmp = valor[cont];
		valor[cont] = valor[cont2];
		valor[cont2] = tmp;
		cont2--;
	}
	printf("\n%s", valor);
}

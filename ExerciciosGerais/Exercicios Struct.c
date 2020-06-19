/*
 ============================================================================
 Name        : Exercicios.c
 Author      : João
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char descricao[40];
	int codigo;
	double preco;
	int quantidade;
} produto;

void menu();
void numProdutos();
void cadastro();
void produtosFalta();
void produtosEstoque();

int main(void) {
	setbuf(stdout, NULL);

	produto *pt;
	pt = (produto *) malloc(sizeof(produto));

	numProdutos();
	menu();

	return 0;
}

void menu() {
	int op;

	do {
		printf("\n CADASTRO DE PRODUTOS \n");
		printf("\n 1 - Cadastrar produto.");
		printf("\n 2 - Relatório de produtos em falta.");
		printf("\n 3 - Relatório de produtos em estoque.");
		printf("\n 0 - Sair.");

		fflush(stdin);
		scanf("%d", &op);

		switch (op) {
		case 1:
			cadastro();
			break;
		case 2:
			produtosFalta();
			break;
		case 3:
			produtosEstoque();
			break;
		case 0:
			break;
			// default (Caso o usuario informe um numero inválido ao menu).
		default:
			printf("\n Opção inválida. \n");
			break;
		}
	} while (op != 0);
}



void numProdutos() {
	int *numP;

	do {
		printf("\nDigite o numero de produtos:");
		scanf("%d", &numP);
	} while (*numP <= 0);

	numP = (int*) malloc(sizeof(int));
}

void cadastro(produto *pt, int*numP) {
	int i, valiNome;

	for (i = 0; i <= *numP; i++) {
		do {
			printf("\nNome:");
			fflush(stdin);
			gets(pt[i].descricao);
			valiNome = strcmp(pt->descricao, " ") || strcmp(pt->descricao, "");
		} while (valiNome == 0);

		do {
			printf("\nDigite o codigo:");
			fflush(stdin);
			scanf("%d", &pt[i].codigo);
		} while (pt[i].codigo < 0 || pt[i].codigo > 50);

		do {
			printf("\nDigite o preco do produto:");
			fflush(stdin);
			scanf("%lf", &pt[i].preco);
		} while (pt[i].preco < 0);

		do {
			printf("\nDigite a quantidade do produto:");
			fflush(stdin);
			scanf("%d", &pt[i].quantidade);
		} while (pt[i].quantidade < 0);
	}
}

void produtosFalta(produto *pt, int *numP) {
	int i;

	printf("\nProddutos em falta:\n");
	for (i = 0; i <= *numP; i++) {
		if (pt[i].quantidade = 0) {
			printf("\n %s", pt[i].descricao);
		}
	}
}

void produtosEstoque(produto *pt, int *numP) {
	int i;

	printf("\nProdutos em estoque:\n");
	for (i = 0; i < numP; ++i) {
		if (pt[i].quantidade > 0) {
			printf("\n %s", pt[i].descricao);
		}
	}
}





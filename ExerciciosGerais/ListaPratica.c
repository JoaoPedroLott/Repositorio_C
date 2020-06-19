/*
 ============================================================================
 Name        : ListaPratica.c
 Author      : João
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
void calcularSalario(int dias, float *novoSalario);
void verificarTriangulo(float lado1, float lado2, float lado3,
		char *tipoTriangulo);
int recebeNum();
void multiplica(int numero);
float preencherVendas(float *vendas);
float calcularComissao(float *vendas, float *comissao);
void resultado4();

int main(void) {
	setbuf(stdout, NULL);
	menu();

	return 0;
}

void menu() {
	int op, dias, numero;
	float novoSalario = 0, lado1 = 0, lado2 = 0, lado3 = 0;
	char tipoTriangulo;
	do {
		printf("\n Lista Pratica \n");
		printf("1 Exercício\n");
		printf("2 Exercício\n");
		printf("3 Exercício\n");
		printf("4 Exercício\n");
		printf("0-SAIR");
		scanf("%d", &op);
		switch (op) {
		case 1:
			do {
				printf("Informe o número de dias trabalhados: ");
				scanf("%d", &dias);
			} while (dias <= 0);
			calcularSalario(dias, &novoSalario);
			printf("O valor liquido a receber: %f", novoSalario);
			break;
		case 2:
			do {
				printf("Informe o primeiro lado: ");
				scanf("%f", &lado1);
				printf("Informe o segundo lado: ");
				scanf("%f", &lado2);
				printf("Informe o terceiro lado: ");
				scanf("%f", &lado3);
			} while (lado1 <= 0 && lado2 <= 0 && lado3 <= 0);
			verificarTriangulo(lado1, lado2, lado3, &tipoTriangulo);
			printf("O triangulo vai ser do tipo: %c", tipoTriangulo);
			break;
		case 3:
			printf("Digite 0 para sai");
			do {
				numero = recebeNum();
				multiplica(numero);
			} while (numero != 0);
			break;
		case 4:
			resultado4();
			break;
		case 0:
			break;
		default:
			printf("Opção inválida.");
			break;
		}
	} while (op != 0);
}

void calcularSalario(int dias, float *novoSalario) {

	*novoSalario = (float) dias * 30 * 92 / 100;
}

void verificarTriangulo(float lado1, float lado2, float lado3,
		char *tipoTriangulo) {

	if ((lado1 + lado2) < lado3 || (lado1 + lado3) < lado2
			|| (lado2 + lado3 < lado1)) {
		tipoTriangulo = 'N';
	} else if (lado1 == lado2 == lado3) {
		tipoTriangulo = 'E';
	} else if (lado1 != lado2 != lado3) {
		tipoTriangulo = 'S';
	} else {
		tipoTriangulo = 'I';
	}
}

int recebeNum() {
	int numero;

	do {
		printf("\nInforme um numero: ");
		scanf("%d", &numero);
	} while (numero < 0);

	return numero;
}

void multiplica(int numero) {
	int resultado, i;

	for (i = 0; i < 11; i++) {
		resultado = numero * i;
		printf("%d x %d = %d \n", numero, i, resultado);
	}
}

float preencherVendas(float *vendas) {
	int i;
	float total = 0;

	for (i = 0; i < 13; i++) {
		do {
			printf("\nInforme o Valor na %d posicao: ", i);
			scanf("%d", vendas[i]);
		} while (vendas < 0);
		total += vendas[i];
	}
	return total;
}

float calcularComissao(float *vendas, float *comissao) {
	int i;
	float total;

	for (i = 0; i < 13; i++) {
		if (vendas[i] > 5000) {
			comissao[i] = vendas[i] * 0, 01;
		} else {
			comissao[i] = vendas[i] * 0, 07;
		}
		total += comissao[i];
	}
	return total;
}

void resultado4() {
	int i;
	float vendas[13], comissao[13];

	preencherVendas(&vendas);
	calcularComissao(&vendas, &comissao);

	printf("\n MES     VALOR DE VENDA     VALOR DE COMISSAO");

	for (i = 0; i < 13; i++) {
		printf("%d     %f     %f \n", i, vendas[i], comissao[i]);
	}
}


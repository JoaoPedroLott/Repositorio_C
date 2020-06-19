/*
 ============================================================================
 Name        : binario.c
 Author      : João Pedro Mattos Lott
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char valor[50], tmp;
    int cont = 0, num, divisao, i = 0, cont2;

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
	fflush(stdin);
	getch();
	break;
	return 0;
}

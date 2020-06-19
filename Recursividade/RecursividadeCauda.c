/*
 ============================================================================
 Name        : RecursividadeCauda.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int MultiplicaRecursivoCalda(int x, int n, int result);
int MultiplicaRecursivoAUX(int x, int n);

int main(void) {
	setbuf(stdout, NULL);

	int x = 3,
		n = 5;

		printf("\nResultado = %d\n", MultiplicaRecursivoAUX(x, n));
	return 0;
}

int MultiplicaRecursivoCalda(int x, int n, int result) {
	if (n == 1) {
		return result + x;
	} else {
		return MultiplicaRecursivoCalda(x, n -1, result + x);
	}
}

int MultiplicaRecursivoAUX(int x, int n) {

	if (n == 0 || x == 0) {
		return 0;
	}else
		return MultiplicaRecursivoCalda(x, n, 0);
}

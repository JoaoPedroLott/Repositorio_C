/*
 ============================================================================
 Name        : 1.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

int MultiplicaRecursivo(int x, int n);
int MultiplicaRecursivoAUX(int x, int n);

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int x = 5,
		n = 6;

		printf("\nResultado = %d\n", MultiplicaRecursivoAUX(x, n));
	return 0;
}

int MultiplicaRecursivo(int x, int n) {

	if (n == 1) {
		return x;
	} else {
		return x + MultiplicaRecursivo(x, n -1);
	}
}

int MultiplicaRecursivoAUX(int x, int n) {

	if (n == 0 || x == 0) {
		return 0;
	}else
		return MultiplicaRecursivo(x, n);
}

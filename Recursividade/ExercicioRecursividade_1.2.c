/*
 ============================================================================
 Name        : 2.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

void multiplicarIterativo(int n, int q);
void multiplicaRecursivoNormal(int n, int q);

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	///multiplicarIterativo(5, 6);
	multiplicaRecursivoNormal(5, 6);

	return 0;
}

void multiplicarIterativo(int n, int q) {
	int i;

	for (i = 1; i <= q; i++) {
		printf("\n%d * %d = %d", n, i, i * n);
	}
}

void multiplicaRecursivoNormal(int n, int q) {

//	if (q == 1){
//		printf("\n%d * %d = %d", n, q, q * n);
//	}else {
//		multiplicaRecursivoNormal(n, q -1);
//		printf("\n%d * %d = %d", n, q, q * n);
//	}

	if (q > 1){
		multiplicaRecursivoNormal(n, q -1);
	}
	printf("\n%d * %d = %d", n, q, q * n);
}

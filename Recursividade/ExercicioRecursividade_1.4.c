/*
 ============================================================================
 Name        : 4.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int somaVetorIterativo(int *vet, int tam);
int somaVetorRecursivoCauda(int *vet, int tam, int result);
int somaVetorRecursivoNormal(int *vet, int tam);
int somaVetorAux(int *vet, int tam);

int main(void) {
	setbuf(stdout, NULL);
	int vet[] = {15, 9, 45, 12};

	//printf("\nSoma dos elementos = %d", somaVetorIterativo(vet, 4));
	//printf("\nSoma dos elementos =%d", somaVetorRecursivoNormal(vet, 4));
	//printf("\nSoma dos elementos = %d", somaVetorRecursivoCauda(vet, 4, 0));
	printf("\nSoma dos elementos = %d", somaVetorAux(vet, 4));

	return 0;
}

int somaVetorIterativo(int *vet, int tam) {
	int i, soma = 0;

	for(i = 0; i < tam; i++) {
		soma += *vet;
		vet++;
	}
	return soma;
}

int somaVetorRecursivoNormal(int *vet, int tam) {
	if (tam == 1) {
		return *vet;
	} else {
		return *vet + somaVetorRecursivoNormal(vet + 1, tam -1);
	}

//	if (tam == 0) {
//		return vet[tam];
//	} else {
//		return vet[tam] + somaVetorRecursivoNormal(vet, tam -1);
//	}
}

int somaVetorRecursivoCauda(int *vet, int tam, int result) {
	if(tam == 0) {
		return result;
	} else {
		return somaVetorRecursivoCauda(vet + 1, tam -1, result + *vet);
	}
}

int somaVetorAux(int *vet, int tam) {
	return somaVetorRecursivoCauda(vet, tam, 0);
}

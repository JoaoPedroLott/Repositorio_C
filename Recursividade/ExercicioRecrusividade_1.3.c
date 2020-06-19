/*
 ============================================================================
 Name        : 3.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcularSerieIterativo(int n);
double calcularSerieRecursivoNormal(int n);
double calcularSerieRecursividadeCauda(int n, double result);
double calcularSerieAux(int n);

int main(void) {
	setbuf(stdout, NULL);

//	printf("\nSomatório = %lf", calcularSerieIterativo(2));
//	printf("\nSomatório = %lf", calcularSerieRecursivoNormal(4));
	printf("\nSomatório = %lf", calcularSerieAux(4));

	return 0;
}

double calcularSerieIterativo(int n){
	int i;
	double resultado = 0;

	for (i = 1; i <= n; i++){
		resultado += pow(i, 3) / pow(10, i-1);
	}
	return resultado;
}

double calcularSerieRecursivoNormal(int n) {
	if (n == 1){
		return 1; // return pow(n, 3) / pow(10, n-1);
	}else {
		return pow(n, 3) / pow(10, n-1) + calcularSerieRecursivoNormal(n -1);
	}
}

double calcularSerieRecursividadeCauda(int n, double result) {
//	if (n == 0){
//		return result;
//	} else {
//		return calcularSerieRecursividadeCauda(n -1, result + pow(n, 3) / pow(10, n-1));
//	}

	if (n == 0){
		return result;
	}
	return calcularSerieRecursividadeCauda(n -1, result + pow(n, 3) / pow(10, n-1));
}

double calcularSerieAux(int n) {
	return calcularSerieRecursividadeCauda(n, 0);
}

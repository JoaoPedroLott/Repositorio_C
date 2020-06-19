/*
 ============================================================================
 Name        : Recursividade.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int fatorialIterativo(int num);
int fatorialRecursivo(int num);

int main(void) {
	setbuf(stdout, NULL);

	int num,
		fat;

	num = 5;

	fat = fatorialRecursivo(num);
	printf("\nResultado = %d", fat);
return 0;
}

int fatorialIterativo(int num){
	int fat = 1,
		i;

	for(i = 2; i<= num; i++){
		fat *= i;
	}
	return fat;
}

int fatorialRecursivo(int num){
	if(num <= 1){
		return 1;
	} else {
		return num * fatorialRecursivo(num - 1);
	}
}

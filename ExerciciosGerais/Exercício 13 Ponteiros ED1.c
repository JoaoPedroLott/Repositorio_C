/*
 ============================================================================
 Name        : Exercício.c
 Author      : Joao Lott
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void CalculoDaNota(float nota1, float nota2, float nota3,
				int numFaltas, int numAulas, float *pmedia);

int main(void) {
	float nota1, nota2, nota3, media, *pmedia;
	int numFaltas, numAulas;

	printf("\n Media do Aluno \n");
	// Entrada de dados
	printf("Informe a primeira nota: \n");
	scanf("%f", &nota1);
	printf("Informe a segunda nota: \n");
	scanf("%f", &nota2);
	printf("Informe a terceira nota: \n");
	scanf("%f", &nota3);
	printf("Informe o numero de faltas: \n");
	scanf("%d", &numFaltas);
	printf("Informe o numero de aulas da disciplina: \n");
	scanf("%d", &numAulas);

	// Ponteiro pmedia aponta para a media.
	pmedia = &media;
	// Chama a funcao
	CalculoDaNota(nota1, nota2, nota3, numFaltas, numAulas, &pmedia);

	return 0;
}

void CalculoDaNota(float nota1, float nota2, float nota3,
				int numFaltas, int numAulas, float *pmedia){

	*pmedia = (nota1 + nota2 + nota3) / 3;

	if (numFaltas > (numAulas*25)/100) {
		printf("Aluno reprovado por faltas.");
	} else {
		if (*pmedia >= 60) {
			printf("Aluno aprovado.");
		} else {
			printf("Aluno reprovado.");
		}
	}

}

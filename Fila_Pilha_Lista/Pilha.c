/*
 ============================================================================
 Name        : Pilha.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct PilhaStruct {
	int codigo;
	struct pilha *proximo;
	struct pilha *anterior;
};

typedef struct PilhaStruct pilhaStruct;

int gerarCodigo();
pilhaStruct* inserirRegistro(pilhaStruct *pilha);
void removerRegistro(pilhaStruct *pilha);
void retornoRecursivo(pilhaStruct *pilha, int contador);
void removerTodosRegistros(pilhaStruct *pilha);

int main(void) {
	setbuf(stdout, NULL);

	int i;
	pilhaStruct *pilha;
	pilha = NULL;

	for (i = 0; i < 5; i++) {
		pilha = inserirRegistro(pilha);
	}

	retornoRecursivo(pilha, 0);

	printf("\nInseriu");

	removerRegistro(pilha);
	//removerTodosRegistros(pilha);

	printf("\nRemoveu");
	retornoRecursivo(pilha, 0);

	return 0;
}

int gerarCodigo() {
	return rand() % 1000;
}

pilhaStruct* inserirRegistro(pilhaStruct *pilha) {
	pilhaStruct *novo;

	novo = (pilhaStruct*) malloc(sizeof(pilhaStruct));

	novo->codigo = gerarCodigo();
	novo->proximo = pilha;
	novo->anterior = NULL;

	if (pilha != NULL) {
		pilha->anterior = novo;
	}
	return novo;
}

// PARA REMOVER UM REGISTRO DA PILHA, TEMOS DE REAPONTAR. O ANTERIOR DO ELEMENTO
// TEM DE SER NULL, ENTÃO FAZEMOS O ANTERIOR DO PROXIMO DO ATUAL APONTAR PARA NULL
// E ENTAO REMOVER O REGISTRO ATUAL.
void removerRegistro(pilhaStruct *pilha) {
	pilhaStruct *primeiro = pilha,
				*tmp = NULL;

	if (pilha->proximo == NULL) {
		printf("/nPilha vazia.");
	} else {
		while(primeiro->proximo != NULL) {
			tmp = primeiro;
			primeiro = tmp->proximo;
		}
	tmp->proximo = NULL;
	}
}

// PARA REMOVER TODOS, BASTA FAZER O ANTERIOR NUM LOOP.
void removerTodosRegistros(pilhaStruct *pilha) {
	pilhaStruct *primeiro = pilha,
				*tmp = NULL;
	 while (pilha != NULL){
		if (pilha->proximo == NULL) {
				printf("/n teste");
		} else {
			while(primeiro->proximo != NULL) {
				tmp = primeiro;
				primeiro = tmp->proximo;
			}
		tmp->proximo = NULL;
		}
	}
}

void retornoRecursivo(pilhaStruct *pilha, int contador) {
	if (pilha != NULL) {
		printf("\nCódigo %d - Meu endereço %p - Proximo %p - Anterior %p\n",
				pilha->codigo, pilha, pilha->proximo, pilha->anterior);
		retornoRecursivo(pilha->proximo, contador + 1);
	} else if (contador == 0) {
		printf("\nLista Vazia.\n");
	}
}



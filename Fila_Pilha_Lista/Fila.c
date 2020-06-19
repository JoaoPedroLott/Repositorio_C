/*
 ============================================================================
 Name        : Fila.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct dadosFila {
	int codigo;
	struct dadosFila *proximo;
	struct dadosFila *anterior;
};

typedef struct dadosFila dadosFila;

int gerarCodigo();
dadosFila* inserirRegistro(dadosFila *fila);
dadosFila* removerRegistro(dadosFila *fila);
void retornoFilaRecursivo(dadosFila *fila, int contador);
void removerTodosRegistros(dadosFila *fila);

int main(void) {
	setbuf(stdout, NULL);
	int i;
	dadosFila *fila;
	fila = NULL;

	for (i = 0; i < 3; i++) {
		fila = inserirRegistro(fila);
	}

	retornoFilaRecursivo(fila, 0);

	fila = removerRegistro(fila);

	retornoFilaRecursivo(fila, 0);

	return 0;
}

int gerarCodigo() {
	return rand() % 1000;
}

dadosFila* inserirRegistro(dadosFila *fila) {
	dadosFila *novo, *tmp = fila;
	novo = (dadosFila*) malloc(sizeof(dadosFila));

	novo->codigo = gerarCodigo();
	novo->proximo = NULL;

	if (tmp != NULL) {
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return fila;
	} else {
		return novo;
	}
}

// PARA REMOVER DA FILA TEMOS QUE PEGAR O PRIMEIRO ELEMENTO DA FILA E FAZER O ANTERIOR DELE
// APONTAR PARA NULL E ENTÃO REMOVE-LO.
dadosFila* removerRegistro(dadosFila *fila) {
	dadosFila *atual = fila, *tmp = NULL;
	char excluiu = 'N';

	if (atual->proximo == NULL) {
		tmp = atual->anterior;
		tmp->proximo = NULL;
		free(atual);
		excluiu = 'S';
		printf("\nRegistro excluído com sucesso.");
		return atual;
	}
	if (excluiu == 'N') {
		printf("\nRegistro não encontrado.");
	} else {
		printf("\nExclusão efetuada com sucesso.");
	}
	return fila;
}

// PARA REMOVER TODOS BASTA FAZER O ANTERIOR DENTRO DE UM LOOP
void removerTodosRegistros(dadosFila *fila) {
	dadosFila *atual = fila, *tmp = NULL;
	while (fila != NULL) {
		if (atual->proximo == NULL) {
			tmp = atual->anterior;
			tmp->proximo = NULL;
			free(atual);
			printf("\nRegistro excluído com sucesso.");
		}
	}
}

void retornoFilaRecursivo(dadosFila *fila, int contador) {
	if (fila != NULL) {
		printf("\nCódigo %d - Meu endereço %p - Proximo %p - Anterior %p\n",
				fila->codigo, fila, fila->proximo, fila->anterior);
		retornoFilaRecursivo(fila->proximo, contador + 1);
	} else if (contador == 0) {
		printf("\nLista Vazia.\n");
	}
}

// VERIFICA SE ESTA VAZIA E CONTA QUANTOS TEM.
void verificarVazia(dadosFila *fila) {
	int cont;
	while (fila->proximo != NULL) {
		cont++;
		printf("\nFila não esta vazia.");
	}
	printf("\nFila vazia.");
}

// PARA CONTAR QUANTOS ELEMENTOS TEMOS NA FILA, PODEMOS FAZER UM LOOP COM UM CONTADOR
// COMECAMOS DO ULTIMO ELEMENTO E VAMOS INCREMENTANDO O CONTADOR A CADA ELEMENTO QUE PASSA
// ATE QUE O PROXIMO == NULL.
void contarFila(dadosFila *fila) {

}


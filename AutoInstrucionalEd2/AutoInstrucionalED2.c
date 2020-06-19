/*
 ============================================================================
 Name        : AutoInstrucionalED2.c
 Author      : João Pedro Lott, João Henrique & Arthur Mares
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct no {
	int codigo;
	int fatorBalan;
	struct no *direita;
	struct no *esquerda;
	struct no *pai;
};

typedef struct no arvore;

arvore* criaArvore();
void inserir(arvore *arv);
arvore* buscar(arvore *arv, int codigo);

int main(void) {
	setbuf(stdout, NULL);

	arvore *arv = criaArvore();
	inserir(arv);
	buscar(arv, 10);

	return 0;
}

// CRIA A ÁRVORE
arvore* criaArvore() {
	return NULL;
}

// INSERE
void inserir(arvore *arv) {
	arvore* aux_1 = NULL, aux_2 = NULL;
	int n;

	printf("Informe o número que deseja inserir: ");
	scanf("%d", &n);
	getchar();

	if (!arv) {
		arv = (arvore*) malloc(sizeof(arvore));

		arv->codigo = n;
		arv->direita = NULL;
		arv->esquerda = NULL;
		arv->pai = NULL;

		arv->fatorBalan = 0;
	} else {
		aux_1 = arv;
		aux_2 = aux_1;

		while (aux_2) {
			if (n < aux_2.codigo) {
				aux_2 = aux_2.esquerda;

				if (!aux_2) {
					aux_1->esquerda = (arvore*) malloc(sizeof(arvore));

					aux_2 = aux_1->esquerda;

					aux_2->esquerda = NULL;
					aux_2->direita = NULL;
					aux_2->pai = aux_1;
					aux_2->codigo = n;
					break;
				} else {
					aux_1 = aux_2;
				}
			} else {
				aux_2 = aux_2->direita;

				if (!aux_2) {
					aux_1->esquerda = (arvore*) malloc(sizeof(arvore));

					aux_2 = aux_1->esquerda;

					aux_2->esquerda = NULL;
					aux_2->direita = NULL;
					aux_2->pai = aux_1;
					aux_2->codigo = n;
					break;
				} else {
					aux_1 = aux_2;
				}
			}

		}
	}
	printf("Elemento Inserido!\n");

	if (aux_2) {
		while (aux_2) {
			aux_2->fatorBalan = altura(aux_2->direita)
					- altura(aux_2->esquerda);

			if (aux_2->fatorBalan > 1 || aux_2->fatorBalan < -1) {
				aux_2 = balanceia(aux_2);
			}
			aux_2 = aux_2->pai;
		}
	}
}

// BUSCA UM CODIGO NA ARVORE
arvore* buscar(arvore *arv, int codigo) {
	arvore *aux;

	aux = arv;

	while (aux && aux->codigo != codigo) {
		if (codigo < aux->codigo) {
			aux = aux->esquerda;
		} else {
			aux = aux->direita;
		}
	}
	return aux;
}

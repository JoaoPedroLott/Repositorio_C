/*
 ============================================================================
 Name        : ArvoreBinária.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct no {
	int codigo;
	struct no *direita;
	struct no *esquerda;
};

typedef struct no arvore;

arvore* criaArvore();
arvore* insereNo(arvore *no, int codigo);
int pesquisaNo(arvore *no, int codigo);
void mostraArvore(arvore* arv);
void arvore_Busca_em_Ordem(arvore *Raiz);
void arvore_Busca_pre_Ordem(arvore *Raiz);
void arvore_Busca_pos_Ordem(arvore *Raiz);
void arvoreExcluirToda(arvore *no);
arvore* busca(arvore* r, int k);
arvore* excluirRaiz(arvore *no);

int main(void) {
	arvore *arv = criaArvore();
	arv = insereNo(arv, 12);
	arv = insereNo(arv, 5);
	arv = insereNo(arv, 32);
	arv = insereNo(arv, 22);
	arv = insereNo(arv, 10);

	arvore_Busca_pre_Ordem(arv);
	printf("\n");
	arvore_Busca_pos_Ordem(arv);
	printf("\n");
	arvore_Busca_em_Ordem(arv);

	int numBusca;
	printf("\nDigite o numero a buscar: ");
	scanf("%d", &numBusca);

	if (busca(arv, numBusca)) {
		printf("\nO numero pertence a arvore!\n\n");
	} else {
		printf("\nO numero NAO pertence a arvore!\n\n");
	}

	// arvoreExcluirToda(arv);
	arv = excluirRaiz(arv);
	printf("\n");
	arvore_Busca_em_Ordem(arv);

	return 0;
}

arvore* criaArvore() {
	return NULL;
}

arvore* insereNo(arvore *no , int codigo) {
	if(no == NULL) {
		no = (arvore*)malloc(sizeof(arvore));
		no->codigo = codigo;
		no->direita = NULL;
		no->esquerda = NULL;
	}else if(codigo < no->codigo) {
		no->esquerda = insereNo(no->esquerda,codigo);
	}else{
		no->direita = insereNo(no->direita , codigo);
	}

	return no;

}

arvore* busca (arvore* r, int k) {
    if (r == NULL || r->codigo == k)
       return r;
    if (r->codigo > k)
       return busca (r->esquerda, k);
    else
       return busca (r->direita, k);
}

void arvore_Busca_em_Ordem(arvore *no) {
    if(no!=NULL){
        arvore_Busca_em_Ordem(no->esquerda);
        printf(" %d",no->codigo);
        arvore_Busca_em_Ordem(no->direita);
    }
}

void arvore_Busca_pre_Ordem(arvore *no) {
    if(no!=NULL){
        printf(" %d",no->codigo);
        arvore_Busca_pre_Ordem(no->esquerda);
        arvore_Busca_pre_Ordem(no->direita);
    }
}

void arvore_Busca_pos_Ordem(arvore *no) {
    if(no!=NULL){
        arvore_Busca_pos_Ordem(no->esquerda);
        arvore_Busca_pos_Ordem(no->direita);
        printf(" %d",no->codigo);
    }
}

void arvoreExcluirToda(arvore *no) {
    if(no!=NULL){
        arvoreExcluirToda(no->esquerda);
        arvoreExcluirToda(no->direita);
        free(no);
        no=NULL;
    }
}

arvore* excluirRaiz(arvore *no) {
	arvore *q;
	arvore *p;

	if(no->esquerda == NULL) {
		q = no->direita;
		free(no);
		return q;
	}

	p = no;
	q = no->esquerda;
	while(q->direita != NULL) {
		p = q;
		q = q->direita;
	}

	if(p!=no) {
		p->direita = q->esquerda;
		q->esquerda = no->esquerda;
	}

	q->direita = no->direita;
	free(no);
	return q;
}

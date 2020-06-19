/*
 ============================================================================
 Name        : ListasDuplamenteEncadeadas.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct dadosListaDuplas {
	int codigo;
	struct dadosListaDuplas *proximo;
	struct dadosListaDuplas *anterior;
};

typedef struct dadosListaDuplas dadosListaDuplas;

int gerarCodigo();
dadosListaDuplas* inserirRegistro(dadosListaDuplas *listaDupla);
void retornoListaRecursivo(dadosListaDuplas *listaDupla, int contador);
dadosListaDuplas* removerRegistro(dadosListaDuplas *listaDupla, int codigo);

int main(void) {
	setbuf(stdout, NULL);
	dadosListaDuplas listaDupla;
	listaDupla = NULL;
	int i;

//	listaDupla = inserirRegistro();
//	printf("\nListaDupla código - %d proximo - %p - endereco %p - anterior %p",
//			listaDupla->codigo, listaDupla->proximo, listaDupla, listaDupla.anterior);

	for(i = 0; i < 5; i++){
		listaDupla = inserirRegistroCabeca(listaDupla);
//		listaDupla = inserirRegistroFim(listaDupla);
	}
	retornoListaRecursivo(listaDupla, 0);

//	listaDupla = removerRegistro(listaDupla, );
//	retornoListaRecursivo(listaDupla, 0);

	return 0;
}

int gerarCodigo() {
	return rand() % 1000;
}

// INSERIR NO MEIO TEM QUE FAZER PROXIMO E ANTERIOR APONTAREM PARA A LISTA (COMO...)?
dadosListaDuplas* inserirRegistro(dadosListaDuplas *listaDupla) {
	dadosListaDuplas *novo;

	novo = (dadosListaDuplas*) malloc(sizeof(dadosListaDuplas));

	novo->codigo = gerarCodigo();
	novo->proximo = NULL;
	novo->anterior = listaDupla;

//	if (listaDupla != NULL) {
//
//	}

	return novo;
}

dadosListaDuplas* inserirRegistroCabeca(dadosListaDuplas *listaDupla) {
	dadosListaDuplas *novo;
	novo = (dadosListaDuplas*) malloc(sizeof(dadosListaDuplas));

	novo->codigo = gerarCodigo();
	novo->proximo = listaDupla;
	novo->anterior = NULL;

	return novo;
}

dadosListaDuplas* inserirRegistroFim(dadosListaDuplas *listaDupla) {
	dadosListaDuplas *novo, *tmp = listaDupla;
	novo = (dadosListaDuplas*) malloc(sizeof(dadosListaDuplas));

	novo->codigo = gerarCodigo();
	novo->proximo = NULL;
	novo->anterior = listaDupla;

	if (tmp != NULL) {
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return listaDupla;
	} else {
		return novo;
	}
}

void retornoListaRecursivo(dadosListaDuplas *listaDupla, int contador) {
	if (listaDupla != NULL) {
		printf("\nCódigo %d - Meu endereço %p - Proximo %p - Anterior %p\n",
				listaDupla->codigo, listaDupla, listaDupla->proximo,
				listaDupla->anterior);
		retornoListaRecursivo(listaDupla->proximo, contador + 1);
	} else if (contador == 0) {
		printf("\nLista Vazia.\n");
	}
}

// PARA REMOVER NA CABECA BASTA FAZER O PROXIMO DO ANTERIOR APONTAR PARA NULL
// PARA REMOVER NO FIM BASTA FAZER O ANTERIOR DO PROXIMO APONTAR PARA NULL
// PARA REMOVER NO MEIO TEMOS QUE FAZER O ANTERIOR DO PROXIMO APONTAR PARA O PROXIMO DO ANTERIOR

dadosListaDuplas* removerRegistro(dadosListaDuplas *listaDupla, int codigo) {
	dadosListaDuplas *atual = listaDupla, *tmp = NULL;
	char excluiu = 'N';

	if (codigo == atual->codigo) {
		tmp = atual;
		atual = atual->proximo;
		free(tmp);
		printf("\nRegistro excluído com sucesso.");
		return atual;
	} else {
		while (atual->proximo != NULL) {
			if (atual->codigo == codigo) {
				tmp->proximo = atual->proximo;
				free(atual);
				excluiu = 'S';
				break;
			}
		}
		if (excluiu == 'N') {
			printf("\nRegistro não encontrado.");
		} else {
			printf("\nExclusão efetuada com sucesso.");
		}
		return listaDupla;
	}
}


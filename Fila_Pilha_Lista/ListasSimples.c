/*
 ============================================================================
 Name        : ListasSimples.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA
struct dadosListaSimples {
	int codigo;
	struct dadosListaSimples *proximo;
};

typedef struct dadosListaSimples dadosListaSimples;

// PROTTÓTIPOS
int gerarCodigo();
dadosListaSimples* inserirRegistro();
dadosListaSimples* inserirRegistroCabeca(dadosListaSimples *lista);
dadosListaSimples* inserirRegistroFim(dadosListaSimples *lista);
dadosListaSimples* removerRegistro(dadosListaSimples *lista, int codigo);
void retornoListaIterativo(dadosListaSimples *lista);
void retornoListaRecursivo(dadosListaSimples *lista, int contador);

int main(void) {
	setbuf(stdout, NULL);
	int i;
	dadosListaSimples *listaSimples;

	// INICIA A LISTA COM NULL
	listaSimples = NULL;
//	printf("\nLista vazia aponta para- %p\n", listaSimples);

	// INSERE UM REGISTRO NA LISTA
//	listaSimples = inserirRegistro();
//	printf("\nLista código - %d Lista endereço - %p Lista aponta para %p", listaSimples->codigo, listaSimples->proximo, listaSimples);


	for(i = 0; i < 5; i++){
		// CHAMA A FUNÇÃO E INSERE 3 VALORES NA CABEÇA DA LISTA
//		listaSimples = inserirRegistroCabeca(listaSimples);

		// CHAMA A FUNÇÃO E INSERE 3 VALORES NO FIM DA LISTA
		listaSimples = inserirRegistroFim(listaSimples);
	}
	retornoListaRecursivo(listaSimples, 0);

	listaSimples = removerRegistro(listaSimples, 41);
	retornoListaRecursivo(listaSimples, 0);

	return 0;
}

// GERAR CODIGO ALEATORIO
int gerarCodigo() {
	return rand() % 1000;
}

// RETORNAR A LISTA DE FORMA RECURSIVA
void retornoListaRecursivo(dadosListaSimples *lista, int contador) {
	if (lista != NULL) {
			printf("\nCódigo %d - Meu endereço %p - Aponto para %p\n", lista->codigo, lista, lista->proximo);
			retornoListaRecursivo(lista->proximo, contador + 1);
		} else if (contador == 0){
			printf("\nLista Vazia.\n");
		}
}

// RETORNAR A LISTA DE FORMA ITERATIVA
void retornoListaIterativo(dadosListaSimples *lista) {
	dadosListaSimples *tmp = lista;

	if (tmp == NULL) {
		printf("\nLista vazia");
	} else {
		do {
			printf("\nLista código - %d - Lista endereço %p - Lista aponta para %p", tmp->codigo, tmp->proximo, tmp);
			tmp = tmp->proximo;
		} while (tmp != NULL);
	}
}

// INSERIR UM REGISTRO NA LISTA
dadosListaSimples* inserirRegistro() {
	// DELCARAR PONTEIRO
	dadosListaSimples *novo;

	// ALOCAR ESPAÇO NA MEMÓRIA
	novo = (dadosListaSimples*) malloc(sizeof(dadosListaSimples));

	// PREENCHER OS DADOS NA LISTA
	novo->codigo = gerarCodigo();
	novo->proximo = NULL;

	// RETORNA O ENDEREÇO ALOCADO
	return novo;
}

// INSERIR UM REGISTRO NO INICIO DA LISTA
dadosListaSimples* inserirRegistroCabeca(dadosListaSimples *lista) {
	dadosListaSimples *novo;
	novo = (dadosListaSimples*) malloc(sizeof(dadosListaSimples));

	novo->codigo = gerarCodigo();
	novo->proximo = lista;

	return novo;
}

// INSERIR UM REGISTRO NO FIM DA LISTA
dadosListaSimples* inserirRegistroFim(dadosListaSimples *lista) {
	dadosListaSimples 	*novo,
						*tmp = lista;
	novo = (dadosListaSimples*) malloc(sizeof(dadosListaSimples));

	novo->codigo = gerarCodigo();
	novo->proximo = NULL;

	// TEM DE TER PELO MENOS UM ITEM NA LISTA
	if (tmp != NULL) {
		// PROCURAR O ULTIMO DA LISTA
		while(tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return lista;
	}else {
		return novo;
	}
}

//
dadosListaSimples* removerRegistro(dadosListaSimples *lista, int codigo) {
	dadosListaSimples 	*atual = lista,
						*anterior = NULL;
	char excluiu = 'N';

	if (codigo == atual->codigo && anterior == NULL) {
		anterior = atual;
		atual = atual->proximo;
		free(anterior);
		printf("\nRegistro excluído com sucesso.");
		return atual;
	} else {
		while (atual->proximo != NULL) {
			if (atual->codigo == codigo){
				anterior->proximo = atual->proximo;
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
		return lista;
	}
}

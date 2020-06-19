/*
 ============================================================================
 Name        : Hash.c
 Author      : João Pedro Lott
 Version     :
 Copyright   : @2018
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define tam = 100

struct dados {
	int codigo;
	struct dados *proximo;
};

typedef struct dados Dados;
typedef dados* Hash[tam];

int funcaoHash(int num);
void insereHash(Hash tab,int num);
void buscaHash(Hash tab, int num);
float porcentagemHash(Hash tab);

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Hash tab;

	//insereHash(,);
	//buscaHash(,);
	//porcentagemHash(tab);

	return 0;
}

int funcaoHash(int num) {
	return (num % 11);
}


 void insereHash(Hash tab, int num) {
	 int i = 0;
	 int chave = funcaoHash(num);
	 Dados* aux = tab[chave];
	 while(aux != NULL) {
		 if(aux->info == num){
			 break;
		 }
	 aux = aux->prox;
	 }
	 if(aux == NULL) {
		 aux = (Dados*)malloc(sizeof(Dados));
		 aux->info = num;
		 aux->prox = tab[chave];
		 tab[chave] = aux;
	 }
 }


// void buscaHash(Hash tab,int num) {
//	 int pos = num;
//	 if(num > tam || num < 0){
//	 	 printf("\nPosicao nao encontrada!");
//	 	 return;
//	 }else {
//	 imprimeColisao(tab,pos);
//	 }
// }
//


float porcentagemHash(Hash tab){
	 int i;
	 float porcent = 0, cont  = 0;
	 for(i = 0; i < tam; i++){
	 	if(tab[i] != NULL){
	   	   cont++;
	  	}
	 }
	 porcent = (cont*100)/tam;
	 return(porcent);
}


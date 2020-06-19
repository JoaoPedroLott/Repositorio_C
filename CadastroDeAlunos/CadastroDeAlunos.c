/*
 ============================================================================
 Name        : CadastroAlunosED1.c
 Author      : João Pedro Mattos Lott
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct cadastro {
	char nome[50];
	int matricula;
	char telefone[11];
//struct cadastro *PROX;
} CadastroAluno;

typedef struct prova {
	CadastroAluno cadastro;
	float prova1;
	float prova2;
	float trabalhos;
//struct prova *PROX;
} Provas;

void cadastroAlunos();
void relatorioAprovados();

int main(void) {
	setbuf(stdout, NULL);
	int *contador, op;

	// Criar ponteiros para os Structs.
	CadastroAluno *cadAluno; //= NULL;
	Provas *prov; //= NULL;

	// Contador inicializado com 1.
	contador = 1;

	// Menu do programa.
	do {
		printf("\n CADASTRO DE ALUNOS \n");
		printf("\n 1 - Cadastrar alunos.");
		printf("\n 2 - Relatório de alunos aprovados.");
		printf("\n 3 - Relatório de alunos reprovados.");
		printf("\n 4 - Relatório geral.");
		printf("\n 0 - Sair.\n");

		fflush(stdin);
		scanf("%d", &op);

		switch (op) {
		// Cadastro do Aluno.
		case 1:
			cadastroAlunos(&cadAluno, &prov, &contador);
			break;
			// Relatório de alunos aprovados.
		case 2:
			relatorioAprovados(&cadAluno, &prov, &contador);
			break;
			// Relatório de alunos reprovados.
		case 3:
			relatorioReprovados(&cadAluno, &prov, &contador);
			break;
			// Relatório geral.
		case 4:
			relatorioGeral(&cadAluno, &prov, &contador);
			break;
			// Sair do programa.
		case 0:
			break;
			// default (Caso o usuario informe um numero inválido ao menu).
		default:
			printf("\n Opção inválida. \n");
			break;
		}
	} while (op != 0);

	// Libera a memória.
	free(cadAluno);
	free(prov);

	return 0;
}

void cadastroAlunos(CadastroAluno *cadAluno, Provas *prov, int *contador) {
	int valiTel, valiNome, i;
	char key;

	// Alocacao da memória.
	cadAluno = (CadastroAluno*) malloc(sizeof(CadastroAluno));

	// Checa se existe memória para ser alocada.
	if (!cadAluno) {
		printf("\n Sem memória disponível \n");
		exit(1);
	}

	// Alocacao da memória
	prov = (Provas*) malloc(sizeof(Provas));

	// Checa se existe memória para ser alocada.
	if (!prov) {
		printf("\n Sem memória disponível \n");
		exit(1);
	}

	// Entrada dos dados pelo usuário.
	do {
		for (i = 0;; i++) {
			do {
				printf("\n Informe o nome do aluno: \n");
				fflush(stdin);
				gets(cadAluno[i].nome);
				valiNome = strcmp(cadAluno[i].nome, " ")
						|| strcmp(cadAluno[i].nome, "");
				if (cadAluno[i].nome == NULL
						|| strcmp(cadAluno[i].nome, " ") == 0
						|| strcmp(cadAluno[i].nome, "") == 0) {
					printf("\n Você deve informar um nome.");
				}
			} while (valiNome == 0);

			do {
				printf("\n Informe o telefone do aluno: \n");
				fflush(stdin);
				gets(cadAluno[i].telefone);
				valiTel = strlen(cadAluno[i].telefone);
				if (valiTel < 11) {
					printf("\n Você deve informar um telefone com o código"
							" da área mais 9 dígitos.");
				}
			} while (valiTel < 11);

			//cadAluno->PROX = cadAluno;

			do {
				printf("\n Informe a nota da primeira prova: \n");
				fflush(stdin);
				scanf("%f", &prov[i].prova1);
				if (prov[i].prova1 < 0 || prov[i].prova1 > 35) {
					printf("\n A nota da primeira prova deve ter o valor "
							"entre 0 e 35 pontos.\n");
				}
			} while (prov[i].prova1 < 0 || prov[i].prova1 > 35);

			do {
				printf("\n Informe a nota da segunda prova: \n");
				fflush(stdin);
				scanf("%f", &prov[i].prova2);
				if (prov[i].prova2 < 0 || prov[i].prova2 > 35) {
					printf("\n A nota da segunda prova deve ter o valor "
							"entre 0 e 35 pontos.\n");
				}
			} while (prov->prova2 < 0 || prov->prova2 > 35);

			do {
				printf("\n Informe a nota do trabalho: \n");
				fflush(stdin);
				scanf("%f", &prov[i].trabalhos);
				if (prov[i].trabalhos < 0 || prov[i].trabalhos > 30) {
					printf("\n A nota do trabalho deve ter o valor "
							"entre 0 e 30 pontos.\n");
				}
			} while (prov[i].trabalhos < 0 || prov[i].trabalhos > 30);

			//prov->PROX = prov;

			printf("\n Deseja continuar o cadastro? S/N \n");
			fflush(stdin);
			scanf("%c", &key);
			if (key == 'N') {
				break;
			}

			// Contador recebe +1 sempre que o usuário quiser continuar.
			contador++;

			// Realocacao da memória.
			cadAluno = (CadastroAluno*) realloc(cadAluno,
					(*contador + 1) * sizeof(CadastroAluno));
			prov = (Provas*) realloc(prov, (*contador + 1) * sizeof(Provas));
		}
	} while (key == 'S');

}

// Funcao para gerar o relatório de alunos APROVADOS.
void relatorioAprovados(CadastroAluno *cadAluno, Provas *prov, int *contador) {
	int i;

	printf("\n Alunos aprovados: \n");
	for (i = 0; i < *contador; i++) {
		if (prov[i].prova1 + prov[i].prova2 + prov[i].trabalhos >= 60) {
			printf("\n Nome: %s", prov[i].cadastro.nome);
			printf("\n Nota: %f", prov[i].prova1 + prov[i].prova2 + prov[i].trabalhos);
		}
	}
}

// Funcao para gerar o relatório de alunos REPROVADOS.
void relatorioReprovados(CadastroAluno *cadAluno, Provas *prov, int *contador) {
	int i, cont;

	cont = &contador;

	printf("\n Alunos reprovados: \n");
	for (i = 0; i < cont; i++) {
		if (prov[i].prova1 + prov[i].prova2 + prov[i].trabalhos < 60) {
			printf("\n Nome: %s", prov[i].cadastro.nome);
			printf("\n Nota: %f", prov[i].prova1 + prov[i].prova2 + prov[i].trabalhos);
			printf("\n Matrícula: %d", prov[i].cadastro.matricula);
		}
	}
}

// Funcao para gerar o relatório GERAL.
void relatorioGeral(CadastroAluno *cadAluno, Provas *prov, int *contador) {
	int i;

	printf("\n Relatório Geral: \n");
	for(i = 0; i < *contador; i++){
		printf("\n Nome do Aluno: %s", prov[i].cadastro.nome);
		printf("\n Telefone do Aluno: %s", prov[i].cadastro.telefone);
		printf("\n Matrícula do Aluno: %d", prov[i].cadastro.matricula);
		printf("\n Primeira prova: %f", prov[i].prova1);
		printf("\n Segunda prova: %f", prov[i].prova2);
		printf("\n Trabalho: %f", prov[i].trabalhos);
	}
}





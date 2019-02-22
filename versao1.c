#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

struct aluno {
	char nome[10];
	int ra;
}Aluno;

struct professor{
	char nome[10];
	int id;
}Professor;

void menu() {

	printf("\t\t\tCadastro de Matriculas\n\n\n");
	printf("\tEscolha uma das opcoes abaixo:\n\n");
	printf("1)Cadastro Aluno\n");
	printf("2)Cadastro Professor\n");
	printf("3)Cadastro Disciplina\n");
	printf("4)Matricular Aluno(s)\n");
	printf("5)Cancelar Matricula\n");
	printf("6)Vincular Disciplina\n");
	printf("7)Desvincular Disciplina\n");
	printf("8)Impressoes\n");
	
}

void cadAluno(char nome[], int ra) {
	struct aluno VetAluno[TAM];
	/*for (int i = 1; i < TAM; i++)
	{
		VetAluno[i].nome = nome;
		ra = VetAluno[i].ra;
	}
	for (int j = 1; j < TAM; j++)
	{
		printf("\nNome: %s", VetAluno[j].nome);
		printf(" RA: %d\n", VetAluno[j].ra);
	}*/

}

void main() {
	

	menu();
	int opcao;
	int auxRA;
	char auxNome[10];
	printf("\nOpcao: ");
	scanf("%d", &opcao);

	switch (opcao)
	{
	case 1:

		printf("\n\n\tCadastro Aluno\n");
		printf("Nome: ");
		scanf("%s", auxNome);
		printf("RA: ");
		scanf("%d", &auxRA);
		cadAluno(auxNome, auxRA);

		break;
	
	case 2:
		printf("\n\n\tCadastro Professor\n");
		//chamar a funcao
		break;
	
	case 3:
		printf("\n\n\tCadastro Disciplina\n");
		//chamar a funcao
		break;
	
	case 4:
		printf("\n\n\tCadastro Aluno\n");
		//chamar a funcao
		break;

	case 5:
		printf("\n\n\tCancelar Matricula\n");
		//chamar a funcao
		break;

	case 6:
		printf("\n\n\tVincular Disciplina\n");
		//chamar a funcao
		break;

	case 7:
		printf("\n\n\tDesvincular Disciplina\n");
		//chamar a funcao
		break;

	case 8:
		printf("\n\n\tImpressoes\n");
		//chamar a funcao
		break;


	default:
		break;
	}


	system("pause");
}

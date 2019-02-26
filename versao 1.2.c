#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TAM 50

typedef struct aluno {
	char nome[10];
	int ra;
	char disciplina[20];
}Aluno;

typedef struct professor {
	char nome[10];
	int id;
	char disciplina[20];
}Professor;

typedef struct disciplina {
	char nome[20];
	int turma;
}Disciplina;

void menu() {

	printf("\t\t\tCadastro de Matriculas\n\n\n");
	printf("\tEscolha uma das opcoes abaixo:\n\n");
	printf("1)Cadastro Aluno\n");
	printf("2)Cadastro Disciplina\n");
	printf("3)Cadastro Professor\n");
	printf("4)Matricular Aluno(s)\n");
	printf("5)Cancelar Matricula\n");
	printf("6)Vincular Disciplina\n");
	printf("7)Desvincular Disciplina\n");
	printf("8)Impressoes\n");

}

Aluno cadAluno(int num, Aluno *vet) {
	int vetControle[TAM] = { 0 };
	for (int i = 1; i <= num; i++)
	{
		if (vetControle[i] == 0)
		{
			printf("\nNome: ");
			scanf("%s", &vet[i].nome);
			printf("\nRA: ");
			scanf("%d", &vet[i].ra);
		}
		

	}

	return *vet;
}

/*Disciplina cadDisciplina(Disciplina *auxDisciplina){

	for (int i = 0; i < ; i++)
	{
		printf("Digite o nome da disciplina: ");
		scanf("%s", &auxDisciplina[i].nome);

	}

}*/


Professor cadProfessor(int num, Professor *vet) {
	for (int i = 1; i <= num; i++)
	{
		printf("\nNome: ");
		scanf("%s", &vet[i].nome);
		printf("\nRA: ");
		scanf("%d", &vet[i].id);

	}

	return *vet;
}
void main() {

	Aluno vetAluno[TAM];
	Professor vetProfessor[TAM];
	int opcao, op = 1;
	int numAlunos, totalAlunos = 0;
	int numProfessores, totalProfessores = 0;
	char auxNome[10];
	char disciplina[20];

	do
	{
		menu();

		printf("\nOpcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:

			printf("\n\n\tCadastro Aluno\n");
			printf("Quantos alunos deseja cadastrar?\nR: ");
			scanf("%d", &numAlunos);
			cadAluno(numAlunos, vetAluno);
			printf("\nCadastro concluido com sucesso!\n");
			for (int j = 1; j <= numAlunos; j++)
			{
				printf("\nNome: %s", vetAluno[j].nome);
				printf(" RA: %d\n", vetAluno[j].ra);
			}
			totalAlunos = totalAlunos + numAlunos;
			printf("%d\n", totalAlunos);
			for (int i = 0; i < totalAlunos; i++)
			{
				printf("%s\n", vetAluno[i].nome);
			}
			

			break;

		case 2:
			printf("\n\n\tCadastro Disciplina\n");
			//chamar a funcao
			break;

		case 3:
			printf("\n\n\tCadastro Professor\n");
			printf("Quantos professores deseja cadastrar?\nR: ");
			scanf("%d", &numProfessores);
			cadProfessor(numProfessores, vetProfessor);
			printf("\nCadastro concluido com sucesso!\n");
			for (int j = 1; j <= numProfessores; j++)
			{
				printf("\nNome: %s", vetProfessor[j].nome);
				printf(" RA: %d\n", vetProfessor[j].id);
			}
			totalProfessores = totalProfessores + numProfessores;
			printf("%d\n", totalProfessores);
			break;

		case 4:
			printf("\n\n\tMatricular Aluno(s)\n");
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
		printf("Continuar? [0 = Nao]");
		scanf("%d", &op);
	} while (op != 0);



	system("pause");
}

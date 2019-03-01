#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

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

void subMenuImp() {
	printf("Impressoes:\n");
	printf("1)Imprimir lista de todos os alunos\n");
	printf("2)Imprimir lista de todas as disciplinas\n");
	printf("3)Imprimir lista de todos os professores\n");
	printf("4)Imprimir lista de disciplinas de um aluno\n");
	printf("5)Imprimir lista de alunos em uma disciplina e turma\n");
	printf("6)Imprimir lista de alunos de uma disciplina\n");
	printf("7)Imprimir lista de todas as disciplinas ministradas por um professor\n");
	printf("8)Imprimir lista de todas os professores vinculados a uma disciplina\n");
}

Aluno cadAluno(int num, Aluno *vet) {

	
	for (int ii = 0; ii < num; ii++)
	{
			printf("\nNome: ");
			scanf("%s", &vet[ii].nome);
			printf("\nRA: ");
			scanf("%d", &vet[ii].ra);
			
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
	for (int i = 0; i < num; i++)
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
	int opcao, op = 0, opImp, opCad = 1;
	int numAlunos, totalAlunos = 0;
	int numProfessores, totalProfessores = 0;
	char auxNome[10];
	char disciplina[20];

	do
	{
		menu();

		printf("\nOpcao: ");
		scanf("%d", &opcao);

		while (opcao < 1 || opcao > 8)
		{
			printf("\nOpcao invalida!\n\nDigite uma opcao entre 1 e 8!\n");

			printf("\nOpcao: ");
			scanf("%d", &opcao);
		}
		

		switch (opcao)
		{
		case 1:
			printf("\n\n\tCadastro Aluno\n");
			do
			{
				for (int q = 0; q < 2; q++)
				{
					printf("Nome: ");
					scanf("%s", vetAluno[q].nome);
					printf("RA: ");
					scanf("%d", &vetAluno[q].ra);
					
				}
				
				printf("Mais 1? ");
				scanf("%d", &opCad);

			} while (opCad != 0);
				
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
			for (int j = 0; j < numProfessores; j++)
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
			
			printf("\n");
			subMenuImp();
			printf("\nOpcao: ");
			scanf("%d", &opImp);

			while (opImp < 1 || opImp > 8)
			{
				printf("\nOpcao invalida!\n\nDigite uma opcao entre 1 e 8!\n");

				printf("\nOpcao: ");
				scanf("%d", &opImp);
			}
			switch (opImp)
			{
			case 1:

				printf("\n\n\tLista de todos os alunos\n");
				for (int iii = 0; iii < TAM; iii++)
				{
					printf("Nome: %s\n", vetAluno[iii].nome);
					printf("RA: %d\n", vetAluno[iii].ra);
				}
				
				break;

			case 2:
				printf("\n\n\tLista de todos as disciplinas\n");
				//chamar a funcao
				break;

			case 3:
				printf("\n\n\tLista de todos os professores\n");
				break;

			case 4:
				printf("\n\n\tLista de todas as disciplinas de um aluno\n");
				//chamar a funcao
				break;

			case 5:
				printf("\n\n\tLista de todos os alunos em uma disciplina e turma\n");
				//chamar a funcao
				break;

			case 6:
				printf("\n\n\tLista de todos os alunos em uma disciplina\n");
				//chamar a funcao
				break;

			case 7:
				printf("\n\n\tLista de todos as disciplinas ministradas por um professor\n");
				//chamar a funcao
				break;

			case 8:
				printf("\n\n\tLista de todos os professores vinculados a uma disciplina\n");
			
			default:
				printf("Erro.\n");
				break;
			}
			break;


		default:
			printf("Erro.\n");
			break;
		}
		printf("Continuar? [0 = Nao]\n");
		printf("Opcao: ");
		scanf("%d", &op);
	} while (op != 0);



	system("pause");
}

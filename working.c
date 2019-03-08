#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5


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



/*Disciplina cadDisciplina(char nome[20]){
	Disciplina *vet = { 0 };
	
	for (int l = 0; l < 2; l++)
	{
		strcpy(vet[l].nome, nome);		
	}
	
	return *vet;
}*/


/*Professor cadProfessor(int num, Professor *vet) {
	for (int i = 1; i <= num; i++)
	{
		printf("\nNome: ");
		scanf("%s", &vet[i].nome);
		printf("\nRA: ");
		scanf("%d", &vet[i].id);

	}

	return *vet;
}*/

void main() {

	Aluno vetAluno[TAM];
	//Professor vetProfessor[TAM]; 
	//Disciplina vetDisciplina[TAM] = { 0 };
	int r=0, opcao, op = 1, opMenu, opAluno, count = 0, count1 = 0, pos = 0, auxRA = 0;
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
			printf("Quantos alunos deseja cadastrar: ");
			scanf("%d", &opAluno);
			count1 = (count + opAluno);
			
			for (int w = count; w < count1; w++)
			{
				printf("Nome: ");
				scanf("%s", vetAluno[w].nome);
				printf("RA: ");
				scanf("%d", &vetAluno[w].ra);
				printf("\n");
				count++;
			}		
		
			break;

		case 2:
			printf("\n\n\tCadastro Disciplina\n");
			printf("Nome da Disciplina: ");
			scanf("%s", disciplina);

			printf("RA do Aluno: ");
			scanf("%d", &auxRA);
			for (r = 0; r < TAM; r++)
			{
				if (auxRA == vetAluno[r].ra) {
					printf("Aluno encontrado.\n");
					pos = r;
				}

			}

			//ERRO 
			if (pos != r) {
				printf("Aluno nao encontrado.\n");
			}
			else {
				printf("Nome: %s", vetAluno[pos].nome);
				printf("RA: %d", vetAluno[pos].ra);
				strcpy(vetAluno[pos].disciplina, disciplina);
				printf("Disciplina: %s", vetAluno[pos].disciplina);
			}
			
			break;

		/*case 3:
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
		*/
		case 8:
			printf("\n\n\tImpressoes\n");
			subMenuImp();
			scanf("%d", &opMenu);
			switch (opMenu)
			{
			case 1:
				printf("\n\n\tLista de todos os alunos\n");

				for (int e = 0; e < count1; e++)
				{
					printf("\n-----------------------------\n");
					printf("\nCadastrados: \n");
					printf("Nome: %s", vetAluno[e].nome);
					printf("\nRA: %d", vetAluno[e].ra);
					printf("\n-----------------------------\n");
				}

				break;

			default:
				break;
			}
			
			break;

			
		default:
			break;
		}
		printf("Continuar? [0 = Nao]");
		scanf("%d", &op);
	} while (op != 0);



	system("pause");
}

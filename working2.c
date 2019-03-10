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
	int reg;
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
//funcoes de busca, retornam -1 caso nao achem
int buscaAluno(Aluno *vet, int n, int ra) {
	int x;
	for (x = 0; x < n; x++)
	{
		if (ra == vet[x].ra) {

			return x;
		}
	}
	return -1;
}

int buscaProf(Professor *prof, int n, int reg) {
	int zz;
	for (zz = 0; zz < n; zz++)
	{
		if (reg == prof[zz].reg) {

			return zz;
		}
	}
	return -1;


}

int buscaDis(Disciplina *disc, int n, char nome[10]) {
	int yy;
	for (yy = 0; yy < n; yy++)
	{
		if (strcmp(disc[yy].nome, nome) == 0) {
			return yy;
		}
	}
	return -1;
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
	Professor vetProfessor[TAM]; 
	Disciplina vetDisciplina[TAM];
	int r=0, opcao, op = 1, opMenu, opAluno, opDisc, count = 0, count1 = 0, pos = 0, auxRA = 0;
	int count2 = 0, count3 = 0, count4 = 0, count5 = 0, auxReg, opProf, busca, opMat = 0, auxRaMat;
	char auxNome[10];
	char disciplina[20], auxDisciplina[20];

	do
	{
		menu();

		printf("\nOpcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:

			printf("\n\n\tCadastro Aluno\n");
			printf("Quantidade de alunos a serem cadastrados: ");
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
			//teste de busca, depois vai sair daqui
			printf("\nBusca:\nRA: ");
			scanf("%d", &auxRA);
			if (buscaAluno(vetAluno, count1, auxRA) != -1) {
				printf("Aluno encontrado.\n");				
			}
			else
			{
				printf("Aluno nao encontrado.\n");
			}


			break;

		case 2:
			printf("\n\n\tCadastro Disciplina\n");
			printf("Quantidade de disciplinas a serem cadastradas: ");
			scanf("%d", &opDisc);
			count5 = (count4 + opDisc);

			for (int nn = count4; nn < count5; nn++)
			{
				printf("Nome: ");
				scanf("%s", vetDisciplina[nn].nome);
			
				printf("\n");
				count4++;
			}

			printf("\nBusca:\nNome da Disciplina: ");
			scanf("%s", disciplina);
			if (buscaDis(vetDisciplina, count5, disciplina) != -1) {
				printf("Disciplina encontrada.\n");
			}
			else
			{
				printf("Disciplina nao encontrada.\n");
			}
			
			break;

		case 3:
			printf("\n\n\tCadastro Professor\n");
			printf("Quantidade de professores a serem cadastrados: ");
			scanf("%d", &opProf);
			count3 = (count2 + opProf);

			for (int z = count2; z < count3; z++)
			{
				printf("Nome: ");
				scanf("%s", vetProfessor[z].nome);
				printf("Numero de Registro: ");
				scanf("%d", &vetProfessor[z].reg);
				printf("\n");
				count2++;
			}
			printf("\nBusca:\nNumero de registro: ");
			scanf("%d", &auxReg);
			if (buscaProf(vetProfessor, count3, auxReg) != -1) {
				printf("Professor encontrado.\n");
			}
			else
			{
				printf("Professor nao encontrado.\n");
			}

			break;
			
		case 4:
			printf("\n\n\tMatricular Aluno(s)\n");
			do
			{
				printf("Digite o RA: ");
				scanf("%d", &auxRaMat);
				if (buscaAluno(vetAluno, count1, auxRaMat) != -1) { //funcao que ve se existe o RA digitado
					printf("Digite a disciplina a qual o aluno sera matriculado: ");
					scanf("%s", auxDisciplina);
					if(buscaDis(vetDisciplina, count5, auxDisciplina) != -1){
						for (int ii = 0; ii < count5; ii++)//prestar atencao nesse count, pode dar erro depois
						{
							strcpy(vetAluno[ii].disciplina, auxDisciplina);
							printf("Disciplina: %s\n", vetAluno[ii].disciplina);
						}
					}
					else
					{
						printf("Disciplina nao encontrada.\n");
					}

				}
				else
				{
					printf("Aluno nao encontrado.\n");
				}
				printf("Mais 1? 0 = Nao\nOp: ");
				scanf("%d", &opMat);

			} while (opMat != 0);
			
			break;

		/*
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

			case 2:
				printf("\n\n\tLista de todas as disciplinas \n");

				printf("Nome: ", disciplina);

				break;

			case 3:
				printf("\n\n\tLista de todos os professores \n");

				for (int c = 0; c < count3; c++)
				{
					printf("\n-----------------------------\n");
					printf("\nCadastrados: \n");
					printf("Nome: %s", vetProfessor[c].nome);
					printf("\nRA: %d", vetProfessor[c].reg);
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

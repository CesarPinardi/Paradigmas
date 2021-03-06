#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5


typedef struct aluno {
	char nome[10];
	int ra;
	char disciplina[20];
	int turma; //chamar struct disciplina e alterar a chamada
}Aluno;

typedef struct disciplina {
	char nome[20];
	int turma;
}Disciplina;

typedef struct professor {
	char nome[10];
	int reg;
	Disciplina disciplina;
}Professor;

typedef struct matricula {
	char nome[20];
	Disciplina disc;
}Matricula;



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

Aluno addAluno(void) {
	Aluno add;
	printf("\nDigite o nome do aluno: ");
	scanf("%s", add.nome);
	printf("Digite o RA do aluno: ");
	scanf("%d", &add.ra);
	printf("OK!\n");
	return add;
}

Professor addProf(void) {
	Professor addP;
	printf("\nDigite o nome do professor: ");
	scanf("%s", addP.nome);
	printf("Digite o numero de registro do professor: ");
	scanf("%d", &addP.reg);
	printf("OK!\n");
	return addP;
}

Disciplina addDisc(void) {
	Disciplina addD;
	printf("\nDigite o nome da disciplina: ");
	scanf("%s", addD.nome);
	printf("\nDigite a turma: ");
	scanf("%d", &addD.turma);
	printf("OK!\n");
	return addD;
}


Matricula addMat() {
	Matricula addM;
	printf("\nNome do aluno: ");
	scanf("%s", addM.nome);
	printf("Disciplina em que o aluno '%s' sera matriculado: ", addM.nome);
	scanf("%s", addM.disc.nome);
	printf("Turma da disciplina em que o aluno '%s' sera matriculado (1 ou 2): ", addM.nome);
	scanf("%d", &addM.disc.turma);
	printf("OK!\n");
	return addM;
}

Matricula cancelaMat() {
	Matricula canM;
	//while para n alunos até sair, n disciplinas tbm
	printf("Nome do aluno: ");
	scanf("%s", canM.nome);
	printf("Disciplina em que o aluno '%s' sera removido: ", canM.nome);
	scanf("%s", canM.disc.nome);
	printf("Turma da disciplina em que o aluno '%s' sera matriculado (1 ou 2): ", canM.nome);
	scanf("%d", &canM.disc.turma);
	strcpy(canM.nome, "00000");
	strcpy(canM.disc.nome, "00000");
	canM.disc.turma = 00000;
	//se encontrar tudo aqui:
	printf("OK!\n");
	return canM;
}

Professor vincular() {
	Professor vinc;
	printf("Disciplina a ser vinculada: ");
	scanf("%s", vinc.disciplina.nome);
	printf("Turma da disciplina a ser vinculada: ");
	scanf("%d", &vinc.disciplina.turma);
	printf("OK!\n");
	return vinc;

}

Professor desvincular(){
	Professor desvinc;
	printf("Disciplina a ser desvinculada: ");
	scanf("%s", desvinc.disciplina.nome);
	printf("Turma da disciplina a ser desvinculada: ");
	scanf("%d", &desvinc.disciplina.turma);
	strcpy(desvinc.disciplina.nome, "00000");
	desvinc.disciplina.turma = 00000;
	printf("OK!\n");
	return desvinc;

}

void main() {

Aluno vetAluno[TAM];
Professor vetProfessor[TAM];
Disciplina vetDisciplina[TAM];
Matricula vetMat[TAM];

int r = 0, opcao, op = 1, opMenu, opAluno, opDisc, count = 0, count1 = 0, pos = 0;
int auxRA = 1, a1, p1, d1, d2, d3, v1, v2;
int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, i2 = 0;
int auxBusca, auxTurma;
int count2 = 0, count3 = 0, count4 = 0, count5 = 0, auxReg, opProf, busca, opMat = 0, auxRaMat;
char auxNome[20];
char disciplina[20], auxDisciplina[20];

do
{
	menu();

	printf("\nOpcao: ");
	scanf("%d", &opcao);

	switch (opcao)
	{
	case 1:
		a1 = 1;
		printf("\n\n\tCadastro de Aluno\n");
		while (a1 != 0) {
			vetAluno[i] = addAluno();
			printf("\nCadastrar mais um? 0 = Sair\nOp: ");
			scanf("%d", &a1);
			i++;
		}	

		break;

	case 2:
		printf("\n\n\tCadastro Disciplina\n");
		d1 = 1;
		while (d1 != 0) {
			vetDisciplina[j] = addDisc();
			printf("\nNome: %s\n", vetDisciplina[j].nome);
			printf("\nCadastrar mais um? 0 = Sair\nOp: ");
			scanf("%d", &d1);
			k++;
		}

		break;

	case 3:
		printf("\n\n\tCadastro de Professor\n");
		p1 = 1;
		while (p1 != 0) {
			vetProfessor[j] = addProf();
			printf("\nNome: %s\n", vetProfessor[j].nome);
			printf("\nNumero de Registro: %d\n", vetProfessor[j].reg);
			printf("\nCadastrar mais um? 0 = Sair\nOp: ");
			scanf("%d", &p1);
			j++;
		}

		break;

	case 4:
		printf("\n\n\tMatricular Aluno(s)\n");
		d2 = 1;
		while (d2 != 0)
		{

			vetMat[l] = addMat();

			printf("\nNome aluno: %s", vetMat[l].nome);
			printf("\nDisciplina: %s, Turma: %d", vetMat[l].disc.nome, vetMat[l].disc.turma);
			printf("\nMatricular mais um? 0 = Sair\nOp: ");
			scanf("%d", &d2);
			l++;
		}
		break;


	case 5:
		printf("\n\n\tCancelar Matricula\n");
		d3 = 1;
		while (d3 != 0)
		{
			vetMat[m] = cancelaMat();
			printf("\nNome aluno: %s", vetMat[m].nome);
			printf("\nDisciplina: %s, Turma: %d", vetMat[m].disc.nome, vetMat[m].disc.turma);
			printf("\nRemover mais um? 0 = Sair\nOp: ");
			scanf("%d", &d3);
			m++;
		}
		break;

		case 6:
			printf("\n\n\tVincular Disciplina\n");
			printf("\nNumero de registro do professor: ");
			scanf("%d", &auxReg);
			auxBusca = buscaProf(vetProfessor, j, auxReg);
			if(auxBusca != -1){
				v1 = 1;
				n = auxBusca;
				while (v1 != 0)
				{
					vetProfessor[n] = vincular();
					printf("\nNome da disciplina: %s\nTurma: %d", vetProfessor[n].disciplina.nome, vetProfessor[n].disciplina.turma);
					printf("\nNumero de registro do professor: %d\n", vetProfessor[n].reg);
					printf("\nVincular mais um? 0 = Sair\nOp: ");
					scanf("%d", &v1);
					n++;
				}

			}
			else
			{
				printf("Numero de registro não encontrado.\n");
			}
			
			break;
	
		case 7:
			printf("\n\n\tDesvincular Disciplina\n");
			v2 = 1;
			while (v2 != 0)
			{
				vetProfessor[o] = desvincular();

				printf("\nDesvincular mais um? 0 = Sair\nOp: ");
				scanf("%d", &v2);
				o++;
			}

			break;

	case 8:
		printf("\n\n\tImpressoes\n");
		subMenuImp();
		scanf("%d", &opMenu);
		switch (opMenu)
		{
		case 1:
			printf("\n\n\tLista de todos os alunos\n");

			for (int e = 0; e < i; e++)
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
			printf("Disciplinas: \n");
			for (int ww = 0; ww < k; ww++)
			{
				printf(" %s\n", vetDisciplina[ww].nome);
			}

			break;

		case 3:
			printf("\n\n\tLista de todos os professores \n");

			for (int c = 0; c < j; c++)
			{
				printf("\n-----------------------------\n");
				printf("\nCadastrados: \n");
				printf("Nome: %s", vetProfessor[c].nome);
				printf("\nRA: %d", vetProfessor[c].reg);
				printf("\n-----------------------------\n");
			}

			break;

		case 4:
			printf("\n\n\tImprimir lista de disciplinas de um aluno\n");
			printf("Digite o nome do aluno: ");
			scanf("%s", auxNome);
			printf("Digite o RA: ");
			scanf("%d", &auxRA);
			auxBusca = buscaAluno(vetAluno, i, auxRA);
			if (auxBusca != -1)
			{
				printf("Disciplinas:\n%s  Turma: %d\n", vetMat[auxBusca].disc.nome, vetMat[auxBusca].disc.turma);
			}
			else {
				printf("Aluno nao encontrado\n");
			}
			break;

		case 5:
			printf("\n\n\tImprimir lista de alunos em uma disciplina e turma\n");
			printf("Digite a disciplina: \nR: ");
			scanf("%s", auxDisciplina);
			//verificar se existe
			printf("Digite a turma: \nR: ");
			scanf("%d", &auxTurma);
			//verificar
			for (int i1 = 0; i1 < i; i1++)
			{
				if ((strcmp(vetMat[i1].disc.nome, auxDisciplina) == 0) && (vetMat[i1].disc.turma == auxTurma)) {
					printf("Nome: %s\n", vetMat[i1].nome);
				}

			}

			break;

		case 6:
			printf("\n\n\tLista de alunos de uma disciplina\n");
			printf("Digite a disciplina: \n");
			scanf("%s", auxDisciplina);
			auxBusca = buscaDis(vetDisciplina, k, auxDisciplina);
			if (auxBusca != -1) {
				i2 = auxBusca;
				for (i2 = 0; i2 < i; i2++)
				{
					if ((strcmp(vetMat[i2].disc.nome, auxDisciplina) == 0) && (vetMat[i2].disc.turma == auxTurma)) {
						printf("Nome: %s\n", vetMat[i2].nome);
					}

				}
			}
			
			

			break;

		case 7:
			printf("\n\n\tLista de todas as disciplinas ministradas por um professor\n");
			printf("\nDigite o numero de registro do professor: ");
			scanf("%d", &auxReg);
			auxBusca = buscaProf(vetProfessor, j, auxReg);
			if(auxBusca != -1){
				for (int g = 0; g < k; g++) {
					printf("Disciplinas:\n%s\n", vetProfessor[auxBusca].disciplina.nome);
				}	

			}	
			else
			{
				printf("Erro.\n");
			}
			

			break;


		case 8:
			printf("\n\n\tLista de todas os professores vinculados a uma disciplina\n");
			printf("Digite o nome da disciplina: ");
			scanf("%s", auxDisciplina);
			auxBusca = buscaDis(vetDisciplina, k, auxDisciplina);
			if(auxBusca != -1){
				for(int h = 0; i < j; i++){
					
					printf("Disciplina: %s\n", vetDisciplina[auxBusca].nome);
					printf("Professores: %s\n", vetProfessor[auxBusca].nome);

				}

			}

			break;

		default:
			printf("Opcao invalida!\n");
			break;
		}

		break;


	default:
		printf("Opcao invalida!\n");
		break;

	}
	printf("\nOutra operacao? [0 = Nao]\nOp: ");
	scanf("%d", &op);


} while (op != 0);



system("pause");
}

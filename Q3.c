#include <stdio.h>
#include <string.h>

typedef struct
{
	int numpj;
	int valorpj;
	char despesapj[2];
}Projeto;

void ControlePj(Projeto *nPj)
{

	
	Projeto tempPj;
	//printf("Numero do projeto:\n"); colocar no main com condição utilizando i;
	//scanf("%d", &tempPj.numpj);
	printf("Digite o valor:\n");
	scanf("%d", &tempPj.valorpj);
	printf("Qual é o tipo de despesa?\n'R' para receita.\n'D' para despesa.\n");
	scanf(" %[^\n]s", tempPj.despesapj);
	char receita[2] = {'R'};
	//char despesa[2] = {'D'};
	if(strcmp(tempPj.despesapj, receita) == 0) nPj->valorpj = nPj->valorpj + tempPj.valorpj;
	else nPj->valorpj = nPj->valorpj - tempPj.valorpj;
	printf("\nSaldo do projeto: %d\n\n", nPj->valorpj);
}

int main(void) 
{
	int i = 0;
	Projeto pj[10] = {0};
	printf("\tCONTROLE FINANCEIRO DE PROJETOS\n\t  QUANTIDADE DE PROJETOS: 9\n\n");
	while(1 != 0)
	{
		printf("Para atualizar um projeto digite o numero referente a ele:\nPara finalizar o programa digite qualquer valor nao associado a um projeto.\n");
		scanf("%d", &i);
		if(i >= 0 && i <= 9) ControlePj(&pj[i]);
		else break;
	}
	printf("\nAté mais!\n");
	return 0;
}


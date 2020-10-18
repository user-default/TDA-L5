#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char nome[50];
	float saldo;
	char senha[9];
	char chave[5];
	int numConta;
	
}Conta;
void criarConta(int *size_acc, Conta *acc)
{
	acc->numConta = *size_acc;
	acc->saldo = 0;
	printf("Digite seu nome:\n");
	scanf(" %[^\n]s", acc->nome);
	printf("\nConta criada!\nNOME: %s\nNUMERO DA CONTA: %d\n",acc->nome,acc->numConta);	
}
void criarSenhaChave(Conta *acc)
{	
		acc->senha[0] = '\0';
		acc->chave[0] = '\0';
		while((strlen(acc->senha))!= 8)
		{
    	printf("Digite uma senha com 8 digitos:\n");
    	scanf(" %[^\n]s", acc->senha);
		}
		while((strlen(acc->chave)) != 4)
		{
    	printf("Digite uma chave de até 4 dígitos:\n");
			scanf(" %[^\n]s", acc->chave);
		}
    printf("\nSenha e chave criada com sucesso!\nSenha: %s\nChave: %s\n", acc->senha, acc->chave);	
}
void depositarConta(Conta *acc)
{		
		char nome[50];
    float deposito = 1;
		printf("\nConfirme seu nome:\n");
		scanf(" %[^\n]s", nome);
		if((strcmp(acc->nome, nome)) == 0)
		{
			printf("Nome confirmado.\n");
		  while(deposito > 0)
			{	
      	printf("\nQual e o valor do seu deposito?\n\nDigite 0 para sair.\n");
      	scanf("%f", &deposito);
        if(deposito > 0)
	      {
      		acc->saldo += deposito;
          printf("\nDeposito realizado:\nValor:%.2f\n",deposito);
					printf("Saldo depois do deposito %.2f\n", acc->saldo);
				}
			}	
		}			
}
void saldoConta(Conta *acc)
{
	char checarsenha[9];
	int tentativas = 0;
	while(tentativas < 4)
	{		
		printf("Digite sua senha:\n");
		scanf(" %[^\n]s", checarsenha);
		if((strcmp(checarsenha, acc->senha))== 0) 
	  {	
			printf("\nSaldo em conta: %.2f\n", acc->saldo);
			break;
		}
		else
		{
			printf("\nSenha incorreta!\n");
			tentativas++;
		}
		if (tentativas == 4)
		{
			printf("Tente novamente outra hora.\n");
			exit(0);
		}
	}
}

void sacarConta(Conta *acc)
{
	int tentativas = 0;
	float saque = 1;
	char senha[9];
	char chave[5];
	
	printf("\nDigite sua senha:\n");
	scanf(" %[^\n]s",senha);
	for(tentativas = 0;tentativas < 4;)
	{
		if((strcmp(senha, acc->senha)) == 0)
		{
			printf("Senha confirmada.\n");
			break;
		}
		else
		{
			tentativas++;
			if(tentativas == 4) exit(0);
			printf("Senha incorreta, tente novamente.\nTentativas: %d\n", tentativas);
			scanf(" %[^\n]s", senha);
 		}
	}		
	printf("Digite sua chave:\n");
	scanf(" %[^\n]s", chave);
	for(tentativas = 0;tentativas < 4;)
	{
		if((strcmp(chave, acc->chave))==0)
		{	
			printf("Chave confirmada.\n");
			break;
		}
		else
		{
			tentativas++;
			if(tentativas == 4) exit(0);
			printf("Chave incorreta, tente novamente.\nTentativas : %d\n", tentativas);
			scanf(" %[^\n]s", chave);
		}
  }
	printf("\nQual valor desejas sacar?\n");
	scanf("%f", &saque);
	
	while(saque > 0 && !(saque < 0))
	{
		if(saque <= acc->saldo && saque != 0)
		{
			 acc->saldo -= saque;
			 printf("Saque realizado!\nSaldo atualizado: %.2f\n", acc->saldo);
		   printf("Deseja repetir a operação com um novo valor?\nSe sim digite o valor desejado:\nCaso contrario digite 0 para sair.\n");
		   scanf("%f", &saque);
		   if(saque == 0)
			 {
				 printf("Operação de saque finalizada pelo usuário!\n");
				 break;
			 }			
			 if(saque > acc->saldo) 
			 {
				printf("Tentativa de saque suspeita, tente outra hora.\n");
				exit(0);
			 }
     }		
	}
}
void deletarConta(Conta *acc)
{
	int tentativas = 0;
	char confirma[4];
	char senha[9];
	char chave[5];
	char nome[50];
	for(tentativas = 0; tentativas < 4; tentativas++)
	{
		if(tentativas ==4)
		{
			printf("Tente mais tarde.\n");
			exit(1);
		}
		printf("Digite seu nome:\n");
		scanf(" %[^\n]s", nome);
		if((strcmp(nome, acc->nome)) == 0)
		{
			printf("Nome confirmado!\n");
			break;
		}
	}
	for(tentativas = 0;tentativas < 4; tentativas++)
	{
		if(tentativas == 4)
		{
			printf("Tente mais tarde.\n");
			exit(0);		
		}
		printf("Para encerrar a conta digite sua senha:\n");
		scanf(" %[^\n]s", senha);
		if((strcmp(senha, acc->senha)) == 0)
		{
			printf("Senha confirmada!\n");
			break;		
		}
		else printf("Senha incorreta, tente novamente.\nTentativas: %d\n", tentativas);
	}
	for(tentativas = 0; tentativas < 4; tentativas++)
	{
		if(tentativas == 4)
		{
			printf("Tente mais tarde.\n");
			exit(1);
		}
		printf("Digite sua chave de 4 digitos:\n");
		scanf(" %[^\n]s", chave);
		if((strcmp(chave, acc->chave)) == 0)
		{
			printf("Chave confirmada!\n");
			break;
		}
		else printf("Chave incorreta, tente novamente.\nTentativas: %d\n", tentativas);
	}
	if(acc->saldo != 0)	printf("Você ainda possui saldo em conta, esvazie sua conta antes de encerrar!\n");
	else
	{
		int confirma = 0;
		printf("Digite 1 para confirmar o encerramento da conta:\n");
		scanf("%d", &confirma);
		if(confirma == 1)
		{
			printf("Encerramento confirmado!\n");
			acc->chave[0] = '\0';
			acc->senha[0] = '\0';
			acc->nome[0] = '\0';
			acc->numConta = 0;
			printf("Conta encerrada!\n");
		} 
	}	
		
}

int main(void) 
{	
	int n_acc = -1;
	Conta acc[10];
	int size_acc = -1;

	for(int c = -1; c != 0;)
	{
		//system("clear");	
		printf("\nBEM VINDO AO SISTEMA BANCARIO INDEPENDENTE(SBI)!\n");
		printf("Opções disponíveis:\n\n");
		printf("\t1 - Abrir conta\n\t2 - Consultar saldo\n\t3 - Depositar um valor\n\t4 - Realizar saques\n\t5 - Encerrar a conta\n");
		printf("\n\tDigite o numero referente a uma das opções, ou 0 para sair:\n\n");	
		scanf("%d", &c);
		if(c == 1)
		{	
				size_acc++;
				criarConta(&size_acc, &acc[size_acc]);
				criarSenhaChave(&acc[size_acc]);			
				getchar();
		}
		if(c == 2)
		{
				printf("Digite o numero da sua conta:\n");
				scanf("%d", &n_acc);
				saldoConta(&acc[n_acc]);
		}
		if(c == 3)
		{
				printf("Digite o numero da sua conta:\n");
				scanf("%d", &n_acc);
				depositarConta(&acc[n_acc]);
		}		
		if(c == 4)
		{		printf("Digite o numero da sua conta:\n");
				scanf("%d", &n_acc);
				sacarConta(&acc[n_acc]);
		}		
		if(c == 5)
		{
				printf("Digite o numero da sua conta:\n");
				scanf("%d", &n_acc);
				deletarConta(&acc[n_acc]);
		}		
		if(c == 0) printf("Programa finalizado pelo usuário!\n");
		if(c < 0 || c > 5) printf("Digite um número válido!\n");
	}
	return 0;
}


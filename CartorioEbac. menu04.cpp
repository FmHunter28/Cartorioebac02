#include <stdio.h>   // biblioteca de cominica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das Strings

int registro()  //Fun��o responsavel por cadastrar os usuarios no Sistema
{
	// Inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de variaveis/string
	
	printf("Digite o cpf a ser cadatrado: "); //coletando as informa��esdo usuario
	scanf("%s", cpf); // % s refere-se a string
	
	strcpy(arquivo, cpf); // Resposavel por copiar os valores das Strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);  // Salva o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
	 printf("\nEssas s�o as informa��es do usuario: ");
	 printf("%s", conteudo);
	 printf("\n");
	 printf("\n");
	  	
	}
    
    system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuarioa ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
}


int main()
    {
	int opcao=0; // Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	      
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
    	printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar Nome\n");
	    printf("\t2 - Consultar Nome\n");
	    printf("\t3 - Deletar Nome\n");
	    printf("\t4 - Listar cadastros\n");
	    printf("\t5 - Sair do Sistema\n\n");
	    printf("Op��o: "); // Fim do menu
	
	    scanf("%d" , &opcao); // Armazenando a escolha do usuario
	
	    system("cls");
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();
            break;
            
            case 2:
            consulta();
			break;
			
			case 3:
			deletar();
            break;
            
            case 4:
            printf("Liste os cadastros do sistema!\n");
            return 0;
            break;
            
            case 5:
            printf("Obrigdo por ultilizar o sistema!\n");
            return 0;
            break;
            
            
            default:
            printf("Est� op��o n�o est� disponivel!\n");
            system("pause");
            break;
				
		}
	
	
    }
	
}

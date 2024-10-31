#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings


int registrar() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char simounao;

    do {
        // Coleta informa��es do usu�rio
        printf("Digite o CPF a ser cadastrado: ");
        scanf("%s", cpf);

        // Cria o arquivo com o nome do CPF
        strcpy(arquivo, cpf);
        FILE *file = fopen(arquivo, "w");
        if (file == NULL) {
            printf("Erro ao criar o arquivo!\n");
            return 1;
        }

        // Escreve as informa��es no arquivo
        fprintf(file, "%s,", cpf);  // Salva CPF
        printf("Digite o nome a ser cadastrado: ");
        scanf("%s", nome);
        fprintf(file, "%s,", nome);  // Salva Nome

        printf("Digite o sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome);
        fprintf(file, "%s,", sobrenome);  // Salva Sobrenome

        printf("Digite o cargo a ser cadastrado: ");
        scanf("%s", cargo);
        fprintf(file, "%s", cargo);  // Salva Cargo

        fclose(file);  // Fecha o arquivo ap�s salvar

        // Pergunta se o usu�rio deseja registrar outro nome
        printf("Deseja fazer um novo cadastro? (s/n): ");
        scanf(" %c", &simounao);  // L� a resposta do usu�rio

    } while (simounao == 's' || simounao == 'S');  // Continua se o usu�rio digitar 's' ou 'S'

    return 0;  // Retorna ao menu principal
}
	int consultar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];
    char cpf_lido[40], nome[50], sobrenome[50], cargo[50];  // Vari�veis para armazenar os dados

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo, n�o foi localizado!.\n"); 
		// Finaliza a fun��o se o arquivo n�o for encontrado

    }

    // Lendo o conte�do do arquivo
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        // Usando sscanf para separar os dados com base nas v�rgulas
       sscanf(conteudo, "%[^,],%[^,],%[^,],%[^\n]", cpf_lido, nome, sobrenome, cargo);

        // Imprimindo os dados separados
        printf("\nEssas s�o as informa��es do usu�rio:\n");
        printf("CPF: %s\n", cpf_lido);
        printf("Nome: %s\n", nome);
        printf("Sobrenome: %s\n", sobrenome);
        printf("Cargo: %s\n\n", cargo);
    }

    fclose(file);
    system("pause");
    return 0;
}
	
	int deletar ()
	{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);

	
	if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso!\n"); // Tenta remover o arquivo com o nome do CPF
        
    } else {
        printf("O usu�rio n�o se encontra no sistema!\n");
        
    }
	system("pause");
    return 0;

	}

	int main ()
	{
	int opcao=0; //definindo v�riaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");	
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); // Fim do menu
	    printf("Op��o: ");
    
    	scanf("%d", &opcao); //armazenando as informa��es
    
    	system("cls");
    	
    	switch(opcao) //Inicio da sele��o do Menu
    	{ 
			case 1:
    		registrar (); // chamada de fun��es
    		break;
    		
    		case 2:
    		consultar ();
    		break;
    		
    		case 3:
    		deletar ();
			break;
    		
    		default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause"); 
    		break;	
		}//fim da sele��o do Menu
    	
    
	} 
	}


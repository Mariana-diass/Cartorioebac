#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings


int registrar() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char simounao;

    do {
        // Coleta informações do usuário
        printf("Digite o CPF a ser cadastrado: ");
        scanf("%s", cpf);

        // Cria o arquivo com o nome do CPF
        strcpy(arquivo, cpf);
        FILE *file = fopen(arquivo, "w");
        if (file == NULL) {
            printf("Erro ao criar o arquivo!\n");
            return 1;
        }

        // Escreve as informações no arquivo
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

        fclose(file);  // Fecha o arquivo após salvar

        // Pergunta se o usuário deseja registrar outro nome
        printf("Deseja fazer um novo cadastro? (s/n): ");
        scanf(" %c", &simounao);  // Lê a resposta do usuário

    } while (simounao == 's' || simounao == 'S');  // Continua se o usuário digitar 's' ou 'S'

    return 0;  // Retorna ao menu principal
}
	int consultar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];
    char cpf_lido[40], nome[50], sobrenome[50], cargo[50];  // Variáveis para armazenar os dados

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo, não foi localizado!.\n"); 
		// Finaliza a função se o arquivo não for encontrado

    }

    // Lendo o conteúdo do arquivo
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        // Usando sscanf para separar os dados com base nas vírgulas
       sscanf(conteudo, "%[^,],%[^,],%[^,],%[^\n]", cpf_lido, nome, sobrenome, cargo);

        // Imprimindo os dados separados
        printf("\nEssas são as informações do usuário:\n");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);

	
	if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n"); // Tenta remover o arquivo com o nome do CPF
        
    } else {
        printf("O usuário não se encontra no sistema!\n");
        
    }
	system("pause");
    return 0;

	}

	int main ()
	{
	int opcao=0; //definindo váriaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");	
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); // Fim do menu
	    printf("Opção: ");
    
    	scanf("%d", &opcao); //armazenando as informações
    
    	system("cls");
    	
    	switch(opcao) //Inicio da seleção do Menu
    	{ 
			case 1:
    		registrar (); // chamada de funções
    		break;
    		
    		case 2:
    		consultar ();
    		break;
    		
    		case 3:
    		deletar ();
			break;
    		
    		default:
			printf("Essa opção não está disponivel!\n");
			system("pause"); 
    		break;	
		}//fim da seleção do Menu
    	
    
	} 
	}


#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

	int registrar () { // Função responsavel por cadastrar o usuario no sistema
	char arquivo [40]; // inicio criação de variáveis/string
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informações do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valors da string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel dentro do arquivo
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobremenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
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
    	
    	switch( opcao) //Inicio da seleção do Menu
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


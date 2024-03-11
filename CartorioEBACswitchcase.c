#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaços de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // função para a tela do registro de nomes, responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf ("Digitar o CPF a ser cadastrado:  "); //coletando informação do usuário
	scanf ("%s", cpf); // armazenando o CPF do usuário (%s refere-se a string)
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings, neste caso o nome do arquivo será o mesmo do CPF
	
	FILE *file; // cria o arquivo no computador
	file = fopen(arquivo, "w"); // cria o arquivo e nomeia, o "w" signifita write
	fprintf(file, cpf); // salva no arquivo o número do CPF
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, ","); // para separar as variáveis por vírgula
	fclose(file); //fecha p arquivo
	
	printf("Digite o nome a ser cadastrado:   "); //coletando informação do usuário
	scanf("%s", nome); // armazenando o nome do usuário
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, nome); // salva no arquivo o nome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, ","); // para separar as variáveis por vírgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:   "); //coletando informação do usuário
	scanf("%s", sobrenome); //armazenando o sobrenome do usuário
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, sobrenome); // salva no arquivo o sobrenome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, ","); // para separar as variáveis por vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:   "); // armazenando o cargo do usuário
	scanf("%s", cargo); //armazenando o cargo do usuário
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, cargo); // salva no arquivo o cargo
	fclose(file); // fecha o arquivo
	
	system("pause");
}

int consulta() // função para a tela de consulta de nomes
{
	setlocale (LC_ALL, "Portuguese"); // definindo o idioma
	//início da criação de variáveis/string
	char cpf[40]; // variável com a qual o usuário consulta os arquivos
	char conteudo[200]; // ler o conteúdo do arquivo
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado:  "); //coletando informações do usuário
	scanf("%s", cpf); // armazenando cpf do usuário
	
	FILE *file; //busca o arquivo no computador
	file = fopen(cpf,"r"); // ler o arquivo com o cpf digitado
	
	if(file == NULL) // condição em caso de CPF não encontrado
	{
		printf("Arquivo não localizado!\n"); // informa ao usuário
	}
	
	while(fgets (conteudo, 200, file) != NULL) // ler as informações nos 200 caracteres do conteúdo
	{
		printf("\nEssas são as informações do usuário:  "); //apresenta as informações lidas
		printf("%s", conteudo); //armazena as informações
		printf("\n\n");
	}
	
	system ("pause"); //dá tempo de leitura ao usuário
}

int deletar () // função para a tela onde serão deletados os nomes
{
	//início da criação de variável para a função deletar
	char cpf[40];
	//fim da criação de variável para a função deletar
	
	printf("Digite o CPF a ser deletado: "); // coleta informação do usuário
	scanf("%s", cpf); // %s significa um pedido de armazenar as informações da "string"
	
	remove(cpf); // remove o cpf digitado
	
	FILE *file;
	file = fopen(cpf, "r"); // lê o aarquivo com cpf digitado
	
	if(file == NULL) // condição caso o cpf não seja localizado
	{
		printf("O usuário não se encontra no sistema!.\n"); // informa ao usuário
		system("pause");
	}
}

int main () // ponto de partida
{
	int opcao=0; // definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system ("cls"); // responsável por limpar a tela
		
		setlocale (LC_ALL, "Portuguese"); // definindo o idioma
	
		printf ("### Cartório da EBAC ###\n\n"); // início do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n");
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Opção:  "); // fim do menu
	
		scanf ("%d", &opcao); // armazenando a escolha do usuário
	
		system ("cls");
	
		switch(opcao) // início da selação do menu
		{
			case 1: // linkado com a função registro
			registro(); // chamada de funções
			break;
			
			case 2: // linkado com a função consulta
			consulta();
			break;
			
			case 3: // linkado com a função deletar
			deletar();
			break;
			
			case 4:
			printf ("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: // erros de digitação do usuário no menu
			printf ("Esta opção não está disponível!\n");
			system ("pause");
			break;				
		} // fim da seleção
		
	}
	
}

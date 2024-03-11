#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // fun��o para a tela do registro de nomes, respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf ("Digitar o CPF a ser cadastrado:  "); //coletando informa��o do usu�rio
	scanf ("%s", cpf); // armazenando o CPF do usu�rio (%s refere-se a string)
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings, neste caso o nome do arquivo ser� o mesmo do CPF
	
	FILE *file; // cria o arquivo no computador
	file = fopen(arquivo, "w"); // cria o arquivo e nomeia, o "w" signifita write
	fprintf(file, cpf); // salva no arquivo o n�mero do CPF
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, ","); // para separar as vari�veis por v�rgula
	fclose(file); //fecha p arquivo
	
	printf("Digite o nome a ser cadastrado:   "); //coletando informa��o do usu�rio
	scanf("%s", nome); // armazenando o nome do usu�rio
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, nome); // salva no arquivo o nome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, ","); // para separar as vari�veis por v�rgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:   "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); //armazenando o sobrenome do usu�rio
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, sobrenome); // salva no arquivo o sobrenome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, ","); // para separar as vari�veis por v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:   "); // armazenando o cargo do usu�rio
	scanf("%s", cargo); //armazenando o cargo do usu�rio
	
	file = fopen(arquivo, "a"); // abre o mesmo arquivo para atualizar
	fprintf(file, cargo); // salva no arquivo o cargo
	fclose(file); // fecha o arquivo
	
	system("pause");
}

int consulta() // fun��o para a tela de consulta de nomes
{
	setlocale (LC_ALL, "Portuguese"); // definindo o idioma
	//in�cio da cria��o de vari�veis/string
	char cpf[40]; // vari�vel com a qual o usu�rio consulta os arquivos
	char conteudo[200]; // ler o conte�do do arquivo
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado:  "); //coletando informa��es do usu�rio
	scanf("%s", cpf); // armazenando cpf do usu�rio
	
	FILE *file; //busca o arquivo no computador
	file = fopen(cpf,"r"); // ler o arquivo com o cpf digitado
	
	if(file == NULL) // condi��o em caso de CPF n�o encontrado
	{
		printf("Arquivo n�o localizado!\n"); // informa ao usu�rio
	}
	
	while(fgets (conteudo, 200, file) != NULL) // ler as informa��es nos 200 caracteres do conte�do
	{
		printf("\nEssas s�o as informa��es do usu�rio:  "); //apresenta as informa��es lidas
		printf("%s", conteudo); //armazena as informa��es
		printf("\n\n");
	}
	
	system ("pause"); //d� tempo de leitura ao usu�rio
}

int deletar () // fun��o para a tela onde ser�o deletados os nomes
{
	//in�cio da cria��o de vari�vel para a fun��o deletar
	char cpf[40];
	//fim da cria��o de vari�vel para a fun��o deletar
	
	printf("Digite o CPF a ser deletado: "); // coleta informa��o do usu�rio
	scanf("%s", cpf); // %s significa um pedido de armazenar as informa��es da "string"
	
	remove(cpf); // remove o cpf digitado
	
	FILE *file;
	file = fopen(cpf, "r"); // l� o aarquivo com cpf digitado
	
	if(file == NULL) // condi��o caso o cpf n�o seja localizado
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); // informa ao usu�rio
		system("pause");
	}
}

int main () // ponto de partida
{
	int opcao=0; // definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system ("cls"); // respons�vel por limpar a tela
		
		setlocale (LC_ALL, "Portuguese"); // definindo o idioma
	
		printf ("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n");
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Op��o:  "); // fim do menu
	
		scanf ("%d", &opcao); // armazenando a escolha do usu�rio
	
		system ("cls");
	
		switch(opcao) // in�cio da sela��o do menu
		{
			case 1: // linkado com a fun��o registro
			registro(); // chamada de fun��es
			break;
			
			case 2: // linkado com a fun��o consulta
			consulta();
			break;
			
			case 3: // linkado com a fun��o deletar
			deletar();
			break;
			
			case 4:
			printf ("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: // erros de digita��o do usu�rio no menu
			printf ("Esta op��o n�o est� dispon�vel!\n");
			system ("pause");
			break;				
		} // fim da sele��o
		
	}
	
}

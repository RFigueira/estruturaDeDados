/*Escrever um programa que:
Abra um arquivo de texto que contém um inteiro e uma string por linha,
sendo que a primeira linha contém apenas um inteiro, que indica o
número restante de linhas;
Defina uma estrutura (registro) para armazenar um inteiro e uma string;
Armazene estes elementos em um vetor alocado dinamicamente do tipo
definido pela estrutura;
Imprima os elementos do vetor no formato:
[inteiro 1 , “string 1 ”]
[inteiro 2 , “string 2 ”]
...
[inteiro N , “string N ”]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cadastro {
   int numero;
   char nome_numero[50];
   
};
//criamos um tipo registro basedo na struct cadastro
typedef struct cadastro registro;

//criamos uma funcao, que irá receber o numero de alocações necessarios
registro * alocacao_dinamica(int numeroDeAlocacoes){

//alocando dinamicamente ;)
 registro *estrutura = malloc( (sizeof(registro) * numeroDeAlocacoes));
  //validacao
  if (estrutura == NULL){
      printf("Memória esgotada\n");
      fflush(stdout);
      exit(1);
    }
  //retornamos a estrutura, tentei fazer por referencia, mas nao deu, nao segui fuçando, quem quiser sinta-se a vontade ;)
  return estrutura; 
}

//procedimento para mostrar os dados ;)
void mostra_na_tela(registro *estrutura, int numeroDeAlocacoes){
	for (int i = 0; i < numeroDeAlocacoes; ++i){
      printf("[ %d,", estrutura[i].numero);
      printf(" %s ]\n", estrutura[i].nome_numero);  
    }
  }
  
  //procedimento para popular os dados
  void popular_estrutura(registro *estrutura, int numeroDeAlocacoes, FILE *arquivo){
	for (int i = 0; i < numeroDeAlocacoes; ++i){
      fscanf(arquivo, "%d", &estrutura[i].numero);
      fscanf(arquivo, "%s", estrutura[i].nome_numero);  
    }
  }

int main(){
	
	FILE *arquivo;
	registro *estrutura;
	
	arquivo = fopen("ex2.txt","r");
	if(arquivo == NULL){
		perror("ERRO");
		return EXIT_FAILURE;
	}
	int numeroDeAlocacoes = 0;
	fscanf(arquivo, "%d", &numeroDeAlocacoes);
	estrutura = alocacao_dinamica(numeroDeAlocacoes);
	
	for (int i = 0; i < numeroDeAlocacoes; ++i){
      fscanf(arquivo, "%d", &estrutura[i].numero);
      fscanf(arquivo, "%s", estrutura[i].nome_numero);  
    }
	popular_estrutura(estrutura, numeroDeAlocacoes, arquivo);
	mostra_na_tela(estrutura, numeroDeAlocacoes);
	free(estrutura);
	fclose(arquivo);
	return 0;
}

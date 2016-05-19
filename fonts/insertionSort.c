#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int * alocacao_dinamica(int numeroDeAlocacoes){
 int *vetor = malloc( (sizeof(int) * numeroDeAlocacoes));
  if (vetor == NULL){
      printf("Memória esgotada\n");
      fflush(stdout);
      exit(1);
    }
    return vetor; 
}

  void popular_estrutura(int *vetor, int numeroDeAlocacoes, FILE *arquivo){	
	for (int i = 0; i < numeroDeAlocacoes; ++i){
      fscanf(arquivo, "%d", vetor+i);
    }
  }
  
  void swap(int *vetor, int x, int y){
 	int num = vetor[x];
	vetor[x] = vetor[y];
	vetor[y] = num;
  }
  
 void swap2(int *vetor, int x, int y){
 	int num = vetor[x];
	vetor[x] = vetor[y];
	vetor[y] = num;
  }
  
  void mostra_na_tela(int *vetor, int numeroDeAlocacoes){
	printf("{ ");
	for (int i = 0; i < numeroDeAlocacoes; ++i){
      printf("%d ,", vetor[i]);
    }
    printf(" }");
  }
  
  void bubbleSort(int *vetor, int numeroDeAlocacoes){
	int x, y =0;
	for( x = 0; x < numeroDeAlocacoes; x++ ){
	    for( y = x + 1; y < numeroDeAlocacoes; y++ ){
			if ( vetor[x] > vetor[y] ){
				swap(vetor, x, y);    
			}
		}
	} 
  }

  void isertionSort(int *vetor, int numeroDeAlocacoes){
	int x, y;
	for( x = 1; x < numeroDeAlocacoes; x++ ){
		y = x;
	    while((y > 0) && (vetor[y - 1] > vetor[y])){		
				swap(vetor, (y-1), y);
				y -=y;    
		}
	} 
  }


  void isertionSort2(int *vetor, int numeroDeAlocacoes){
	int x, y;
	for( x = 1; x < numeroDeAlocacoes; ++x ){
		for(y = x; y > 0 && vetor[y-1] > vetor[y]; --y){
			swap(vetor, (y-1), y);
		}
	} 
  }


int main(){
	
	FILE *arquivo;
	int *vetor;
	
	arquivo = fopen("num.txt","r");
	if(arquivo == NULL){
		perror("ERRO");
		return EXIT_FAILURE;
	}
	int numeroDeAlocacoes = 0;
	fscanf(arquivo, "%d", &numeroDeAlocacoes);
	
	vetor = alocacao_dinamica(numeroDeAlocacoes);
	popular_estrutura(vetor, numeroDeAlocacoes, arquivo);
	
	mostra_na_tela(vetor, numeroDeAlocacoes);
	isertionSort2(vetor, numeroDeAlocacoes);
	mostra_na_tela(vetor, numeroDeAlocacoes);
	
	
	free(vetor);
	fclose(arquivo);
	return 0;
}

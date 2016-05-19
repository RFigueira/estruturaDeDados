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
  
  void mostra_na_tela(int *vetor, int numeroDeAlocacoes){
	printf("{ ");
	for (int i = 0; i < numeroDeAlocacoes; ++i){
      printf("%d ,", vetor[i]);
    }
    printf(" }");
  }
  
  void cocktilSort(int *vetor, int numeroDeAlocacoes){
	int i;
	int ai=0, af=numeroDeAlocacoes-1;
		
	int flag = 1;
		
	while((ai < af) && (flag == 1)) {
		flag = 0;
		// Esquerda para direita
		for(i=ai; i<af; i++) {
			if(vetor[i] > vetor[i+1]) {
				swap(vetor, i , i+1);
				flag = 1;
			}
		}
			af--;
		if(!flag){
			break;
		}
		// Direita para esquerda
		for(i=af; i>ai; i--) {
			if(vetor[i] < vetor[i-1]) {
				swap(vetor,i , i-1);
				flag = 1;
			}	
		}
			ai++;
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
	cocktilSort(vetor, numeroDeAlocacoes);
	mostra_na_tela(vetor, numeroDeAlocacoes);
	
	
	free(vetor);
	fclose(arquivo);
	return 0;
}






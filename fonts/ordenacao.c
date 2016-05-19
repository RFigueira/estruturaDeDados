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

void mostra_na_tela2(int *vetor, int inicio, int fim){
	printf("{ ");
	for (int i = inicio; i <= fim; ++i){
		printf("%d ,", vetor[i]);
	}
	printf(" }\n");
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
	int x, y =0;
	for( x = 1; x < numeroDeAlocacoes; x++ ){
		y = x;
		while((y > 0) && (vetor[y - 1] > vetor[y])){		
			swap(vetor, (y-1), y);    
		}
	} 
}

void particionar(int *vetor, int inicio, int fim){
	mostra_na_tela2(vetor,inicio,fim);
	if(inicio == fim){
		return;
	}
	int meio = ((inicio + fim) /2);
	particionar(vetor, inicio, meio);
	particionar(vetor, (meio+1), fim);
}

void merge_sort(int *vetor, int *temp, int inicio, int fim){
	mostra_na_tela2(vetor,inicio,fim);
	if(inicio == fim){
		return;
	}
	int meio = ((inicio + fim) /2);
	merge_sort(vetor, temp, inicio, meio);
	merge_sort(vetor, temp, (meio+1), fim);
	int i, j, k;
	for(i = inicio; i<=fim; ++i){
		temp[i] = vetor[i];
	}
	i = inicio;
	j = meio+1;
	k = inicio;
	while(i<=meio && j<= fim){
		vetor[k++] = (temp[i] <= temp[j]) ? temp[i++] : temp[j++];
	}
	while(i<= meio){
		vetor[k++] = temp[i++];
	}
	while(j<= fim){
		vetor[k++] = temp[j++];
	}
}



int main(){
	
	FILE *arquivo;
	int *vetor, *temp;
	
	arquivo = fopen("num.txt","r");
	if(arquivo == NULL){
		perror("ERRO");
		return EXIT_FAILURE;
	}
	int numeroDeAlocacoes = 0;
	fscanf(arquivo, "%d", &numeroDeAlocacoes);
	
	vetor = alocacao_dinamica(numeroDeAlocacoes);
	temp = alocacao_dinamica(numeroDeAlocacoes);
	popular_estrutura(vetor, numeroDeAlocacoes, arquivo);
	
	//mostra_na_tela(vetor, numeroDeAlocacoes);
	//bubbleSort(vetor, numeroDeAlocacoes);
	//particionar(vetor,0, (numeroDeAlocacoes-1) );
	merge_sort(vetor,temp,0,(numeroDeAlocacoes-1));
	mostra_na_tela(vetor, numeroDeAlocacoes);
	
	free(temp);
	free(vetor);
	fclose(arquivo);
	return 0;
}

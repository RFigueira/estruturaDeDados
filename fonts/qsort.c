#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
int swap(const void *a, const void *b){
 	return *(int*)a - *(int*)b;
}
  
void mostra_na_tela(int *vetor, int numeroDeAlocacoes){
	printf("{ ");
	for (int i = 0; i < numeroDeAlocacoes; ++i){
		printf("%d ", vetor[i]);
		if(i != (numeroDeAlocacoes - 1)){
			printf(", ");
		}
	}
	printf(" }");
}

 

int main(){
	
	int vetor[10] = {1,2,8,15,45,55,99,0,81,10};
	printf("\n NÃO ORDENADO \n\n");
	mostra_na_tela(vetor, 10);

	qsort(vetor,10, sizeof *vetor, &swap);
	printf("\n\n\n ORDENADO \n\n");
	mostra_na_tela(vetor, 10);
	
	return 0;
}


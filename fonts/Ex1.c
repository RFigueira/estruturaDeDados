#include <stdio.h>
#include <stdlib.h>



int main(){
	//declaraceos
	FILE *arquivo;
	int tamanhoVetor = 0;
	
	
	arquivo = fopen("num.txt","r");
	if(arquivo == NULL){
		perror("ERRO");
		return EXIT_FAILURE;
	}
	fscanf(arquivo, "%d", &tamanhoVetor);
	
	int *vetor = malloc( (sizeof(int) * tamanhoVetor));
		
	for(int i = 0; i < tamanhoVetor; ++i){	
		fscanf(arquivo, "%d", vetor+i);
		//fscanf(arquivo, "%d", &vetor[i]); a mesma coisa que a linha de cima!
	}
	printf("{");
	for(int i = 0; i < tamanhoVetor; ++i){	
		printf("%d, ", vetor[i]);
	}
	printf("}");
	free(vetor);
	fclose(arquivo);
	
	
	
	 
	
	
	//vetor = *malloc(size_t size);
	
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 31000
#define TAM_VETOR_CHAVES 10

int chave;
int contador_binaria = 0;
int contador_liniar = 0;
int vetor_chaves[10] = { 1, 354, 100, 8889, 7, 888, 30025, 19, 355, 0 };


int ordenar(const void * a, const void * b) {   // Ordenação do vetor para a busca binária
  return *(int*)a - *(int*)b ;
}

int* buscaLinear(int* v, int chave, int n) {
	
	for(int i = 0; i < n; i++) {
	contador_liniar++;
		if(chave == v[i]){
		return	&v[i];
		}
	}
	
	 return NULL;
}

int * buscaBinaria(int* v, int chave, int n) {
	int ini = 0;
	int fim = n-1;
	int meio;
	
	while (ini <= fim) {		
		meio = fim +(ini - fim) / 2;		
		if (chave < v[meio]){
			fim = meio - 1;
		}	
		else if (chave > v[meio]){
			ini = meio + 1;
		}
		else{
			return &v[meio];
		}
			contador_binaria++;
	}
	 
	return NULL;
}

int main() {
	
	int vetor_rand[TAM];
	srand(time(NULL));
	
	for(int i =0; i<TAM; i++){
		vetor_rand[i] = rand()%TAM;		
	}
	
	
	
	
	
	
	printf("\n\t\t------ BUSCA LINEAR -------");
	for(int i = 0; i < TAM_VETOR_CHAVES; ++i){
		if(buscaLinear(vetor_rand,vetor_chaves[i],TAM) != NULL){
			printf("\n-Para encontrar o numero  %d foi necessario %d vezes",vetor_chaves[i] ,contador_liniar);
			
		}
		else{
			printf("\n-O numero %d não foi encontrado :.(, foi percorido o total de %d vezes ",vetor_chaves[i] ,contador_liniar);
		}	
		contador_liniar = 0;
	}
	
	
	printf("\n\n\t\t------ BUSCA BINARIA ------");
	for(int i = 0; i < TAM_VETOR_CHAVES; ++i){	
		qsort (vetor_rand, TAM, sizeof(int), ordenar);
		if(buscaBinaria(vetor_rand,vetor_chaves[i],TAM)!= NULL){
			printf("\n-Para tentar encontrar o numero  %d foi necessario %d vezes",vetor_chaves[i] ,contador_binaria);
		}
		else{
			printf("\n-O numero %d não foi encontrado :.(, foi percorido o total de %d vezes ",vetor_chaves[i] ,contador_binaria);
		}
		contador_binaria = 0;
		
	}	
}

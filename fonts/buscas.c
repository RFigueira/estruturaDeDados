#include <stdio.h>
#include <stdlib.h>
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
			return printf("\n\n\nValor encontrado na posicao %d, no endereco de memoria %p.", i, &v[i]);
		}
	}
	
	 return printf("\n\n\nValor nao encontrado. %d", NULL);
}

int * buscaBinaria(int* v, int chave, int n) {
	int ini = 0;
	int fim = n-1;
	int meio;
	
	while (ini <= fim) {
		
		meio = (ini + fim) / 2;
		if (chave < v[meio]){
			fim = meio - 1;
		}	
		else if (chave > v[meio]){
			ini = meio + 1;
		}
		else{
			return printf("\n\n\nValor encontrado na posicao %d, no endereco de memoria %p.", meio, &v[meio]);
		}
			contador_binaria++;
	}
	 
	return printf("\n\n\nValor nao encontrado. %d", NULL);
}

int main() {
	
	int vetor_rand[TAM];
	srand(time(NULL));
	
	for(int i =0; i<TAM; i++){
		vetor_rand[i] = rand()%TAM;		
	}
	
	printf("\n\t\t------ BUSCA LINEAR -------");
	for(int i = 0; i < TAM_VETOR_CHAVES; ++i){
		buscaLinear(vetor_rand,vetor_chaves[i],TAM);
		printf("\nPara encontrar o numero  %d foi necessario %d vezes",vetor_chaves[i] ,contador_liniar);
		contador_liniar = 0;	
	}
	
	
	printf("\n\n\t\t------ BUSCA BINARIA ------");
	for(int i = 0; i < TAM_VETOR_CHAVES; ++i){	
		qsort (vetor_rand, TAM, sizeof(int), ordenar);
		buscaBinaria(vetor_rand,vetor_chaves[i],TAM);
		printf("\nPara tentar encontrar o numero  %d foi necessario %d vezes",vetor_chaves[i] ,contador_binaria);
		contador_binaria = 0;
		
	}	
}

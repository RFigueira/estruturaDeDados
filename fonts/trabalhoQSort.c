#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 void swap(int *vetor, int x, int y){
 	int num = vetor[x];
	vetor[x] = vetor[y];
	vetor[y] = num;
  }
 
 int gerar_valor_absoluto(int valor){
	
	return valor < 0 ? -valor : valor;

}
 
//o menor inteiro precede o maior (ordem crescente)  
int compara1(const void *a, const void *b){
 	return *(int*)a - *(int*)b;
}

//o maior inteiro precede o menor (ordem decrescente)
int compara2(const void *a, const void *b){
 	return   *(int*)b - *(int*)a;
}
/*
Compara3 - o inteiro ímpar precede o inteiro par, mas se ambos
forem ímpar/par então o menor precede o maior*/
int compara3(const void *a, const void *b){
 	int resto_a = ((*(int*)a)%2);
 	int resto_b = ((*(int*)b)%2);
 	
	if(resto_a != 0 && resto_b == 0){
		return -1;
	}
	else if( resto_b !=0 && resto_a == 0){
		return 1;
	}
	
	return	compara1(a,b);	
}
/*
*Compra4 - O inteiro positivo precede o inteiro negativo, mas se
*	ambos forem positivos, o menor precede o maior; e se ambos forem
*	negativos, o maior precede o menor  
*	
*	ENTRADA: 2, -3, 1, 3, -1, -2	 
* 
* 	SAIDA Esperada compara4:
*	
*	{1, 2, 3, -1, -2, -3}
*/
int compara4(const void *a, const void *b){
 	int valor_a = (*(int*)a);
 	int valor_b = (*(int*)b);
 	
 	if(valor_a >= 0 && valor_b <= 0){
		return -1;
	}
	else if(valor_a >= 0 && valor_b >= 0){
		return compara1(a,b);
	}
	else if(valor_a <= 0 && valor_b <= 0){
		return compara2(a,b);
	}
	
	return 1;
}


/*
*Função compara5: o menor inteiro precede o maior com base nos seus valores absolutos
*- mas se os valores absolutos forem iguais, o inteiro positivo	precede o inteiro negativo
*	
*	ENTRADA: 2, -3, 1, 3, -1, -2	 
* 	SAIDA: {1, -1, 2, -2, 3, -3} 
*/
 
/* A função deve retornar:
	Um inteiro negativo(< 0) caso o primeiro parâmetro preceda o segundo;
	Um inteiro positivo (> 0)caso o segundo parâmetro preceda o primeiro;
	Zero caso ambos (== 0)parâmetros empatem em critério de ordenação.
 */
int compara5(const void *a, const void *b){
 	int valor_a = (*(int*)a);
 	int valor_b = (*(int*)b);
 	 	
 	if(gerar_valor_absoluto(valor_a) > gerar_valor_absoluto(valor_b)){
		return 1;
	} 
	else if(gerar_valor_absoluto(valor_a) == gerar_valor_absoluto(valor_b)){
		compara4(a,b);
	}
	return 0;
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


void insertion_sort(int *vetor, int numeroDeAlocacoes, int (*operacao)(const void *, const void *)){

	int x, y;
	for( x = 1; x < numeroDeAlocacoes; x++ ){
	 for(y = x; y > 0 && operacao(&vetor[y-1], &vetor[y]) > 0; --y){
			swap(vetor, (y-1), y);
		}
	} 
}

int main(){
	
	int vetor[6] = {2,-3,1,3,-1,-2};
	
	
	printf("\n NÃO ORDENADO \n\n");
	mostra_na_tela(vetor, 6);

	qsort(vetor,6, sizeof *vetor, &compara1);
	printf("\n\n\n ORDENADO COMPARA  1 \n\n");
	mostra_na_tela(vetor, 6);
	
	qsort(vetor,6, sizeof *vetor, &compara2);
	printf("\n\n\n ORDENADO COMPARA  2 \n\n");
	mostra_na_tela(vetor, 6);
	
	qsort(vetor,6, sizeof *vetor, &compara3);
	printf("\n\n\n ORDENADO COMPARA  3 \n\n");
	mostra_na_tela(vetor, 6);
	
	qsort(vetor,6, sizeof *vetor, &compara4);
	printf("\n\n\n ORDENADO COMPARA  4 \n\n");
	mostra_na_tela(vetor, 6);
	
	qsort(vetor,6, sizeof *vetor, &compara5);
	printf("\n\n\n ORDENADO COMPARA  5 \n\n");
	mostra_na_tela(vetor, 6);
	
	printf("\n\n\n ORDENADO COM INSERTION SORT ");
	
	insertion_sort(vetor,6, &compara1);
	printf("\n\n\n ORDENADO COMPARA 1  \n\n");
	mostra_na_tela(vetor, 6);
	
	insertion_sort(vetor,6, &compara2);
	printf("\n\n\n ORDENADO COMPARA 2   \n\n");
	mostra_na_tela(vetor, 6);
	
	insertion_sort(vetor,6, &compara3);
	printf("\n\n\n ORDENADO COMPARA 3   \n\n");
	mostra_na_tela(vetor, 6);
	
	insertion_sort(vetor,6, &compara4);
	printf("\n\n\n ORDENADO COMPARA 4  \n\n");
	mostra_na_tela(vetor, 6);
	
	insertion_sort(vetor,6, &compara5);
	printf("\n\n\n ORDENADO COMPARA 5  \n\n");
	mostra_na_tela(vetor, 6);

	return 0;
}



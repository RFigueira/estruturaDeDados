#include <stdio.h>
#include <stdlib.h>

struct No {
	int valor;
	struct No *prox;
};

typedef struct No no;


void inicio (no *lista) {	
	lista->prox = NULL;
}

int listavazia (no *lista) {	
	if (lista->prox == NULL )
		return 1;
	else
		return 0;
}

no *insere (no *lista, int valor) {	
	no *novo=(no*) malloc(sizeof(no));
	novo->valor = valor;	
	novo->prox = lista->prox;
	lista->prox = novo;
	return novo;
}

int remover (no *lista) {	
	if(!listavazia(lista)) {
		no *proxNo, *atual;
		atual = lista->prox;
		
		while(atual !=NULL) {
			proxNo = atual->prox;
			free(atual);
			atual= proxNo;
		}
		return 1;
	}
	return 0;
}

no *busca (no *lista, int valor) {
	no *novo = lista;
	while ( novo != NULL && novo->valor != valor) {
		novo = novo->prox;
	}
	return novo;
}

void imprime (no *lista) {
	no *novo;
	for (novo = lista; novo !=NULL; novo = novo->prox) {
		printf("%d\n", novo->valor);
	}
}

int main(void) {
	int x = 0;
	no *lista=(no*) malloc(sizeof(no));
	int v2[10] = { 2, -3, 1, 89, 99, 88, -3, 19, 35, 11 }; //arbitrário ;)
	inicio(lista);
	
	for ( x = 0; x < 10; x++) {
		insere(lista, v2[x]);
	}
	imprime(lista);
	
	for ( x = 0; x<10; x ++) {
		busca(lista, v2[x]);
	}
	
	for ( x = 0; x<10; x ++) {
		remover(lista);
	}
	imprime(lista);
	
	return 0;
}



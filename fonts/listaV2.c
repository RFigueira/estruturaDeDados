#include <stdio.h>
#include <stdlib.h>

struct Lista{
 int num;
 struct Lista *prox;
 int tam;
};

typedef struct Lista lista;

int menu(void){
	int opt;
	
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar elemento no inicio\n");
	printf("3. Adicionar elemento no final\n");
	printf("4. Buscar elemnto\n");
	printf("5. Zerar lista\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

int vazia(lista *PILHA){
	if(PILHA->prox == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void libera(lista *PILHA){
	if(!vazia(PILHA)){
		lista *proxNode,*atual;
		atual = PILHA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void inicia(lista *LISTA){
	LISTA->prox = NULL;
	//LISTA->tam=0;
}

void exibe(lista *LISTA){
	if(vazia(LISTA)){
		printf("\n\n A Pilha está vazia.\n\n");
		return ;
	}

	lista *tmp;
	tmp = LISTA->prox;
	printf("\n\n---Exibindo Pilha---\n");
	printf("Elent:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < LISTA->tam ; count++){
		printf("  ^  ");
	}
		printf("\nOrdem:");
	for(count=0 ; count < LISTA->tam ; count++){
		printf("%5d", count+1);
	}
	printf("\n\n");
}

lista *alocar(){
	lista *novo=(lista *) malloc(sizeof(lista));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}

void insereFim(lista *LISTA)
{
	lista *novo=(lista *) malloc(sizeof(lista));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: "); scanf("%d", &novo->num);
	novo->prox = NULL;
	
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		lista *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}


void insereInicio(lista *LISTA)
{
	lista *novo=(lista *) malloc(sizeof(lista));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: "); scanf("%d", &novo->num);
	
	lista *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->prox = oldHead;
}

lista  *busca (lista *LISTA, int valor) {
	lista *novo = LISTA;
	while ( novo != NULL && novo->num != valor) {
		novo = novo->prox;
	}
	return novo;
}

void imprime (lista *LISTA) {
	
	if (LISTA != NULL) {
		printf("Elemento encontrado-> %d\n->", LISTA->num);
	}
	else{
		printf("Erro!\n");
	}
	
}

void opcao(lista *LISTA, int op, int valor){
	
	switch(op){
		case 0:
			libera(LISTA);
			break;
			
		case 1:
			exibe(LISTA);
			break;
		
		case 2:
			insereInicio(LISTA);
			break;
		
		case 3:
			insereFim(LISTA);
			break;		
			
		case 4:
			imprime(busca(LISTA, valor));
			break;
			
		case 5:
			inicia(LISTA);
			break;
		default:
			printf("Comando invalido\n\n");
	}
}

int main(void){
	lista *LISTA = (lista *) malloc(sizeof(lista));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		inicia(LISTA);
		int opt;
		int valor;

		do{
			opt=menu();
			if(opt == 4){
				printf("Digite o valor a ser procurado: "); scanf("%d", &valor);
				opcao(LISTA,opt,valor);
			}
			else{
			opcao(LISTA,opt,0);
		}
		}while(opt && opt != 4);

		free(LISTA);
		return 0;
	}
}















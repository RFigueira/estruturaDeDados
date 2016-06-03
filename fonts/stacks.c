#include <stdio.h>
#include <stdlib.h>

struct Stack{
 int num;
 struct Stack *prox;
 int tam;
};

typedef struct Stack stack;

int menu(void){
 int opt;

 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Esvaziar PILHA\n");
 printf("2. Mostrar PILHA\n");
 printf("3. Push\n");
 printf("4. Pop\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
}

int vazia(stack *PILHA){
	if(PILHA->prox == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void libera(stack *PILHA){
	if(!vazia(PILHA)){
		stack *proxNode,*atual;
		atual = PILHA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void inicia(stack *PILHA){
	PILHA->prox = NULL;
	PILHA->tam=0;
}

void exibe(stack *PILHA){
	if(vazia(PILHA)){
		printf("\n\n A Pilha está vazia.\n\n");
		return ;
	}

	stack *tmp;
	tmp = PILHA->prox;
	printf("\n\n---Exibindo Pilha---\n");
	printf("Elent:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < PILHA->tam ; count++){
		printf("  ^  ");
	}
		printf("\nOrdem:");
	for(count=0 ; count < PILHA->tam ; count++){
		printf("%5d", count+1);
	}
	printf("\n\n");
}

stack *alocar(){
	stack *novo=(stack *) malloc(sizeof(stack));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}

void push(stack *PILHA){
	stack *novo=alocar();
	novo->prox = NULL;
	if(vazia(PILHA)){
	  PILHA->prox=novo;
	}
	else{
		stack *tmp = PILHA->prox;
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}
	PILHA->tam++;
}

stack *pop(stack *PILHA){
	if(PILHA->prox == NULL){
		printf("\n\n A pilha ainda está vazia\n\n");
		return NULL;
	}
	else{
		stack *ultimo = PILHA->prox,
              *penultimo = PILHA;

		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;
		PILHA->tam--;
		return ultimo;
	}
}

void opcao(stack *PILHA, int op){
	stack *tmp;
	switch(op){
		case 0:
			libera(PILHA);
			break;
		case 1:
			libera(PILHA);
			inicia(PILHA);
			break;
		case 2:
		   exibe(PILHA);
		   break;
		case 3:
		   push(PILHA);
		   break;
		case 4:
			tmp= pop(PILHA);
			if(tmp != NULL){
				printf("Retirado: %3d\n\n", tmp->num);
			}
			break;
		default:
			printf("\n\nOps! Comando invalido\n\n");
	}
}

int main(void){
	stack *PILHA = (stack *) malloc(sizeof(stack));
	if(!PILHA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		inicia(PILHA);
		int opt;

		do{
			opt=menu();
			opcao(PILHA,opt);
		}while(opt);

		free(PILHA);
		return 0;
	}
}














#include <stdio.h>
#include <stdlib.h>

struct Queues{
	int num;
	struct Queues *prox;
	int tam;
};
typedef struct Queues queues;

int menu(void){
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar fila\n");
	printf("2. Exibir fila\n");
	printf("3. Adicionar Elemento na Fila\n");
	printf("4. Retirar Elemento da Fila\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

int vazia(queues *FILA){
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;
}

void libera(queues *FILA){
	if(!vazia(FILA)){
		queues *proxNode,
			  *atual;

		atual = FILA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void inicia(queues *FILA){
	FILA->prox = NULL;
	FILA->tam=0;
}

void exibe(queues *FILA){
	if(vazia(FILA)){
		printf("\n\n A Fila está vazia.\n\n");
		return ;
	}
	queues *tmp;
	tmp = FILA->prox;
	printf("\n\n---Exibindo Fila---\n");
	printf("Elemt:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < FILA->tam ; count++){
		printf("  ^  ");
	}
	printf("\nOrdem:");
	for(count=0 ; count < FILA->tam ; count++){
		printf("%5d", count+1);
	}


	printf("\n\n");
}

queues *aloca(){
	queues *novo=(queues *) malloc(sizeof(queues));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}

void insere(queues *FILA){
	queues *novo=aloca();
	novo->prox = NULL;

	if(vazia(FILA))
		FILA->prox=novo;
	else{
		queues *tmp = FILA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
	FILA->tam++;
}

queues *retira(queues *FILA){
	if(FILA->prox == NULL){
		printf("\n\n A Fila  esta vazia\n");
		return NULL;
	}else{
		queues *tmp = FILA->prox;
		FILA->prox = tmp->prox;
		FILA->tam--;
		return tmp;
	}

}

void opcao(queues *FILA, int op){
	queues *tmp;
	switch(op){
		case 0:
			libera(FILA);
			break;
		case 1:
			libera(FILA);
			inicia(FILA);
			break;
		case 2:
			exibe(FILA);
			break;
		case 3:
			insere(FILA);
			break;
		case 4:
			tmp= retira(FILA);
			if(tmp != NULL){
				printf("\n\nRetirado o numero: %3d\n\n", tmp->num);
			}
			break;
		default:
			printf("\n\n Ops! Comando invalido\n\n");
	}
}

int main(void){
	queues *FILA = (queues *) malloc(sizeof(queues));
	if(!FILA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else{
		inicia(FILA);
		int opt;
		do{
			opt=menu();
			opcao(FILA,opt);
		}while(opt);
		free(FILA);
		return 0;
	}
}


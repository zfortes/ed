#include <stdio.h>
#include <stdlib.h>
#include "printPersonagem.h"
#include "arvore.h"
#include "criador.h"

typedef struct nodo{/*Celula da lista que carrega seu conteudo e enderecos para proximo e anterior*/
	Tree* personagem;
	struct nodo* prox;
	struct nodo* ant;
}Nodo;

typedef struct lista{/*Endereco da cabeca da lista*/
	Nodo* primeiro;
}Lista;



Lista* cria_lista(){/*Funcao que cria e retorna o endereo da lista*/
	Lista *plista = (Lista *) malloc(sizeof(Lista));

	plista->primeiro = NULL;
	return plista;
}

int vazia_lista(Lista *cabeca){/*Funcao retorna 1 caso a lista esteja vazia e 0 caso contrario*/
	if(cabeca->primeiro==NULL){
		return 1;
	}
	else
		return 0;
}

Nodo* retorna_elemento(Lista *cabeca, int posicao){/*Funcao retorna o endereco da ultima celula da lista*/
	Nodo *last;
	int c=0;
	last = cabeca->primeiro;

	while(c!=posicao){
		last=last->prox;
		c++;
	}

	return last;
}

int tamanho_lista(Lista *cabeca){/*Retorna um inteiro com tamanho(Número de celulas) da lista*/
	int i=1;
	Nodo *last;	


	last = cabeca->primeiro;
	while(last->prox!=NULL){
		last=last->prox;
		i++;
	}
	
	return i;
}

void insere_lista(Lista *cabeca, int posicao, Tree *personagem){/*Funcao que insere em qualquer posicao da lista*/
	Nodo *novo = (Nodo *) malloc (sizeof(Nodo));
	Nodo *aux;
	int tamanho;

	novo->personagem=personagem;
	novo->prox=NULL;
	novo->ant=NULL;
	if(posicao>0)
		aux=retorna_elemento(cabeca, posicao-1);
	if(vazia_lista(cabeca)){
		cabeca->primeiro=novo;
	}
	else{
		tamanho=tamanho_lista(cabeca);
		if(tamanho==posicao){
			aux->prox=novo;
			novo->ant=aux;
		}
		else if(tamanho>posicao){
			aux->ant->prox=novo;
			novo->ant=aux->ant;
			novo->prox=aux;
			aux->ant=novo;
		}
	}
}

void remove_lista(Lista *cabeca, int posicao){/*Remove um elemento em qualquer posicao da lista, desde que esta nao esteja vazia*/
	int i, tamanho;
	Nodo *elemento=cabeca->primeiro;
	
	if(vazia_lista(cabeca)){
		printf("Lista ja vazia\n");
	}
	else{
		tamanho=tamanho_lista(cabeca);
		if(tamanho>=posicao){/*Teste para ver se a posicao em que se deseja remover e valida*/
			for(i=0; i<posicao; i++){
				elemento=elemento->prox;
			}
			if(elemento->prox!=NULL){
				elemento->ant->prox=elemento->prox;
				elemento->prox->ant=elemento->ant;
			}
			else
				elemento->ant->prox=NULL;
			free(elemento);
		}
		else
			printf("Impossivel remover nesta posicao\n"); 
		
	}
}

void free_lista(Lista* cabeca){/*Funcao libera todos os elementos da lista*/
	Nodo *elemento=cabeca->primeiro;
	Nodo *aux=cabeca->primeiro;
	while(aux!=NULL){
		aux=elemento->prox;
		free(elemento);
		elemento=aux;
	}
	free(elemento);
	free(cabeca);
}

void libera_tudo(Lista* lista){/*Funcao libera tudo alocado no programa, ou seja as arvores e os elementos da lista*/
	int i;
	Nodo* nodo;
	Tree* tree;
	nodo = lista->primeiro;
	
	for (i=0; i<16; i++){
		tree=nodo->personagem;
		tree_free(tree);
		nodo=nodo->prox;

	}
	
	free_lista(lista);
}

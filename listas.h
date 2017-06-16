
typedef struct nodo{//Celula da lista que carrega seu conteudo e enderecos para proximo e anterior
	Tree* personagem;
	struct nodo* prox;
	struct nodo* ant;
}Nodo;

typedef struct lista{//Endereco da cabeca da lista
	Nodo* primeiro;
}Lista;

Lista*  cria_lista();
int     vazia_lista(Lista *cabeca);
Nodo*   retorna_elemento(Lista *cabeca, int posicao);
int     tamanho_lista(Lista *cabeca);
void    insere_lista(Lista *cabeca, int posicao, Tree *personagem);
void    remove_lista(Lista *cabeca, int posicao);
void    free_lista(Lista* cabeca);
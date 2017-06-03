#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"printPersonagem.h"
#include"arvore.h"
#include"criador.h"

typedef struct nodo{/*Celula da lista que carrega seu conteudo e enderecos para proximo e anterior*/
	Tree* personagem;
	struct nodo* prox;
	struct nodo* ant;
}Nodo;

typedef struct lista{/*Endereco da cabeca da lista*/
	Nodo* primeiro;
}Lista;


/*Assinatura das funcoes*/
Lista*  cria_lista();
int     vazia_lista(Lista *cabeca);
Lista   retorna_ultimo(Lista *cabeca, int posicao);
int     tamanho_lista(Lista *cabeca);
void    insere_lista(Lista *cabeca, int posicao, Tree *personagem);
void    remove_lista(Lista *cabeca, int posicao);
void    free_lista(Lista* cabeca);


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

Nodo retorna_elemento(Lista *cabeca, int posicao){/*Funcao retorna o endereco da ultima celula da lista*/
	Nodo *last = (Nodo *) malloc (sizeof(Nodo));
	int c=0;

	last = cabeca->primeiro;

	while(c!=posicao){
		last=last->prox;
		c++;
	}
	return *last;
}

int tamanho_lista(Lista *cabeca){/*Retorna um inteiro com tamanho(Número de celulas) da lista*/
	int i=0;
	Nodo *last = (Nodo *) malloc (sizeof(Nodo));	

	last = cabeca->primeiro;
	while(last->prox!=NULL){
		last=last->prox;
		i++;
	}
	return i;
}

void insere_lista(Lista *cabeca, int posicao, Tree *personagem){/*Funcao que insere em qualquer posicao da lista*/
	Nodo *novo = (Nodo *) malloc (sizeof(Nodo)), *aux;
	int tamanho;

	novo->personagem=personagem;
	novo-prox=NULL;
	novo->ant=NULL;
	aux=retorna_elemento(cabeca, posicao);
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
	
	while(elemento!=NULL){
		elemento=elemento->prox;
		free(elemento->ant);
	}
	free(cabeca);
}



void preenche_lista_primeiros(Tree* personagem, int* posicao){
	int escolha;
	int flag;
	if (personagem != NULL){
		//printf("Passou na esquerda\n");
		preenche_lista_primeiros(personagem->left, 	posicao);
		int escolha;
		if (personagem->left==NULL){
			flag=*posicao;
			*posicao = flag + 1;
			//printf("%d\n", flag);
			
			if (flag <9){
				
				if (flag <7){
					if ((flag == 1) || (flag == 2)){
						escolha = 1+rand()%4;
						personagem->info->dom=escolha; //Salva a dominancia

						if (escolha <3){ //cor dos olhos
							if (escolha == 1){
								strcpy(personagem->info->carac,"azul");
							}else{
								strcpy(personagem->info->carac,"castanho");
							}
						}else{
							if (escolha==3){
								strcpy(personagem->info->carac,"preto");
							}else{
								strcpy(personagem->info->carac,"verde");
							}
						}
					}else{
						//formato dos olhos
						if ((flag == 3) || (flag == 4)){
							escolha = 5 + rand() % 2;
							personagem->info->dom=escolha;
							if (escolha == 5){
								strcpy(personagem->info->carac,"circular");
							}else{
								strcpy(personagem->info->carac,"triangular");
							}
						}else{
							//cor do cabelo
							if ((flag == 5) || (flag == 6)){
								escolha = 7+rand()%4;
								personagem->info->dom=escolha; //Salva a dominancia

								if (escolha <9){
									if (escolha == 7){
										strcpy(personagem->info->carac,"amarelo");
									}else{
										strcpy(personagem->info->carac,"azul");
									}
								}else{
									if (escolha==9){
										strcpy(personagem->info->carac,"preto");
									}else{
										strcpy(personagem->info->carac,"vermelho");
									}
								}
							}
						}
					}
				}else{
					//formato do cabelo
					if ((flag == 7) || (flag == 8)){
						escolha = 11+rand()%4;
						personagem->info->dom=escolha; //Salva a dominancia

						if (escolha <13){
							if (escolha == 11){
								strcpy(personagem->info->carac,"careca");
							}else{
								strcpy(personagem->info->carac,"goku");
							}
						}else{
							if (escolha==13){
								strcpy(personagem->info->carac,"trunks");
							}else{
								strcpy(personagem->info->carac,"vegeta");
							}
						}
					}
				}
			}else{
				if (flag <15){
					//calcas
					if ((flag == 9) || (flag == 10)){
						escolha = 15 +rand()%3;
						personagem->info->dom=escolha; //Salva a dominancia

						if (escolha <17){ //cor dos olhos
							if (escolha == 15){
								strcpy(personagem->info->carac,"azul");
							}else{
								strcpy(personagem->info->carac,"laranja");
							}
						}else{							
							strcpy(personagem->info->carac,"preta");
						}
					}else{
						//cor da bota
						if ((flag == 11) || (flag == 12)){
							escolha = 18 +rand()%3;
							personagem->info->dom=escolha; //Salva a dominancia

							if (escolha <20){ //cor dos olhos
								if (escolha == 18){
									strcpy(personagem->info->carac,"azul");
								}else{
									strcpy(personagem->info->carac,"marrom");
								}
							}else{							
								strcpy(personagem->info->carac,"preta");
							}
						}else{
							//raca
							if ((flag == 13) || (flag == 14)){
								escolha = 21 + rand() % 3;
								personagem->info->dom=escolha; //Salva a dominancia

								if (escolha <23){
									if (escolha == 21){
										strcpy(personagem->info->carac,"humano");
									}else{
										strcpy(personagem->info->carac,"namekusei");
									}
								}else{
									strcpy(personagem->info->carac,"saiyajin");
								}
							}
						}
					}
				}else{
					//camisa
					if ((flag == 15) || (flag == 16)){
						escolha = 24+rand()%3;
						personagem->info->dom=escolha; //Salva a dominancia

						if (escolha <26){
							if (escolha == 24){
								strcpy(personagem->info->carac,"armadura");
							}else{
								strcpy(personagem->info->carac,"treino");
							}
						}else{							
							strcpy(personagem->info->carac,"semcamisa");
						}
					}
				}
			}
		}
		preenche_lista_primeiros(personagem->right, posicao);
	}	
}

/*Cria os primeiros 4 personagens aleatorios*/

Lista* cria_primeiros_personagens(){
	Lista* lista= cria_lista();
	int i, j;
	int* posicao = (int *) malloc(sizeof(int));
	Tree* personagem = (Tree *) malloc(sizeof(Tree*));
	*posicao = 1;
	for (i=1; i<=5; i++){
		srand(time(NULL));
		personagem=cria_arvore_personagem(i);
		printf("passou aqui\n");
		insere_lista(lista, i-1 , personagem);
		printf("passou aqui 2\n");
		preenche_lista_primeiros(personagem, posicao);
	}

	return lista;
}



int main()
{
	

	/*Criamos uma arvore de personagem para testes */
	/*Lembre-se que ela recebe o id do personagem */
	//Tree* personagem = cria_arvore_personagem(0);
	//imprime_arvore(personagem);

	Lista* lista = cria_primeiros_personagens();
	printf("passou\n");
	/*printf("Dominio olhos = %d\n", personagem->left->left->left->info->dom);
	printf("%s\n", personagem->left->right->right->info->carac);*/
	
	int i;
	Nodo* nodo;

	for (i=0; i<5; i++){
		nodo = retorna_elemento(lista, i);
		imprime_arvore(nodo->personagem);
	}


	
	printf("\nO personagem impresso graficamente nao corresponde ao personagem vazio impresso de forma textual");
	printf("\n\n");



	/*Caso queira testar a biblioteca grafica */
	//imprime_personagem_aleatorio();
    return 0;
}

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
Nodo*   retorna_elemento(Lista *cabeca, int posicao);
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

Nodo* retorna_elemento(Lista *cabeca, int posicao){/*Funcao retorna o endereco da ultima celula da lista*/
	Nodo *last = (Nodo *) malloc (sizeof(Nodo));
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
	Tree* personagem;
	srand(time(NULL));
	for (i=1; i<5; i++){
		*posicao = 1;
		
		personagem=cria_arvore_personagem(i);
		insere_lista(lista, i-1 , personagem);
		preenche_lista_primeiros(personagem, posicao);
	}

	return lista;
}


int carac_mutante(int carac){/*Funcao retorna um inteiro correspondente a caracteristica aleatoria para um gene mutante*/
	int x=0;

	//variável = (rand() % ((MAIOR VALOR - menor valor) + 1)) + menor valor ;

	// Define um intervalo para [menor valor, MAIOR VALOR]
	if((carac>0) && (carac<5)){
		x=(rand()%((4-1)+1))+1;
	}
	else if((carac>4) && (carac<7)){
		x=(rand()%((6-5)+1))+5;
	}
	else if((carac>6) && (carac<11)){
		x=(rand()%((10-7)+1))+7;
	}
	else if((carac>10) && (carac<15)){
		x=(rand()%((14-11)+1))+11;
	}
	else if((carac>14) && (carac<18)){
		x=(rand()%((17-15)+1))+15;
	}
	else if((carac>17) && (carac<21)){
		x=(rand()%((20-18)+1))+18;
	}
	else if((carac>20) && (carac<24)){
		x=(rand()%((23-21)+1))+21;
	}
	else if((carac>23) && (carac<27)){
		x=(rand()%((26-24)+1))+24;
	}
	return x;
}

int retorna_dominante(int carac1, int carac2){/*Funcao retorna o inteiro correspondente ao do gene dominante ou -1 para um mutante*/
	int mut=-1, x;

	x=(rand()%((10-1)+1))+1;
	if((x==1) || (x==2)){/*Teste de mutacao*/
		return mut;
	}
	else{
		if(carac1==carac2)
			return carac1;
		else{
			if(carac1<carac2)
				return carac1;
			else
				return carac2;
		}
	}
}

void preenche_personagem(Tree* pai, Tree* mae, Tree* filho, int posicao){/*Funcao percorre duas arvores e preenche uma terceira*/
	
	if( pai!= NULL){
		if((strcmp(filho->left->info->carac, "VAZIO")==0) && (strcmp(filho->right->info->carac, "VAZIO"))==0){
			/*atribuicoes a folha left do filho*/
			filho->left->info->pai=pai->info->id;
			filho->left->info->mae=mae->info->id;
			filho->left->info->dom=retorna_dominante(pai->left->info->dom, pai->right->info->dom);
			filho->left->info->id=posicao;
			if(filho->left->info->dom==pai->left->info->dom)
				strcpy(filho->left->info->carac,pai->left->info->carac);
			else if(filho->left->info->dom==pai->right->info->dom)
				strcpy(filho->left->info->carac,pai->right->info->carac);
			/*atribuicoes a folha right do filho*/
			filho->right->info->pai=pai->info->id;
			filho->right->info->mae=mae->info->id;
			filho->right->info->dom=retorna_dominante(mae->left->info->dom, mae->right->info->dom);
			filho->right->info->id=posicao;
			if(filho->right->info->dom==mae->left->info->dom)
				strcpy(filho->right->info->carac,mae->left->info->carac);
			else if(filho->right->info->dom==mae->right->info->dom)
				strcpy(filho->right->info->carac,mae->right->info->carac);
			if((filho->left->info->dom)>(filho->right->info->dom)){/*Teste que deixa a folha do gene dominante sempre a esquerda*/
				Tree *aux;
				aux=filho->left;
				filho->left=filho->right;
				filho->right=aux;
			}
			/*Mutacao*/
			if(filho->left->info->dom==-1){
                                printf("-1");
				filho->left->info->mutante=1;
				filho->left->info->dom=carac_mutante(pai->left->info->dom);
				
				if(filho->left->info->dom==1)
					strcpy(filho->left->info->carac,"azul");
				else if(filho->left->info->dom==2)
					strcpy(filho->left->info->carac,"castanho");
				else if(filho->left->info->dom==3)
					strcpy(filho->left->info->carac,"preto");
				else if(filho->left->info->dom==4)
					strcpy(filho->left->info->carac,"verde");
				else if(filho->left->info->dom==5)
					strcpy(filho->left->info->carac,"circular");
				else if(filho->left->info->dom==6)
					strcpy(filho->left->info->carac,"triangular");
				else if(filho->left->info->dom==7)
					strcpy(filho->left->info->carac,"amarelo");
				else if(filho->left->info->dom==8)
					strcpy(filho->left->info->carac,"azul");
				else if(filho->left->info->dom==9)
					strcpy(filho->left->info->carac,"preto");
				else if(filho->left->info->dom==10)
					strcpy(filho->left->info->carac,"vermelho");
				else if(filho->left->info->dom==11)
					strcpy(filho->left->info->carac,"careca");
				else if(filho->left->info->dom==12)
					strcpy(filho->left->info->carac,"goku");
				else if(filho->left->info->dom==13)
					strcpy(filho->left->info->carac,"trunks");
				else if(filho->left->info->dom==14)
					strcpy(filho->left->info->carac,"vegeta");
				else if(filho->left->info->dom==15)
					strcpy(filho->left->info->carac,"azul");
				else if(filho->left->info->dom==16)
					strcpy(filho->left->info->carac,"laranja");
				else if(filho->left->info->dom==17)
					strcpy(filho->left->info->carac,"preta");
				else if(filho->left->info->dom==18)
					strcpy(filho->left->info->carac,"azul");
				else if(filho->left->info->dom==19)
					strcpy(filho->left->info->carac,"marrom");
				else if(filho->left->info->dom==20)
					strcpy(filho->left->info->carac,"preta");
				else if(filho->left->info->dom==21)
					strcpy(filho->left->info->carac,"humano");
				else if(filho->left->info->dom==22)
					strcpy(filho->left->info->carac,"namekusei");
				else if(filho->left->info->dom==23)
					strcpy(filho->left->info->carac,"saiyajin");
				else if(filho->left->info->dom==24)
					strcpy(filho->left->info->carac,"armadura");
				else if(filho->left->info->dom==25)
					strcpy(filho->left->info->carac,"treino");
				else if(filho->left->info->dom==26)
					strcpy(filho->left->info->carac,"sem camisa");
			}
			if(filho->right->info->dom==-1){
                                printf("-1");
				filho->right->info->mutante=1;
				filho->right->info->dom=carac_mutante(mae->right->info->dom);
				
				if(filho->right->info->dom==1)
					strcpy(filho->right->info->carac,"azul");
				else if(filho->right->info->dom==2)
					strcpy(filho->right->info->carac,"castanho");
				else if(filho->right->info->dom==3)
					strcpy(filho->right->info->carac,"preto");
				else if(filho->right->info->dom==4)
					strcpy(filho->right->info->carac,"verde");
				else if(filho->right->info->dom==5)
					strcpy(filho->right->info->carac,"circular");
				else if(filho->right->info->dom==6)
					strcpy(filho->right->info->carac,"triangular");
				else if(filho->right->info->dom==7)
					strcpy(filho->right->info->carac,"amarelo");
				else if(filho->right->info->dom==8)
					strcpy(filho->right->info->carac,"azul");
				else if(filho->right->info->dom==9)
					strcpy(filho->right->info->carac,"preto");
				else if(filho->right->info->dom==10)
					strcpy(filho->right->info->carac,"vermelho");
				else if(filho->right->info->dom==11)
					strcpy(filho->right->info->carac,"careca");
				else if(filho->right->info->dom==12)
					strcpy(filho->right->info->carac,"goku");
				else if(filho->right->info->dom==13)
					strcpy(filho->right->info->carac,"trunks");
				else if(filho->right->info->dom==14)
					strcpy(filho->right->info->carac,"vegeta");
				else if(filho->right->info->dom==15)
					strcpy(filho->right->info->carac,"azul");
				else if(filho->right->info->dom==16)
					strcpy(filho->right->info->carac,"laranja");
				else if(filho->right->info->dom==17)
					strcpy(filho->right->info->carac,"preta");
				else if(filho->right->info->dom==18)
					strcpy(filho->right->info->carac,"azul");
				else if(filho->right->info->dom==19)
					strcpy(filho->right->info->carac,"marrom");
				else if(filho->right->info->dom==20)
					strcpy(filho->right->info->carac,"preta");
				else if(filho->right->info->dom==21)
					strcpy(filho->right->info->carac,"humano");
				else if(filho->right->info->dom==22)
					strcpy(filho->right->info->carac,"namekusei");
				else if(filho->right->info->dom==23)
					strcpy(filho->right->info->carac,"saiyajin");
				else if(filho->right->info->dom==24)
					strcpy(filho->right->info->carac,"armadura");
				else if(filho->right->info->dom==25)
					strcpy(filho->right->info->carac,"treino");
				else if(filho->right->info->dom==26)
					strcpy(filho->right->info->carac,"sem camisa");
			}

		}
		else{/*Recursividade para percorrer a lista*/
	        	preenche_personagem(pai->left, mae->left, filho->left, posicao);
        		preenche_personagem(pai->right, mae->right, filho->right, posicao);
		}
	}
}


int* cria_descendente(Lista *cabeca){
	int i=0, x, k=5, aux, possibilidades[6], *flag = (int *) calloc (6, sizeof (int));
	Nodo *pai1, *pai2;
	Tree *filho;

	for(i=0; i<6; i++){
		possibilidades[i]=i;
		flag[i]=0;
	}
	srand( (unsigned)time(NULL) );
	for(i=0; i <4; i++){
		aux=i;
	        x=rand()%6;
		if((x==possibilidades[0]) && flag[0]==0){
			pai1=retorna_elemento(cabeca, 0);
			pai2=retorna_elemento(cabeca, 1);
			filho= cria_arvore_personagem(k);
			filho->info->pai=pai1->personagem->info->id;
			filho->info->mae=pai2->personagem->info->id;
			preenche_personagem(pai1->personagem, pai2->personagem, filho, k);
			k++;
			flag[0]=1;
		}
		else if((x==possibilidades[1]) && flag[1]==0){
			pai1=retorna_elemento(cabeca, 0);
			pai2=retorna_elemento(cabeca, 2);
			filho= cria_arvore_personagem(k);
			filho->info->pai=pai1->personagem->info->id;
			filho->info->mae=pai2->personagem->info->id;
			preenche_personagem(pai1->personagem, pai2->personagem, filho, k);
			k++;
			flag[1]=1;
		}
		else if((x==possibilidades[2]) && flag[2]==0){
			pai1=retorna_elemento(cabeca, 0);
			pai2=retorna_elemento(cabeca, 3);
			filho= cria_arvore_personagem(k);
			filho->info->pai=pai1->personagem->info->id;
			filho->info->mae=pai2->personagem->info->id;
			preenche_personagem(pai1->personagem, pai2->personagem, filho, k);
			k++;
			flag[2]=1;
		}
		else if((x==possibilidades[3]) && flag[3]==0){
			pai1=retorna_elemento(cabeca, 1);
			pai2=retorna_elemento(cabeca, 2);
			filho= cria_arvore_personagem(k);
			filho->info->pai=pai1->personagem->info->id;
			filho->info->mae=pai2->personagem->info->id;
			preenche_personagem(pai1->personagem, pai2->personagem, filho, k);
			k++;
			flag[3]=1;
		}
		else if((x==possibilidades[4]) && flag[4]==0){
			pai1=retorna_elemento(cabeca, 1);
			pai2=retorna_elemento(cabeca, 3);
			filho= cria_arvore_personagem(k);
			filho->info->pai=pai1->personagem->info->id;
			filho->info->mae=pai2->personagem->info->id;
			preenche_personagem(pai1->personagem, pai2->personagem, filho, k);
			k++;
			flag[4]=1;
		}
		else if((x==possibilidades[5]) && flag[5]==0){
			pai1=retorna_elemento(cabeca, 2);
			pai2=retorna_elemento(cabeca, 3);
			filho= cria_arvore_personagem(k);
			filho->info->pai=pai1->personagem->info->id;
			filho->info->mae=pai2->personagem->info->id;
			preenche_personagem(pai1->personagem, pai2->personagem, filho, k);
			k++;
			flag[5]=1;
		}
		else
			i--;
		if(aux==i)
			insere_lista(cabeca, k-2 , filho);
	}
	return flag;

}

void cria_novageracao(int *usados){
	int matriz[8][8], i, j;

	//Elimina a possibilidade de um casal ser formado com ele mesmo na matriz
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(i==j){
				matriz[i][j]=1;
			}
			else{
				matriz[i][j]=0;
			}
		}
	}
	//Insere os casais ja feitos na funcao dos 8 primeiros
	if(usados[0]==1){
		matriz[0][1]=1;
	}
	if(usados[1]==1){
		matriz[0][2]=1;
	}
	if(usados[2]==1){
		matriz[0][3]=1;
	}
	if(usados[3]==1){
		matriz[1][2]=1;
	}
	if(usados[4]==1){
		matriz[1][3]=1;
	}
	if(usados[5]==1){
		matriz[2][3]=1;
	}

	Tree* pai1, pai2;
	int escolha1, escolha2;
	//while (i=7; i<15; i++){
	//	escolha1 = 7 + rand() % 8;
	//	escolha2 = 7 + rand() % 8;
	//}


} 

void imprime_personagem(Tree *persona, int id){
	if(id==0)
		printf("\n\n-Identificacao: %d  -Pai: %d -Mae: %d\n", persona->info->id, persona->info->pai, persona->info->mae);
	if((strcmp(persona->info->carac, "personagem")!=0) && (strcmp(persona->info->carac, "cabeca")!=0) && (strcmp(persona->info->carac, "corpo")!=0))
		printf("\n %s", persona->info->carac);
	if( persona!= NULL){
		if(((persona->left->left==NULL) && (persona->left->right==NULL)) && ((persona->right->left==NULL) && (persona->right->right==NULL))){
			if(persona->left->info->mutante==1)
				printf(": MUTANTE (%d)%s,",persona->left->info->dom, persona->left->info->carac);
                        else
                                printf(": (%d)%s,",persona->left->info->dom, persona->left->info->carac);
                        if(persona->right->info->mutante==1)
				printf(" MUTANTE (%d)%s",persona->right->info->dom, persona->right->info->carac);
                        else
                                printf(" (%d)%s",persona->right->info->dom, persona->right->info->carac);
                        if((strcmp(persona->info->carac, "formato")==0) || (strcmp(persona->info->carac, "tipo")==0) || (strcmp(persona->info->carac, "botas")==0))
                                printf("\n");
		}
		else{/*Recursividade para percorrer a lista*/
	        	imprime_personagem(persona->left, 1);
        		imprime_personagem(persona->right, 1);
		}
        }
}

int main(){
	int *usados;

	/*Criamos uma arvore de personagem para testes */
	/*Lembre-se que ela recebe o id do personagem */
	//Tree* personagem = cria_arvore_personagem(0);
	//imprime_arvore(personagem);

	Lista* lista = cria_primeiros_personagens();
	usados=cria_descendente(lista);
	//cria_novageracao(usados);
	/*printf("Dominio olhos = %d\n", personagem->left->left->left->info->dom);
	printf("%s\n", personagem->left->right->right->info->carac);*/
	
	int i;
	Nodo *nodo;

	for (i=0; i<8; i++){
		nodo = retorna_elemento(lista, i);
		imprime_personagem(nodo->personagem, 0);
	}


	
	printf("\nO personagem impresso graficamente nao corresponde ao personagem vazio impresso de forma textual");
	printf("\n\n");

	/*Caso queira testar a biblioteca grafica */
	//imprime_personagem_aleatorio();
    return 0;
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arvore.h"
#include "criador.h"
#include "listas.h"

void preenche_lista_primeiros(Tree* personagem, int* posicao){/*Preenche a arvore de um dos 4 personagens primordiais*/ 
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


Lista* cria_primeiros_personagens(){/*Cria os primeiros 4 personagens aleatorios*/
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
	free(posicao);
	return lista;
}


int carac_mutante(int carac){/*Funcao retorna um inteiro correspondente a caracteristica aleatoria para um gene mutante*/
	int x=0;

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
		if((strcmp(filho->left->info->carac, "VAZIO")==0) && (strcmp(filho->right->info->carac, "VAZIO"))==0){/*Teste que impede a recursao ate as folhas da arvore do personagem*/
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
			/*Seta a flag mutante e atribui a caracteristica mutante a dominancia do filho*/
			if(filho->left->info->dom==-1){
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


void cria_novageracao(Lista *lista){
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
	

	Nodo* nodo;
	Tree* filho; 
	Tree* pai, *mae;
	int escolha1, escolha2;


	for (i=5; i<=8; i++){/*Sorteia entre os 4 peimordias casais para serem pais dos novos personagens que serao criados*/
		escolha1 = rand() % 4;
		escolha2 = rand() % 4;
		while (matriz[escolha1][escolha2] == 1){/*Impede que um casal ja formado se forme novamente*/
			escolha1 = rand() % 4;
			escolha2 = rand() % 4;
		}
		//seta o novo casal
		matriz[escolha1][escolha2]=1;
		matriz[escolha2][escolha1]=1;
		filho = cria_arvore_personagem(i);
		//Coloca os ids dos pais no filho
		filho->info->pai=escolha1+1;
		filho->info->mae=escolha2+1;
		//retorna a arvore do pai
		nodo = retorna_elemento(lista, escolha1);
		pai = nodo->personagem;
		//Retorna a arvore da mae
		nodo = retorna_elemento(lista, escolha2);
		mae = nodo->personagem;
		preenche_personagem(pai, mae, filho, i);
		//Insere o filho na lista
		insere_lista(lista, i-1, filho);
	}



	for (i=9; i<=16; i++){/*Sorteia entre os 4 peimordias casais para serem pais dos novos personagens que serao criados*/
		escolha1 = rand() % 7;
		escolha2 = rand() % 7;
		while (matriz[escolha1][escolha2] != 0){/*Impede que um casal ja formado se forme novamente*/
			escolha1 = rand() % 7;
			escolha2 = rand() % 7;
		}
		//seta o novo casal
		matriz[escolha1][escolha2]=1;
		matriz[escolha2][escolha1]=1;
		filho = cria_arvore_personagem(i);
		//Coloca os ids dos pais no filho
		filho->info->pai=escolha1+1;
		filho->info->mae=escolha2+1;
		//retorna a arvore do pai
		nodo = retorna_elemento(lista, escolha1);
		pai = nodo->personagem;
		//Retorna a arvore da mae
		nodo = retorna_elemento(lista, escolha2);
		mae = nodo->personagem;
		preenche_personagem(pai, mae, filho, i);
		//Insere o filho na lista
		insere_lista(lista, i-1, filho);
	}
}

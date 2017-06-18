#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "printPersonagem.h"
#include "arvore.h"
#include "criador.h"


#include "listas.h"
#include "criador_personagem.h"
#include "menu.h"

void imprime_personagem_text(Tree *persona, int id){/*Funcao recursiva para imprimir em texto o que corresponde a um personagem*/
	if(id==0)/*Teste para imprimir a id do personagem, de seu pai e de sua mae*/
		printf("\n---------------------------------------------\n\n-Identificacao: %d  -Pai: %d -Mae: %d\n", persona->info->id, persona->info->pai, persona->info->mae);
	if((strcmp(persona->info->carac, "personagem")!=0) && (strcmp(persona->info->carac, "cabeca")!=0) && (strcmp(persona->info->carac, "corpo")!=0))/*Teste para imprimir a raiz que corresponde ao tipo da caracteristica*/
		printf("\n %s", persona->info->carac);
	if( persona!= NULL){
		if(((persona->left->left==NULL) && (persona->left->right==NULL)) && ((persona->right->left==NULL) && (persona->right->right==NULL))){/*Teste que impede a recursao ate as folhas da arvore do personagem*/
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
	        	imprime_personagem_text(persona->left, 1);
        		imprime_personagem_text(persona->right, 1);
		}
        }
}

void menu(Lista *lista){/*Funcao que oferece ao usuario as opcoes de impressao dos personagens criados*/
	int i, k=0, escolha;
	char escolhaT[37], aux[2];
	Nodo *nodo;

	printf("Escolha uma opcao para a visualizacao de personagem:\n");
	printf("1-Visualizar personagem único\n");	
	printf("2-Visualizar conjunto de personagens\n");
	printf("3-Visualizar todos personagens\n");
	scanf("%d", &escolha);
	while((escolha!=1) && (escolha!=2) && (escolha!=3)){
		printf("Escolha invalida, digite novamente: ");
		scanf("%d", &escolha);
	}
	if (escolha==1){/*Usado para imprimir um unico personagem*/
		printf("Digite o numero do personagem que deseja visualizar(entre 1 e 16): ");
		scanf("%d", &escolha);
		nodo = retorna_elemento(lista, escolha-1);
		imprime_personagem_text(nodo->personagem, 0);
		//imprime_personagem(nodo->personagem);
		printf("\n");
	}
	else if(escolha==2){/*Usado para imprimir os personagens determinados pelo usuario*/
		printf("Digite(separando por espaco) o numero dos personagens que deseja visualizar :");
		getchar();
		scanf("%[^\n]", escolhaT);
		while(k!=(strlen(escolhaT))){
			if((escolhaT[k+1]==' ') || (escolhaT[k+1]=='\0')){
				if((k>0) && (escolhaT[k-1]!=' ')){
					aux[0]=escolhaT[k-1];
					aux[1]=escolhaT[k];
					escolha=atoi(aux);
					nodo = retorna_elemento(lista, escolha-1);
					imprime_personagem_text(nodo->personagem, 0);
					//imprime_personagem(nodo->personagem);
					
				}
				else{
					aux[0]=escolhaT[k];
					aux[1]=' ';
					escolha=atoi(aux);
					nodo = retorna_elemento(lista, escolha-1);
					imprime_personagem_text(nodo->personagem, 0);
					//imprime_personagem(nodo->personagem);
				}
			}
			k++;
		}
		printf("\n");
	}
	else{/*Usado para imprimir todos os personagens criados*/
		for (i=0; i<16; i++){
			nodo = retorna_elemento(lista, i);
			imprime_personagem_text(nodo->personagem, 0);
			//imprime_personagem(nodo->personagem);
		}
	}
	printf("\n");
	printf("\nDeseja Visualizar personagens ja criados (1-Sim/2-Nao)\n");
	scanf("%d", &escolha);
	while((escolha!=1) && (escolha!=2)){
		printf("Escolha invalida, digite novamente: ");
		scanf("%d", &escolha);
	}
	if(escolha==1)/*Retorno ao menu caso o usuario queira ver os personagens ja criados*/
		menu(lista);
}

int continua(){/*Funcao que pergunta e retorna a resposta de caso o usuario deseje que novos personagens sejam criados*/
	int continuar;

	printf("Deseja criar novos personagens? (1-Sim/2-Nao)\n");
	scanf("%d", &continuar);
	while((continuar!=1) && (continuar!=2)){
		printf("Escolha invalida, digite novamente: ");
		scanf("%d", &continuar);
	}
	//system("clear||cls");
	return continuar;
}

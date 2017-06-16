void preenche_lista_primeiros(Tree* personagem, int* posicao);

/*Cria os primeiros 4 personagens aleatorios*/

Lista* cria_primeiros_personagens();


int carac_mutante(int carac);

int retorna_dominante(int carac1, int carac2);/*Funcao retorna o inteiro correspondente ao do gene dominante ou -1 para um mutante*/
	

void preenche_personagem(Tree* pai, Tree* mae, Tree* filho, int posicao);/*Funcao percorre duas arvores e preenche uma terceira*/
	
	


void cria_novageracao(Lista *lista);
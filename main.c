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






int main(){

	

	Lista* lista = cria_primeiros_personagens();
	cria_novageracao(lista);
	menu(lista);
	libera_tudo(lista);
    return 0;
}

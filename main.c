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
	int executa=1;
	
	while(executa==1){/*Executa o programa do zero criando novos personagens caso o usuario o queira*/
		Lista* lista = cria_primeiros_personagens();
		cria_novageracao(lista);
		menu(lista);
		libera_tudo(lista);
		executa=continua();
	}
	printf("Programa encerrado\n");
    return 0;
}

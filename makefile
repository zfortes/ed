all: main.c
	g++ -o trabalho main.c listas.c criador_personagem.c menu.c -L. -l personagem -l playAPC  -I.

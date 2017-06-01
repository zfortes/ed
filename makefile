all: main.c
	g++ -o trabalho main.c -L. -l personagem -l playAPC  -I.
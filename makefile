tudo:
	make mesa
	make taca
	make garrafa
	make cadeira
	make luminaria
	make main

main:
	gcc -o Main main.c -lglut  -lGL -lGLU -lm
	./Main

chao:
	gcc -o Chao chao.c -lglut  -lGL -lGLU -lm
	./Chao
mesa:
	gcc -o Mesa mesa.c -lglut  -lGL -lGLU -lm
	./Mesa

taca:
	gcc -o Taca taca.c -lglut  -lGL -lGLU -lm
	./Taca

garrafa: garrafa.c 
	gcc -o Garrafa garrafa.c -lglut -lGL -lGLU -lm
	./Garrafa

cadeira: cadeira.c 
	gcc -o Cadeira cadeira.c -lglut -lGL -lGLU -lm
	./Cadeira

luminaria: luminaria.c 
		gcc -o Luminaria luminaria.c -lglut -lGL -lGLU -lm
	./Luminaria

clear: 
	rm Cadeira Garrafa Luminaria Main Mesa Taca
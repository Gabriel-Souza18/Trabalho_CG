clean:
	rm mesa

mesa:
	gcc -o Mesa mesa.c -lglut  -lGL -lGLU -lm
	./Mesa

taca:
	gcc -o Taca taca.c -lglut  -lGL -lGLU -lm
	./Taca


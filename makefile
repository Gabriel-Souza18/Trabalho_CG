clean:
	rm mesa

mesa:
	gcc -o Mesa mesa.c -lglut  -lGL -lGLU -lm
	./Mesa


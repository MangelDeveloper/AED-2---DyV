
programa.out: main.o algoritmo.o controlador.o
	g++ -std=c++20 main.o algoritmo.o controlador.o -o programa.out

algoritmo.o: Algoritmo.cpp Algoritmo.h
	g++ -std=c++20 -c Algoritmo.cpp -o algoritmo.o

controlador.o: Controlador.cpp Controlador.h algoritmo.o
	g++ -std=c++20 -c Controlador.cpp -o controlador.o

main.o: Main.cpp controlador.o algoritmo.o
	g++ -std=c++20 -c Main.cpp -o main.o

run:
	 ./programa.out

clean:
	rm -f *.o programa.out




CC = g++
CFLAGS = -Werror -Wall -g  -std=c++11
SFML  = -lsfml-graphics -lsfml-window -lsfml-system

NBodySimulation: Body.o NBody.o
	$(CC) $(CFLAGS) -o NBodySimulation Body.o NBody.o $(SFML)

NBody.o: NBody.cpp Body.o
	$(CC) $(CFLAGS) -c NBody.cpp -o NBody.o

Body.o: Body.cpp Body.hpp
	$(CC) $(CFLAGS) -c Body.cpp -o Body.o 

clean:
	rm NBody.o Body.o NBodySimulation *~ *#

CC = g++
# CC = clang
FLAGS = -std=c++11 

main.out: main.cpp textgraphics.o imgcontainer.o pixel.o
	$(CC) $(FLAGS) main.cpp textgraphics.o pixel.o imgcontainer.o -o main.out
textgraphics.o: textgraphics.cpp
	$(CC) $(FLAGS) -c -o textgraphics.o textgraphics.cpp
imgcontainer.o: imgcontainer.cpp
	$(CC) $(FLAGS) -c -o imgcontainer.o imgcontainer.cpp
pixel.o: pixel.cpp
	$(CC) $(FLAGS) -c -o pixel.o pixel.cpp
clean:
	rm -f *.o *.out

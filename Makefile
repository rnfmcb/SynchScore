output:	main.o sych.o
	g++ -std=c++0x -Wall main.o sych.o -o sychScore

main.o: main.cpp
	g++ -c main.cpp

tree.o: sych.cpp sych.h
	g++ -c sych.cpp

clean:
	rm *.o sychScore

output: program.o swap.o
	g++ program.o swap.o -o output

program.o: program.cpp program.h
	g++ -c program.cpp -o program.o

swap.o: swap.cpp
	g++ -c swap.cpp -o swap.o

.PHONY: clean
clean:
	rm -r *.o output

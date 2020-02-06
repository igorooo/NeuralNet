prog: Matrix.o test.o
	g++ -o prog test.o Matrix.o

test.o: test.cpp
	g++ -c test.cpp

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp

clean:
	rm *.o prog

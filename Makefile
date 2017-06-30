all:main

main:test.o vigenere.o
	g++ -o run test.o vigenere.o
test.o:test.cpp vigenere.h
	g++ -o test.o -c test.cpp
vigenere.o:vigenere.cpp vigenere.h
	g++ -o vigenere.o -c vigenere.cpp

clean:
	rm *.o run 

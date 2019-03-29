# Makefile
# oberoi, sean
# ssoberoi

linkedList: LinkedList.o Main.o
	rm -rf linkedList
	g++ -v -I LinkedList.o Main.o -o ./linkedList

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

Main.o: Main.cpp LinkedList.h
	g++ -c Main.cpp

clean:
	@rm -f $(PROGRAMS) *.o core
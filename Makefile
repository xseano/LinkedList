# Makefile
# oberoi, sean
# ssoberoi

linkedlist: LinkedList.o Main.o
	rm -rf linkedList
	g++ LinkedList.o Main.o -o ./linkedList
	make clean

clean:
	@rm -f $(PROGRAMS) *.o core
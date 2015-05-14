#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic 


Struktury:  obj/Czasomierz.o obj/Wyniki.o  obj/Main.o
	g++ -Wall -pedantic -o Struktury obj/*.o

obj:
	mkdir obj

obj/Main.o: src/Main.cpp inc/*.hh
	g++ ${CPPFLAGS} -o obj/Main.o src/Main.cpp

obj/Wyniki.o: src/Wyniki.cpp inc/Wyniki.hh
	g++ ${CPPFLAGS} -o obj/Wyniki.o src/Wyniki.cpp

obj/Czasomierz.o: src/Czasomierz.cpp inc/Czasomierz.hh
	g++ ${CPPFLAGS} -o obj/Czasomierz.o src/Czasomierz.cpp
clean:
	rm -f obj/*.o Struktury



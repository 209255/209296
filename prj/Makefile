a.out: main.o Statystyka.o Pliki.o
	g++ -Wall -pedantic main.o Statystyka.o Pliki.o

main.o: src/main.cpp inc/Lista.hh inc/Kolejka.hh inc/Stos.hh inc/Statystyka.hh inc/InterfejsADT.hh inc/ListArr2x.hh inc/ListArr1.hh
	g++ -c -Wall -pedantic src/main.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh
	g++ -c -Wall -pedantic src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

clean:
	rm -f *.o

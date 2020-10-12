all: CompOrgTools.x

CompOrgTools.x: main.o CompOrgTools.o CompOrgTools.h
	g++ -std=c++11 -o CompOrgTools.x main.o CompOrgTools.o

main.o: main.cpp CompOrgTools.h
	g++ -std=c++11 -c main.cpp

CompOrgTools.o: CompOrgTools.cpp CompOrgTools.h
	g++ -std=c++11 -c CompOrgTools.cpp

clean:
	rm -f *.o CompOrgTools.x

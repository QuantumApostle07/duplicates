EXECUTABLE := read

read: read.o strSHA2.o
	gcc strSHA2.o read.o -o read

read.o: read.c header.h
	gcc -c read.c

strSHA2.o: strSHA2.o header.h
	gcc -c strSHA2.c

clean: 
	rm *.o a.out read
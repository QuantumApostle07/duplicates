
   
EXECUTABLE := duplicates
C11     =  cc -std=c11
CFLAGS  =  -Wall -Werror -pedantic




duplicates: storage.o strSHA2.o duplicates.o linkedlist.o iterate.o 
	$(C11) $(CFLAGS) strSHA2.o storage.o duplicates.o linkedlist.o iterate.o  -o duplicates

storage.o: storage.c storage.h
	$(C11) $(CFLAGS) -c storage.c

strSHA2.o: strSHA2.c strSHA2.h
	$(C11) $(CFLAGS) -c strSHA2.c

duplicates.o: duplicates.c
	$(C11) $(CFLAGS) -c duplicates.c

linkedlist.o: linkedlist.c linkedlist.h
	$(C11) $(CFLAGS) -c linkedlist.c

iterate.o: iterate.c iterate.h
	$(C11) $(CFLAGS) -c iterate.c

clean: 
	rm *.o a.out main debugger
CFLAGS = -Wall -g
all:main1_1 libhello.so

main1_1:main1_1.o
	gcc $(CFLAGS) -o main1_1 main1_1.o

hello_ariel.o: hello_ariel.c hello_ariel.h
	gcc $(CFLAGS)-c hello_ariel.c

main1_1.o:main1_1.c hello_ariel.h
	gcc $(CFLAGS) -c main1_1.c

libhello.so:hello_ariel.o
	gcc -o libhello.so -shared -fPIC hello_ariel.c

main1_2:main.o
	gcc $(CFLAGS)

.PHONY: clean all

clean:
		rm *.o main1_1
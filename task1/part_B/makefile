all:task2_1 friend task2_2 task2_3 task2_4

task2_1:main2_1.c
	gcc -o main2_1 main2_1.c

friend:friend.c
	gcc -o friend friend.c

task2_2:main2_2.c
	gcc -o main2_2 main2_2.c

task2_3: main2_3.c
	gcc -o main2_3 main2_3.c

task2_4: main2_1.c main2_2.c main2_3.c main2_4.c 
	gcc -o main4 main2_4.c

.PHONY: all clean
clean:
		-rm main2_1 friend main2_2 main2_3 main4

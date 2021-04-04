all:task2_1 friend task2_2 task2_3

task2_1:main2_1.c
	gcc -o fork main2_1.c

friend:friend.c
	gcc -o friend friend.c

task2_2:main2_2.c
	gcc -o clone main2_2.c

task2_3: main2_3.c
	gcc -o deamon main2_3.c


.PHONY: all clean
clean:
		-rm fork friend clone deamon

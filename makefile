CC = gcc
CFLAGS = -Wall -Werror -ansi
LIBDIR = ./lib

main.out: main.o
	$(CC) $(CFLAGS) -o main.out main.o user.o caesar.o rle.o searching.o sorting.o xor.o
	
main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c 

user.o: user.c
	$(CC) $(CFLAGS) -c -o user.o user.c
	
caesar.o: caesar.c
	$(CC) $(CFLAGS) -c -o caesar.o $(LIBDIR)caesar.c
	
rle.o: rle.c
	$(CC) $(CFLAGS) -c -o rle.o $(LIBDIR)rle.c
	
searching.o: searching.c
	$(CC) $(CFLAGS) -c -o searching.o $(LIBDIR)searching.c
	
sorting.o: sorting.c
	$(CC) $(CFLAGS) -c -o sorting.o $(LIBDIR)sorting.c
	
xor.o: xor.c
	$(CC) $(CFLAGS) -c -o xor.o $(LIBDIR)xor.c

clean:
	rm main.out main.o user.o caesar.o rle.o searching.o sorting.o xor.o
CC = gcc
CFLAGS = -Wall -Werror
LIBDIR = ./libs

main.out: main.o user.o caesar.o rle.o searching.o sorting.o xor.o
	$(CC) $(CFLAGS) -o main.out main.o user.o caesar.o rle.o searching.o sorting.o xor.o
	
main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c 

user.o: user.c
	$(CC) $(CFLAGS) -c -o user.o user.c
	
caesar.o: $(LIBDIR)/caesar.c
	$(CC) $(CFLAGS) -c -o caesar.o $(LIBDIR)/caesar.c
	
rle.o: $(LIBDIR)/rle.c
	$(CC) $(CFLAGS) -c -o rle.o $(LIBDIR)/rle.c
	
searching.o: $(LIBDIR)/searching.c
	$(CC) $(CFLAGS) -c -o searching.o $(LIBDIR)/searching.c
	
sorting.o: $(LIBDIR)/sorting.c
	$(CC) $(CFLAGS) -c -o sorting.o $(LIBDIR)/sorting.c
	
xor.o: $(LIBDIR)/xor.c
	$(CC) $(CFLAGS) -c -o xor.o $(LIBDIR)/xor.c

clean:
	rm main.out main.o user.o caesar.o rle.o searching.o sorting.o xor.o
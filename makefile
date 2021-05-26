CC = gcc
CFLAGS = -Wall -Werror
LIBDIR = ./libs

main.out: main.o user.o caesar.o rle.o binary_search.o radix_sort.o xor.o # huffman.o
	$(CC) $(CFLAGS) -o main.out main.o user.o caesar.o rle.o binary_search.o radix_sort.o xor.o
	
main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c 

user.o: user.c
	$(CC) $(CFLAGS) -c -o user.o user.c
	
caesar.o: $(LIBDIR)/caesar.c
	$(CC) $(CFLAGS) -c -o caesar.o $(LIBDIR)/caesar.c

# huffman.o: $(LIBDIR)/huffman.c
#	$(CC) $(CFLAGS) -c -o huffman.o $(LIBDIR)/huffman.

rle.o: $(LIBDIR)/rle.c
	$(CC) $(CFLAGS) -c -o rle.o $(LIBDIR)/rle.c
	
binary_search.o: $(LIBDIR)/binary_search.c
	$(CC) $(CFLAGS) -c -o binary_search.o $(LIBDIR)/binary_search.c
	
radix_sort.o: $(LIBDIR)/radix_sort.c
	$(CC) $(CFLAGS) -c -o radix_sort.o $(LIBDIR)/radix_sort.c
	
xor.o: $(LIBDIR)/xor.c
	$(CC) $(CFLAGS) -c -o xor.o $(LIBDIR)/xor.c

clean:
	rm main.out main.o user.o caesar.o rle.o binary_search.o radix_sort.o xor.o
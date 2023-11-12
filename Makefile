CC=gcc

binaries=matmul_base

all: matmul_base

matmul_base: matmul.c kernel_base.c
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f *.exe *.o $(binaries)
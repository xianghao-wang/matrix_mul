CC=gcc

targets=matmul_base matmul_reorder

all: $(targets)

matmul_base: matmul.c kernel_base.c
	$(CC) -o $@ $^

matmul_reorder: matmul.c kernel_reorder.c
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f *.exe *.o $(targets)
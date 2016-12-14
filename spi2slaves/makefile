APP = spi2ss
BINARY = $(APP)

# Compiler and  Compiler Flags
CC = gcc
CFLAGS = -O2 -Wall

$(BINARY): $(APP).c
	$(CC) $(CFLAGS) -o $(BINARY) $(APP).c
asm: $(APP).c
	$(CC) $(CFLAGS) -S $(APP).c
clean:
	rm -f $(BINARY)

.PHONY: all asm clean

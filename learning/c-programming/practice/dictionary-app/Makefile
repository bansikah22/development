CC = gcc
SRC = src/main.c src/dictionary.c
OUT = dictionary

all:
	$(CC) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

SRC = main.c sum.c Product.c unity.h
OBJ = main.o sum.o Product.o unity.o

object.o: $(SRC)
	gcc $^ -c

all: $(OBJ)
	gcc $^ -o all.exe

run: all
	./all.exe
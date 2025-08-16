object.0: main.c swap.c unity.c
	gcc $^ -c
out: main.o swap.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe
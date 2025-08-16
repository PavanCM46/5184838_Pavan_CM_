object.0: main.c arr_swap.c unity.c
	gcc $^ -c
out: main.o arr_swap.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe
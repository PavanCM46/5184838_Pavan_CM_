object.0: main.c functions.c unity.c
	gcc $^ -c
out: main.o functions.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe
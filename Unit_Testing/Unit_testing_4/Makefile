object.0: main.c average.c unity.c
	gcc $^ -c
out: main.o average.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe
object.0: main.c leap_year.c unity.c
	gcc $^ -c
out: main.o leap_year.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe
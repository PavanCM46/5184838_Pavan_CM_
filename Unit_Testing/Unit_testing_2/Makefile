object.0: main.c leap_year.c unity.c
	gcc $^ -c 
out: main.o leap_year.o unity.o
	gcc $^ -o output.exe
run: output
	./output.exe
clean:
	rm -f *.o*.exe
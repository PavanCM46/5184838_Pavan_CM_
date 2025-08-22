object.o: main.c digitSum.c superDigit.c unity.c
	gcc $^ -c
out: main.o digitSum.o superDigit.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe
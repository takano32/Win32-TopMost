OBJ=main.o
all	:	${OBJ}
	gcc -mwindows -mno-cygwin -o top2nd.exe ${OBJ} -lstdc++

clean:
	rm -f *.o *.exe

run: clean main.o raylib.h draw.o init.o update.o
	gcc main.o draw.o init.o update.o -o main -lraylib
	./main

main.o: main.c
	gcc -c main.c

draw.o: modulos/draw.c bibliotecas/draw.h 
	gcc -c modulos/draw.c

init.o: modulos/init.c bibliotecas/init.h
	gcc -c modulos/init.c

update.o: modulos/update.c bibliotecas/update.h
	gcc -c modulos/update.c

runElverton: elverton.c raylib.h
	gcc elverton.c -o elverton -lraylib
	./elverton

clean:
	rm -f main
	rm -f elverton
	rm -f *.o
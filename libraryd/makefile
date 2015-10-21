libraryd : database.o main.o nfc.o
	gcc -o database.o main.o nfc.o

database.o : database.c libraryd.h
	gcc -c database.c

main.o : main.c libraryd.h
	gcc -c main.c

nfc.o : nfc.c libraryd.h
	gcc -c nfc.c


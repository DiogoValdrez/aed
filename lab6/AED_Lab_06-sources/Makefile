CC=gcc
CFLAGS= -Wall -g -std=c99 

PROJECT= pg2


OBJ_FILES= DataStruct.o main.o LinkedList.o file.o defs.h


$(PROJECT): $(OBJ_FILES)
	gcc $(CFLAGS) -o $(PROJECT) $(OBJ_FILES) 


clean:
	rm -f *.o $(PROJECT)



CC = gcc -Wall 
SRC = main.c Apprentissage.c Tools.c initialisation.c Annexe.c
OBJ = main.o Apprentissage.o Tools.o initialisation.o Annexe.o

SOM:	$(OBJ) header.h
	$(CC) -o SOM $(OBJ) -lm
%.o:	%.c header.h
	$(CC) -c $<

clean:
	rm *.o 



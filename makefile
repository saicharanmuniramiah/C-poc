CC = gcc
CFLAGS = -Wall

# Target to build the final executable
all: file_system

file_system: main.o fs_node.o operations.o navigation.o
$(CC) $(CFLAGS) -o file_system main.o fs_node.o operations.o navigation.o

main.o: main.c fs_node.h operations.h navigation.h
$(CC) $(CFLAGS) -c main.c

fs_node.o: fs_node.c fs_node.h
$(CC) $(CFLAGS) -c fs_node.c

operations.o: operations.c operations.h fs_node.h
$(CC) $(CFLAGS) -c operations.c

navigation.o: navigation.c navigation.h fs_node.h
$(CC) $(CFLAGS) -c navigation.c

clean:
rm -f *.o file_system

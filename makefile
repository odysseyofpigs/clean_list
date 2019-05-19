CC=gcc
CFLAGS=-g -Wall
CFLAGS_OBJ=-g -Wall -c
C_OBJ=clean_list.o

all: clean_list a_test

clean_list: clean_list.c clean_list.h
	$(CC) $(CFLAGS_OBJ) clean_list.c

a_test: clean_list main.c
	$(CC) $(CFLAGS) main.c $(C_OBJ) -o a_test

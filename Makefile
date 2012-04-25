CC = g++
CFLAGS = -Wall -Wshadow -pedantic -ansi
OUT = quatTest

all:
	$(CC) main.cpp -o $(OUT) $(CFLAGS) 

# Makefile for P5 - CS 320 Fall 2021
# @author Arthur Vo 
CC=g++
CFLAGS=-g -std=c++11 -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings

p5: driver.cpp fraction.o
		$(CC) $(CFLAGS) -o p5 driver.cpp fraction.o

fraction.o: fraction.cpp fraction.h fraction_exception.h
		$(CC) $(CFLAGS) -c fraction.cpp

clean:
		rm *.o p5
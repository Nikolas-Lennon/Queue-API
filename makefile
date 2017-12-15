#
# makefile for stack project
#

CC = g++ -std=c++11 -Wall -Wextra -I.

all: fstack.x fqueue.x in2post.x

fstack.x: tstack.h id.h id.cpp fstack.cpp
	$(CC) -o fstack.x fstack.cpp

fqueue.x: tqueue.h fqueue.cpp
	$(CC) -o fqueue.x fqueue.cpp

in2post.x: in2post.cpp
	$(CC) -o in2post.x in2post.cpp

fstack.o: tstack.h id.h fstack.cpp
	$(CC) -c fstack.cpp

in2post.o: tstack.h tqueue.h in2post.cpp
	$(CC) -c in2post.cpp

fqueue.o: tqueue.h fqueue.cpp
	$(CC) -c fqueue.cpp

id.o: id.h id.cpp
	$(CC) -c id.cpp

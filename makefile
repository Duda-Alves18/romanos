TARGET=main
CC=g++
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLAGS=$(PTHREAD) -export-dynamic
OBJS= testa_romanos.o romanos.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)
 
testa_romanos.o: testa_romanos.cpp
	$(CC) -c $(CCFLAGS) testa_romanos.cpp -o testa_romanos.o
 
romanos.o: romanos.cpp
	$(CC) -c $(CCFLAGS) romanos.cpp  -o romanos.o
 
clean:
	rm -rf *.o *~ main
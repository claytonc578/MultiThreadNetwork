#Flags
CFLAG := -Wall -g -pthread
Q := @
CC := g++
TARGET := main
OBJ := server.o client.o

all: $(TARGET)

server.o: server.cpp server.hpp
	$(CC) $(CFLAG) -c server.cpp

client.o: client.cpp client.hpp
	$(CC) $(CFLAG) -c client.cpp

$(TARGET): $(OBJ) $(TARGET).cpp
	$(CC) $(CFLAG) -o $(TARGET) $(TARGET).cpp $(OBJ)

clean:
	rm -f $(TARGET) $(OBJ)

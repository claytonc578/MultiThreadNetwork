#Flags
CFLAG := -Wall -Werror -g -pthread -lsocket -lnsl
Q := @
CC := g++
#TARGET := server
# OBJ := server.o client.o

# all: $(TARGET)

server: server.cpp
	$(CC) $(CFLAG) -c server.cpp

client: client.cpp
	$(CC) $(CFLAG) -c client.cpp

# $(TARGET): $(OBJ) $(TARGET).cpp
# 	$(CC) $(CFLAG) -o $(TARGET) $(TARGET).cpp $(OBJ)

# clean:
	# rm -f $(TARGET) $(OBJ)

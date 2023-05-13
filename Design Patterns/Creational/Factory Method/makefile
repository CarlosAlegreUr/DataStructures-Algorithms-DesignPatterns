CC = g++
CFLAGS = -Wall -std=c++11
OUT = main
SRC = main.cpp example.cpp
OBJ = $(SRC:.cpp=.o)

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OUT) $(OBJ)

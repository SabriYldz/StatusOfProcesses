CC = gcc
CFLAGS = -Wall -Wextra -pthread

# The output executable name
TARGET = linux_monitor

# Source files
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o

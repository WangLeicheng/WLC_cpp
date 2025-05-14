CC      := gcc
CFLAGS  := -O0 -Wall -Wextra -std=c11
TARGET  := range_vs_loop_c

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: all clean

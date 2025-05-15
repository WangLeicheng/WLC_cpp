# Name of the final executable
TARGET = app

# Compiler
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I./source/student

# Source files
SRCDIR = source
STUDENTDIR = $(SRCDIR)/student

SRC = $(SRCDIR)/main.cpp \
      $(STUDENTDIR)/student.cpp

OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean


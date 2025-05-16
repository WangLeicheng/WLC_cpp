# Name of the final executable
TARGET = app

# Compiler
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I./source/student -I./source/teacher -I./source/people

# Source files
SRCDIR = source
PEOPLEDIR = $(SRCDIR)/people
STUDENTDIR = $(SRCDIR)/student
TEACHERDIR = $(SRCDIR)/teacher

SRC = $(SRCDIR)/main.cpp \
      $(PEOPLEDIR)/people.cpp	\
      $(STUDENTDIR)/student.cpp	\
      $(TEACHERDIR)/teacher.cpp

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
	rm -f $(SRCDIR)/.main.cpp.un~
	rm -f $(PEOPLEDIR)/.people.cpp.un~
	rm -f $(PEOPLEDIR)/.people.h.un~
	rm -f $(STUDENTDIR)/.student.cpp.un~
	rm -f $(STUDENTDIR)/.student.h.un~
	rm -f $(TEACHERDIR)/.teacher.cpp.un~
	rm -f $(TEACHERDIR)/.teacher.h.un~

.PHONY: all clean


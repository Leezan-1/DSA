# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Output executable
TARGET = main_program

# Source files
SRC = main.cpp queue.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Build the target
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

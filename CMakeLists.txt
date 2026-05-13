# Compiler
CXX = g++
TARGET = py_embed

# Get Python build flags automatically
PY_INCLUDES = $(shell python3-config --includes)
PY_LDFLAGS  = $(shell python3-config --ldflags)

# Source files
SRC = src/quantum_python_interpreter.c

# Build flags
CXXFLAGS = -std=c++17 -O2 -Wall

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(PY_INCLUDES) $(PY_LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

#Simple Makefile to get started

#Compiler flags
CXX := g++
CXXFLAGS := -Wall -Wextra -O2 -g

#Source files
CPP_SRC := src/main.cpp

#Output directory
BIN_DIR := bin

#Target executables
CPP_TARGET := $(BIN_DIR)/main.exe

#Build rules
main: $(CPP_TARGET)

# Create bin directory if it doesn't exist, for convenience
$(BIN_DIR):
	mkdir -p $(BIN_DIR) 

$(CPP_TARGET): $(BIN_DIR) $(CPP_SRC)
	$(CXX) $(CXXFLAGS) $(CPP_SRC) -o $(CPP_TARGET)

#Run rules
run_main: $(CPP_TARGET)
	$(CPP_TARGET)

# Clean rule
clean:
	rm -f $(CPP_TARGET)

# Phony targets to avoid conflicts with files of the same name
.PHONY: all run_main clean

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -g -Werror -pedantic -o1

# Source files directory and file extension
SRC_DIR := src
SRC_EXT := c

# Build directory
BUILD_DIR := build

# Freshly cloned repos wont have build dir yet
$(shell mkdir -p $(BUILD_DIR))

# Find all source files in the source directory
SRCS := $(wildcard $(SRC_DIR)/*.$(SRC_EXT))

# Create a list of corresponding object files in the build directory
OBJS := $(patsubst $(SRC_DIR)/%.$(SRC_EXT),$(BUILD_DIR)/%.o,$(SRCS))

# List of executable targets (automatically generated based on source file names)
EXECS := $(patsubst $(SRC_DIR)/%.$(SRC_EXT),%.bin,$(SRCS))

# Default target: build all executables
all: $(EXECS)

# Rule to build each executable from its corresponding object file
$(EXECS): %.bin: $(BUILD_DIR)/%.o
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile each source file to an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove all executables and object files
clean:
	rm -f $(EXECS) $(OBJS)

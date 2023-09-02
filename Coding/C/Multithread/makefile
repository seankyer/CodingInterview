# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -g -Werror -pedantic -O1

# Source files directory and file extension
SRC_DIR := src
SRC_EXT := c

# Additional source directory for test.c (two levels up)
TEST_SRC_DIR := ../Testing

# Build directory
BUILD_DIR := build

# Freshly cloned repos won't have a build directory yet
$(shell mkdir -p $(BUILD_DIR))

# Find all source files in the source directories
SRCS := $(wildcard $(SRC_DIR)/*.$(SRC_EXT)) $(wildcard $(TEST_SRC_DIR)/*.$(SRC_EXT))

# Create a list of corresponding object files in the build directory
OBJS := $(patsubst $(SRC_DIR)/%.$(SRC_EXT),$(BUILD_DIR)/%.o,$(filter-out $(TEST_SRC_DIR)/%.c,$(SRCS)))

# List of executable targets (automatically generated based on source file names)
EXECS := $(patsubst $(SRC_DIR)/%.$(SRC_EXT),%.bin,$(filter-out $(TEST_SRC_DIR)/%.c,$(SRCS)))

# Default target: build all executables
all: $(EXECS)

# Rule to build each executable from its corresponding object file
$(EXECS): %.bin: $(BUILD_DIR)/%.o $(BUILD_DIR)/test.o
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile each source file to an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile test.c to an object file
$(BUILD_DIR)/test.o: $(TEST_SRC_DIR)/test.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove all executables and object files
clean:
	rm -f $(EXECS) $(OBJS) $(BUILD_DIR)/test.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -I./include
LDFLAGS = 

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Target executable
# CHANGED: Replaced space with underscore to prevent compiler errors
TARGET = $(BIN_DIR)/chess

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header files
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Clean complete"

# Run the program
run: all
	@./$(TARGET)

# Rebuild everything
rebuild: clean all

# Help
help:
	@echo "Available targets:"
	@echo "  all       - Build the project (default)"
	@echo "  clean     - Remove build artifacts"
	@echo "  run       - Build and run the program"
	@echo "  rebuild   - Clean and build"
	@echo "  help      - Show this help message"

.PHONY: all directories clean run rebuild help
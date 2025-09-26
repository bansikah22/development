# Makefile for C Programming Learning Guide
# This makefile compiles all the example programs

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
MATHLIB = -lm

# Directories
DIRS = 01-hello-world 02-variables-datatypes 03-control-structures 04-functions 05-arrays 06-pointers 07-structures 08-input-output

# All targets
all: hello variables control functions arrays pointers structures input_output
	@echo "All programs compiled successfully!"
	@echo "Run 'make help' for usage instructions"

# Individual program targets
hello:
	@echo "Compiling Hello World..."
	$(CC) $(CFLAGS) 01-hello-world/hello.c -o 01-hello-world/hello

variables:
	@echo "Compiling Variables and Data Types..."
	$(CC) $(CFLAGS) 02-variables-datatypes/variables.c -o 02-variables-datatypes/variables

control:
	@echo "Compiling Control Structures..."
	$(CC) $(CFLAGS) 03-control-structures/control.c -o 03-control-structures/control

functions:
	@echo "Compiling Functions..."
	$(CC) $(CFLAGS) 04-functions/functions.c -o 04-functions/functions $(MATHLIB)

arrays:
	@echo "Compiling Arrays..."
	$(CC) $(CFLAGS) 05-arrays/arrays.c -o 05-arrays/arrays

pointers:
	@echo "Compiling Pointers..."
	$(CC) $(CFLAGS) 06-pointers/pointers.c -o 06-pointers/pointers

structures:
	@echo "Compiling Structures..."
	$(CC) $(CFLAGS) 07-structures/structures.c -o 07-structures/structures

input_output:
	@echo "Compiling Input/Output..."
	$(CC) $(CFLAGS) 08-input-output/input_output.c -o 08-input-output/input_output

# Run specific programs
run-hello: hello
	@echo "Running Hello World:"
	@./01-hello-world/hello

run-variables: variables
	@echo "Running Variables example:"
	@./02-variables-datatypes/variables

run-control: control
	@echo "Running Control Structures example:"
	@./03-control-structures/control

run-functions: functions
	@echo "Running Functions example:"
	@./04-functions/functions

run-arrays: arrays
	@echo "Running Arrays example:"
	@./05-arrays/arrays

run-pointers: pointers
	@echo "Running Pointers example:"
	@./06-pointers/pointers

run-structures: structures
	@echo "Running Structures example:"
	@./07-structures/structures

run-input: input_output
	@echo "Running Input/Output example:"
	@./08-input-output/input_output

# Clean compiled files
clean:
	@echo "Cleaning compiled files..."
	@rm -f 01-hello-world/hello
	@rm -f 02-variables-datatypes/variables
	@rm -f 03-control-structures/control
	@rm -f 04-functions/functions
	@rm -f 05-arrays/arrays
	@rm -f 06-pointers/pointers
	@rm -f 07-structures/structures
	@rm -f 08-input-output/input_output
	@rm -f 08-input-output/output.txt
	@echo "Clean complete!"

# Help target
help:
	@echo "C Programming Learning Guide - Makefile Help"
	@echo "============================================="
	@echo ""
	@echo "Available targets:"
	@echo "  all          - Compile all programs"
	@echo "  hello        - Compile hello world program"
	@echo "  variables    - Compile variables program"
	@echo "  control      - Compile control structures program"
	@echo "  functions    - Compile functions program"
	@echo "  arrays       - Compile arrays program"
	@echo "  pointers     - Compile pointers program"
	@echo "  structures   - Compile structures program"
	@echo "  input_output - Compile input/output program"
	@echo ""
	@echo "Run targets:"
	@echo "  run-hello     - Compile and run hello world"
	@echo "  run-variables - Compile and run variables example"
	@echo "  run-control   - Compile and run control structures"
	@echo "  run-functions - Compile and run functions example"
	@echo "  run-arrays    - Compile and run arrays example"
	@echo "  run-pointers  - Compile and run pointers example"
	@echo "  run-structures - Compile and run structures example"
	@echo "  run-input     - Compile and run input/output example"
	@echo ""
	@echo "Utility targets:"
	@echo "  clean        - Remove all compiled files"
	@echo "  help         - Show this help message"
	@echo ""
	@echo "Example usage:"
	@echo "  make all          # Compile everything"
	@echo "  make run-hello    # Compile and run hello world"
	@echo "  make clean        # Clean up compiled files"

# Declare phony targets
.PHONY: all clean help run-hello run-variables run-control run-functions run-arrays run-pointers run-structures run-input

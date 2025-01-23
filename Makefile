CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRC = parser/var.c parser/label.c parser/operation.c lexer/lexer.c parser/expression.c parser/parser.c lexer/token.c
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = parser

# Build rules
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

var.o: parser/var.c
	$(CC) $(CFLAGS) -c $<

label.o: parser/label.c var.o
	$(CC) $(CFLAGS) -c $<

operation.o: parser/operation.c lexer.o
	$(CC) $(CFLAGS) -c $<

expression.o: parser/expression.c lexer.o var.o operation.o parser.o token.o
	$(CC) $(CFLAGS) -c $<

parser.o: parser/parser.c var.o label.o operation.o lexer.o expression.o token.o
	$(CC) $(CFLAGS) -c $<

# Clean build artifacts
clean:
	rm -f parser/*.o lexer/*.o $(EXEC)

.PHONY: all clean

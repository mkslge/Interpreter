#include "lexer.c"

struct ExpressionType {
    INT,
    BOOL,
    STRING,
    ID,
    NOT,
    BINOP,
    IF
};

struct Variable {
    char* name;
};



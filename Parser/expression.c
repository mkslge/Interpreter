#include "lexer.c"
#include "var.c"
#include "operation.c"
#include "parser.c"

struct ExpressionType {
    INT,
    BOOL,
    STRING,
    ID,
    NOT,
    BINOP,
    IF
};


struct expression {
    struct ExpressionType;
    int possibleInt;
    int possibleBool;
    char* possibleString;
    struct expression *next;
};


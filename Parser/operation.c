#include "../lexer/lexer.c"

typedef enum {
    ADD_OP,
    SUB_OP,
    MULT_OP,
    DIV_OP,
    GREATER_OP,
    LESS_OP,
    GREATER_EQUAL_OP,
    LESS_EQUAL_OP,
    EQUAL_OP,
    NOT_EQUAL_OP,
    OR_OP,
    AND_OP
} OperationType;
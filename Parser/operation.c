#include "lexer.c"

struct OperationType {
    ADD,
    SUB,
    MULT,
    DIV,
    GREATER,
    LESS,
    GREATER_EQUAL,
    LESS_EQUAL,
    EQUAL,
    NOT_EQUAL,
    OR,
    AND
};
#include "lexer.c"
#include "var.c"
#include "operation.c"
#include "parser.c"
#include "token.c"
#include <stdlib.h>
#include <stdio.h>

typedef enum {
    INT,
    BOOL,
    STRING,
    ID,
    NOT,
    BINOP,
    IF
} ExpressionType;


typedef struct Expression {
    ExpressionType type;
    int possibleInt;
    int possibleBool;
    char* possibleString;
    struct Expression* next;
} Expression;

Expression* initExpression(ExpressionType type, int* pInt, int *pBool, char* pString) {
    Expression* expression = malloc(sizeof(Expression));
    expression->type = type;
    if(pInt) {
        expression->possibleInt = *pInt;
    } else if(pBool) {
        expression->possibleBool = *pBool;
    } else if(pString) {
        expression->possibleString = strdup(pString);
    }
    expression->next = NULL;
    return expression;
}
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
    union Data{
        struct {int value} intVal;
        struct {int value} boolVal;
        struct {char* string} stringVal;
        struct {OperationType operation; Expression* first; Expression* second} binop;
        struct {Expression* condition; Expression* thenExpression; Expression* elseExpression};
    } data;
    
} Expression;

Expression* initExpression(ExpressionType type, int* pInt, int *pBool, char* pString) {
    Expression* expression = malloc(sizeof(Expression));
    expression->type = type;
    if(pInt) {
        
        expression->data.intVal.value = *pInt;
    } else if(pBool) {
        expression->data.boolVal.value = *pBool;
        
    } else if(pString) {
        expression->data.stringVal.string = strdup(pString);
    }
    

    return expression;
}

void deleteExpression(Expression *expression) {
    
}

Expression* addExpression(Expression* curr, Expression* toAdd) {
    return NULL;
}
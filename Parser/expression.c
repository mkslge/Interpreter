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
        struct {char* string; Expression* value} variable;
        struct {OperationType operation; Expression* first; Expression* second} binop;
        struct {Expression* condition; Expression* thenExpression; Expression* elseExpression} ifExpression;
    } data;
    
} Expression;

Expression* initExpression(ExpressionType type, int* pInt, int *pBool, char* pString) {
    Expression* expression = malloc(sizeof(Expression));
    expression->type = type;
    if(type == INT) {
        expression->data.intVal.value = *pInt;
    } else if(type == BOOL) {
        expression->data.boolVal.value = *pBool;
        
    } else if(type == STRING) {
        expression->data.stringVal.string = strdup(pString);
    } else if(type == ID) {
        

    } else if()
    //still need to take care of NOT type
    

    return expression;
}

void deleteExpression(Expression *expression) {
    ExpressionType type = expression->type;
    if(type == STRING) {
        free(expression->data.stringVal.string);
    } else if(type == BINOP) {
        deleteExpression(expression->data.binop.first);
        deleteExpression(expression->data.binop.second);
    } else if(type == IF) {
        deleteExpression(expression->data.ifExpression.condition);
        deleteExpression(expression->data.ifExpression.thenExpression);
        deleteExpression(expression->data.ifExpression.elseExpression);
    } else if(type == ID) {
        free(expression->data.variable.string);
        deleteExpression(expression->data.variable.value);
    }
    free(expression);
}

Expression* addExpression(Expression* curr, Expression* toAdd) {
    return NULL;
}
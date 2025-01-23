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
        struct {int value} notExpression;
        struct {char* string} stringVal;
        struct {char* name; Expression* value} variable;
        struct {OperationType operation; Expression* first; Expression* second} binop;
        struct {int condition; Expression* thenExpression; Expression* elseExpression} ifExpression;
    } data;
    
} Expression;

Expression* initExpression(ExpressionType type, int* pInt, int *pBool, char* pString, Expression* first, Expression* second, OperationType* operation) {
    //allocate memory for next expression
    Expression* expression = malloc(sizeof(Expression));

    //set type
    expression->type = type;

    //set data based on what type the expression is
    if(type == INT) {
        expression->data.intVal.value = *pInt;
    } else if(type == BOOL) {
        expression->data.boolVal.value = *pBool;
    } else if(type == NOT) {
        expression->data.notExpression.value = *pBool;
        //NEED TO SOLVE THIS PROBLEM
        
    } else if(type == STRING) {
        expression->data.stringVal.string = strdup(pString);
    } else if(type == ID) {
        expression->data.variable.name = strdup(pString);
    }  else if(type == IF) {
        expression->data.ifExpression.condition = *pBool;
        expression->data.ifExpression.thenExpression = first;
        expression->data.ifExpression.elseExpression = second;
    } else {
        expression->data.binop.operation = *operation;
        expression->data.binop.first = first;
        expression->data.binop.second = second;
    }
    
    

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
        free(expression->data.variable.name);
        deleteExpression(expression->data.variable.value);
    } else if(type == NOT) {
        deleteExpression(expression->data.notExpression.value);
    }
    free(expression);
}


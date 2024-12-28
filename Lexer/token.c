#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* This struct stores all types of tokens in the language
*/
typedef enum {
    DUMMY_TOKEN,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    EQUALS,
    EQUALS_COMPARISON,
    LESS_THAN,
    MORE_THAN,
    LESS_EQUAL_THAN,
    MORE_EQUAL_THAN,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    IF,
    ELSE,
    LEFT_BRACE,
    RIGHT_BRACE,
    INT,
    BOOL,
    AND,
    OR,
    NOT,
    TRUE,
    FALSE,
    SEMICOLON,
    INTEGER,
    BOOLEAN,
    VARIABLE_NAME
} TokenType;

typedef struct Token Token;
struct Token  {
    TokenType type;
    char* stringName;
    int integerValue;
    int booleanValue;
    Token* next;
};


/* Constructor for token
*/
Token* makeToken(TokenType type, char* name, int integerValue, int booleanValue) {
    //allocates memory for token
    Token *newToken = (Token *)malloc(sizeof(Token));
    //sets all values of token
    newToken->type = type;
    if(name) {
        newToken->stringName = strdup(name);
    }
    newToken->integerValue = integerValue;
    newToken->booleanValue = booleanValue;
    newToken->next = NULL;
    return newToken;
}

void freeToken(Token *token) {
    //first free the string
    free(token->stringName);

    //then free the actual token object
    free(token);
}


void printToken(Token *token) {
    //exit if token is null
    if(!token) {
        printf("token is null ):\n");
        return;
    }
    //otherwise match to each type of token type and a matching print statement
    switch (token->type) {
        case DUMMY_TOKEN: printf("DUMMY_TOKEN\n"); break;
        case PLUS: printf("PLUS\n"); break;
        case MINUS: printf("MINUS\n"); break;
        case MULTIPLY: printf("MULTIPLY\n"); break;
        case DIVIDE: printf("DIVIDE\n"); break;
        case EQUALS: printf("EQUALS\n"); break;
        case EQUALS_COMPARISON: printf("EQUALS_COMPARISON\n"); break;
        case LESS_THAN: printf("LESS_THAN\n"); break;
        case MORE_THAN: printf("MORE_THAN\n"); break;
        case LESS_EQUAL_THAN: printf("LESS_EQUAL_THAN\n"); break;
        case MORE_EQUAL_THAN: printf("MORE_EQUAL_THAN\n"); break;
        case LEFT_PARENTHESIS: printf("LEFT_PARENTHESIS\n"); break;
        case RIGHT_PARENTHESIS: printf("RIGHT_PARENTHESIS\n"); break;
        case IF: printf("IF\n"); break;
        case ELSE: printf("ELSE\n"); break;
        case LEFT_BRACE: printf("LEFT_BRACE\n"); break;
        case RIGHT_BRACE: printf("RIGHT_BRACE\n"); break;
        case INT: printf("INT\n"); break;
        case BOOL: printf("BOOL\n"); break;
        case AND: printf("AND\n"); break;
        case OR: printf("OR\n"); break;
        case NOT: printf("NOT\n"); break;
        case TRUE: printf("TRUE\n"); break;
        case FALSE: printf("FALSE\n"); break;
        case SEMICOLON: printf("SEMICOLON\n"); break;
        case INTEGER: printf("INTEGER: %d\n", token->integerValue); break;
        case BOOLEAN: printf("BOOLEAN: %d\n", token->booleanValue); break;
        case VARIABLE_NAME: printf("VARIABLE_NAME: %s\n", token->stringName); break;
        //emergency case
        default: printf("Unknown token type\n"); break;
    }
}


void printTokens(Token *token) {
    while(token) {
        printToken(token);
        token = token->next;
    }
}



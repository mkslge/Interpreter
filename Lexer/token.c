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
    newToken->stringName = strdup(name);
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



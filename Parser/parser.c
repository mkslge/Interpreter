#include <stdlib.h>
#include "token.c"


TokenType lookahead(Token* token) {
    if(!token) {
        printf("null\n");
        return DUMMY_TOKEN;
    }
    return token->type;
}


Token* match_token(Token* token, TokenType type) {
    if(!token) {
        printf("match_token encountered NULL\n");
        EXIT_FAILURE;
    } else if(token->type != type) {
        printf("wrong token!\n");
        EXIT_FAILURE;
    }
    return token->next;
}


Expression* parseTokens(Token* tokenList) {
    if(!tokenList) {
        printf("error in token creation!\n");
        EXIT_FAILURE;
    }
}

/* typedef enum {
    INT,
    BOOL,
    STRING,
    ID,
    NOT,
    BINOP,
    IF
} ExpressionType;
*/

int main() {

    Expression* INT_TYPE = initExpression(INT, 5,NULL, NULL, NULL, NULL, NULL);
    printf("INT_TYPE: -> %d\n", INT_TYPE->data.intVal);

    return 0;
}














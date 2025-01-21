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














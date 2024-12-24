#include <regex.h>
#include <stdio.h>
#include <string.h>
#include "token.c"


//regex for lexer to match with
char* regex_plus = "+";
char* regex_minus = "-";

char* regex_number = "^-?[0-9]+$";

char* regex_lparen = "(";
char* regex_rparen = ")";
char* regex_multiply = "*";
char* regex_divide = "/";
char* regex_equals = "=";
char* regex_if = "if";
char* regex_else = "else";
char* regex_more_than = ">";
char* regex_less_than = "<";
char* regex_more_or_equal = ">=";
char* regex_less_or_equal = "<=";
char* regex_equal_comparison = "==";
char* regex_starting_brace = "{";
char* regex_ending_brace = "}";
char* regex_int = "int";
char* regex_boolean = "bool";
char* regex_and = "&&";
char* regex_or = "||";
char* regex_not = "!";
char* regex_variable_name = "[:word:]";
char* regex_true = "true";
char* regex_false = "false";
char* regex_semi_colon = ";";

//get substring for lexer
char* substring(char* string, int start, int end) {
    //make new array
    char sol[end - start + 1];
    //copy substring into new string using strncpy
    strncpy(sol, string + start, start - end + 1);
    
    //terminate string
    sol[end] = '\0';

    return sol;
}


//lexer function
Token* tokenize(char* sentence, Token* currList) {

    //make sure sentence is not null
    if(!sentence ) {
        return -1;
    }

    int emptyList = 0;
    //since the use of tokenize is intended to begin with an empty list currList variable will
    //be null so we will start with a NULL list, so we begin by making a dummy head token
    if(!currList) {
        currList = makeToken(DUMMY_TOKEN,"dummy", -1, -1);
        //update to indicate we began with an empty list
        emptyList = 1;
    }
    Token* head = currList;


    //start comparing lexer to values
    regex_t regex;
    int value = -1;


    //compile regex
    value = regcomp(&regex, regex_number, REG_EXTENDED);
    //and then compare it to our input (do this for every token pattern)
    value = regexec(&regex, sentence, 0, NULL, 0);

    if(!value) {
        printf("Matched to number");
        //STILL NEED TO MATCH WITH INTEGERS
        return 0;
    }

    
    //comparing bool keyword
    value = regcomp(&regex, regex_boolean,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to bool keyword");
        currList->next = makeToken(BOOLEAN, "this is a bool", -1, -1);
        sentence += 4;
        currList = currList->next;
        return currList;
    }

    //comparing int keyword
    value = regcomp(&regex, regex_int,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to int keyword");
        currList->next = makeToken(INT, "this is an integer", -1, -1);
        sentence += 3;
        currList = currList->next;
        return currList;
    }


    //comparing if keyword
    value = regcomp(&regex, regex_if,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to if keyword");
        currList->next = makeToken(IF, "IF", -1, -1);
        sentence += 2;
        currList = currList->next;
        return currList;
        
    }

    //comparing else keyword
    value = regcomp(&regex, regex_else,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to Else");
        currList->next = makeToken(ELSE, "ELSE", -1, -1);
        sentence += 4;
        currList = currList->next;
        return currList;
    }

    value = regcomp(&regex, regex_variable_name,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("matched to variable name");
        printf("%s",sentence);
        //need to add the token to a list

        return 0;
    } 

    


    //compares true
    value = regcomp(&regex, regex_true,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        currList->next = makeToken(TRUE, "TRUE", -1, -1);
        sentence += 4;
        currList = currList->next;
        return currList;
    }


    //compares false
    value = regcomp(&regex, regex_false,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        currList->next = makeToken(FALSE, "FALSE", -1, -1);
        sentence += 5;
        currList = currList->next;
        return currList;
    }

    //comparing semicolon
    value = regcomp(&regex, regex_semi_colon,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        currList->next = makeToken(SEMICOLON, ";", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing not
    value = regcomp(&regex, regex_not,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        currList->next = makeToken(NOT, "!", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing or
    value = regcomp(&regex, regex_or,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        currList->next = makeToken(OR, "OR", -1, -1);
        sentence += 2;
        currList = currList->next;
        return currList;
    }

    //comaparing and 
    value = regcomp(&regex, regex_and,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        currList->next = makeToken(AND, "AND", -1, -1);
        sentence += 3;
        currList = currList->next;
        return currList;
    }

    //comparing end brace
    value = regcomp(&regex, regex_ending_brace,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(RIGHT_BRACE, "}", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing start brance
    value = regcomp(&regex, regex_starting_brace,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(LEFT_BRACE, "{", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }


    //comaring equal comparison (==)
    value = regcomp(&regex, regex_equal_comparison,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(EQUALS_COMPARISON, "==", -1, -1);
        sentence += 2;
        currList = currList->next;
        return currList;
    }


    value = regcomp(&regex, regex_less_or_equal,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(LESS_EQUAL_THAN, "<=", -1, -1);
        sentence += 2;
        currList = currList->next;
        return currList;
    }

    value = regcomp(&regex, regex_more_or_equal,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(MORE_EQUAL_THAN, ">=", -1, -1);
        sentence += 2;
        currList = currList->next;
        return currList;
    }




    value = regcomp(&regex, regex_less_than,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(LESS_THAN, "<", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }


    value = regcomp(&regex, regex_more_than,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(MORE_THAN, ">", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing equals
    value = regcomp(&regex, regex_equals,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(EQUALS, "=", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing multiply
    value = regcomp(&regex, regex_multiply,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(MULTIPLY, "*", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing divides
    value = regcomp(&regex, regex_divide,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(DIVIDE, "/", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }


    //comparing plus
    value = regcomp(&regex, regex_plus,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(PLUS, "+", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing minus
    value = regcomp(&regex, regex_minus,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(MINUS, "-", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing left parenthesis
    value = regcomp(&regex, regex_lparen,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        currList->next = makeToken(LEFT_PARENTHESIS, "(", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }

    //comparing right parenthesis
    value = regcomp(&regex, regex_rparen,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        currList->next = makeToken(RIGHT_PARENTHESIS, ")", -1, -1);
        sentence += 1;
        currList = currList->next;
        return currList;
    }


    if(emptyList) {
        return head->next;
    } else {
        return currList;
    }
    return NULL;
}








//place holder main
int main() {
    Token* test = tokenize("int", NULL);
    printf("%s\n", test->stringName);
    //freeToken(test);
    return 0;
}
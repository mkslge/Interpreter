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
Token* tokenize(char* sentence) {
    //make sure sentence is not null
    if(!sentence ) {
        return -1;
    }


    //start comparing lexer to values
    regex_t regex;
    int value = -1;


    //comparing number
    value = regcomp(&regex, regex_number, REG_EXTENDED);
    value = regexec(&regex, sentence, 0, NULL, 0);

    if(!value) {
        printf("Matched to number");
        return 0;
    }

    
    //comparing bool keyword
    value = regcomp(&regex, regex_boolean,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to bool keyword");
        return 0;
    }

    //comparing int keyword
    value = regcomp(&regex, regex_int,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to int keyword");
        return 0;
    }


    //comparing if keyword
    value = regcomp(&regex, regex_if,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to if keyword");
        return 0;
    }

    //comparing else keyword
    value = regcomp(&regex, regex_else,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        printf("Matched to Else");
        return 0;
    }
    printf("Passed else");

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

        return 0;
    }


    //compares false
    value = regcomp(&regex, regex_false,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        return 0;
    }

    //comparing semicolon
    value = regcomp(&regex, regex_semi_colon,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        return 0;
    }

    //comparing not
    value = regcomp(&regex, regex_not,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        return 0;
    }

    //comparing or
    value = regcomp(&regex, regex_or,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        return 0;
    }

    //comaparing and 
    value = regcomp(&regex, regex_and,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {

        return 0;
    }

    //comparing end brace
    value = regcomp(&regex, regex_ending_brace,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    //comparing start brance
    value = regcomp(&regex, regex_starting_brace,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }


    //comaring equal comparison (==)
    value = regcomp(&regex, regex_equal_comparison,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }


    value = regcomp(&regex, regex_less_or_equal,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    value = regcomp(&regex, regex_more_or_equal,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }




    value = regcomp(&regex, regex_less_than,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }


    value = regcomp(&regex, regex_more_than,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    //comparing equals
    value = regcomp(&regex, regex_equals,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    //comparing multiply
    value = regcomp(&regex, regex_multiply,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    //comparing divides
    value = regcomp(&regex, regex_divide,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }


    //comparing plus
    value = regcomp(&regex, regex_plus,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    //comparing minus
    value = regcomp(&regex, regex_minus,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    //comparing left parenthesis
    value = regcomp(&regex, regex_lparen,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }

    //comparing right parenthesis
    value = regcomp(&regex, regex_rparen,0);
    value = regexec(&regex, sentence, 0, NULL, 0);
    if(!value) {
        
        return 0;
    }


    return NULL;
}








//place holder main
int main() {
    tokenize("else");
    return 0;
}
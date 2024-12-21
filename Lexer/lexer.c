#include <regex.h>
#include <stdio.h>
#include <string.h>

struct {
    
} Token;

char* regex_plus = "+";
char* regex_minus = "-";
char* regex_number = "[:number]";
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



int lexer(char* sentence) {
    if(!sentence ) {
        return -1;
    }
    regex_t regex;
    int value = regcomp(&regex, regex_variable_name,0);
    if(!value) {
        printf("matched! ");
        printf("%s",sentence);
    } else {
        printf("no match ):");
    }
    return 0;
}



char* substring(char* string, int start, int end) {
    char sol[end - start + 1];
    strncpy(sol, string + start, start - end + 1);
    sol[end] = '\0';

    return sol;
}

int main() {
    lexer("hi");
    return 0;
}
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include "token.c"
#include "capture.c"


//regex for lexer to match with
char* regex_plus = "\\+";
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
char* regex_variable_name = "[a-zA-Z_][a-zA-Z0-9_]*";
char* regex_true = "true";
char* regex_false = "false";
char* regex_semi_colon = ";";

//get substring for lexer
char* substring(char* string, int start, int end) {
    //make new array
    char* sol = malloc(end - start + 2);
    //copy substring into new string using strncpy
    strncpy(sol, string + start, end - start + 1);
    
    //terminate string
    sol[end] = '\0';

    return sol;
}


//lexer function
Token* tokenize(char* sentence, Token* currList) {

    //make sure sentence is not null
    if(!sentence ) {
        printf("NULL GIVEN");
        return NULL;
    }

    int emptyList = 0;
    int matched = 0;
    //since the use of tokenize is intended to begin with an empty list currList variable will
    //be null so we will start with a NULL list, so we begin by making a dummy head token
    
    if(!currList) {
        currList = makeToken(DUMMY_TOKEN,"dummy", -1, -1);
        //update to indicate we began with an empty list
        emptyList = 1;
    }
    Token* head = currList;


    int length = strlen(sentence);

    int index = 0;
    printf("began loop\n");
    while(index < length) {
    

        //start comparing lexer to values
        regex_t regex;
        int value = -1;

        //always check if we have already matched to something before doing anything
        if(!matched) {
            //compile regex
            value = regcomp(&regex, regex_number, REG_EXTENDED);
            //and then compare it to our input (do this for every token pattern)
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                printf("Matched to number");
                //STILL NEED TO MATCH WITH INTEGERS
                int number = capture_int(&sentence[index]);
                int intLength = length_of_integer(number);
                currList->next = makeToken(INTEGER, NULL, number, -1);
                index += intLength;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            printf("checking match to bool keyword\n");
            //comparing bool keyword
            value = regcomp(&regex, regex_boolean,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                printf("Matched to bool keyword");
                currList->next = makeToken(BOOLEAN, NULL, -1, -1);
                index += 4;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            //comparing int keyword
            printf("checking match to int keyword\n");
            value = regcomp(&regex, regex_int,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                printf("Matched to int keyword");
                currList->next = makeToken(INT, "this is an integer", -1, -1);
                index += 4;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            //comparing if keyword
            value = regcomp(&regex, regex_if,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                printf("Matched to if keyword");
                currList->next = makeToken(IF, NULL, -1, -1);
                index += 2;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing else keyword
            value = regcomp(&regex, regex_else,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                printf("Matched to Else");
                currList->next = makeToken(ELSE, NULL, -1, -1);
                index += 4;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            value = regcomp(&regex, regex_variable_name,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                printf("matched to variable name");
                printf("%s",sentence);
                char* variableName = capture_variable_name(&sentence[index]);
                currList->next = makeToken(VARIABLE_NAME,variableName,-1,-1);
                currList = currList->next;
                index += strlen(variableName);
                matched = 1;
            } 
            regfree(&regex);
        }


        if(!matched) {
            //compares true
            value = regcomp(&regex, regex_true,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                currList->next = makeToken(TRUE, NULL, -1, 1);
                index += 4;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            //compares false
            value = regcomp(&regex, regex_false,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {

                currList->next = makeToken(FALSE, NULL, -1, 0);
                index += 5;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            //comparing semicolon
            value = regcomp(&regex, regex_semi_colon,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {

                currList->next = makeToken(SEMICOLON, NULL, -1, -1);
                index += 1;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing not
            value = regcomp(&regex, regex_not,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {

                currList->next = makeToken(NOT, NULL, -1, -1);
                index += 1;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            //comparing or
            value = regcomp(&regex, regex_or,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                currList->next = makeToken(OR, NULL, -1, -1);
                index += 2;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        
        if(!matched) {
            //comaparing and 
            value = regcomp(&regex, regex_and,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {

                currList->next = makeToken(AND, NULL, -1, -1);
                index += 3;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            //comparing end brace
            value = regcomp(&regex, regex_ending_brace,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(RIGHT_BRACE, NULL, -1, -1);
                index += 1;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            //comparing start brance
            value = regcomp(&regex, regex_starting_brace,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(LEFT_BRACE, NULL, -1, -1);
                index++;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }



        if(!matched) {
            //comaring equal comparison (==)
            value = regcomp(&regex, regex_equal_comparison,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(EQUALS_COMPARISON, NULL, -1, -1);
                index += 2;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            value = regcomp(&regex, regex_less_or_equal,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(LESS_EQUAL_THAN, NULL, -1, -1);
                index += 2;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            value = regcomp(&regex, regex_more_or_equal,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(MORE_EQUAL_THAN, ">=", -1, -1);
                index += 2;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }



        if(!matched) {
            value = regcomp(&regex, regex_less_than,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(LESS_THAN, "<", -1, -1);
                index++;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }


        if(!matched) {
            value = regcomp(&regex, regex_more_than,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(MORE_THAN, NULL, -1, -1);
                index++;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing equals
            value = regcomp(&regex, regex_equals,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {

                currList->next = makeToken(EQUALS, NULL, -1, -1);
                index += 1;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing multiply
            value = regcomp(&regex, regex_multiply,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
            
                currList->next = makeToken(MULTIPLY, NULL, -1, -1);
                index += 1;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing divides
            value = regcomp(&regex, regex_divide,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
            
                currList->next = makeToken(DIVIDE, NULL, -1, -1);
                index += 1;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing plus
            value = regcomp(&regex, regex_plus,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {

                currList->next = makeToken(PLUS, NULL, -1, -1);
                index += 1;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing minus
            value = regcomp(&regex, regex_minus,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                currList->next = makeToken(MINUS, NULL, -1, -1);
                index++;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }

        if(!matched) {
            //comparing left parenthesis
            printf("starting left paren match\n");
            value = regcomp(&regex, regex_lparen,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                
                currList->next = makeToken(LEFT_PARENTHESIS, NULL, -1, -1);
                index++;
                currList = currList->next;
                matched = 1;
                
            }
            regfree(&regex);
        }
        

        if(!matched) {
            //comparing right parenthesis
            value = regcomp(&regex, regex_rparen,0);
            value = regexec(&regex, &sentence[index], 0, NULL, 0);
            if(!value) {
                printf("making token\n");
                currList->next = makeToken(RIGHT_PARENTHESIS, NULL, -1, -1);
                printf("MADE TOKEN\n");
                index++;
                currList = currList->next;
                matched = 1;
            }
            regfree(&regex);
        }
        matched = 0;
    }


    if(emptyList) {
        return head->next;
    } else {
        return head;
    }

    return NULL;
}








//place holder main
int main() {
    printf("starting function\n");
    Token* test = tokenize("(", NULL);
    printf("function complete\n");
    printf("%s\n", test->stringName);
    //freeToken(test);
    return 0;
}
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int MAXIMUM_LENGTH_OF_INTEGER = 12;

/*This function converts a string to an integer*/
int capture_int(char* sentence) {
    //allocate to store 
    char *sol  = malloc(MAXIMUM_LENGTH_OF_INTEGER + 1);

    //variables to keep track of indices of both strings
    int index = 0;
    int solIndex = 0;

    //first check if there is a negative sign at beginning of the string
    if(sentence[index] == '-') {
        printf("SPACE\n");
        sol[solIndex++] = '-';
        index++;
    }
    //while we have a number we keep going and store it in our solution
    while(isdigit(sentence[index])) {
        sol[solIndex++] = sentence[index++];
    }
    //terminate our solution
    sol[solIndex] = '\0';
    //convert it to a number
    int numericSol = atoi(sol);
    
    return numericSol;
}


int length_of_integer(int number) {
    if(number == 0) {
        return 1;
    }
    int length = 0;
    //if we have a negative number we account for the - character at the front
    length = number < 0 ? length + 1 : length;
    number = abs(number);

    while(number > 0) {
        length++;
        number /= 10;
    }
    return length;
}




char* capture_variable_name(char* sentence) {
    int length = strlen(sentence);
    char* sol = malloc(length + 1);
    int index = 0;
    int solIndex = 0;

    while(sentence[index] != '\0' && !isspace(sentence[index])) {
        sol[solIndex++] = sentence[index++];
    }
    sol[solIndex] = '\0';
    return sol;
}
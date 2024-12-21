
#include <regex.h>
#include <stdio.h>

int main() {
    //testing regex
        regex_t regex;
        int value = -1;
        //
        value = regcomp(&regex, "[:number]",0);
        if(!value) {
            printf("Success");
        } else {
            printf("Fail");
        }



    return 0;
}
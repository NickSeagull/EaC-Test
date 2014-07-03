#include <string.h>
#include <stdio.h>

#define NORMAL_COLOR "\x1B[0m"
#define FG_RED "\x1B[31m"
#define FG_GREEN "\x1B[32m"
#define INIT_COLOR "0x1B[0m"
#define BG_BLACK 40

void printInGreen(const char* message){
    printf(FG_GREEN "%s\n", message);
    printf(NORMAL_COLOR "");
}

void printInRed(const char* message){
    printf(FG_RED"%s\n", message);
    printf(NORMAL_COLOR "");
}

void pass(char* desc){
    char message[128] = "\0";
    strcat(message, desc);
    strcat(message, " [PASSED]\n");
    printInGreen(message);
}

void fail(char* desc){
    char message[128]  = "\0";
    strcat(message, desc);
    strcat(message, " [FAILED]");
    printInRed(message);
}

void assertIntEquals(char* message, int a, int b){
    if(a == b){
        pass(message);
    }
    else{
        fail(message);
        printf("  %d is not %d\n\n", a, b);
    }
}

void assertStringEquals(char* message, char* a, char* b){
    if(strcmp(a, b) == 0){
        pass(message);
    }
    else{
        fail(message);
        printf("  %s is not %s\n\n", a, b);
    }
}

void assertTrue(char* message, int condition){
    if(condition){
        pass(message);
    }
    else{
        fail(message);
        printf("  result was false\n\n");
    }
}

void assertFalse(char* message, int condition){
    if(condition != 0){
        pass(message);
    }
    else{
        fail(message);
        printf("  result was true\n\n");
    }
}

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

void assertIntEquals(char* msg, int a, int b){
    if(a == b){
        pass(msg);
    }
    else{
        fail(msg);
        printf("  %d is not %d\n\n", a, b);
    }
}

void assertStringEquals(char* msg, char* a, char* b){
    if(strcmp(a, b) == 0){
        pass(msg);
    }
    else{
        fail(msg);
        printf("  %s is not %s\n\n", a, b);
    }
}

void assertTrue(char* msg, int condition){
    if(condition){
        pass(msg);
    }
    else{
        fail(msg);
        printf("  result was false\n\n");
    }
}

void assertFalse(char* msg, int condition){
    if(condition != 0){
        pass(msg);
    }
    else{
        fail(msg);
        printf("  result was true\n\n");
    }
}

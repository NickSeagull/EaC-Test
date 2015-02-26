#ifndef __EACTEST__
#define __EACTEST__

void assertIntEquals(char* description, int expected, int actual);
void assertStringEquals(char* description, char* expected, char* actual);
void assertTrue(char* description, int condition);
void assertFalse(char* description, int condition);

#include <string.h>
#include <stdio.h>

#define EACTEST_NORMAL_COLOR "\x1B[0m"
#define EACTEST_FG_RED "\x1B[31m"
#define EACTEST_FG_GREEN "\x1B[32m"

void printInGreen(const char* message){
    printf(EACTEST_FG_GREEN "%s\n", message);
    printf(EACTEST_NORMAL_COLOR "");
}

void printInRed(const char* message){
    printf(EACTEST_FG_RED"%s\n", message);
    printf(EACTEST_NORMAL_COLOR "");
}

void pass(char* description){
    char message[128] = "\0";
    strcat(message, description);
    strcat(message, " [PASSED]\n");
    printInGreen(message);
}

void fail(char* description){
    char message[128]  = "\0";
    strcat(message, description);
    strcat(message, " [FAILED]");
    printInRed(message);
}

void assertIntEquals(char* description, int expected, int actual){
    if(expected == actual){
        pass(description);
    }
    else{
        fail(description);
        printf("  %d is not %d\n\n", expected, actual);
    }
}

void assertStringEquals(char* description, char* expected, char* actual){
    if(strcmp(expected, actual) == 0){
        pass(description);
    }
    else{
        fail(description);
        printf("  %s is not %s\n\n", expected, actual);
    }
}

void assertTrue(char* description, int condition){
    if(condition){
        pass(description);
    }
    else{
        fail(description);
        printf("  Expected true but was false\n\n");
    }
}

void assertFalse(char* description, int condition){
    if(condition){
        fail(description);
        printf("  Expected false but was true\n\n");
    }
    else{
        pass(description);
    }
}

#endif

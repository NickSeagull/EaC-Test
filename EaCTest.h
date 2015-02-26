#ifndef __EACTEST__
#define __EACTEST__

void AssertIntEquals(char* description, int expected, int actual);
void AssertStringEquals(char* description, char* expected, char* actual);
void AssertTrue(char* description, int condition);
void AssertFalse(char* description, int condition);

#include <string.h>
#include <stdio.h>

#define EACTEST_NORMAL_COLOR "\x1B[0m"
#define EACTEST_FG_RED "\x1B[31m"
#define EACTEST_FG_GREEN "\x1B[32m"

static void PrintInGreen(const char* message){
    printf(EACTEST_FG_GREEN "%s\n", message);
    printf(EACTEST_NORMAL_COLOR "");
}

static void PrintInRed(const char* message){
    printf(EACTEST_FG_RED "%s\n", message);
    printf(EACTEST_NORMAL_COLOR "");
}

void Pass(char* description){
    char message[128] = "\0";
    strcat(message, description);
    strcat(message, " [PASSED]\n");
    PrintInGreen(message);
}

void Fail(char* description){
    char message[128]  = "\0";
    strcat(message, description);
    strcat(message, " [FAILED]");
    PrintInRed(message);
}

void AssertIntEquals(char* description, int expected, int actual){
    if(expected == actual){
        Pass(description);
    }
    else{
        Fail(description);
        printf("  %d is not %d\n\n", expected, actual);
    }
}

void AssertStringEquals(char* description, char* expected, char* actual){
    if(strcmp(expected, actual) == 0){
        Pass(description);
    }
    else{
        Fail(description);
        printf("  %s is not %s\n\n", expected, actual);
    }
}

void AssertTrue(char* description, int condition){
    if(condition){
        Pass(description);
    }
    else{
        Fail(description);
        printf("  Expected true but was false\n\n");
    }
}

void AssertFalse(char* description, int condition){
    if(condition){
        Fail(description);
        printf("  Expected false but was true\n\n");
    }
    else{
        Pass(description);
    }
}

#endif

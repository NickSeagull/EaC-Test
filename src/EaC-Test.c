#include <string.h>
#include <stdio.h>

#define BOLD 1
#define FG_RED 31
#define FG_GREEN 32
#define FG_WHITE 37
#define BG_BLACK 40
#define INIT_COLOR 0x1B

static int set_green_text(){
    printf("%c[%d;%d;%dm",INIT_COLOR,FG_GREEN,BG_BLACK);
    return 0;
}

static int set_red_text(){
    printf("%c[%d;%d;%dm",INIT_COLOR,FG_RED,BG_BLACK);
    return 0;
}

static int set_default_text(){
    printf("%c[%dm\n",INIT_COLOR,0);
    return 0;
}

int pass(char *desc){
    set_green_text();
    printf("%s [PASSED]\n",desc);
    set_default_text();
    return 0;
}

int fail(char *desc){
    set_red_text();
    printf("%s [FAILED]\n",desc);
    set_default_text();
    return 0;
}

int test_equal_ints(char *msg, int a, int b){
    if(a == b){
        pass(msg);
    }
    else{
        fail(msg);
    }
    return 0;
}

int test_equal_strings(char *msg, char *a, char *b){
    if(strcmp(a, b) == 0){
        pass(msg);
    }
    else{
        fail(msg);
    }
}

int test_is_true(char *msg, int condition){
    if(condition){
        pass(msg);
    }
    else{
        fail(msg);
    }
    return 0;
}

int test_is_false(char *msg, int condition){
    test_is_true(msg, condition!=0);
    return 0;
}

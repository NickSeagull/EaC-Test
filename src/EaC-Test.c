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

int assertIntEquals(char *msg, int a, int b){
    if(a == b){
        pass(msg);
    }
    else{
        fail(msg);
    }
    return 0;
}

int assertStringEquals(char *msg, char *a, char *b){
    if(strcmp(a, b) == 0){
        pass(msg);
    }
    else{
        fail(msg);
    }
}

int assertTrue(char *msg, int condition){
    if(condition){
        pass(msg);
    }
    else{
        fail(msg);
    }
    return 0;
}

int assertFalse(char *msg, int condition){
    assertTrue(msg, condition!=0);
    return 0;
}

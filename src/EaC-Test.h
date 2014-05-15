#ifndef __EACTEST__
#define __EACTEST__

static int set_green_text();
static int set_red_text();
static int set_default_text();
int pass(char *desc);
int fail(char *desc);
int assertIntEquals(char *msg, int a, int b);
int assertStringEquals(char *msg, char *a, char *b);
int assertTrue(char *msg, int condition);
int assertFalse(char *msg, int condition);

#endif

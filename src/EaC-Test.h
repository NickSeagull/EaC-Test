#ifndef __EACTEST__
#define __EACTEST__

static int set_green_text();
static int set_red_text();
static int set_default_text();
int pass(char *desc);
int fail(char *desc);
int test_equal_ints(char *msg, int a, int b);
int test_equal_strings(char *msg, char *a, char *b);
int test_is_true(char *msg, int condition);
int test_is_false(char *msg, int condition);

#endif

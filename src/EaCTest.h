#ifndef __EACTEST__
#define __EACTEST__

int assertIntEquals(char *msg, int a, int b);
int assertStringEquals(char *msg, char *a, char *b);
int assertTrue(char *msg, int condition);
int assertFalse(char *msg, int condition);

#endif

#ifndef __EACTEST__
#define __EACTEST__

void assertIntEquals(char *msg, int a, int b);
void assertStringEquals(char *msg, char *a, char *b);
void assertTrue(char *msg, int condition);
void assertFalse(char *msg, int condition);

#endif

#ifndef __EACTEST__
#define __EACTEST__

void assertIntEquals(char* description, int a, int b);
void assertStringEquals(char* description, char* a, char* b);
void assertTrue(char* description, int condition);
void assertFalse(char* description, int condition);

#endif

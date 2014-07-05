#ifndef __EACTEST__
#define __EACTEST__

void assertIntEquals(char* description, int expected, int actual);
void assertStringEquals(char* description, char* expected, char* actual);
void assertTrue(char* description, int condition);
void assertFalse(char* description, int condition);

#endif

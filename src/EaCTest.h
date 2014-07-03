#ifndef __EACTEST__
#define __EACTEST__

void assertIntEquals(char* message, int a, int b);
void assertStringEquals(char* message, char* a, char* b);
void assertTrue(char* message, int condition);
void assertFalse(char* message, int condition);

#endif

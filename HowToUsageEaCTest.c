#include "EaCTest/src/EaCTest.h"

void shouldPassAssertTrue(){
	assertTrue("1 == 1", 1 == 1);
}

void shouldFailAssertTrue(){
	assertTrue("1 == 0", 1 == 0);
}

void shouldPassAssertFalse(){
	assertFalse("1 != 0", 1 != 0);
}

void shouldFailAssertFalse(){
	assertFalse("1 == 0", 1 == 0);
}

void shouldPassAssertIntEquals(){
	assertIntEquals("1 is 1", 1, 1);
}

void shouldFailAssertIntEquals(){
	assertIntEquals("1 is 2", 1, 2);
}

void shouldPassAssertStringEquals(){
	assertStringEquals("a is a", "a", "a");
}

void shouldFailAssertStringEquals(){
	assertStringEquals("a is b", "a", "b");
}

int main(int argc, char const *argv[]){
	shouldPassAssertTrue();
	shouldFailAssertTrue();
	shouldPassAssertFalse();
	shouldFailAssertFalse();
	shouldPassAssertIntEquals();
	shouldFailAssertIntEquals();
	shouldPassAssertStringEquals();
	shouldFailAssertStringEquals();
	return 0;
}
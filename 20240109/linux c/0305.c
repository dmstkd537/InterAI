#include <stdio.h>
int main(){
	char *p = "hello!";
	char m[] = "World good day";
	printf("%s %s\n", p, m);
	p = m;
	printf("%s\n", p);
	while(*p)
		putchar(*p++);
}

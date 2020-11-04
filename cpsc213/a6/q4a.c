#include <stdlib.h>
#include <stdio.h>

int s[10];
int* p = s;

int foo(int a0, int a1){
	p[a0] += a0;
}

int bar(){
	l0 = 1;
	l1 = 2;
	foo(3, 4);
	foo(l0, l1);
	for(int i=0, i<sizeof(s), i++)
		printf("%d\n", s[i]);
}
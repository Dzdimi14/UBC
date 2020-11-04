#include <stdlib.h>
#include <stdio.h>

int x[] = {1,2,3,-1,-2,0,184,340057058};
int y[] = {0,0,0,0,0,0,0,0};

int f(int a0){
	int a = a0;
	int r = 0;
	while(a != 0){
		if((a & 0x80000000) != 0)
			r++;
		a << 1;
	}
	
}

int main{
	for (i=0; i<sizeof(x); i++)
		printf("%d\n", x[i]);
	for (i=0; i<sizeof(x); i++){
		y[i] = f(x[i]);
		printf ("%d\n", y[i]);
	}	
}
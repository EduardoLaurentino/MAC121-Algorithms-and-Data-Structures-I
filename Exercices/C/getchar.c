#include <stdio.h>
#include <stdlib.h>

int main(){
	char c;

	while ( (c = getchar ()) != '\n'){
		putchar(c);
	}	

	return 0;

}
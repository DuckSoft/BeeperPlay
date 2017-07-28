#include<windows.h>
#include<stdio.h>
#include<memory.h>
#include<math.h>

// kbd
const char str[] = "zsxdcvgbhnjmq2w3er5t6y7ui9o0p[=]\0";

// func: beep freq
void bf(char chr) {
	// Twelve-tone equal temperament
	// freq
	static const double a = 440.0;	// A440 standard
	double c = 440.0 * pow(2,3/12);	// 

	for (int i=0; str[i]!=0; ++i) 
		if ((int)str[i] == chr) {
			Beep(c * pow(2,((double)i)/12.0),20);
			break;
		}
}

int main() {
	// splash
	printf("input music string.\nkbd: %s\n\n# ",str);
	// alloc
	char *buff = memset(malloc(sizeof(char)*256),0,256);
	// input
	gets(buff);
	// beep
	for (int i=0; buff[i]!=0; bf(buff[i]), ++i);
	// dealloc
	free(buff);
}

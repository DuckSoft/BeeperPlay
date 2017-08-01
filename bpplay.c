#include<windows.h>
#include<stdio.h>
#include<memory.h>
#include<math.h>

// kbd
const char str[] = "zsxdcvgbhnjmq2w3er5t6y7ui9o0p[=]\0";
// note duration (ms)
const int note_duration = 180;

// func: beep freq
void bf(char chr, int length) {
	// Twelve-tone equal temperament
	// freq
	static const double a = 440.0;	// A440 standard
	double c = 440.0 * pow(2,3/12);	// 
	
	// pause
	if (chr == ' ') {
		Sleep(note_duration);
		return;
	}

	for (int i=0; str[i]!=0; ++i) 
		if ((int)str[i] == chr) {
			Beep(c * pow(2,((double)i)/12.0),note_duration * length);
			break;
		}
}

int main() {
	// splash
	printf("This is BeeperPlay.\n ->\n",str);
	// alloc
	static const size_t bufsize = 32767;
	char *buff = memset(malloc(sizeof(char)*bufsize),0,bufsize);
	// input and beep
	while (fgets(buff, bufsize, stdin)) {
		int len;
		
		for (int i=0; buff[i]!=0; ++i) {
			len = 1;
			for (int j=i+1; buff[j]=='-'; ++j) len++;
			bf(buff[i],len);
		}
	}
	// dealloc
	free(buff);
}

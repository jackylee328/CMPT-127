#include <stdio.h>
#include <string.h>

int main(void){
	char str;
	int i = 0;
	int word,last;
	unsigned long int charcount = 0;
	unsigned long int wordcount = 0;
	unsigned long int linecount = 0;
	str = getchar();
	while (str != EOF){
		charcount++;
		if ((str>='a'&&str<='z')||(str>='A'&&str<='Z')||str=='\''){
			word = 1;
		}
		else{
			word = 0;
		}
		if (last == 1 && word == 0){
			wordcount++;
		}
		if (str == '\n'){
			linecount++;
		}
		last = word;
		str = getchar();
	}
	printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
	return 0;
}

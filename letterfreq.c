#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void freq(char string[]){
	int i = 0;
	float count = 0;
	int freq[26]={0};
	while (string[i] != '\0'){
		if (tolower(string[i]) >= 'a' && tolower(string[i]) <= 'z'){
			freq[tolower(string[i])-'a']++;
			count++;
		}
		i++;
	}
	for (int j = 0; j < 26; j++){
		if (freq[j] != 0){
			float val = freq[j] / count;
			printf("%c %.4f\n", j+'a', val);
		}
	}
}


int main(int argc,char* argv[]){
	int count = 0;
	int i = 0;
	char c;
	char *str = malloc(1000000);
	c = getchar();
	while (c != EOF){
		str[i] = c;
		i++;
		c = getchar();
	}
	//printf("%s",str);
	freq(str);
	free(str);
	return 0;

}






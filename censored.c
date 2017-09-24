#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int len,censorLen,match,i;
	char c;
	char *word = malloc(50);
	int result = scanf("%c", &c);
	while (result != EOF){
		if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')||c=='\''){
			word[len] = c;
			len++;
		}
		else{
			i = 0;
			while (argv[i] != '\0'){
				censorLen = strlen(argv[i]);
				if (len == censorLen){
					match = 1;
					for(int j = 0; j < len; j++){
						if(word[j] != argv[i][j]){
							match = 0;
						}
					}
					if (match == 1){
						printf("CENSORED");
						break;
					}
				}
				i++;
			}
			if(match == 0 || len != censorLen){
					printf("%s", word);
			}
			printf("%c", c);
			len = 0;
			memset(word,0,strlen(word));
		}
		result = scanf("%c", &c);
	}
	free(word);
	return 0;
}
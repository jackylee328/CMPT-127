#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argb, char** argv){
	int val;
	int i = 0;
	int j = 0;
	int lena = strlen(argv[1]);
	int lenb = strlen(argv[2]);
	int len;
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	if (lena == lenb){
		len = 1;
	}
	else if (lena > lenb){
		len = lena - lenb;
	}
	else{
		len = lena;
	}
	while (i < len){
		val = 1;
		j = 0;
		while (j < lenb){
			if (argv[1][i+j] != argv[2][j]){
				val = 0;
			}
			j++;
		}
		if (val == 1){
			printf("true\n");
			break;
		}
		i++;
	}
	if (val == 0){
		printf("false\n");
	}
	return 0;
}

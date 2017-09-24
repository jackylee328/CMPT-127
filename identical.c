#include <stdio.h>

int identical( int a[], int b[], unsigned int len ){
	int result = 1;
	for(int i = 0; i < len; i++){
		if(a[i] != b[i]){
			result = 0;
		}
	}
	return result;
}
		
#include <stdio.h>

int scrambled (unsigned int a[], unsigned int b[], unsigned int len){
	int i;
	int array[100];
	for (i = 0; i < 100; i++){
		array[i] = 0;
	}
	for (i = 0; i < len; i++){
		array[a[i]]++;
		array[b[i]]--;
	}
	for (i = 0; i < 100; i++){
		if (array[i] != 0){
			return 0;
		}
	}
	return 1;
}

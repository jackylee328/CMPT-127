#include <stdio.h>

void reverse( int arr[], unsigned int len ){
	for (int i = 0; i < len/2; i++){
		int temp = arr[i];
		arr[i] = arr[len-i-1];
		arr[len-i-1] = temp;
	}
}
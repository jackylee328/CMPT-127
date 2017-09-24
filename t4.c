#include <stdio.h>
#include <math.h>

int main(void){
	float a = 0;
	int b = 0;
	b = scanf("%f",&a);
	if (b == 1){
		int largest = floor(a);
		int nearest = round(a);
		int smallest = ceil(a);
		printf("%d %d %d\n", largest, nearest, smallest);
	}
	else{
		printf("scanf error: (%d)\n",b);
	}
	return 0;
}
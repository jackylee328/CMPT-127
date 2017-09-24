#include <stdio.h>
#include <math.h>

int main(void){
	float a = 0;
	scanf("%f",&a);
	int largest = floor(a);
	int nearest = round(a);
	int smallest = ceil(a);
	printf("%d %d %d\n", largest, nearest, smallest);
	return 0;
}
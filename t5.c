#include <stdio.h>
#include <math.h>

int main(void){
	float i = 0;
	int result;
	int largest;
	int nearest;
	int smallest;
	
	while (result != EOF){
		result = scanf("%f", &i);
		if (result == EOF){
			printf("Done.\n");
			break;
		}
		largest = floor(i);
		nearest = round(i);
		smallest = ceil(i);
		printf("%d %d %d\n", largest, nearest, smallest);
	}	
	return 0;
}
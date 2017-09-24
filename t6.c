#include <stdio.h>
#include <math.h> 

int main(void){
	float a = 0;
	float smallest = 100000;
	float largest = -100000;
	float total = 0;
	float count = 0;
	float mean;
	int result;
	while (result != EOF){
		result = scanf("%f",&a);
		if (result == EOF){
			mean = total / count;
			printf("%.2f %.2f %.2f\n", smallest, largest, mean);
			break;
		}
		if (a < smallest){
			smallest = a;
		}
		if (a > largest){
			largest = a;
		}
		total += a;
		count++;
	}
	return 0;
}
#include <stdio.h>

int main(void){
	int result = 0;
	int a = 0;
	result = scanf("%d", &a);
	while (result != EOF){
		for(int i = 0; i < a; i++){
			printf("#");
		}
		printf("\n");
		result = scanf("%d", &a);
	}
	
	return 0;
}
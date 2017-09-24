// 8. Pyramid Projection 1
#include <stdio.h> 

int main(void){
	int x = 0; 
	int y = 0;
	int z = 0;
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	int i = 1;
	while (i <= y){
		if (i == 1 || i == y){
			int j = 1;
			while (j <= x){
				printf("#");
				j++;
			}
			printf("\n");
		}
		else{
			int k = 1;
			while (k <= x){
				if (k == 1 || k == x){
					printf("#");
				}
				else{
					printf(".");
				}
				k++;	
			}
			printf("\n");
		}
	i++;
	}
	return 0;
}
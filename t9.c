#include <stdio.h>
#include <math.h>

int main(void){
	int width, breath, height, space;
	scanf("%d", &width);
	scanf("%d", &breath);
	scanf("%d", &height);
	for (int i = height; i > 0; i--) {
		space = floor((i-1) * (width/(2.0 *height)));
		for (int j = 1; j <= space; j++) {
			printf(" ");
		}
		int rowwidth = width - (space * 2) ;
		if (i == 1 || i == height){
			for (int k = 1; k <= rowwidth; k++){
				printf("#");
			}
			printf("\n");
		}
		else{
			for (int l = 1; l <= rowwidth; l++){
				if (l == 1 || l == rowwidth){
					printf("#");
				}
				else{
					printf(".");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
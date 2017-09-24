#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int a,i,j,result,h;
	int count = 0;
	int graph[80][80];
	result = scanf("%d",&a);
	h = a;
	while (result != EOF){
		for (i = 0; i < a; i++){
			graph[i][count] = 1;
		}
		if (a > h){
			h = a;
		}
		count++;
		result = scanf("%d",&a);
	}
	for (i = h-1; i >= 0; i--){
		for (j = 0; j < count; j++){
			if (graph[i][j] == 1){
				printf("#");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void draw_circle( uint8_t img[], unsigned int cols,unsigned int rows,int x,int y,int r,uint8_t color ){
	int i,j,index;
	double distx,disty,dist;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			index=j+i*cols;
			distx=abs(x-j)-0.5;
			disty=abs(y-i)-0.5;
			dist=sqrt(distx*distx+disty*disty);
			if(dist<r){
				img[index]=color;
			}
		}
	}
}
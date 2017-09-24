#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

unsigned int hoodsize( uint8_t array[], unsigned int cols, unsigned int rows, unsigned int p, unsigned int q ) {
	unsigned int sum = 0;
	for (int x=-1; x<=1; x++){
		for (int y=-1; y<=1; y++){
			if(x != 0 || y != 0 ){
				int xx = (p+x+cols) % cols;
				int yy = (q+y+rows) % rows;
				int index = yy*cols + xx;
				sum += array[index] > 0;
			}
		}
	}
	return sum;
}

void life( uint8_t array[], unsigned int cols, unsigned int rows ){
	uint8_t* cp = malloc(rows*cols*sizeof(int));
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			int in = j + i * cols;
			cp[in] = array[in];
		}
	}
	for (int x=0; x<cols; x++){
		for (int y=0; y<rows; y++){
			int index = y * cols + x;
			unsigned int hood = hoodsize( cp, cols, rows, x, y );
			if (hood < 2){
				array[index] = 0;
			}
			if (hood > 3){
	  			array[index] = 0;
			}
			if (hood == 3){
	  			array[index] = 255;	
      		}
		}
	}
	free(cp);
}




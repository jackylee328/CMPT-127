#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "imgops.h"

void draw_rectangle( uint8_t* array, unsigned int cols, unsigned int rows,int x,int y,int rect_width,int rect_height,uint8_t color ){
	int i,index,w,h;
	if (rect_width == 0 || rect_height == 0){
		return;
	}
	
	if (rect_width > 0){
		w = rect_width-1;
	}
	else{
		w = rect_width+1;
	}
	if (rect_height > 0){
		h = rect_height-1;
	}
	else{
		h = rect_height+1;
	}
	
	if (rect_width > 0){
		for (i=0; i<rect_width; i++){
			if (x+i < cols && y < rows){
				set_pixel(array,cols,rows,x+i,y,color);
			}
			if (x+i < cols && y+rect_height < rows){
				set_pixel(array,cols,rows,x+i,y+h,color);
			}
		}
	}
	if (rect_width < 0){
		for (i=0; i>rect_width; i--){
			if (x+i < cols && y < rows){
				set_pixel(array,cols,rows,x+i,y,color);
			}
			if (x+i < cols && y+rect_height < rows){
				set_pixel(array,cols,rows,x+i,y+h,color);
			}
		}
	}
	
	if (rect_height > 0){
		for (i=0; i<rect_height; i++){
			if (x < cols && y+i < rows){
				set_pixel(array,cols,rows,x,y+i,color);
			}
			if (x+rect_width < cols && y+i < rows){
				set_pixel(array,cols,rows,x+w,y+i,color);
			}
		}
	}
	else{
		for (i=0; i>rect_height; i--){
			if (x < cols & y+i < rows){
				set_pixel(array,cols,rows,x,y+i,color);
			}
			if (x+rect_width < cols && y+i < rows){
				set_pixel(array,cols,rows,x+w ,y+i,color);
			}
		}
	}
}


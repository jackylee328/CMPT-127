/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  for (int i = 0; i < cols * rows; i++){
    array[i] = 0;
  }
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
  return NULL;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  int smallest = array[0];
  unsigned int size = cols * rows;
  for (int i = 1; i < size; i++){
    if (array[i] < smallest){
      smallest = array[i];
    }
  }
  return smallest;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  int largest = array[0];
  unsigned int size = cols * rows;
  for (int i = 1; i < size; i++){
    if (array[i] > largest){
      largest = array[i];
    }
  }
  return largest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  unsigned int size = cols * rows;
  for (int i = 0; i < size; i++){
    if (array[i] == pre_color){
      array[i] = post_color;
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  int x,y,index,flipIndex,element;
  if(cols%2==1){
    cols--;
  }
  for(y=0;y<rows;y++){
    for(x=0;x<cols/2;x++){
      index=x+y*cols;
      flipIndex=(y+1)*cols-x-1;
      element=array[index];
      array[index]=array[flipIndex];
      array[flipIndex]=element;
    }
  }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  int x,y,index,flipIndex,element;
  if(rows%2==1){
    rows--;
  }
  for(x=0;x<cols;x++){
    for(y=0;y<rows/2;y++){
      index=x+y*cols;
      flipIndex=(rows-y-1)*cols+x;
      element=array[index];
      array[index]=array[flipIndex];
      array[flipIndex]=element;
    }
  }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  int index;
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      index = i * cols + j;
      if (array[index] == color){
        *x = j;
        *y = i;
        return 1;
      }
    }
  }
  return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    int size = cols * rows;
    for (int i = 0; i < size; i++){
      array[i] = abs(array[i] - 255);
    }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  int i,index;
  for(i=0;i<(rows*cols);i++){
    if ((array[i] * scale_factor) > 255) {
      array[i] = 255;
    }
    else {
      array[i] = round(array[i] * scale_factor);
    }
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  uint32_t mini, maxi;
  mini = min(array,cols,rows);
  maxi = max(array,cols,rows);
  uint32_t range = maxi - mini;
  for(int i=0;i < (rows*cols); i++){
      array[i] = round((255.0/range) * (array[i] - mini));
  }
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  int i,j,index,newcols,newrows,in1,in2,in3,in4,val1,val2,val3,val4,val;
  if(cols%2==1){
    newcols=(cols-1)/2;
  }
  else{
    newcols=cols/2;
  }
  if(rows%2==1){
    newrows=(rows-1)/2;
  }
  else{
    newrows=rows/2;
  }
  uint8_t *new=malloc(rows*cols*sizeof(int));
  for(i=0;i<newrows;i++){
    for(j=0;j<newcols;j++){
      index=j+i*newcols;
      in1=(j*2)+(i*2)*cols;
      in2=(j*2+1)+(i*2)*cols;
      in3=(j*2+1)+((i*2)+1)*cols;
      in4=(j*2)+((i*2)+1)*cols;
      val1=array[in1];
      val2=array[in2];
      val3=array[in3];
      val4=array[in4];
	    //printf("%d %d %d %d\n",val1,val2,val4,val3);
	    float avg = (val1+val2+val3+val4)/4.00;
      int val=round(avg);
	    //printf("avg = %d\n\n", val);
      new[index]=val;
    }
  }
  return new;
}



/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  int x,y,index;
  if ((top != bottom) && (right != left)) {
    for (int y = top; y < bottom; y++){
      for (int x = left; x < right; x++){
        index = x + y * cols;
        array[index] = color;
      }
    }
  }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  int i,j,index;
  unsigned int sum=0;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      if(j>=left&&j<=(right-1)&&i>=top&&i<=(bottom-1)){
        index=j+i*cols;
        sum+=array[index];
      }
    }
  }
  return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  int newrows,newcols,i,j,index,newIndex;
  newrows=right-left;
  newcols=bottom-top;
  uint8_t *new=malloc(newrows*newcols*sizeof(int));
  if((top==bottom)||(left==right)){
    return NULL;
  }
  newIndex=0;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      if(j>=left&&j<=(right-1)&&i>=top&&i<=(bottom-1)){
        index=j+i*cols;
        new[newIndex]=array[index];
        newIndex++;
      }
    }
  }
  return new;
}



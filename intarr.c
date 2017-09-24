#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

//task 1
intarr_t* intarr_create(unsigned int len){
	intarr_t* ia = malloc(sizeof(intarr_t));
	if (ia != NULL){
		ia->data = malloc(len*sizeof(int));
		ia->len = len;
		return ia;
	}
	return NULL;
}

void intarr_destroy( intarr_t* ia ){
	if (ia->data != NULL){
		free(ia);
		ia = NULL;
	}
}

//task 2 
intarr_result_t intarr_set (intarr_t* ia, unsigned int index, int val){
	if (ia != NULL){
		if (index >= 0 && index <= ia->len){
			ia->data[index] = val;
			return INTARR_OK;
		}
		return INTARR_BADINDEX;
	}
	return INTARR_BADARRAY;
}

intarr_result_t intarr_get (const intarr_t* ia, unsigned int index, int* i){
	if (ia != NULL){
		if (index >= 0 && index <= ia->len){
			*i = ia->data[index];
			return INTARR_OK;
		}
		return INTARR_BADINDEX;
	}
	return INTARR_BADARRAY;
}


//task 3
intarr_t* intarr_copy( const intarr_t* ia ){
	int len = ia->len * sizeof(int);
	intarr_t *copy = intarr_create(ia->len);
	copy->data = malloc(len);
	copy->len = ia->len;
	memcpy(copy->data, ia->data, len);
	return copy;
}
	
//task 4
intarr_result_t intarr_sort (intarr_t* ia){
	if (ia != NULL){
		for (int i = 1; i < ia->len; i++){
			int element = ia->data[i];
			int j = i;
			while (j > 0 && element < ia->data[j-1]){
				ia->data[j] = ia->data[j-1];
				j--;
			}
			ia->data[j] = element;
		}
		return INTARR_OK;
	}
	return INTARR_BADARRAY;
}

//task 5
intarr_result_t intarr_find( intarr_t* ia, int target, int* i){
	if (ia != NULL){
		int flag = 0;
		for (int index = 0; index < ia->len; index++){
			if (ia->data[index] == target){
				*i = index;
				flag = 1;
				return INTARR_OK;
			}
		}
		return INTARR_NOTFOUND;
	}
	return INTARR_BADARRAY;
}

//task 6
intarr_result_t intarr_push( intarr_t* ia, int val ){
	if (ia != NULL){
		ia->len++;
		ia->data = realloc(ia->data, ia->len * sizeof(int));
		ia->data[ia->len-1] = val;
		if (ia->data[ia->len-1] ==val){
			return INTARR_OK;
		}
		return INTARR_BADALLOC;
	}
	return INTARR_BADARRAY;
}

intarr_result_t intarr_pop( intarr_t* ia, int* i){
	if((ia->len) == 0){
		return INTARR_BADINDEX;
	}
	else if(ia == NULL){
		return INTARR_BADARRAY;
	}
	else{
		*i = ia->data[(ia->len)-1];
		ia->len--;
		return INTARR_OK;
	}
}

//task 7 
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
	if (ia != NULL){
		if (newlen <= ia->len){
			ia->len = newlen;
			return INTARR_OK;
		}
		else{
			ia->len = newlen;
			for (int index = ia->len; index < newlen; index++){
				ia->data[index] = 0;
			}
			return INTARR_OK;
		}
		return INTARR_BADALLOC;
	}
	return INTARR_BADARRAY;
}

//task 8
intarr_t* intarr_copy_subarray( intarr_t* ia, unsigned int first, unsigned int last ){
	if (first <= last && first >= 0 && last < ia->len){
		intarr_t* copy = malloc(sizeof(intarr_t));
		copy->len = last - first + 1;
		copy->data = malloc(copy->len * sizeof(int));
		int copyIndex = 0;
		for (int iaIndex = first; iaIndex <= last; iaIndex++){
			copy->data[copyIndex] = ia->data[iaIndex];
			copyIndex++;
		}
		return copy;
	}
	return NULL;
}

	
	
	
	

	
	










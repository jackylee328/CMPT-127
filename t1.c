#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

int intarr_save_binary(intarr_t* ia, const char* filename ){
	if(ia != NULL && filename != NULL) {
		FILE* ff = fopen(filename,"w");
		if(ff != NULL ) {
			fwrite(&ia->len, sizeof(int), 1,ff);
			fwrite(ia->data, sizeof(int), ia->len, ff);
			fclose(ff);
			return 0;

		}
	}
	return 1;
}

intarr_t* intarr_load_binary( const char* filename ){
	int i, data, len;
	if(filename != NULL) {
		FILE* ff = fopen(filename,"r");
		if (ff != NULL){
			intarr_t* new = malloc(sizeof(intarr_t));
			fread(&new->len, sizeof(int),1,ff);
			new->data = malloc(new->len * sizeof(int));
			fread(new->data,sizeof(int),new->len,ff);
			return new;
		}
	}
	return NULL;
}

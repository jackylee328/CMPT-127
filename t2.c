#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

int intarr_save_json( intarr_t* ia, const char* filename ){
	if (ia != NULL){
		FILE* ff = fopen(filename,"w");
		if (ff != NULL){
			fprintf(ff,"[\n");
			for (int i=0; i<ia->len; i++){
				if (i == ia->len-1){
					fprintf(ff," %d\n",ia->data[i]);
				}
				else{
					fprintf(ff," %d\n",ia->data[i]);
				}
			}
		fprintf(ff,"]");
		fclose(ff);
		return 0;
		}
	}
	return 1;
}

intarr_t* intarr_load_json( const char* filename ){
	FILE* ff = fopen(filename, "r");
	if (ff == NULL){
		return NULL;
	}
	intarr_t* load = intarr_create(0);
	int val;
	fscanf(ff,"%c ",&val);
	char line[100];
	while (fgets(line,100,ff)){
		if (line[0] == ']' || sscanf(line,"%d",&val)!=1){
			break;
		}
		intarr_push(load,val);
	}
	fclose(ff);
	return load;
}

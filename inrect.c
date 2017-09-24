#include <stdio.h>

int InRectangle( float pt[2], float rect[4] ){
	float element;
	if (rect[0] > rect[2]){
		element = rect[0];
		rect[0] = rect[2];
		rect[2] = element;
	}
	if (rect[1] > rect[3]){
		element = rect[1];
		rect[1] = rect[3];
		rect[3] = element;
	}
	if ((pt[0] >= rect[0] && pt[0] <= rect[2])
	   && (pt[1] >= rect[1] && pt[1] <= rect[3])){
		return 1;
	}
	return 0;
}
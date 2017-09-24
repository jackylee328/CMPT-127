#include <stdint.h> // for uint8_t
#include "image2.hpp"

Image();
  

~Image();

int resize( unsigned int width,  unsigned int height, uint8_t fillcolor );

int set_pixel( unsigned int x, unsigned int y, uint8_t color );
 
int get_pixel( unsigned int x, unsigned int y, uint8_t* colorp );

int save( const char* filename );

int load( const char* filename );
};

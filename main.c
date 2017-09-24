#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] ){
  int i;
  list_t* list = list_create();
  if (list == NULL){
    return 1;
  }
  for( i=0; i<5; i++ )
    list_append( list, i );
  
  for( i=-1; i>-5; i-- )
    list_prepend( list, i );
  list_print( list );
  int index = 2;
  element_t* el = list_index( list, index );
  if( el == NULL ){
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  printf( "value at index %d is %d\n", index, el->val );
  if( el->val != -2 ) 
    return 1;
  
  list_t* list1 = list_create();
  for (i=0; i<5; i++){
    list_append(list1,i);
  }
  for (i=-1; i>-5; i--){
    list_prepend(list1,i);
  }
  element_t* el1 = list_index(list1,2);
  if (el1 == NULL){
    return 1;
  }
  if (el1->val != -2){
    return 1;
  }
  
  
  list_t* list2 = list_create();
  list_prepend(list2,2);
  if (list2->tail->val != 2){
    return 1;
  }
  
  list_t* list3 = list_create();
  element_t* el3 = list_index(list3,5);
  if(el3 != NULL){
    return 1;
  }
                     
  
  element_t * el4 = element_create(1);
  if (el4->val != 1){
    return 1;
  }
  if (el4 == NULL){
    return 1;
  }

  list_t* list5 = list_create();
  for(i=0; i<5;i++){
       list_append(list5,i);
  }
  for(i=-1; i>-5; i--){
    list_prepend(list5,i);
  }
  if(list5->tail->val!=4){
    return 1;
  }
  
  element_t *el5 = element_create(100);
  el5->next = list_index(list5,3);
  free(el5->next);
  el5 = element_create(100);
  if (el5->next != NULL){
    return 1;
  }
  
  list_t* list6 = list_create();
  list_print(list6);
  
  list_destroy( list );

  return 0; // tests pass
}




















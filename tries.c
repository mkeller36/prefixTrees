#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHAR 256

typedef struct trienode{
  struct trienode *children[NUM_CHAR];
  bool terminating;
} trienode;

trienode *createnode(){
  trienode *newnode = malloc(sizeof(*newnode));

  for(int i = 0; i < NUM_CHAR; i++){
    newnode->children[i] = NULL;
  } 
  newnode->terminal = false;
  return newnode;
}

bool trieInsert(trienode **root, char *signedtext){
  
}

void main(void){
  
  

}

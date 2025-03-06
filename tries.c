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
  newnode->terminating = false;
  return newnode;
}

bool trieInsert(trienode **root, char *signedtext){
  if(*root == NULL){
    *root = createnode();
  }

  unsigned char *text = (unsigned char *)signedtext;
  trienode *tmp = *root;

  int length = strlen(signedtext);

  for(int i = 0; i < length; i++){
    if(tmp->children[text[i]] == NULL){
      /* Create new node */
      tmp->children[text[i]] = createnode();

    }
    tmp = tmp->children[text[i]];
  }

  if(tmp->terminating){
    return false;
  }
  else{
    tmp->terminating = true;
    return true;
  }
}

void printftrie_rec(trienode *node, unsigned char * prefix, int length){
  unsigned char newprefix[length+2];
  memcpy(newprefix, prefix, length);
  newprefix[length+1] = 0;

  if(node->terminating){
    printf("WORD: %s\n", prefix);
  }

  for(int i = 0; i < NUM_CHAR; i++){
    if(node->children[i] != NULL){
      newprefix[length] = i;
      printftrie_rec(node->children[i], newprefix, length+1);
    }
  }
}

void printtrie(trienode * root){
  if (root == NULL){
    printf("TRIE empty\n");
    return;
  }
  printftrie_rec(root, NULL, 0);
}

void main(void){
  trienode *root = NULL;
  trieInsert(&root, "KIT");
  trieInsert(&root, "CATTLE");
  trieInsert(&root, "KIN");
  trieInsert(&root, "CAT");
  trieInsert(&root, "HAPPY");
  printtrie(root);
  

} 

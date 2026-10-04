#include <stdio.h>
#include "tokenizer.h"
int stringcomp(char*a, char *b){
  while (*a && *b){
    int diff = *a++ - *b++;
    if (diff) return diff;
  }
  if (!*a && !*b) return 0;
  return (*a) ? 1 : -1;
}

int space_char(char c){
  char space = ' ';
  char tab = '\t';

  if (c==space | c==tab){
    return 1;
  }
  return 0;
}
int non_space_char(char c){
  if (space_char(c)==0){
    return 1;
  }
  return 0;
}

char *token_start(char *str){
  char *nullpointer = 0;
  char *pointerPointer = str;
  while (space_char(*pointerPointer)){
    if (pointerPointer=="\0"){
      return nullpointer;
    }
    *pointerPointer++;
    
  }
  return pointerPointer;
}

char *token_terminator(char *token){
  char *pointerPointer = &*token;
  while (non_space_char(*pointerPointer) && pointerPointer!="\0"){
    *pointerPointer++;
  }
  return pointerPointer;

}

int count_tokens(char *str){
  int counter = 0;
  char *pointy = str;
  pointy = token_start(pointy);
  while (*pointy != '\0'){
    pointy=token_terminator(pointy);
    counter++;
    pointy=token_start(pointy);
  }
  return counter;
}

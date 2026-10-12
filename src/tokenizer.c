#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
static int debug=0;


int stringcomp(char*a, char *b){
  while (*a && *b){
    int diff = *a++ - *b++;
    if (diff) return diff;
  }
  if (!*a && !*b) return 0;
  return (*a) ? 1 : -1;
}

int space_char(char c){
  return (c == ' '|| c == '\t' || c == '\n');
}

int non_space_char(char c){
  return (c != 0 && c!=' '&&c!='\t'&& c!='\n');
}

char *token_start(char *str){
  char *p = str;
  while (space_char(*p)) p++;
  if (debug) printf("found start at: %ld\n", (p-str));
  return *p ? p : 0;
}

char *token_terminator(char *token){
  char *p = token;
  while (non_space_char(*p) && p!="\0"){
    *p++;
  }
  if (debug) printf("found term at: %ld\n", (token-p));  
  return p;

}

int count_tokens(char *str){
  int counter = 0;
  char *pointy = str;
  pointy = token_start(pointy);
  while (pointy != 0 && *pointy){
    pointy=token_terminator(pointy);
    counter++;
    pointy=token_start(pointy);
  }
  return counter;
}
char *copy_str(char *inStr, short len){
  char *copy = malloc(len+1);
  for (int i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  copy[len]='\0';
  return copy;
}

char **tokenize(char *str){
   int count = count_tokens(str);
   char **tokens = malloc((count+1)* sizeof(char *));
   char *pointy = str;
   char *start;
   char *end;
   int i;
   while (i<count){
     pointy = token_start(pointy);
     start = pointy;
     end = token_terminator(pointy);
     int diff = end-start;
     tokens[i] = copy_str(start, diff);
     pointy = end;
     i++;
   }
   tokens[count]=0;
   return tokens;
 }

void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != 0 && *tokens[i] != '\0'; i++){
    printf("[%d] %s\n", i, tokens[i]);
  }
}

void free_tokens(char **tokens) {
  for (int i; tokens[i] != 0 && *tokens[i] != '\0'; i++){
    free(tokens[i]);
  }
}

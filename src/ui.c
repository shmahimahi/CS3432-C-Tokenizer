#include <stdio.h>
#include "tokenizer.h"
void input(){
  char **tokens;
  while (1){
        char stringie[250];
        printf("> ");
        fgets(stringie, 250, stdin);
	
	char* pointStringie = stringie;
	tokens = tokenize(stringie);
	print_tokens(tokens);
	free_tokens(tokens);
  }
}
int main(){
     input();
}

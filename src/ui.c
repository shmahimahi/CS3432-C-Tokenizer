#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int stringLen(char *pointy) {
    int len = 0;
    while (pointy[len] != 0) {
        len++;
    }
    return len;
}

void input(){

  char stringie[250];
  char stoppie[]="history";
  char* pointStoppie = stoppie;

  char **tokens;
  List *history = init_history();

  while (1){
    printf("> ");
    fgets(stringie, 250, stdin);
    
    char* pointStringie = stringie;
    tokens = tokenize(stringie);

    if (stringcomp(tokens[0], pointStoppie)!=0){
      print_history(history);
    } else {
      print_tokens(tokens);
      add_history(history, copy_str(stringie, stringLen(stringie)));
      
    }
    free_tokens(tokens);

    
    
  }
}
int main(){
     input();
}

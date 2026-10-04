#include <stdio.h>
#include "tokenizer.h"
void input(){
  char stop[] = "stop";
  while (1){
        char stringie[250];
        printf("> ");
        fgets(stringie, 250, stdin);

	char* pointStringie = stringie;
	char* pointStop = stop;
	
	if (stringcomp(pointStringie, pointStop)==0){
	  break;
        } else {
	  printf("%s \n", stringie);
	  printf("%d \n", count_tokens(pointStringie));
	}
  }
}
int main(){
     input();
}

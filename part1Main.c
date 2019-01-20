#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch, poper=0, ch2=0 ;
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    else if (ch=='<'){
        ch = getchar();
        if (isalpha(ch)){
            if (islower(ch)){
                push(ch);
                if (getchar() != '>'){
                    fprintf(stderr,"Error: Please only use single characters\n");
                    fprintf(stdout,"NOT Valid\n");
                    exit(1);
                    }
                }
                else{
                    fprintf(stderr,"Error: No capital letters, please use lower case\n");
                    fprintf(stdout,"NOT Valid");
                    exit(1);
                    }
                }
        else if(ch=='/'){
            poper = (pop());
            ch2 = getchar();
            if (poper != ch2){
                fprintf(stdout,"NOT Valid\n");
                exit(1);
            }
        }
    }
if (isEmpty() == 0){
    fprintf(stdout,"Valid\n");
    exit(0);
    }
else {
    fprintf(stdout, "NOT Valid\n");
    exit(1);
}
}
    exit(0);
}

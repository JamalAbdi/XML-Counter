#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *  pop();
extern void push(char *);
extern void add(char *,int);
extern int isEmpty();
extern void make();
extern void hash_print();


int main(int argc, char * argv[])
{
  int ch, i,count;
    char search1[100], search2[100];
    char* string;
    make();
    while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    else if (ch == '<'){
        ch = getchar();
    if (isalpha(ch)){
            i=0;
            search1[i] = ch;
            i++;
            while((ch=getchar()) != '>'){
                search1[i] = ch;
                i++;
            }
            search1[i]=0;
            string = (char *)malloc(sizeof(char)*i);
            strcpy(string,search1);
            push(string);
            add(string, i);
        }
    else if (ch == '/'){
        i=0;
        while((ch=getchar()) != '>'){
            search1[i] = ch;
            i++;
        }
        search1[i]=0;
        strcpy(search2, pop());
        if(strcmp(search1,search2) !=0 ){
            fprintf (stderr, "NOT Valid\n");
            exit(1);
            }
        }
    }
}
    if((isEmpty())){
        printf ("Valid\n\n");
        hash_print();
        exit(0);
    }
    else{
        fprintf (stderr, "NOT Valid\n");
    }
  exit(1);
}

#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#define HASH_TABLE_SIZE 1057

typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];
int place,i;

void make(){
for(place=0;place<HASH_TABLE_SIZE;i++)
hash_table[place].count=0;
}

void add(char * a, int b){
int sum;
sum =0;
int c;
for (place=0;place<b;i++)
sum += a[place];
c = sum%HASH_TABLE_SIZE;

if(hash_table[c].string != NULL){
    if(strcmp(hash_table[c].string, a)==0){
        hash_table[c].count++;
    }
    else{
        while(hash_table[c].string != NULL){
            c++;
            if(hash_table[c].string != NULL){
                if(strcmp(hash_table[c].string, a)==0){
                    hash_table[c].count++;
                    break;
                }
            }
        }
    }
}

if(hash_table[c].string == NULL){
    hash_table[c].count++;
    hash_table[c].string = a;
}
}

void hash_print(){
    for(place=0; place<HASH_TABLE_SIZE; i++){
        if(hash_table[place].count != 0)
            fprintf(stdout,"%s: %d\n",hash_table[place].string, hash_table[place].count);
    }
}


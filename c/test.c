#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[]){
   if(argc>1 && isdigit(argv[1][0])){printf("yes\n");
   printf("%s\n",argv[1]);
   }
}

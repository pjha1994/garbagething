#include<stdio.h>
int getline1(char s[],int lim){
    int c,i;    
    for(i=0;;i++)
        if(i<lim-1)
           if((c=getchar())!=EOF)
                if( c!='\n')
                {
                   s[i]=c;
                   if(c=='\n')
                   {
                   s[i]=c;
                    ++i;
                   }
                }
        else
            break;
   s[i]='\0';
   return i;
}
upper_to_lower_to_upper(char s[]){
     int i=0;
     for(i=0;s[i]!='\0';i++)
        if(s[i]>='A'&&s[i]<='Z')
           s[i]=s[i]+'a'-'A';
        else if(s[i]>='a'&&s[i]<='z')
           s[i]=s[i]+'A'-'a';  
}
prints(char s[]){
    int i=0;
    for(i=0;s[i]!='\0';i++)
         printf("%c",s[i]);
}
main(){
char s[1000];
int i=0;
printf("%d\n",getline1(s,1000));

upper_to_lower_to_upper(s);


for(i=0;s[i]!='\0';i++)
     printf("%c",s[i]);
printf("\n");
return 0;
}

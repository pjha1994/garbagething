#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
main(){

//printf("hello, world\f");

int fahr,celcius;
int lower,upper,step;

lower=0;
upper=300;
step=20;
fahr=lower;
while(fahr<=upper){
    celcius=5*(fahr-32)/9;
    //printf("%3d\t%6d\n",fahr,celcius);//width added
    fahr=fahr+step;
}
//f();
//a();
//b();
c();
}

f(){
float fahr,celcius;
int lower,upper,step;

lower=0.0;
upper=300.0;
step=20.0;
fahr=lower;
while(fahr<=upper){
    celcius=5.0*(fahr-32.0)/9.0;
    printf("%3.0f\t%6.1f\t%d\t%6d\t%f\t%6f\t%.2f\t%6.2f\n",fahr,celcius,(int)fahr,(int)fahr,celcius,celcius,celcius,celcius);//change formatting to see
    fahr=fahr+step;
}
}
a(){
int fahr;
for(fahr=0;fahr<=300;fahr+=20)
  printf("%3d\t%6.1f\n",fahr,5.0*(fahr-32.0)/9.0);
for(fahr=300;fahr>=0;fahr-=20)
  printf("%3d\t%6.1f\n",fahr,5.0*(fahr-32.0)/9.0);
for(fahr=LOWER;fahr<=UPPER;fahr+=STEP)
  printf("%3d\t%6.1f\n",fahr,5.0*(fahr-32.0)/9.0);

}

b(){//interleaved putchar and printf
char c,d;
    printf("Enter the first character\n");
    scanf("%c",&c);
    printf("%c\n",c);
    printf("Enter the second character\n");
    d=getchar();
    putchar(d);
}
c(){//interleaved putchar and printf
char c,d;
printf("Enter the first character\n");
scanf("%c\n",&c);
printf("%c\n",c);
printf("Enter the second character\n");
d=getchar();
putchar(d);
printf("Enter the third character\n");
scanf("%c",&c);
getchar();
printf("%c",c);


}

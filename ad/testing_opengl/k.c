#include<stdio.h>
no_return_type()
{
	printf("Thers's no return type here, considered int");
	return 1;
}
void main()
{
no_return_type();
getchar();getchar();
}
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char file[60]  = "house.cat";

void main()
{	FILE *u;
	u=fopen(file,"rb");
	printf("%s",u);
	fclose(u);
}

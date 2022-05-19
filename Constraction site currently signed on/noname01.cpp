#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void main()
{	char a[20]="nai.txt",temp1[20]="shaolin",temp2[20]="one",temp3[20]="two";
	FILE *u;
	u=fopen(a,"ab");
	fprintf(u,"%s %s %s %s %s\n",temp1,temp2,temp3,temp1,temp2);
                              }

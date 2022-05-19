#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int cheak(char a[],char b[]) ;
void main()
{  int i;
	char a[10]="shbolin",b[10]="shaolin";
	i=cheak(a,b);
	printf("%d",i);
}

int cheak(char a[],char b[]) //return 1 when a > b else return 0
{
	int i,j,len1,len2,pass=1;
	len1=strlen(a);
	len2=strlen(b);
	for(i=0;i<len1;i++)
	{  if(a[i]>b[i])	{return 1;}
		else if(a[i]<b[i])	{return 0;}
		else continue;
	}
	if(len1==len2)	{printf("Same information occured");}
	return 0;
}
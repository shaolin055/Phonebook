#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define max 200

double value(char a[]);

void main()
{	char a[20]="shaolin";
	double i;
	i=value(a);
	printf("%lf",i);
}


double value(char a[])
{	int i,len;
	double x=1000.0,id=0.0,j=0.0;
	len=strlen(a);
//	printf("%d %s",len,a);
	for(i=0,j=len-1;i<len;i++,j--)
	{	id=id+a[i]*pow(x,j);
//		printf("%d\n",a[i]);
	}
	return id;
}

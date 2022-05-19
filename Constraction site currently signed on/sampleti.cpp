/* localtime example */ 

#include <time.h>
#include<string.h>
#include <stdio.h>
#include <dos.h>
#include<stdlib.h>

int main(void)
{  char a[30];
	int i;
	FILE *p;
	time_t timer;
	struct tm *tblock;

	/* gets time of day */
	timer = time(NULL);
	p=fopen("E:\\a.txt","w");
	/* converts date/time to a structure */
	tblock = localtime(&timer);
	strcpy(a,asctime(tblock));
	for(i=0;i<24;i++)
	{a[3]='*';
	 a[7]='*';
	 a[10]='*';
	 a[11]=a[20];
	 a[12]=a[21];
	 a[13]=a[22];
	 a[14]=a[23];
	 a[15]='\0';

	 }
	fprintf(p,"%s",a);
	fclose(p);
	printf("Local time is: %s", a);
/*	p=fopen("E:\\a.txt","r");
	fscanf(p,"%s",a);
	printf("Local time is: %s", a);*/


	return 0;
}




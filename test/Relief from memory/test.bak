#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define max 200
char file_1[20]="temp.cat";

void main()
{	FILE *u;
	char *temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9;
	double id;
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	temp9=(char*) malloc(max);
   strcpy(temp9,"shaolin");
	u=fopen(file_1,"ab");
	fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
	printf("%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id);
	fprintf(u,"%s %s %s %s %s %s %s %s %lf\n",temp9,temp9,temp9,temp9,temp9,temp9,temp9,temp9,id);
}
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void det();
char file[60]  = "house.cat";
char inf[60]	="setting.cat";

void main()
{  int i;
	char a;
	for (i=0;i<4;i++)
	{	getchar();
		a=getchar();
		if(a=='a')	printf("Yes %c %d",a,i);
		else {printf("No %c %d",a,i);}
	//det();
	}

}

void det()
{  int i,j,maxline=370,steak=5,lin=0,brk=0,info=0,step=1;
	FILE *t,*u;
	char a[10],*temp;
	temp= (char *) malloc(500);
	t=fopen(file,"rb");
	u=fopen(inf,"rb");
	fscanf(u,"%s %d %d",a,&i,&j);
  	printf("%d %d",i,j);
	fclose(u);
	for(i=0;i<500;i++)
	{strcpy(temp,"\0");
	 fscanf(t,"%s %s %s %s %s %s %s %s\n",temp,temp,temp,temp,temp,temp,temp,temp);
	 if(strlen(temp)==0) break;
	}
	if(a[0]=='*') steak++;
	if(a[1]=='*') steak++;
	if(a[3]=='*') steak=steak+3;
	info=maxline/steak;
//	printf("%d %d",info,steak);
	lin=steak*i;
	brk=lin;
	for(i=0;i<5;i++)
	{	if(brk<=maxline)	break;
		brk=brk-info*steak;
		step++;
	}
	fclose(t);
	u=fopen(inf,"wb");
	fprintf(u,"%s %d %d",a,info,step);
	fclose(u);
}


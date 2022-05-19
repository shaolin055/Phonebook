#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define max 200

void add(char x[],char y[]);
void strcat_(char c[],char a[],char b[]);

char file[20]="a.cat";
char file1[20]="temp.cat";

void main()
{	char x1[40]="shao",x2[40]="01721996382.01819194286",x3[40]="nai";
	add(x1,x2);
}

void add(char x[],char y[])
{  FILE *u,*v,*w;
	int pass=1,pass_=1;
	char na[50],ra[50],ad[50],na_[500]="\0",none[10]="\0";
	char x_[500]="\0";
	double i,j,k,a,b,z,len,id,temp=0,count=1;
	u=fopen(file,"rb");
	for(i=1;;i++)
	{  strcpy(na,"\0");
		strcpy(ra,"\0");
		fscanf(u,"%s %s %lf\n",na,ra,&temp);
		if(strlen(na)==0) {break;}
		if(temp!=i)	{	pass=0;
							printf("Fatal error! \nType: Disorder found in data stake.\nOrder redestribution recomanded. Do u wanna do it now?\nThen press 'y': ");
							exit(1);
						}
	}
	len=i-1;
	printf("%lf",len);
	fclose(u);
	strcat_(x_,x,y);
	u=fopen(file,"rb");
	for(i=1;i<=len;i++)
	{	strcpy(na,"\0");
		strcpy(ra,"\0");
		fscanf(u,"%s %s %lf\n",na,ra,&temp);
		if(strlen(na)==0) {break;}

		strcat_(na_,na,ra);
		if(strcmp(x_,na_)==0) {	printf("Error occured. Type: Information repeted");
										exit(1);
									 }
		if(strcmp(x_,na_)<0) {	z=temp;
										pass_=0;
										break;
									}
	}
	if(pass_==1)	{z=i;}
	fclose(u);
	u=fopen(file,"rb");
	v=fopen(file1,"wb");
	pass=0;
	for(i=1;i<=len;i++)
	{	strcpy(na,"\0");
		strcpy(ra,"\0");
		fscanf(u,"%s %s %lf\n",na,ra,&temp);
		if(strlen(na)==0) {break;}
		if(temp==z)	{pass=1;fprintf(v,"%s %s %lf\n",x,y,z);}
		if(pass==1)	{fprintf(v,"%s %s %lf\n",na,ra,temp+1.0);}
		else {fprintf(v,"%s %s %lf\n",na,ra,temp);}
	}
	if(pass_==1) {fprintf(v,"%s %s %lf\n",x,y,z);}
	fclose(u);
	fclose(v);
	remove(file);
	rename(file1,file);
}
/*-------------------------*/
void strcat_(char c[],char a[],char b[]) //concate a and b in c
{	int i,j,len1,len2;
	len1=strlen(a);
	len2=strlen(b);
	strcpy(c,"\0");
	strcpy(c,a);
	for(i=len1,j=0;i<len1+len2;i++,j++)
	{	c[i]=b[j];
	}
	c[i]='\0';
//	printf("%s\n",c);
//	return c;
}
/*------------------------------------------------------------------------------*/
void decode(char a[])
{	int i,j;
	char *temp;
	temp= (char *) malloc(max);
	strcpy(temp,"\0");
	for(i=0,j=0;i<max;i++,j++)
	{  if(a[i]=='\0')  		 break;
		if(64<a[i]&&a[i]<91)	{	temp[j]=a[i]+32;
										j++;
										temp[j]=14;
										j++;
										temp[j]=14;
										continue;
									}
		else temp[j]=a[i];
	}
	temp[j]='\0';
	strcpy(a,temp);
	for(i=0;i<max;i++)
		{  if(a[i]=='\0')  		 break;
			j=a[i];
			if(j<100)			{	 a[i]=(j-(j%10))/10+(j%10)*10;
									}
			else if(j>=100)	{   a[i]=100+(j-100-(j%10))/10+(j%10)*10;
									}
			}
	a[i]='\0';
	free(temp);
}
/*------------------------------------------------------------------------------*/
void encode1(char a[])
{	int i,j;
	char *sto;
	sto=	(char *) malloc(max);
	for(i=0;i<max;i++)
		{  if(a[i]=='\0')  		 break;
			j=a[i];
			if(j<0)				{	 j=j+256;
										 a[i]=100+(j-100-(j%10))/10+(j%10)*10;
									}
			else if(j<100)		{	 a[i]=(j-(j%10))/10+(j%10)*10;
									}
			else if(j>=100)	{   a[i]=100+(j-100-(j%10))/10+(j%10)*10;
									}
			}
	a[i]='\0';

	for(i=0,j=0;i<max;i++,j++)
	{  sto[j]='\0';
		if(a[i]=='\0')	{break;}
		else if(a[i+1]==14&&a[i+2]==14)	{  sto[j]=a[i]-32;
														i=i+2;
														continue;
													}
		else {sto[j]=a[i];}
	}
	sto[j]='\0';
	strcpy(a,sto);
	for(i=0;i<max;i++)
	{	if(a[i]=='\0')	{break;}
		a[i]='\0';
	}
	strcpy(a,sto);
}

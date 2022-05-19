#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define max 200

void refresh();
void strcat_(char c[],char a[],char b[]);
void arr();
void decode(char a[]);
void encode1(char a[]);

char file[20]="house.cat";
char file_1[20]="temp.cat";
char temp[60]= "tem.cat";

struct phone{
	char na[250];
//	char ph[50];
//	char ad[80];
	};
phone huge p[500];

void main()
{	refresh();
}
void refresh()
{  char c,*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9,*temp1_,*temp2_,*temp3_,*temp4_,*temp5_,*temp6_,*temp7_,*temp8_,*temp9_;
	int i,j,k,x,x1=0;
	double a=0,b,len,len_,id1;

	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	temp9=(char*) malloc(max);
	FILE *u,*v,*w;


	v=fopen(file_1,"wb");
	for(i=1,x=48;x<123;x++,i++)
	{  if(x>90&&x<97)	{continue;}
		if(x==58)	{x=64;continue;}
		u=fopen(file,"rb");
//		strcpy(file_1,"\0");
//		temp9[0]=x;
//		strcat_(file_1,temp9,".cat");
//		v=fopen(file_1,"wb");
		for(j=1;;j++)
		{  strcpy(temp1,"\0");
			fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id1);
			if(strlen(temp1)==0) {break;}
			encode1(temp1);
			x1=temp1[0];
			if(x1==x) {
							encode1(temp2);
							encode1(temp3);
							encode1(temp4);
							encode1(temp5);
							encode1(temp6);
							encode1(temp7);
							encode1(temp8);
							fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id1);
							a++;
						 }
		}
		fclose(u);
		//fclose(v);
	}
	fclose(v);
	len=a;

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

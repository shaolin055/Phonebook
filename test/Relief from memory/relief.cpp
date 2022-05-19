#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define max 200

void refresh();
void strcat_(char c[],char a[],char b[]);
void paste(char a[],char b[]);
void decode(char a[]);
void encode1(char a[]);

char file[20]="house.cat";
char file_1[20]="temp.cat";
char temp[60]= "tem.cat";

void main()
{	refresh();
}
void refresh()
{  char *na_,*na1_,*na__,*na1__,*x_,*x__,*temp1,*temp2,*temp3,*temp1_,*temp2_,*temp3_,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9;
	int i,j,k;
	double a,b,len,id,count=1;
	na_=(char*) malloc(max);
	na__=(char*) malloc(max);
	na1_=(char*) malloc(max);
	na1__=(char*) malloc(max);
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp1_=(char*) malloc(max);
	temp2_=(char*) malloc(max);
	temp3_=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	temp9=(char*) malloc(max);
	FILE *u,*v,*w;
	paste(temp,file);
	u=fopen(file,"rb");
	v=fopen(file_1,"wb");

	for(a=0;;a++)
	{  count=1.0;
		strcpy(temp1,"\0");
		strcpy(temp2,"\0");
		strcpy(temp3,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);
		if(strlen(temp1)==0) {break;}
		encode1(temp1);
		encode1(temp2);
		encode1(temp3);
		strcat_(na_,temp1,temp2);
		strcat_(na__,na_,temp3);
		w=fopen(temp,"rb");
		for(b=0;;b++)
		{  strcpy(temp1_,"\0");
			strcpy(temp2_,"\0");
			strcpy(temp3_,"\0");
			if(a==b) {	fscanf(w,"%s %s %s %s %s %s %s %s\n",temp1_,temp2_,temp3_,temp9,temp9,temp9,temp9,temp9);
							continue;
						}
			fscanf(w,"%s %s %s %s %s %s %s %s\n",temp1_,temp2_,temp3_,temp9,temp9,temp9,temp9,temp9);
			//printf("%s %s\n",na,na1);
			if(strlen(temp1_)==0) {break;}
			encode1(temp1_);
			encode1(temp2_);
			encode1(temp3_);
			strcat_(na1_,temp1_,temp2_);
			strcat_(na1__,na1_,temp3_);
			if(strcmp(na__,na1__)>0)   {count=count+1.0;}
		 }
		 printf("\n\n");
		 fclose(w);
		 decode(temp1);
		 decode(temp2);
		 decode(temp3);
		 fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,count);
	}
	len=a;
	fclose(v);
	fclose(u);
//	printf("%lf\n",len);
	w=fopen(temp,"wb");

	for(a=1;a<=len;a++)
	{  v=fopen(file_1,"rb");
		for(b=1;b<=len;b++)
		{	strcpy(temp1,"\0");
			strcpy(temp2,"\0");
			strcpy(temp3,"\0");
			fscanf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
			if(strlen(temp1)==0) break;
			if(id==a)	{fprintf(w,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id);
							 break;
							}
		}
		fclose(v);
	}
	fclose(w);
remove(file_1);
remove(file);
rename(temp,file);
}
/*--------------------------------------*/
void paste(char a[],char b[])
{	FILE *u,*v;
	char ch;
	u=fopen(b,"rb");
	v=fopen(a,"wb");
	for(;;)
	{	ch=fgetc(u);
		if(ch==EOF) {break;}
		fputc(ch,v);
	}
	fclose(u);
	fclose(v);
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

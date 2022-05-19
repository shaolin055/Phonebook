#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define max 200

void delete_(char x1[],char x2[],char x3[]);
void strcat_(char c[],char a[],char b[]);
void decode(char a[]);
void encode1(char a[]);

char file[20]="house.cat";
char file_1[20]="temp.cat";


void main()
{	char x1[]="shaolin",x2[]="bios",x3[]="nai";
	delete_(x1,x2,x3);
}
void delete_(char x1[],char x2[],char x3[])  // It offers 3 front row informations cheaking facilities to delete one data
{	FILE *u,*v;
	int pass=1;
	char *na_,*na__,*x_,*x__,*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8;
	double i,a,b,len,id;
	x_=(char*) malloc(max);
	x__=(char*) malloc(max);
	na_=(char*) malloc(max);
	na__=(char*) malloc(max);
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	//strcpy(x_,strcat(x,y));
	u=fopen(file,"rb");
	for(i=1;;i++)
	{  strcpy(temp1,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
		if(strlen(temp1)==0) {break;}
		if(id!=i)	{	pass=0;
							printf("Fatal error! \nType: Disorder found in data stake.\nOrder redestribution recomanded. Do u wanna do it now?\nThen press 'y': ");
							exit(1);
						}
	}

	strcat_(x_,x1,x2);
	strcat_(x__,x_,x3);
	len=i-1;
	fclose(u);
	u=fopen(file,"rb");
	v=fopen(file_1,"wb");
	pass=0;
	for(i=1;i<=len;i++)
	{	strcpy(temp1,"\0");
		strcpy(temp2,"\0");
		strcpy(temp3,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
		if(strlen(temp1)==0) {break;}
		encode1(temp1);
		encode1(temp2);
		encode1(temp3);
		strcat_(na_,temp1,temp2);
		strcat_(na__,na_,temp3);
		decode(temp1);
		decode(temp2);
		decode(temp3);
		if(strcmp(x__,na__)==0) {	pass=1;id=1;}
		if(pass==1)	{fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id-1);}
		else	{fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id);}

	}
	if(pass==0) {printf("\n\n\n\n\n\n\n\t\tNo record found to delete named: %s",x1);
					 exit(1);
					}
	fclose(u);
	fclose(v);
	u=fopen(file,"wb");
	for(a=1;a<=len;a++)
	{  v=fopen(file_1,"rb");
		for(b=1;b<=len;b++)
		{	strcpy(temp1,"\0");
			strcpy(temp2,"\0");
			strcpy(temp3,"\0");
			fscanf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
			if(strlen(temp1)==0) break;
			if(id==a)	{fprintf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id);
							 break;
							}
		}
		fclose(v);
	}
	fclose(u);
	remove(file_1);
  	free(x_);
	free(x__);
	free(na_);
	free(na__);
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
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
//	printf("%s %s %s\n",a,b,c);
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


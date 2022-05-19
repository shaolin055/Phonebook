#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define max 200

void refresh();
double value(char a[]);

void paste(char a[],char b[]);


char file[20]="house.cat";
char file_1[20]="temp.cat";
char temp[60]= "tem.cat";

void main()
{	refresh();
}
void refresh()
{  char *na_,*na1_,*na__,*na1__,*x_,*x__,*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9,*temp1_,*temp2_,*temp3_,*temp4_,*temp5_,*temp6_,*temp7_,*temp8_,*temp9_;
	int i,j,k;
	double a,b,len,id1,id2,id3,id4,count=1;
	na_=(char*) malloc(max);
	na__=(char*) malloc(max);
	na1_=(char*) malloc(max);
	na1__=(char*) malloc(max);
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	temp9=(char*) malloc(max);
	temp1_=(char*) malloc(max);
	temp2_=(char*) malloc(max);
	temp3_=(char*) malloc(max);
	temp4_=(char*) malloc(max);
	temp5_=(char*) malloc(max);
	temp6_=(char*) malloc(max);
	temp7_=(char*) malloc(max);
	temp8_=(char*) malloc(max);
	temp9_=(char*) malloc(max);
	FILE *u,*v,*w;
	paste(temp,file);
	u=fopen(file,"rb");
	v=fopen(file_1,"wb");

/*	for(a=0;;a++)
	{  count=1.0;
		strcpy(temp1,"\0");
		strcpy(temp2,"\0");
		strcpy(temp3,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id1);
		if(strlen(temp1)==0) {break;}
		id2=value(temp1);
		fprintf(v,"%s %s %s %s %s %s %s %s %lf %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id1,id2);
	}       */
	//len=a;
	fclose(u);
	fclose(v);
	v=fopen(file,"rb");
	w=fopen(temp,"wb");
	fscanf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id1);
	for(a=0;;a++)
	{	fscanf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1_,temp2_,temp3_,temp4_,temp5_,temp6_,temp7_,temp8_,&id3);
		if(strlen(temp1_)==0) {break;}
//		if(id2<id4) {  fprintf(w,"%s %s %s %s %s %s %s %s %lf %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id1,id2);
  //    				}
		if(strcmp(temp1,temp1_)>0)	{	fprintf(w,"%s %s %s %s %s %s %s %s %lf\n",temp1_,temp2_,temp3_,temp4_,temp5_,temp6_,temp7_,temp8_,id3);
							strcpy(temp1,temp1_);
							strcpy(temp2,temp2_);
							strcpy(temp3,temp3_);
							strcpy(temp4,temp4_);
							strcpy(temp5,temp5_);
							strcpy(temp6,temp6_);
							strcpy(temp7,temp7_);
							strcpy(temp8,temp8_);
							id1=id3;
                     
						}
	}
	fclose(v);
	fclose(w);

}
/*------------------------------------------------------------------------------*/
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


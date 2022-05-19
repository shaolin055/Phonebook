#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define max 200

void add(char x1[],char x2[],char x3[],char inf1[],char inf2[],char inf3[],char inf4[],char inf5[]);
void strcat_(char c[],char a[],char b[]);
void decode(char a[]);
void encode1(char a[]);
void time1(char a[]);

char file[20]="house.cat";
char file_1[20]="temp.cat";
char none[10]=";";

void main()
{	char *tim,x1[]="shaol0in",x2[]="bios",x3[]="nai";
	tim=(char*) malloc(max);
	time1(tim);
//	printf("%s",tim);
	add(x1,x2,x3,tim,none,none,none,none);
//   exit(1);
	free(tim);
}

void add(char x1[],char x2[],char x3[],char inf1[],char inf2[],char inf3[],char inf4[],char inf5[])
{  FILE *u,*v;
	int pass=1,pass_=1;
	char *na_,*na__,*x_,*x__,*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp4_,*temp5_,*temp6_,*temp7_,*temp8_;
	double i,z,len,id;
	x_=(char*) malloc(max);
//	x_1=(char*) malloc(max);
	x__=(char*) malloc(max);
	na_=(char*) malloc(max);
//	na_1=(char*) malloc(max);
	na__=(char*) malloc(max);
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	temp4_=(char*) malloc(max);
	temp5_=(char*) malloc(max);
	temp6_=(char*) malloc(max);
	temp7_=(char*) malloc(max);
	temp8_=(char*) malloc(max);
	strcpy(temp4_,inf1);
	strcpy(temp5_,inf2);
	strcpy(temp6_,inf3);
	strcpy(temp7_,inf4);
	strcpy(temp8_,inf5);
	u=fopen(file,"rb");
	for(i=1;;i++)
	{  strcpy(temp1,"\0");
		strcpy(temp2,"\0");
		strcpy(temp3,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
		if(strlen(temp1)==0) {break;}
		if(id!=i)	{	pass=0;
							printf("Fatal error! \nType: Disorder found in data stake.\nOrder redestribution recomanded. Do u wanna do it now?\nThen press 'y': ");
							exit(1);
						}
	}
	len=i-1;
	fclose(u);
	strcat_(x_,x1,x2);
//	strcpy(x_1,x_);
	strcat_(x__,x_,x3);
	u=fopen(file,"rb");
	for(i=1;i<=len;i++)
	{	strcpy(temp1,"\0");
		strcpy(temp2,"\0");
		strcpy(temp3,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
		if(strlen(temp1)==0) {break;}
		encode1(temp1);
//    printf("%s ",na);
		encode1(temp2);
		encode1(temp3);
		strcat_(na_,temp1,temp2);
//		strcpy(na_1,na_);
		strcat_(na__,na_,temp3);
//		printf("%s ",temp3);
		if(strcmp(x__,na__)==0) {	printf("\n\n\n\tError occured.\n\tType: Information repeted");
										exit(1);
									 }
		if(strcmp(x__,na__)<0) {	z=id;
										pass_=0;
										break;
									}
	}
	if(pass_==1)	{z=i;}
	fclose(u);
	u=fopen(file,"rb");
	v=fopen(file_1,"wb");
	pass=0;
	printf("%s   %s   %s    %s    %s\n",inf1,inf2,inf3,inf4,inf5);
	decode(x1);
	decode(x2);
	decode(x3);
	decode(temp4_);
	decode(temp5_);
	decode(temp6_);
	decode(temp7_);
	decode(temp8_);
	printf("%s     %s         %s       %s          %s\n",inf1,inf2,inf3,inf4,inf5);

	for(i=1;i<=len;i++)
	{	strcpy(temp1,"\0");
		strcpy(temp2,"\0");
		strcpy(temp3,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
		if(strlen(temp1)==0) {break;}
		if(id==z)	{pass=1;fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",x1,x2,x3,temp4_,temp5_,temp6_,temp7_,temp8_,z);}
		if(pass==1)	{fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id+1.0);}
		else {fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id);}
	}
	if(pass_==1) {fprintf(v,"%s %s %s %s %s %s %s %s %lf\n",x1,x2,x3,temp4_,temp5_,temp6_,temp7_,temp8_,z);}
	fclose(u);
	fclose(v);
	remove(file);
	rename(file_1,file);
	free(x_);
//	free(x_1);
	free(x__);
	free(na_);
//	free(na_1);
	free(na__);
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
	free(temp4_);
	free(temp5_);
	free(temp6_);
	free(temp7_);
	free(temp8_);
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
//	printf("%s\n",a);
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

/*------------------------------------------------------------------------------*/
void time1(char a[])
{	int i;
	time_t timer;
	struct tm *tblock;
	/* gets time of day */
	timer = time(NULL);
	/* converts date/time to a structure */
	tblock = localtime(&timer);
	strcpy(a,asctime(tblock));
	for(i=0;i<24;i++)
	{a[3]=';';
	 a[7]=';';
	 a[10]=';';
	 a[11]=a[20];
	 a[12]=a[21];
	 a[13]=a[22];
	 a[14]=a[23];
	 a[15]='\0';
	 }
}

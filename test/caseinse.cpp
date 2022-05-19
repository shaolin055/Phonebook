#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void decode(char a[]);
void encode1(char a[]);
int cheaker(char a[],char s[]);

void main()
{  int i=0;
	char a[200],s[200];
	printf("inter a string : ");
	scanf("%s",a);
	printf("inter string for cheaking : ");
	scanf("%s",s);
	decode(a);
	decode(s);
//	printf("%s\n",a);
	//encode1(a);
	//printf("%s",a);
	i=cheaker(a,s);
	if(i==1)	printf("\ndone!");
	else printf("alase!");
	exit(1);
	}




/*------------------------------------------------------------------------------*/
void decode(char a[])
{	int i,j;
	char *temp;
	temp= (char *) malloc(200);
	strcpy(temp,"\0");
	for(i=0,j=0;i<1000;i++,j++)
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
	for(i=0;i<1000;i++)
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
	sto=	(char *) malloc(200);
	for(i=0;i<1000;i++)
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

	for(i=0,j=0;i<1000;i++,j++)
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
	for(i=0;i<1000;i++)
	{	if(a[i]=='\0')	{break;}
		a[i]='\0';
	}
	strcpy(a,sto);
}
/*------------------------------------------------------------------------------*/
int cheaker(char a[],char s[])          // cheaker(by which,to be cheaked);
{  int l,p,i,j=0,k=0;

	l=strlen(s);
	p=strlen(a);

	for(i=0;i<p;i++)
	{  if(a[i]==41&&a[i+1]==41)	{i++;continue;}
		if(s[j]==41&&s[j+1]==41)   {j=j+2;
											 i--;
											 if(j==l) {	k=1;
																break;
															}
											 continue;
											}
		if(a[i]==s[j]) {	j++;
								if(j==l) {	k=1;
												break;
											}
							}
		else j=0;
	}
	if(k==1) return 1;
	else return 0;
	}


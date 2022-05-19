#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
/*------------------------------------------------------------------------*/
void load(void);
void sar(void);
void save(void);
void all(void);
void rule(void);
struct phone{
	char na[100];
	char ph[100];
	char ad[100];
	}p[10];
/*-------------------------------------------------------------------------*/
void main ()
{	int x;
	char p[8],q[8]="shaolin";
	clrscr();
	printf("Type: 1: If you want to sarch\n      2: To save(protected)\n      3: To see DIRECTORY\n      4: For rules\n");
	scanf("%d",&x);
	switch(x){
	case 1:load();break;
	case 2:{printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)!=0) {printf("sorry your passored is wrong!!!");break;}
			  save();
			  break;  }
	case 3:all();break;
	case 4:rule();break;
	}
	getch(); }
/*--------------------------------------------------------------------------*/
void save()
{	int i;
	FILE *u;
	u=fopen("address1.txt","w");
	for(i=0;i<10;i++)
	{
	printf("enter name:");
	scanf("%s",p[i].na);
	fprintf(u,"%s ",p[i].na);
	printf("enter phone:");
	scanf("%s",p[i].ph);
	fprintf(u,"%s ",p[i].ph);
	printf("enter address:");
	scanf("%s",p[i].ad);
	fprintf(u,"%s \n",p[i].ad);
	}
	fclose(u);
	}
/*--------------------------------------------------------------------------*/
void sar()
{       int i,j,m=1;
	char name[20];
	printf("inter the name you want to sarch:");
	scanf("%s",&name);
	for(i=0;i<10;i++)
	{       j=strcmp(name,p[i].na);
		if(j==0) {      printf("name:%s\nphone:%s\naddress:%s\n",p[i].na,p[i].ph,p[i].ad);
				m=2;
				}
				 }
	if(m==1) {printf("Sorry your name is not in directory. Thank you."); }
	}
/*--------------------------------------------------------------------------*/
void load()
{       FILE *u;
	int i;
	u=fopen("phone.txt","r");
	for(i=0;i<10;i++)
	{fscanf(u,"%s %s %s ",p[i].na,p[i].ph,p[i].ad); }
	fclose(u);
	sar();}
/*--------------------------------------------------------------------------*/
void all()
{       FILE *u;
	int i;
	int k;
	//char ch;
	clrscr();
	u=fopen("phone.txt","r");
	for(i=0;i<10;i++)
	{fscanf(u,"%s %s %s ",p[i].na,p[i].ph,p[i].ad);
	 }
	fclose(u);
	for(i=0,k=1;i<10;i++)
	{printf("%d)\nName: %s\nMobil: %s\nAddress: %s\n\n",k,p[i].na,p[i].ph,p[i].ad);
	 k++;
	 }
	}
/*--------------------------------------------------------------------------*/
void rule()
{       clrscr();
	printf("SOME INSTRACTIONS:\n   1) When searching put the acurate spelling.\n   2) After input, press enter.\n   3) Don't put a space when putting a string.\n");
		}

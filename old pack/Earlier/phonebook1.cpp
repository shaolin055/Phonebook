/*------------------------------01--------------------------------------*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define	updat	1
/*------------------------------------------------------------------------*/
void choice(void);
void load(void);
void sar(void);
void save(void);
void all(void);
void rule(void);
void arr();
void update();
void wriup();
struct phone{
	char na[100];
	char ph[100];
	char ad[100];
	}p[150];
/*-------------------------------------------------------------------------*/
void main ()
{  update();
	choice();
	}
/*--------------------------------------------------------------------------*/
void choice(void)
{  char p[8],q[22]="shaolin";
	int x;
	printf("\n\n\n\n\n\n\n\n\n\t\t\t        **************\n\t\t\t        * PHONE BOOK *\n\t\t\t        **************\n\t\t\t\t      ");
	getchar();
	clrscr();
	printf("\n                         ** MAIN MENU **\n\nType 1: If you want to sarch\n      2: To save(protected)\n      3: To see DIRECTORY(protected)\n      4: For rules\n      5: Exit\n\n\n      Type -> ");
	scanf("%d",&x);
	switch(x){
	case 1:sar();break;
	case 2:{clrscr();printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)!=0) {printf("sorry your passored is wrong!!!");break;}
			  save();
			  break;  }
	case 3:{clrscr();printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)!=0) {printf("sorry your passored is wrong!!!");break;}
			  all();break;}
	case 4:rule();break;
	case 50:wriup();choice();break;
	case 5:exit(1);
	}
		 }
/*--------------------------------------------------------------------------*/
void save()
{	int i;
	char a[20];
	FILE *u;
	u=fopen("f:\\c\\phone1.txt","a");
	for(i=0;i<1;i++)
	{
	clrscr();
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
	printf("Wanna to enter more? Press 'S'.\nIf not press anykey.\n");
	scanf("%s",&a);
	if(strcmp("s",a)==0||strcmp("S",a)==0) save();
	fclose(u);
	arr();
	}
/*--------------------------------------------------------------------------*/
void load()
{       FILE *s;
	int i;
	s=fopen("f:\\c\\phone1.txt","r");
	for(i=0;i<100;i++)
	{fscanf(s,"%s %s %s ",p[i].na,p[i].ph,p[i].ad); }
	fclose(s);
	}
/*---------------------------------------------------------------------------*/
void sar()
{  int i,j,m=1;
	char name[20],ch[20];
	load();
	clrscr();
	printf("inter the name you want to sarch -> ");
	scanf("%s",&name);
	clrscr();
	for(i=0;i<100;i++)
	{       j=strcmp(name,p[i].na);
		if(j==0) {      printf("name -> %s\nphone -> %s\naddress\e-mail ->%s\n",p[i].na,p[i].ph,p[i].ad);
				m=2;
				}
				 }
	if(m==1) {printf("Sorry your name is not in directory.\n"); }
	getchar();	getchar();
	clrscr();
	printf("\nWhat now?\n\n      To search press \"s\".\n      To go to \"MAIN MENU\" press \"m\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	if(strcmp("s",ch)==0||strcmp("S",ch)==0) {load();}
	else if(strcmp("m",ch)==0||strcmp("m",ch)==0) {clrscr();choice();}
	else exit(1);
	}
/*--------------------------------------------------------------------------*/
void all()
{  FILE *t;
	int i,j;
	int k;
	//char ch;
	clrscr();
	t=fopen("f:\\c\\phone1.txt","r");
	for(i=0;i<150;i++)
	{fscanf(t,"%s %s %s ",p[i].na,p[i].ph,p[i].ad);
	 if(strlen(p[i].na)==0) break;
	 }
	fclose(t);
	for(j=0,k=1;i>0;i--,j++)
	{//if(strlen(p[i].na)==0) break;
	 printf("%d)\nName -> %s\nMobil -> %s\nAddress\e-mail -> %s\n\n",k,p[j].na,p[j].ph,p[j].ad);
	 k++;
	 }
	}
/*--------------------------------------------------------------------------*/
void rule()
{  clrscr();
	char c[20];
	printf("SOME INSTRACTIONS -> \n   1) When searching put the acurate spelling.\n   2) After input, press enter.\n   3) Don't put a space when putting a string.\n");
	getchar();
	getchar();
	clrscr();
	printf("To go to \"MAIN MENU\" press \"s\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("s",c)==0||strcmp("S",c)==0) {	clrscr();
															choice();}
	else exit(1);
		}
/*------------------------------------------------------------------------*/
void arr()
{  FILE *q;
	int i,j,k;
	char c[12];
	struct phone temp;
	load();
	for(i=0;p[i].na[0]!='\0';i++)
		{	for(j=i+1;p[j].na[0]!='\0';j++)
			{for(k=0;k<strlen(p[i].na);k++)
				{if((p[i].na[k])>(p[j].na[k]))
					{ temp=p[i];
					 p[i]=p[j];
					 p[j]=temp;
					 break;
					 }
				 else if(p[i].na[k]<p[j].na[k]) break;
					 }
						}
							}
	q=fopen("phone1.txt","w");
	for(i=0;p[i].na[0]!='\0';i++)
		{ fprintf(q,"%s %s %s\n",p[i].na,p[i].ph,p[i].ad);}
	fclose(q);
	clrscr();
	printf("To go to \"MAIN MENU\" press \"s\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("s",c)==0||strcmp("S",c)==0) {	clrscr();
															choice();}
	else exit(1);
}
/*------------------------------------------------------------------------------*/
void update()
{	FILE *q;
	int c;
	q=fopen("f:\\c\\update.txt","r");
	fscanf(q,"%d",&c);
	if(updat<c) {printf("\n\n\n\t\t\t\tNOTE\n\t\tIt is not letest virsion of phone book.\n\t\tUpdate please.");
					  getchar();
					  clrscr();}
					  }
/*------------------------------------------------------------------------------*/
void wriup()
{	FILE *q;
	int x;
	q=fopen("f:\\c\\update.txt","w");
	x=updat;
	fprintf(q,"%d",x);
	}









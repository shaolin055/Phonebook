/*------------------------------04--------------------------------------*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define	updat	4
/*------------------------------------------------------------------------*/
void choice(void);
void load(void);
void sar(void);
void save(void);
void edit();
void all(void);
void rule(void);
void arr();
void update();
void wriup();
void virsion();
/*-------------------------------------------------------------------------*/
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
	printf("\n                         ** MAIN MENU **\n\nType  1: If you want to sarch\n      2: To save(protected)\n      3: Edit\n      4: To see DIRECTORY(protected)\n      5: Virsion\n      6: For rules\n      7: Exit\n\n\n      Type -> ");
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
			  edit();break;}
	case 4:{clrscr();printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)!=0) {printf("sorry your passored is wrong!!!");break;}
			  all();break;}
	case 5:virsion();break;
	case 6:rule();break;
	case 50:wriup();choice();break;
	case 7:exit(1);
	}
		 }
/*--------------------------------------------------------------------------*/
void save()
{	int i;
	char a[20];
	FILE *u;
	u=fopen("f:\\phone1.txt","a");
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
	printf("Wanna to enter more? Press 'Y'.\nIf not press anykey.\n");
	scanf("%s",&a);
	if(strcmp("y",a)==0||strcmp("Y",a)==0) save();
	fclose(u);
	load();
	arr();
	}
/*--------------------------------------------------------------------------*/
void load()
{  FILE *s;
	int i;
	s=fopen("f:\\phone1.txt","r");
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
	printf("\nWhat now?\n\n      To search press \"S\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	if(strcmp("s",ch)==0||strcmp("S",ch)==0) {load();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
	else exit(1);
	}
/*--------------------------------------------------------------------------*/
void all()
{  FILE *t;
	int i,j;
	int k;
	char c[20];
	//char ch;
	clrscr();
	t=fopen("f:\\phone1.txt","r");
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
	getchar();
	getchar();
	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else exit(1);
	}
/*--------------------------------------------------------------------------*/
void rule()
{  clrscr();
	char c[20];
	printf("SOME INSTRACTIONS -> \n   1) When searching put the acurate spelling.\n   2) After input, press enter.\n   3) Don't put a space when putting a string.\n");
	getchar();
	getchar();
	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else exit(1);
		}
/*------------------------------------------------------------------------*/
void arr()
{  FILE *q;
	int i,j,k;
	char c[12];
	struct phone temp;
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
	q=fopen("f:\\phone1.txt","w");
	for(i=0;p[i].na[0]!='\0';i++)
		{ fprintf(q,"%s %s %s\n",p[i].na,p[i].ph,p[i].ad);}
	fclose(q);
	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else exit(1);
}
/*------------------------------------------------------------------------------*/
void update()
{	FILE *q;
	int x,c;
	q=fopen("f:\\c\\update.txt","r");
	fscanf(q,"%d",&c);
//   printf("%d",c);
	x=updat;
	if(updat<c) {printf("\n\n\n\t\t\t\tNOTE\n\t\tIt is not letest virsion of phone book.\n\t\tUpdate please.\n\t\tThis is virsion: %d\n\t\tNew virsion: %d\n\t\tLink: F:\c\Phonebook\latest\phoneb~1.exe",x,c);
					  getchar();
					  clrscr();}
	else    wriup();				  }
/*------------------------------------------------------------------------------*/
void wriup()
{	FILE *q;
	int x;
	q=fopen("f:\\c\\update.txt","w");
	x=updat;
	fprintf(q,"%d",x);
	}
/*------------------------------------------------------------------------------*/
void virsion()
{	int x;
	char c[20];
	clrscr();
	x=updat;
	printf("\n\n\n\n\n\n\n\t\t\t\tThis is \"Program Virsion\": %d\n\t\t\t\t----------------------------",x);
	getchar();
	getchar();
	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else exit(1);
			  }
/*------------------------------------------------------------------------------*/
void edit()
{  int i,j,m=1;
	int x;
	char name[20],ch[20];
	load();
	clrscr();
	printf("inter the name you want to edit -> ");
	scanf("%s",&name);
	clrscr();
	for(i=0;i<100;i++)
	{       j=strcmp(name,p[i].na);
		if(j==0) {      printf("Old information:\nname -> %s\nphone -> %s\naddress\e-mail ->%s\n",p[i].na,p[i].ph,p[i].ad);
				m=2;
				printf("\n\t\t\tIf wanna to change name press 1\n\t\t\tif phone press 2\n\t\t\tIf address press 3\n\t\t\tIf nothing press 4\n\t\t\ttype: ");
				scanf("%d",&x);
				switch(x){
				case 1:{ printf("enter new name:");
							scanf("%s",p[i].na);
							arr();
							break;}
				case 2:{ printf("enter new phone:");
							scanf("%s",p[i].ph);
							arr();
							break;}
				case 3:{ printf("enter new address:");
							scanf("%s",p[i].ad);
							arr();
							break;}
				case 4:{ clrscr();
							printf("To edit another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
							scanf("%s",&ch);
							if(strcmp("e",ch)==0||strcmp("E",ch)==0) {load();}
							else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
							else exit(1); }
								 }
					}
						}
	if(m==1) {printf("Sorry your name is not in directory.\n"); }

	getchar();	getchar();
	clrscr();
	printf("Try another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	if(strcmp("e",ch)==0||strcmp("E",ch)==0) {load();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
	else exit(1);

	}
/*------------------------------------------------------------------------------*/

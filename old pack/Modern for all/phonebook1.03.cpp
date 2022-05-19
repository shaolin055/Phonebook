/*-----------2,3,8,20,21,34-37,50,84,340-358-----------------------------------------*/
/*------------------------------------1.03--------------------------------------*/
/*--------------------------------All computer virsion--------------------------*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define	updat	1.03
/*------------------------------------------------------------------------------*/
void choice(void);
void load(void);
void sar(void);
void save(void);
void edit();
void erase();
void all(void);
void rule(void);
void arr();
/*------------------------------------------------------------------------------*/
//void update();
//void wriup();
void virsion();
void tutorial();
void out();
/*------------------------------------------------------------------------------*/
void choice1(void);
void all1();
void load1();
void save1();
void arr1();
void erase1();
void edit1();
/*------------------------------------------------------------------------------*/
char file[60]  = "c:\\phone.fat";
char file1[60]  ="c:\\personal.fat";
int a=1; //used not to show personal tag twice
char q[22]="987654";
/*------------------------------------------------------------------------------*/
struct phone{
	char na[100];
	char ph[60];
	char ad[100];
	}p[100];
/*------------------------------------------------------------------------------*/
struct personal{
	char inf[100];
	}n[100];
/*------------------------------------------------------------------------------*/
void main ()
{  //update();
	choice();
	}
/*------------------------------------------------------------------------------*/
void choice(void)
{  char p[8];
	int x;
	printf("\n\n\n\n\n\n\n\n\n\t\t\t        **************\n\t\t\t        * PHONE BOOK *\n\t\t\t        **************\n\t\t\t\t      ");
	getchar();
	clrscr();
	printf("\n                         ** MAIN MENU **\n\nType  1: If you want to sarch\n\n      2: To save(protected)\n\n      3: Edit\n\n      4: Erase\n\n      5: To see DIRECTORY(protected)\n\n      6: For rules\n\n      7: For solving problem\n\n      8: About\n\n      Any key: Exit\n\n\n      Type -> ");
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
			  erase();break;}
	case 5:{clrscr();printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)!=0) {printf("sorry your passored is wrong!!!");break;}
			  all();break;}
	case 6:rule();break;
	case 7:tutorial();break;
	case 8:virsion();break;
//	case 50:wriup();choice();break;
	case 100:load();arr();break;
	case 1000:choice1();
	default :out();

	}
		 }
/*------------------------------------------------------------------------------*/
void save()
{	int i;
	char a[20],c[20];
	FILE *u;
	u=fopen(file,"ab");
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
	clrscr();
	printf("\n\n\n\n\n\n\n\t\t\t\tTaking entry....");
	getchar();
	getchar();
	clrscr();
	printf("Wanna to enter more? Press 'Y'.\nIf not press anykey.\n");
	scanf("%s",&a);
	fclose(u);
	if(strcmp("y",a)==0||strcmp("Y",a)==0) {load();arr();save();}
//	fclose(u);
	load();
	arr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();

	}
/*------------------------------------------------------------------------------*/
void load()
{  FILE *s;
	int i;
	s=fopen(file,"rb");
	for(i=0;i<100;i++)
	{fscanf(s,"%s %s %s ",p[i].na,p[i].ph,p[i].ad); }
	fclose(s);
	}
/*------------------------------------------------------------------------------*/
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
	if(strcmp("s",ch)==0||strcmp("S",ch)==0) {sar();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
	else out();
	}
/*------------------------------------------------------------------------------*/
void all()
{  FILE *t;
	int i,j;
	int k;
	char c[20];
	//char ch;
	clrscr();
	t=fopen(file,"rb");
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
	else out();
	}
/*------------------------------------------------------------------------------*/
void edit()
{  int i,j,m=1;
	int x;
	char name[20],ch[20];
	load();
	clrscr();
	continu:printf("inter the name you want to edit -> ");
	scanf("%s",&name);
	clrscr();
	for(i=0;i<100;i++)
	{        again: j=strcmp(name,p[i].na);
				if(j==0) {      printf("Old information:\nname -> %s\nphone -> %s\naddress\e-mail ->%s\n",p[i].na,p[i].ph,p[i].ad);
				m=2;
				printf("\n\t\t\tIf wanna to change name press 1\n\t\t\tif phone press 2\n\t\t\tIf address press 3\n\t\t\tIf nothing press 4\n\t\t\ttype: ");
				scanf("%d",&x);
				switch(x){
				case 1:{ printf("enter new name:");
							scanf("%s",p[i].na);
							arr();
							goto again;
						  //	break;
						  }
				case 2:{ printf("enter new phone:");
							scanf("%s",p[i].ph);
							arr();
							goto again;
						  //	break;
						  }
				case 3:{ printf("enter new address:");
							scanf("%s",p[i].ad);
							arr();
							goto again;
						  //	break;
						  }
				case 4:{ clrscr();
							printf("To edit another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
							scanf("%s",&ch);
							if(strcmp("e",ch)==0||strcmp("E",ch)==0) {load();clrscr();goto continu;}
							else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
							else out(); }
								 }
					}
						}
	if(m==1) {printf("Sorry your name is not in directory.\n"); }

	getchar();	getchar();
	clrscr();
	printf("Try another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	if(strcmp("e",ch)==0||strcmp("E",ch)==0) {edit();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
	else out();

	}
/*------------------------------------------------------------------------------*/
 void erase()
{  int i,j,k,m=1;
 //	int x;
	char name[20],ch[20],c[20];
	load();
	clrscr();
	printf("inter the name you want to erase -> ");
	scanf("%s",&name);
	clrscr();
	for(i=0;i<100;i++)
	{        j=strcmp(name,p[i].na);
				if(j==0) {      printf("Old information:\nname -> %s\nphone -> %s\naddress\e-mail ->%s\n\n\n\t\t\tWarning: Next step will permanently remove the name.\n\t\t\tBECAUSIOUS\n\t\t\t..........",p[i].na,p[i].ph,p[i].ad);
				getchar();getchar();
				printf("\t\tDO U WANNA PROCEDE???\n\t\tIf yes press \"y\"\n\t\tElse \"anykey\"\n\t\tType: ");
				scanf("%s",&c);
				if(strcmp("y",c)==0||strcmp("Y",c)==0)  { m=2;
																		strcpy(p[i].na," ");
																		strcpy(p[i].ph," ");
																		strcpy(p[i].ad," ");
																		arr();
																		for(k=0;k<100;k++)
																		{strcpy(p[k].na,"\0");
																		 strcpy(p[k].ph,"\0");
																		 strcpy(p[k].ad,"\0");
																		}
																		clrscr();
																		printf("\n\n\n\n\n\n\n\t\t\t\tSucessfuly erased....");
																		getchar();
																		getchar();
																		load();
																		arr();}//getchar();getchar();goto pass;}
			  /*	m=2;
				strcpy(p[i].na," ");
				strcpy(p[i].ph," ");
				strcpy(p[i].ad," ");
				arr();}    */
				//getchar();getchar();
				goto pass;				  }
			  }
	 if(m==1) {clrscr();printf("Sorry your name is not in directory.\n");getchar();getchar(); }

	pass: clrscr();
	printf("Try another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	if(strcmp("e",ch)==0||strcmp("E",ch)==0) {erase();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
	else out();

	}
/*------------------------------------------------------------------------------*/
void arr()
{  FILE *q;
	int i,j,k;
//	char c[12];
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
	q=fopen(file,"wb");
	for(i=0;p[i].na[0]!='\0';i++)
		{ fprintf(q,"%s %s %s\n",p[i].na,p[i].ph,p[i].ad);}
	fclose(q);
	clrscr();
/*	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();     *///solution to save function problem//
}
/*------------------------------------------------------------------------------*/
void rule()
{  clrscr();
	char c[20];
	printf("\n\t\t\t     SOME INSTRACTIONS : \n\n\t   1)  When searching  put the acurate  spelling. Because  it\n\t       is case sensitive programme.\n\n\t   2)  After input, press enter.\n\n\t   3)  Don't put a spacewhen putting a string. It will hamper\n\t       the internal stracture.**\n\n\t   4)  When exit please  close the  window, it does not close\n\t       automatically\n\n\t   5)  It is just a programme for personal using purpuse...\n\n\t   6)  In virsion number,  \"zero\" in first  digit after  point \n\t       means, suitatable for all computer.* \n");
	getchar();
	getchar();
	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();
		}
/*------------------------------------------------------------------------------*/
/*void update()
{	FILE *q;
	float x,c;
	q=fopen(up,"rb");
	fscanf(q,"%f",&c);
//	printf("%f",c);
	x=updat;
	if(x<c) {printf("\n\n\n\t\t\t\tNOTE\n\t\tIt is not letest virsion of phone book.\n\t\tUpdate please.\n\t\tThis is virsion: %f\n\t\tNew virsion: %f\n\t\tLink: F:\\c\\Phonebook\\latest\\phoneb~1.exe",x,c);
					  getchar();
					  clrscr();}
	else    wriup();				  }*/
/*------------------------------------------------------------------------------*/
/*void wriup()
{	FILE *q;
	float x;
	q=fopen(up,"wb");
	x=updat;
	fprintf(q,"%f",x);
	}*/
/*------------------------------------------------------------------------------*/
void virsion()
{	float x;
	char c[20];
	clrscr();
	x=updat;
	printf("\n\n\n\n\n\n\t\t\t\t\t\t   ***************\n\t\t\tThis is \"Program Virsion\": (  %f   )\n\t\t\t-------------------------- ***************\n\n\t\t\tWritten by: Shaolin\n\n\t\t\tContact address: sh.aolin@yahoo.com\n\n\t\t\t\t",x);
	getchar();
	getchar();
	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();
			  }
/*------------------------------------------------------------------------------*/
void tutorial()
{  char c[20];
	clrscr();
	printf("\n\t\t\t   If any problem rise :\n\t\t\t   .....................\n\n\t   1)  Make sure your computer has a drive named \"C\". Because\n\t\t\bthis prohram is suitable for only thouse computer has a\n\t\t\b\"C\" drive in hard disk.\n\n\t   2)  Problem like, General protection fault... Then be sure\n\t\t\byou have run setup.exe file at least 1 time before the 1st \n\t\t\buse of this programme. If not please run it now!!!\n\n\t   3)  Make sure u have got a valid password from the owner of\n\t\t\bthis program.\n\n\t   4)  For any problem please contact. Access \"About\" for contact\n\t\t\binformations from \"main menu\".\n  ");
	getchar();
	getchar();
	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();
	}
/*------------------------------------------------------------------------------*/
void out()
{	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\tThanks for using this programme\n\t\t\t...............................\n\t\t\t\t\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\b\b**Please close the window");
	exit(1);	}
/*------------------------------------------------------------------------------
--------------------------------------------------------------------------------
-----------------------------PERSONAL-------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------*/
void choice1(void)
{  char p[8];
	int x;
	clrscr();
	if(a==1)	{	printf("\n\n\n\n\n\n\n\n\n\t\t\t        ************\n\t\t\t        * PERSONAL *\n\t\t\t        ************\n\t\t\t\t      ");
					getchar();
					getchar();}
	a=2;
	clrscr();
	printf("\n                         ** PERSONAL **\n\nType  1: If you want to see all information\n\n      2: To save(protected)\n\n      3: To edit.\n\n      4: To erase\n\n      5: To go PHONE-BOOK menu\n\n      Any key: To exit\n\n\n      Type -> ");
	scanf("%d",&x);
	switch(x){
	case 1:{clrscr();
			  all1();
			  break;
			  }
	case 2:{clrscr();printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)!=0) {printf("sorry your passored is wrong!!!");break;}
			  save1();
			  break;
			  }
	case 3:{clrscr();edit1();}
	case 4:{clrscr();erase1();}
	case 5:{clrscr();choice();}
	default :out();

	}
		 }
/*------------------------------------------------------------------------------*/
void save1()
{	int i;
	char a[20],c[20];
	FILE *u;
	u=fopen(file1,"ab");
	for(i=0;i<1;i++)
	{
	clrscr();
	printf("enter information:");
	scanf("%s",n[i].inf);
	fprintf(u,"%s \n",n[i].inf);
	}
	clrscr();
	printf("\n\n\n\n\n\n\n\t\t\t\tTaking entry....");
	getchar();
	getchar();
	clrscr();
	printf("Wanna to enter more? Press 'Y'.\nIf not press anykey.\n");
	scanf("%s",&a);
	fclose(u);
	if(strcmp("y",a)==0||strcmp("Y",a)==0) {load1();arr1();save1();}
//	fclose(u);
	load1();
	arr1();
	clrscr();
	printf("To go to \"PERSONAL MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice1();}

	}
/*------------------------------------------------------------------------------*/
void load1()
{  FILE *s;
	int i;
	s=fopen(file1,"rb");
	for(i=0;i<150;i++)
	{fscanf(s,"%s ",n[i].inf); }
	fclose(s);
	}
/*------------------------------------------------------------------------------*/
void all1()
{  FILE *t;
	int i,j;
	int k;
	char c[20];
	//char ch;
	load1();
	arr1();
	clrscr();
	t=fopen(file1,"rb");
	for(i=0;i<150;i++)
	{fscanf(t,"%s ",n[i].inf);
	 if(strlen(n[i].inf)==0) break;
	 }
	fclose(t);
	for(j=0,k=1;i>0;i--,j++)
	{//if(strlen(p[i].na)==0) break;
	 printf("%d) %s\n\n",k,n[j].inf);
	 k++;
	 }
	getchar();
	getchar();
	clrscr();
	printf("To go to \"PERSONAL MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice1();}
	else out();
	}
/*------------------------------------------------------------------------------*/
void arr1()
{  FILE *q;
	int i,j,k;
//	char c[12];
	struct personal temp;
	//load1();
	for(i=0;n[i].inf[0]!='\0';i++)
		{	for(j=i+1;n[j].inf[0]!='\0';j++)
			{for(k=0;k<strlen(n[i].inf);k++)
				{if((n[i].inf[k])>(n[j].inf[k]))
					{ temp=n[i];
					 n[i]=n[j];
					 n[j]=temp;
					 break;
					 }
				 else if(n[i].inf[k]<n[j].inf[k]) break;
					 }
						}
							}
	q=fopen(file1,"wb");
	for(i=0;n[i].inf[0]!='\0';i++)
		{ fprintf(q,"%s\n",n[i].inf);}
	fclose(q);
/*	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice1();}
	else exit(1);                       */
}

/*------------------------------------------------------------------------------*/
 void erase1()
{  int i,j,k,l;
	int x;
	char ch[20],c[20];
	load1();
	clrscr();

/*-----------------to view--------------*/
	FILE *t;
	t=fopen(file1,"rb");
	for(i=0;i<150;i++)
	{fscanf(t,"%s ",n[i].inf);
	 if(strlen(n[i].inf)==0) break;
	 }
	fclose(t);
	for(j=0,k=1;i>0;i--,j++)
	{printf("%d) %s\n",k,n[j].inf);
	 k++;
	 }
/*-------------------------------------*/

	printf("inter the number you want to erase -> ");
	scanf("%d",&x);
	clrscr();
	printf("Old information: %s\n\n\n\t\t\tWarning: Next step will permanently remove the name.\n\t\t\tBECAUSIOUS\n\t\t\t..........",n[x-1].inf);
	getchar();getchar();
	printf("\t\tDO U WANNA PROCEDE???\n\t\tIf yes press \"y\"\n\t\tElse \"anykey\"\n\t\tType: ");
	scanf("%s",&c);
	if(strcmp("y",c)==0||strcmp("Y",c)==0)  { strcpy(n[x-1].inf," ");
															clrscr();
															printf("\n\n\n\n\n\n\n\t\t\t\tSucessfuly erased....");
															arr1();
															for(l=0;l<100;l++)
															{strcpy(n[l].inf,"\0");
																	}
															clrscr();
															printf("\n\n\n\n\n\n\n\t\t\t\tSucessfuly erased....");
															getchar();
															getchar();
															load();
															arr();
															}
	pass: clrscr();
	printf("Try another press \"E\".\n      To go to \"PERSONAL MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	if(strcmp("e",ch)==0||strcmp("E",ch)==0) {erase1();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice1();}
	else out();

	}
/*------------------------------------------------------------------------------*/
void edit1()
{  int i,j,k;
	int x,name;
	char ch[20];
	load1();
	clrscr();
/*-----------------to view--------------*/
	FILE *t;
	t=fopen(file1,"rb");
	for(i=0;i<150;i++)
	{fscanf(t,"%s ",n[i].inf);
	 if(strlen(n[i].inf)==0) break;
	 }
	fclose(t);
	for(j=0,k=1;i>0;i--,j++)
	{//if(strlen(p[i].na)==0) break;
	 printf("%d) %s\n",k,n[j].inf);
	 k++;
	 }
/*-------------------------------------*/

	printf("inter the number you want to edit -> ");
	scanf("%d",&name);
	clrscr();
	printf("Old information: %s\n\t\tPress 1 to edit.\n\t\tPress 2 to edit another.\n\t\tPress 3 to go main menu\n\t\tType-> ",n[name-1].inf);
	scanf("%d",&x);
	switch(x){
	case 1:	{ 	printf("enter new information:");
					scanf("%s",n[name-1].inf);
					clrscr();
					printf("\tYour entry is successfull.\n\n\tNew information:%d) %s",name,n[name-1].inf);
					arr1();
					break;
					}
	case 2:	{	clrscr();
					edit1();
					}
	case 3:	{	clrscr();
					choice1();
					}
	default:		choice1();

					}

	getchar();	getchar();
	clrscr();
	printf("      Try another press \"E\".\n      To go to \"PERSONAL MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	if(strcmp("e",ch)==0||strcmp("E",ch)==0) {edit1();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice1();}
	else out();

	}
/*------------------------------------------------------------------------------*/

/*------------------------------------DECLEARATIONS & FACILITIES------------------------------*/
/*
1) Personal information storeable facilities**
2) Floating update concious version.
3) Cradit informer virsion.
4) Some problem solving stakes included.
5) First almost all computer useable virsion (actually 1.01,102... virsion)
6) All most different than other virsions. so a unice or distinct virsion. a lots of new idea involved here
7) More safer virsion to store data than old virsions.
8) From now, other virsion's are dicleared as "old virsion" & it is strongly quoted that their update number & patern will not match with "new virsions" from now.
9) Now it contains the solution for pazel of dual last data at ereasing time & "information showing" prob. when more than one data inputed as save option
*/

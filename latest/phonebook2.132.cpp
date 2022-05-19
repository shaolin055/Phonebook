/*------------------------- 3,4,10,35,36,49-63,77,117,1016-1037-----------------*/
/*----------------------------------------Trial---------------------------------*/
/*----------------------------------------2.132---------------------------------*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define	updat	2.132
#define	max 500
/*------------------------------------------------------------------------------*/
void choice(void);
void save(void);
void set();
void sar(void);
void all(void);
void det(void);
void alls(void);
void edit();
void erase();
void rule(void);
void tutorial();
void update();
void arr();
int mlist(char a[]);
void decode(char a[]);
void encode1(char a[]);
int cheaker(char a[],char s[]);
void time1(char a[]);
void load(void);
//void load_(void);
int special(char name[],int k);
void fresh();
void encode(char a[]);
void initial();
/*------------------------------------------------------------------------------*/
void wriup();
void virsion();
void password1(void);
void out();
void font();
/*-----------------------------------------personal-----------------------------*/
void choice1(void);
void save1();
void load1();
void arr1();
void all1();
void erase1();
void edit1();
/*------------------------------------------------------------------------------*/
char file[60]  = "house.cat";
//char file_[60]  = "F:\\short.fat";
char file_1[60]  = "temp.cat";
char temp[60]	  = "tem.cat";
char up[60]    = "f:\\Phonebook\\upgrade.fat";
char file1[60]  ="information.cat";
char inf[60]	="setting.cat";
int a=1; //used not to show personal tag twice
int form=1;
int glob=0;//sequrity veriable
char q[8]="shaolin";
char r[20]="bangladesh";
char gen1[100]="\0";
char gen2[200]="\0";
char gen3[300]="\0";
/*------------------------------------------------------------------------------*/
struct phone{
	char na[131];
//	char ph[50];
//	char ad[80];
	};
phone huge p[1000];
/*------------------------------------------------------------------------------*/
/*struct personal{
	char inf[100];
	}n[50]; */
/*------------------------------------------------------------------------------*/
void main ()
{  update();
	choice();
	}
/*------------------------------------------------------------------------------*/
void choice(void)
{  char p[8];
	int x;
	if(a==1) {font();getchar();}
	a++;
	clrscr();
	printf("\n                         ** MAIN MENU **\n\nType  1: If you want to sarch\n\n      2: To save(protected)\n\n      3: Edit\n\n      4: Erase\n\n      5: To see DIRECTORY(protected)\n\n      6: Setting(Constracting)\n\n      7: For rules\n\n      8: For solving problem\n\n      9: About\n\n      Any key: Exit\n\n\n      Type -> ");
	scanf("%d",&x);
	switch(x){
	case 1:sar();break;
	case 2:{clrscr();
			  password1();
			  save();
			  break;  }
	case 3:{clrscr();
			  password1();
			  edit();
			  break;}
	case 4:{clrscr();
			  password1();
			  erase();
			  break;}
	case 5:{clrscr();printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)==0) {all();break;}
			  else if(strcmp(p,r)==0) {alls();break;}
			  clrscr();
			  printf("\n\n\n\n\n\n\t\t\t\tAccess is denied...\n\t\t\t\tPassored is wrong!!!");
			  break;}
	case 6:set();break;
	case 7:rule();break;
	case 8:tutorial();break;
	case 9:virsion();break;
	case 50:wriup();choice();break;
	case 100:load();arr();break;
	case 1000:a=1;choice1();
	default :out();

	}
		 }
/*------------------------------------------------------------------------------*/
void save()
{	int i;
	char a[20],c[20],tim[20],*temp1,*temp2,*temp3,none[10]=";";
	FILE *u;
	temp1= (char *) malloc(max);
	temp2= (char *) malloc(max);
	temp3= (char *) malloc(max);
	u=fopen(file,"ab");
	for(i=0;i<1;i++)
	{
	clrscr();
	time1(tim);
	decode(tim);
	printf("\nenter name:");
	scanf("%s",temp1);
	decode(temp1);
	printf("\n\nenter phone:");
	scanf("%s",temp2);
	decode(temp2);
	printf("\n\nenter address:");
	scanf("%s",temp3);
	decode(temp3);
	decode(none);
	fprintf(u,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,tim,none,none,none,none);
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
	free(temp1);
	free(temp2);
	free(temp3);
	load();
	arr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();

	}
/*------------------------------------------------------------------------------*/
void set()
{  int i=0,info,step;
	char p[20],a[20]="";
	FILE *u;
	u=fopen(inf,"rb");
	clrscr();
   det();
	printf("...........................Settings...............\n\n\n");
	again: if(i==0)	{	fscanf(u,"%s %d %d",a,&info,&step);
								printf("Description                status\n-----------                ------\n\n");
								//	fclose(u);
								if(a[0]=='*')	{printf("Show Date Created          Yes\n");}
								else	{printf("Show Date Created          No\n");}
								if(a[1]=='*')	{printf("\nShow Date Modified         Yes\n");}
								else	{printf("\nShow Date Modified         No\n");}
								if(a[2]=='*')	{printf("\nShow Status	    	   Yes\n");}
								else	{printf("\nShow Status		   No\n");}
								if(a[3]=='*')	{printf("\nShow Old information       Yes\n");}
								else	{printf("\nShow Old information       No\n");}
								printf("\n\nWanna change settings?\n\n");
								password1();
						  }
	fscanf(u,"%s %d %d",a,&info,&step);
	clrscr();
	fclose(u);
	printf("No     Description                status\n--      -----------                ------\n\n");
	if(a[0]=='*')	printf("1)     Show Date Created          Yes\n");
	else	printf("1)     Show Date Created          No\n");
	if(a[1]=='*')	printf("\n2)     Show Date Modified         Yes\n");
	else	printf("\n2)     Show Date Modified         No\n");
	if(a[2]=='*')	printf("\n3)     Show Status		  Yes\n");
	else	printf("\n3)     Show Status		  No\n");
	if(a[3]=='*')	printf("\n4)     Show Old information       Yes\n");
	else	printf("\n4)     Show Old information       No\n");
	printf("\nEnter 555 to exit*\nEnter numder you wanna change : ");
	scanf("%d",&i);
	if(i==555) {clrscr();choice();exit(1);}
	if(i!=1&&i!=2&&i!=3&&i!=4)	{printf("\nException in input occured. programme turminated");getchar();exit(1);}
	a[i-1]=a[i-1]%10*10+a[i-1]/10;
	i=7;
	u=fopen(inf,"wb");
	fprintf(u,"%s %d %d",a,info,step);
	fclose(u);
	u=fopen(inf,"rb");
	clrscr();
	det();
	goto again;

}
/*------------------------------------------------------------------------------*/
void sar()
{  int i,j,info,step,l=0,k=1,m=1,n=1;
	char name[20]="\0",phone[20]="\0",*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*phone_,*name_,ch[20],a[10];
	FILE *u,*v;
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	name_=(char*) malloc(20);
	phone_=(char*) malloc(20);
	clrscr();
	printf("inter the information you want to sarch : \n\n\tName -> ");
	gets(name);
	gets(name);
	strcpy(name_,name);
	if(strcmp(name,"\0")!=0) 	decode(name);
	printf("\n\tphone-> ");
	gets(phone);
	strcpy(phone_,phone);
	if(strcmp(phone,"\0")!=0)	decode(phone);
	clrscr();
	v=fopen(inf,"rb");
	fscanf(v,"%s %d %d",a,&info,&step);
	u=fopen(file,"rb");
	if(strcmp(name,"\0"))	printf("\n\t            ******************-***********************\n\t\t\t\b\bRESULT BAISED ON NAME: \" %s \"\n\t            ******************-***********************\n",name_);
	for(i=1;i<max;i++)
	{  strcpy(temp1,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);
		if(strlen(temp1)==0)   break;
		j=cheaker(temp1,name);
		if(j==1&&strcmp(name,"\0")) {      m=2;l++;
													  printf("\n\n   **   name -> ");
													  encode1(temp1);
													  encode(temp1);
													  printf("\n        phone -> ");
													  encode1(temp2);
													  encode(temp2);
													  printf("\n        address\e-mail -> ");
													  encode1(temp3);
													  encode(temp3);
													  if(a[0]=='*')	{printf("\n        Date created -> ");
																			 encode1(temp4);
																			 encode(temp4);
																			}
													  if(a[1]=='*')	{printf("\n        Date last modified -> ");
																			 encode1(temp5);
																			 encode(temp5);
																			 printf("\n");
																			}
													  if(a[3]=='*')	{printf("\n\t\tOld name -> ");
																			 encode1(temp6);
																			 encode(temp6);
																			 printf("\n\t\tOld phone -> ");
																			 encode1(temp7);
																			 encode(temp7);
																			 printf("\n\t\tOld Address -> ");
																			 encode1(temp8);
																			 encode(temp8);
																			 }

											  }
	 }
	 if(strcmp(name,"\0"))	{printf("\n\n\n * %d Search results\n\n\t\t\t. . . . . . . . . . . . . .\n\t\t\t. . . . . . . . . . . . . .\n\n",l);l=0;}
	 printf("\n\n");
	 fclose(u);
	 u=fopen(file,"rb");
	 if(strcmp(phone,"\0"))	printf("\n\t            ******************-***********************\n\t\t\t\b\bRESULT BAISED ON PHONE: \" %s \"\n\t            ******************-***********************\n",phone_);
	 for(i=1;i<max;i++)
	{       strcpy(temp2,"\0");
			  fscanf(u,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);
			  if(strlen(temp2)==0)   break;
			  k=cheaker(temp2,phone);
		if(k==1&&strcmp(phone,"\0")) {     n=2;l++;
													  printf("\n\n        name -> ");
													  encode1(temp1);
													  encode(temp1);
													  printf("\n    **  phone -> ");
													  encode1(temp2);
													  encode(temp2);
													  printf("\n        address\e-mail -> ");
													  encode1(temp3);
													  encode(temp3);
														if(a[0]=='*')	{printf("\n        Date created -> ");
																			 encode1(temp4);
																			 encode(temp4);
																			 }
													  if(a[1]=='*')	{printf("\n        Date last modified -> ");
																			 encode1(temp5);
																			 encode(temp5);
																			 printf("\n");
																			}
													  if(a[3]=='*')	{printf("\n\t\tOld name -> ");
																			 encode1(temp6);
																			 encode(temp6);
																			 printf("\n\t\tOld phone -> ");
																			 encode1(temp7);
																			 encode(temp7);
																			 printf("\n\t\tOld Address -> ");
																			 encode1(temp8);
																			 encode(temp8);
																			 }
											  }
	}
	 if(strcmp(phone,"\0"))	printf("\n\n\n * %d Search results\n\n\t     *************************><********************************\n\n\n",l);
	fclose(u);
	if(m==1&&n==1) {printf("Sorry nothing matched with directory contented.\n"); }
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
	free(name_);
	free(phone_);
	getchar();
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
	int i;
	char c[20],*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8;
	//char ch;
	temp1= (char *) malloc(max);
	temp2= (char *) malloc(max);
	temp3= (char *) malloc(max);
	temp4= (char *) malloc(max);
	temp5= (char *) malloc(max);
	temp6= (char *) malloc(max);
	temp7= (char *) malloc(max);
	temp8= (char *) malloc(max);
	clrscr();
	t=fopen(file,"rb");
	for(i=0;i<max;i++)
	{strcpy(temp1,"\0");
	 fscanf(t,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);
	 if(strlen(temp1)==0) break;
	 printf("%d) ",i+1);
	 encode1(temp1);
	 encode(temp1);
	 printf("\n\n");
	 }
	fclose(t);
	getchar();
	getchar();
	clrscr();
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();
	}
/*------------------------------------------------------------------------------*/
void det()
{  int i,j,maxline=370,steak=5,lin=0,brk=0,info=0,step=1;
	FILE *t,*u;
	char a[10]="",*temp;
	temp= (char *) malloc(500);
	t=fopen(file,"rb");
	u=fopen(inf,"rb");
	fscanf(u,"%s %d %d",a,&i,&j);
//	printf("%d %d",i,j);
	fclose(u);
	for(i=0;i<500;i++)
	{strcpy(temp,"\0");
	 fscanf(t,"%s %s %s %s %s %s %s %s\n",temp,temp,temp,temp,temp,temp,temp,temp);
	 if(strlen(temp)==0) break;
	}
	if(a[0]=='*') steak++;
	if(a[1]=='*') steak++;
	if(a[3]=='*') steak=steak+3;
	info=maxline/steak;
	lin=steak*i;
	brk=lin;
	for(i=0;i<5;i++)
	{	if(brk<=maxline)	break;
		brk=brk-info*steak;
		step++;
	}
	fclose(t);
	u=fopen(inf,"wb");
	fprintf(u,"%s %d %d",a,info,step);
	fclose(u);
}
/*------------------------------------------------------------------------------*/
void alls()
{  FILE *t,*u;
	int i,j,k,info=50,step=1;
	char sto,c[20],a[10],*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8;
	//char ch;
	temp1= (char *) malloc(max);
	temp2= (char *) malloc(max);
	temp3= (char *) malloc(max);
	temp4= (char *) malloc(max);
	temp5= (char *) malloc(max);
	temp6= (char *) malloc(max);
	temp7= (char *) malloc(max);
	temp8= (char *) malloc(max);
	clrscr();
	u=fopen(inf,"rb");
	fscanf(u,"%s %d %d",a,&info,&step);
	fclose(u);
	det();
	for(k=0;k<=10;k++)
	{  t=fopen(file,"rb");
		for(i=0,j=1;i<max&&j<=step;i++)
		{   strcpy(temp1,"\0");
			 fscanf(t,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);
			 if(strlen(temp1)==0) {break;}
			 printf("%d)\nName -> ",i+1);
			 encode1(temp1);
			 encode(temp1);
			 printf("\nContact Ad. -> ");
			 encode1(temp2);
			 encode(temp2);
			 printf("\nAddress\e-mail -> ");
			 encode1(temp3);
			 encode(temp3);
			 if(a[0]=='*')	{printf("\nDate created -> ");
								 encode1(temp4);
								 encode(temp4);
								 }
			 if(a[1]=='*')	{printf("\nDate last modified -> ");
								 encode1(temp5);
								 encode(temp5);
								}

			 if(a[3]=='*')	{printf("\n\t\tOld name -> ");
								 encode1(temp6);
								 encode(temp6);
								 printf("\n\t\tOld phone -> ");
								 encode1(temp7);
								 encode(temp7);
								 printf("\n\t\tOld Address -> ");
								 encode1(temp8);
								 encode(temp8);
								}
			 printf("\n\n");
			 if(i==info*j) { printf("Page %d of %d press 'Enter' to continue",j,step);
								  getchar();
								  getchar();
								  clrscr();
								  j++;
							   }
		}
	 fclose(t);
	 if(step==1) {break;}
	 printf("\nPress 'C' to see data again: ");
	 sto=getchar();
	 if(sto=='c'||sto=='C')	{clrscr();continue;}
	 clrscr();
    break;
	 }
//	getchar();
	getchar();
	clrscr();
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();
	}
/*------------------------------------------------------------------------------*/
void edit()
{  char name[20],ch[20],a[10];
	int i,j,k,info,step;
	int x;
	glob=0;
	char *temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9,*temp10,*temp11,*temp12,*temp13,*temp14,tim[20];
	FILE *u,*v,*w;
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	temp9=(char*) malloc(max);
	temp10=(char*) malloc(max);
	temp11=(char*) malloc(max);
	temp12=(char*) malloc(max);
	temp13=(char*) malloc(max);
	temp14=(char*) malloc(max);
	time1(tim);
	decode(tim);

	//load();
	clrscr();
	roll:printf("inter the name you want to edit -> ");
	scanf("%s",&name);
	decode(name);
	j=mlist(name);
	clrscr();
	w=fopen(inf,"rb");
	fscanf(w,"%s %d %d",a,&info,&step);
	fclose(w);
	u=fopen(temp,"rb");
	if(j==0)				{	printf("Sorry your name is not in directory.\n");getchar();getchar();goto pass;
							}
	else if(j!=0)	{	for(i=0;i<max;i++)
							{  strcpy(temp1,"\0");
								fscanf(u,"%d %s %s %s %s %s %s %s %s\n",&j,temp1,temp2,temp3,temp10,temp11,temp12,temp13,temp14);
								if(!strcmp(temp1,"\0"))		{break;}
								printf("\n\n%d)\tname -> ",j);
								encode1(temp1);
								encode(temp1);
								printf("\n  \tphone -> ");
								encode1(temp2);
								encode(temp2);
								printf("\n  \taddress\e-mail ->");
								encode1(temp3);
								encode(temp3);
								if(a[0]=='*')	{printf("\nDate created -> ");
													 encode1(temp10);
													 encode(temp10);
													}
								if(a[1]=='*')	{printf("\nDate last modified -> ");
													 encode1(temp11);
													 encode(temp11);
													}
								if(a[3]=='*')	{printf("\n\t\tOld name -> ");
													 encode1(temp12);
													 encode(temp12);
													 printf("\n\t\tOld phone -> ");
													 encode1(temp13);
													 encode(temp13);
													 printf("\n\t\tOld Address -> ");
													 encode1(temp14);
													 encode(temp14);
													 }
							}
							fclose(u);
							if(i>1)	{	printf("\n\nWhich one u wanna edit? Give number-> ");
											scanf("%d",&i);
										}
							clrscr();
							u=fopen(temp,"rb");
							for(k=0,j=0;k<max;k++)
							{			fscanf(u,"%d %s %s %s %s %s %s %s %s\n",&j,temp1,temp2,temp3,temp10,temp11,temp12,temp13,temp14);
										if(!strcmp(temp1,"\0"))  break;
										if(j==i) {again:printf("Old information:\nname -> ");
															 encode1(temp1);
															 encode(temp1);
															 decode(temp1);
															 printf("\nphone -> ");
															 encode1(temp2);
															 encode(temp2);
															 decode(temp2);
															 printf("\naddress\e-mail ->");
															 encode1(temp3);
															 encode(temp3);
															 decode(temp3);
															 if(a[0]=='*')	{printf("\nDate created -> ");
																				 encode1(temp10);
																				 encode(temp10);
																				 decode(temp10);
																				}
															 if(a[1]=='*')	{printf("\nDate last modified -> ");
																				 encode1(temp11);
																				 encode(temp11);
																				 decode(temp11);
																				}
															 if(a[3]=='*')	{printf("\n\t\tOld name -> ");
																				 encode1(temp12);
																				 encode(temp12);
																				 printf("\n\t\tOld phone -> ");
																				 encode1(temp13);
																				 encode(temp13);
																				 printf("\n\t\tOld Address -> ");
																				 encode1(temp14);
																				 encode(temp14);
																				}
															 glob++;
															 /*if(glob>4)	{	 getchar();
																				 getchar();
																				 clrscr();
																				 printf("\n\n\n\n\t\t\tTracking too much intraption in same information....\n\n\t\t\tRestarting programme.");
																				 getchar();
																				 glob=0;
																				 clrscr();
																				 choice();
																				 }   */
															 printf("\n\t\t\tIf wanna to change name press 1\n\t\t\tif phone press 2\n\t\t\tIf address press 3\n\t\t\tIf nothing press 4\n\t\t\ttype: ");
															 scanf("%d",&x);
															 if(x==1||x==2||x==3) {if(glob>4)	{	 getchar();
																				 getchar();
																				 clrscr();
																				 printf("\n\n\n\n\t\t\tTracking too much intraption in same information....\n\n\t\t\tRestarting programme.");
																				 getchar();
																				 getchar();
																				 glob=0;
																				 clrscr();
																				 choice();
																				 }
																				 }
															 switch(x){
																case 1:{ printf("enter new name:");
																			scanf("%s",temp7);
																			decode(temp7);
																			strcpy(temp8,temp2);
																			strcpy(temp9,temp3);
																			strcpy(temp11,tim);
																			strcpy(temp12,temp1);
																			break;
																		 }
																case 2:{ printf("enter new phone:");
																			scanf("%s",temp8);
																			decode(temp8);
																			strcpy(temp9,temp3);
																			strcpy(temp7,temp1);
																			strcpy(temp11,tim);
																			strcpy(temp13,temp2);
																			break;
																		 }
																case 3:{ printf("enter new address:");
																			scanf("%s",temp9);
																			decode(temp9);
																			strcpy(temp7,temp1);
																			strcpy(temp8,temp2);
																			strcpy(temp11,tim);
																			strcpy(temp14,temp3);
																			break;
																		 }
																case 4:{ pass: clrscr();
																			remove(temp);
																			printf("To edit another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
																			scanf("%s",&ch);
																			if(strcmp("e",ch)==0||strcmp("E",ch)==0) {load();clrscr();goto roll;}
																			else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
																			else {out();}
																		 }
																default: exit(1);
																 }
																 v=fopen(file,"ab");
																 fprintf(v,"%s %s %s %s %s %s %s %s\n",temp7,temp8,temp9,temp10,temp11,temp12,temp13,temp14);
																 fclose(v);
																 load();
																 arr();
																 v=fopen(file,"rb");
																 for(k=0;k<max;k++)
																 {strcpy(temp4,"\0");
																  fscanf(v,"%s %s %s %s %s %s %s %s\n",temp4,temp5,temp6,temp10,temp11,temp12,temp13,temp14);
																  //printf("%s %s %s \n",temp4,temp1,temp7);
																  if(!strcmp(temp4,"\0"))    break;
																  if(strcmp(temp4,temp1)==0&&strcmp(temp5,temp2)==0&&strcmp(temp6,temp3)==0)		{	 fclose(v);
																																												 /*v=fopen(file,"ab");
																																												 fprintf(v,"%s %s %s \n",temp7,temp8,temp9);
																																												 fclose(v);
																																												 load();
																																												 arr(); */
																																												 for(;;k++)
																																												 {if(!strcmp(p[k+1].na,"\0"))	{strcpy(p[k].na,"\0");
																																																						 break;}
																																												  strcpy(p[k].na,p[k+1].na);
																																												 }
																																												 /*for(k=0;k<10;k++)
																																												 {printf("%s\n",p[k].na);} */
																																												 strcpy(gen1,temp1);
																																												 strcpy(gen2,temp2);
																																												 strcpy(gen3,temp3);
																																												 //printf("%s %s %s\n",gen1,gen2,gen3);
																																												 //form=1;
																																												 fresh();
																																												 /*getchar();
																																												 getchar();  */
																																												 strcpy(temp1,"\0");
																																												 strcpy(temp2,"\0");
																																												 strcpy(temp3,"\0");
																																												 /*v=fopen(file,"ab");
																																												 fprintf(v,"%s %s %s \n",temp7,temp8,temp9);
																																												 fclose(v);
																																												 load();
																																												 arr();
																																												 getchar();
																																												 getchar(); */
																																												 v=fopen(file,"rb");
																																												 for(i=0;i<max;i++)
																																												 {strcpy(temp1,"\0");
																																												  fscanf(v,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,temp10,temp11,temp12,temp13,temp14);
																																												  if(!strcmp(temp1,"\0"))		{break;}
																																												  if(strcmp(temp7,temp1)==0&&strcmp(temp8,temp2)==0&&strcmp(temp9,temp3)==0)	{strcpy(temp4,"\0");
																																																																						 strcpy(temp5,"\0");
																																																																						 strcpy(temp6,"\0");
																																																																						 strcpy(temp7,"\0");
																																																																						 strcpy(temp8,"\0");
																																																																						 strcpy(temp9,"\0");
																																																																						 //strcpy(temp10,"\0");
																																																																						 //strcpy(temp11,"\0");
																																																																						 x=7;
																																																																						 goto again;
																																																																						}
																																												 }
																																												 fclose(v);
																																												 printf("Warning! Entry aborted !");
																																												 getchar();
																																												 getchar();
																																												 exit(1);
																																												 goto pass;
																																												 //break;
																																												}
																 }
													}
										  //	goto pass;
							}

						//	 	else continue;
						}
	fclose(u);
	remove(temp);
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
	free(temp9);
	free(temp10);
	free(temp11);
	free(temp12);
	free(temp13);
	free(temp14);
}
/*------------------------------------------------------------------------------*/
 void erase()
{  int i,j,k;
 //	int x;
	char name[20],ch[20],c[20],*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9,*temp10,*temp11;
	FILE *u,*v;
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	temp9=(char*) malloc(max);
	temp10=(char*) malloc(max);
	temp11=(char*) malloc(max);

	load();
	clrscr();
	printf("inter the name you want to erase -> ");
	scanf("%s",&name);
	decode(name);
	j=mlist(name);
	clrscr();
	u=fopen(temp,"rb");
	if(j==0)	{printf("Sorry your name is not in directory.\n");getchar();getchar();}
	else if(j!=0)	{	for(i=0;i<max;i++)
							{  strcpy(temp1,"\0");
								fscanf(u,"%d %s %s %s %s %s %s %s %s\n",&j,temp1,temp2,temp3,temp7,temp8,temp9,temp10,temp11);
								if(!strcmp(temp1,"\0"))		{break;}
								printf("\n\n%d)\tname -> ",j);
								encode1(temp1);
								encode(temp1);
								printf("\n  \tphone -> ");
								encode1(temp2);
								encode(temp2);
								printf("\n  \taddress\e-mail ->");
								encode1(temp3);
								encode(temp3);

							}
							fclose(u);
							if(i>1)	{	printf("\n\nWhich one u wanna erase? Give number-> ");
											scanf("%d",&i);
										}
							clrscr();
							u=fopen(temp,"rb");
							for(k=0,j=0;k<max;k++)
							{        fscanf(u,"%d %s %s %s %s %s %s %s %s\n",&j,temp1,temp2,temp3,temp7,temp8,temp9,temp10,temp11);
										if(j==i) {  	 printf("Old information:\nname -> ");
															 encode1(temp1);
															 encode(temp1);
															 decode(temp1);
															 printf("\nphone -> ");
															 encode1(temp2);
															 encode(temp2);
															 decode(temp2);
															 printf("\naddress\e-mail ->");
															 encode1(temp3);
															 encode(temp3);
															 decode(temp3);
															 printf("\n\n\n\t\t\tWarning: Next step will permanently remove the name.\n\t\t\tBECAUSIOUS\n\t\t\t..........");
															 getchar();
															 printf("\t\tDO U WANNA PROCEDE???\n\t\tIf yes press \"y\"\n\t\tElse \"anykey\"\n\t\tType: ");
															 scanf("%s",c);
															 if(strcmp("y",c)==0||strcmp("Y",c)==0)  { v=fopen(file,"rb");
																													 for(j=0;j<max;j++)
																													 {fscanf(v,"%s %s %s %s %s %s %s %s\n",temp4,temp5,temp6,temp7,temp8,temp9,temp10,temp11);
																													 if(strcmp(temp4,temp1)==0&&strcmp(temp5,temp2)==0&&strcmp(temp6,temp3)==0)		{for(;;j++)
																																																								 {if(!strcmp(p[j+1].na,"\0"))	{strcpy(p[j].na,"\0");
																																																																		 break;}
																																																								  strcpy(p[j].na,p[j+1].na);
																																																								 }
																																																								 strcpy(gen1,temp1);
																																																								 strcpy(gen2,temp2);
																																																								 strcpy(gen3,temp3);
																																																								 fresh();
																																																								 break;
																																																								}
																													 }
																													 //mofile(temp1,temp2,temp3,temp4,temp5,temp6);
																													 fclose(v);
																													 clrscr();
																													 printf("\n\n\n\n\n\n\n\t\t\t\tSucessfuly erased....");
																													 getchar();
																													 getchar();
																												  }
															 goto pass;
													 }
										else continue;
							}
					}
	pass: clrscr();
	printf("Try another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
	scanf("%s",&ch);
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
	free(temp9);
	free(temp10);
	free(temp11);
	fclose(u);
	remove(temp);
	if(strcmp("e",ch)==0||strcmp("E",ch)==0) {erase();}
	else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
	else out();

	}

/*------------------------------------------------------------------------------*/
void rule()
{  clrscr();
	char c[20];
	printf("\n\t\t\t     SOME INSTRACTIONS : \n\n\t   1)  This programme is case insensitive .\n\n\t   2)  After input, press enter.\n\n\t   3)  Don't put a space when putting a string. It will hamper\n\t       the internal stracture. Better put a ';'. The programme\n\t       will automatically convert it to a space. If you  wanna\n\t       putting  a ';' use ';;' . And ';;;' for a double space.\n\t       and ';;;; for a ' ;'.\n\n\t   4)  When exit please  close the  window, it does not close\n\t       automatically\n\n\t   5)  It is just a programme for personal using purpuse...\n\n\t   6)  In the virsion number,  \"zero\" after  point, means this \n\t       programme is suitatable for all computer.\n\n\t   7)  Use setting option to see extra informations\n");
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
	printf("\n\t\t\t   If any problem rise :\n\t\t\t   .....................\n\n\t   1)  If phone book is not showing any saved information, Notice \n\t\t\bwhather or not  Phonebook.exe and the sink.cat files stay\n\t\t\btogether.If not,copy sink.cat and past in the Phonebook.exe\n\t\t\bfolder.Sink.cat holds all informations so be carefull to\n\t\t\bhandle it.\n\n\t   2)  Make sure u have got a valid password from the owner of\n\t\t\bthis program.\n\n\t   3)  For any problem please contact. Access \"About\" for contact\n\t\t\binformations from \"main menu\".\n  ");
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

void update()
{	FILE *q;
	float x,c;
	q=fopen(up,"rb");
	fscanf(q,"%f",&c);
//	printf("%f",c);
	x=updat;
	if(x<c) {printf("\n\n\n\t\t\t\tNOTE\n\t\tIt is not letest virsion of phone book.\n\t\tUpdate please.\n\t\tThis is virsion: %f\n\t\tNew virsion: %f\n\t\tLink: F:\\c\\Phonebook\\latest\\phoneb~1.exe",x,c);
					  getchar();
					  clrscr();}
	else    wriup();
	fclose(q);			  }
/*------------------------------------------------------------------------------*/
void arr()
{  //FILE *q;
	int i,j,k;
//	char c[12];
	struct phone temp;
	for(i=0;i<max;i++)
	{	encode1(p[i].na);
		//encode1(p[i].ph);
		//encode1(p[i].ad);
		}
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
		//printf("%s\n",p[i].na);
							}
//	q=fopen(file_,"wb");
		for(i=0;i<max;i++)
	{	decode(p[i].na);
	}
/*	for(i=0;p[i].na[0]!='\0';i++)
		{ fprintf(q,"%d %s\n",i+1,p[i].na);}
	fclose(q);  */
	fresh();
	clrscr();
/*	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();     *///solution to save function problem//
}
/*..............................................................................*/
int mlist(char a[])
{  int i,j=0;
	char *temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8;
	FILE *u,*v;
	temp1=(char*) malloc(max);
	temp2=(char*) malloc(max);
	temp3=(char*) malloc(max);
	temp4=(char*) malloc(max);
	temp5=(char*) malloc(max);
	temp6=(char*) malloc(max);
	temp7=(char*) malloc(max);
	temp8=(char*) malloc(max);
	u=fopen(file,"rb");
	v=fopen(temp,"wb");
	for(i=0;i<max;i++)
	{  strcpy(temp1,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);
		if(!strcmp(temp1,"\0"))		break;
		else if(cheaker(temp1,a))	{	 j++;
										 fprintf(v,"%d %s %s %s %s %s %s %s %s\n",j,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8);
										 }
	}
	fclose(u);
	fclose(v);
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(temp8);
	if(j==0) return 0;
	else return 1;
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
/*------------------------------------------------------------------------------*/
void load()
{  int i;
	char *temp1,*temp2;
	FILE *u;
	//initial();
	temp1= (char *) malloc(max);
	temp2= (char *) malloc(max);
	strcpy(temp1,"\0");
	strcpy(temp2,"\0");
	u=fopen(file,"rb");
	for(i=0;i<max;i++)
	{strcpy(p[i].na,"\0");
	 fscanf(u,"%s %s %s %s %s %s %s %s\n",p[i].na,temp1,temp2,temp1,temp1,temp2,temp2,temp2);
	 if(strlen(p[i].na)==0) break;
	 //printf("load %s %s %s\n",p[i].na,temp1,temp2);
	 }
	 fclose(u);
	 free(temp1);
	 free(temp2);

}
/*..............................................................................*/
/*void load_()
{  int i,j=0;
	FILE *u;
	u=fopen(file_,"rb");
	for(i=0;i<200;i++)
	{fscanf(u,"%d %s",j,p[i].na);
	 if(strlen(p[i].na)==0) break;
	 }
	 fclose(u);

} */
/*------------------------------------------------------------------------------*/
int special(char name[],int k)
{  int i,j=0;
	char *name_,*pho_,*ad_,*oname,*opho,*oad,tim[20],mod[20];
	FILE *u;
	name_= (char *) malloc(max);
	pho_= (char *) malloc(max);
	ad_= (char *) malloc(max);
	oname= (char *) malloc(max);
	opho= (char *) malloc(max);
	oad= (char *) malloc(max);
	u=fopen(file,"rb");
	for(i=0;i<max&&k>0;i++)
	{	fscanf(u,"%s %s %s %s %s %s %s %s\n",name_,pho_,ad_,tim,mod,oname,opho,oad);
		if(!strcmp(name_,gen1)&&!strcmp(pho_,gen2)&&!strcmp(ad_,gen3)&&form==1)  {form=0;j=1;continue;}
		if(!strcmp(name_,name))	{k--; }
	}
	fclose(u);
	u=fopen(file_1,"ab");
	fprintf(u,"%s %s %s %s %s %s %s %s\n",name_,pho_,ad_,tim,mod,oname,opho,oad);
//	printf("1 %s %s %s %s %s %s\n",name_,pho_,ad_,gen1,gen2,gen3);
	fclose(u);
	free(name_);
	free(pho_);
	free(ad_);
	free(oname);
	free(opho);
	free(oad);
	if(j==1) {j=0;return 1;}
	else return 0;
}
/*..............................................................................*/
void fresh()
{	int i,j,l,k=1,x=0;
	char *name,*pho,*ad,*name_="\0",*pho_="\0",*ad_="\0",*oname,*opho,*oad,tim[20],mod[20];
	FILE *u,*v;
	v=fopen(file_1,"wb");
	fclose(v);
//	v=fopen(file_1,"ab");
	name= (char *) malloc(max);
	pho= (char *) malloc(max);
	ad= (char *) malloc(max);
	name_= (char *) malloc(max);
	pho_= (char *) malloc(max);
	ad_= (char *) malloc(max);
	oname= (char *) malloc(max);
	opho= (char *) malloc(max);
	oad= (char *) malloc(max);
	strcpy(name_,"\0");
	strcpy(pho_,"\0");
	strcpy(name_,"\0");
	for(i=0;i<max;i++)
	{  if(strlen(p[i].na)==0) break;
		u=fopen(file,"rb");
		if(!strcmp(name_,p[i].na))  {fclose(u);
											  k++;
											  x=special(name_,k);
											  k=k+x;
											  /*v=fopen(file_1,"ab");*/
											  continue;
											  }
		k=1;
		strcpy(name_,p[i].na);
		v=fopen(file_1,"ab");
		for(l=0;l<max;l++)
		{  //printf("2 , %d\n",l);	//For testing purpuse
			fscanf(u,"%s %s %s %s %s %s %s %s\n",name,pho,ad,tim,mod,oname,opho,oad);
			if(strlen(name)==0) {break;}
			j=strcmp(name,p[i].na);
			//printf("\n%d\n",i);
			//if(strcmp(name,gen1)==0&&strcmp(pho,gen2)==0&&strcmp(ad,gen3)==0&&form==1)  {printf("oao\n");}
			if(j==0&&strcmp(name,"\0")) {	if(strcmp(name,gen1)==0&&strcmp(pho,gen2)==0&&strcmp(ad,gen3)==0&&form==1)  {form=0;
																																						  k++;
																																						  continue;
																																						 }
													fprintf(v,"%s %s %s %s %s %s %s %s\n",name,pho,ad,tim,mod,oname,opho,oad);
													//printf("2 %s %s %s\n",name,pho,ad);
													//printf("2 %d %d %d %d  %s %s %s \n",form,x,y,z,p[i].na,pho,ad);
													//printf("%d %s %s\n",i+1,toc,temp); //For testing purpuse
													break;}
		}
		fclose(v);
		fclose(u);
	 }
//	 fclose(v);
	 u=fopen(file_1,"rb");
/*	 for(l=0;l<20;l++)
	 {  //printf("2 , %d\n",l);	//For testing purpuse
			strcpy(name,"\0");
			fscanf(u,"%s %s %s\n",name,pho,ad);
			if(strlen(name)==0) {break;}
			printf("%s %s %s\n",name,pho,ad); }    */
	 fclose(u);
//	 getchar();
//	 getchar();
	 free(name);
	 free(pho);
	 free(ad);
	 free(name_);
	 free(pho_);
	 free(ad_);
	 free(oname);
	 free(opho);
	 free(oad);
	 remove(file);
	 rename(file_1,file);
	 remove(file_1);
	 form=1;
}

/*------------------------------------------------------------------------------*/
void encode(char a[])
{	int i;
	for(i=0;;i++)
		{	if(a[i]=='\0') break;
			if(a[i]==';') {   if(a[i+1]==';'&&a[i+2]==';'&&a[i+3]==';') {printf(" ;");i=i+3;}
									else if(a[i+1]==';'&&a[i+2]==';') {printf("  ");i=i+2;}
									else if(a[i+1]==';')			  {printf(";");i++;}
									else printf(" ");}
			else if(a[i]=='\\') {if(a[i+1]=='n')	{printf("\n");i++;}
										else if(a[i+1]=='t')	{printf("\t");i++;}
										else printf("\\");
										}
			else printf("%c",a[i]);
		}
		}
/*------------------------------------------------------------------------------*/
void initial()
{	int i;
	for(i=0;i<max;i++)
	{strcpy(p[i].na,"\0");
	}
	}
/*------------------------------------------------------------------------------*/
void wriup()
{	FILE *q;
	float x;
	q=fopen(up,"wb");
	x=updat;
	fprintf(q,"%f",x);
	fclose(q);
	}
/*------------------------------------------------------------------------------*/
void virsion()
{	float x;
	char c[20];
	clrscr();
	x=updat;
	printf("\n\n\n\n\n\n\t\t\t\t\t   ***************\n\t\tThis is \"Program Virsion\": (  %f   )\n\t\t-------------------------- ***************\n\n\t\tWritten by: Shaolin using language 'C'\n\n\t\tContact address: sh.aolin@yahoo.com\n\n\t\tSpecial thanks to: Builder, Turbo C++ virsion 4.5\n\n\t\t\t\t",x);
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
void password1(void)
{  char p[8];
	printf("Enter passored please: ");
	scanf("%s",p);
	if(strcmp(p,q)!=0) {clrscr();printf("\n\n\n\n\n\n\t\t\t\tAccess is denied...\n\t\t\t\tPassored is wrong!!!");exit(1);}

}
/*------------------------------------------------------------------------------*/
void out()
{	clrscr();
	printf("\n\t\t ______________________________________\n\t\t|\\ ____________________________________\\");
	printf("\n\t\t| |\\____________________________________\\");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |    Thanks for using this book\t|");
	printf("\n\t\t| | |    ...... ... ..... .... ....\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t| | |\t\t\t\t\t|");
	printf("\n\t\t \\| |\t\t\b\b**Please close the window |");
	printf("\n\t\t   \\|___________________________________|\n\t\t\t\t\t\b\b");
	exit(1);	}
/*------------------------------------------------------------------------------*/
void font()
{  printf("\n\n\n\t\t _____________________._______________________\n\t\t|\\ ___________________:______________________/|");
	printf("\n\t\t| |\\__________________:____________________/| |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |   PHONE BOOK\t\b\b|   \t\t  | | |");
	printf("\n\t\t| | |   ===== ====\t\b\b|   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      |   \t\t  | | |");
	printf("\n\t\t| | |\t\t      | Virsion: %f | | |",updat);
	printf("\n\t\t \\| |\t\t      |   \t\t  | |/");
	printf("\n\t\t   \\|_________________|___________________|/\n\t\t\t\t\t\b\b");
}
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
					getchar();
					clrscr();printf("\n\t\t\t\tPassword protected\n\t\t\t\t........ .........\n\n\n\nEnter passored please: ");
					scanf("%s",p);
					if(strcmp(p,r)!=0) {clrscr();printf("\n\n\n\n\n\n\t\t\t\tAccess is denied...\n\t\t\t\tPassored is wrong!!!");exit(1);}
					}
	a=2;
	clrscr();
	printf("\n                         ** PERSONAL **\n\nType  1: If you want to see all information\n\n      2: To save(protected)\n\n      3: To edit.\n\n      4: To erase\n\n      5: To go PHONE-BOOK menu\n\n      Any key: To exit\n\n\n      Type -> ");
	scanf("%d",&x);
	initial();
	switch(x){
	case 1:{clrscr();
			  all1();
			  break;
			  }
	case 2:{clrscr();printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,r)!=0) {clrscr();printf("\n\n\n\n\n\n\t\t\t\tAccess is denied...\n\t\t\t\tPassored is wrong!!!");break;}
			  save1();
			  break;
			  }
	case 3:{clrscr();edit1();}
	case 4:{clrscr();erase1();}
	case 5:{clrscr();initial();choice();}
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
	scanf("%s",p[i].na);
	decode(p[i].na);
	fprintf(u,"%s \n",p[i].na);
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
	for(i=0;i<50;i++)
	{fscanf(s,"%s ",p[i].na); }
	fclose(s);
	}
/*------------------------------------------------------------------------------*/
void arr1()
{  FILE *q;
	int i,j,k;
//	char c[12];
	struct phone temp;
	//load1();
	for(i=0;i<50;i++)
	{	encode1(p[i].na);}
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
	q=fopen(file1,"wb");
	for(i=0;i<50;i++)
		{	decode(p[i].na);
		}
	for(i=0;p[i].na[0]!='\0';i++)
		{ fprintf(q,"%s\n",p[i].na);}
	fclose(q);
/*	clrscr();
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice1();}
	else exit(1);                       */
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
	{fscanf(t,"%s ",p[i].na);
	 if(strlen(p[i].na)==0) break;
	 }
	fclose(t);
	for(j=0,k=1;i>0;i--,j++)
	{//if(strlen(p[i].na)==0) break;
	 printf("%d) ",k);
	 encode1(p[j].na);
	 encode(p[j].na);
	 printf("\n\n");
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
 void erase1()
{  int i,j,k,l;
	int x;
	char ch[20],c[20];
	load1();
	clrscr();

/*-----------------to view--------------*/
	FILE *t;
	t=fopen(file1,"rb");
	for(i=0;i<50;i++)
	{fscanf(t,"%s ",p[i].na);
	 if(strlen(p[i].na)==0) break;
	 }
	fclose(t);
	for(j=0,k=1;i>0;i--,j++)
	{printf("%d) ",k,p[j].na);
	 encode1(p[j].na);
	 encode(p[j].na);
	 decode(p[j].na);
	 printf("\n");
	 k++;
	 }
/*-------------------------------------*/

	printf("inter the number you want to erase -> ");
	scanf("%d",&x);
	clrscr();
	printf("Old information: ");
	encode1(p[x-1].na);
	encode(p[x-1].na);
	decode(p[x-1].na);
	printf("\n\n\n\t\t\tWarning: Next step will permanently remove the name.\n\t\t\tBECAUSIOUS\n\t\t\t..........");
	getchar();getchar();
	printf("\t\tDO U WANNA PROCEDE???\n\t\tIf yes press \"y\"\n\t\tElse \"anykey\"\n\t\tType: ");
	scanf("%s",&c);
	if(strcmp("y",c)==0||strcmp("Y",c)==0)  { strcpy(p[x-1].na," ");
															clrscr();
															printf("\n\n\n\n\n\n\n\t\t\t\tSucessfuly erased....");
															arr1();
															for(l=0;l<100;l++)
															{strcpy(p[l].na,"\0");
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
/*-----------------to view-------------*/
	FILE *t;
	t=fopen(file1,"rb");
	for(i=0;i<150;i++)
	{fscanf(t,"%s ",p[i].na);
	 if(strlen(p[i].na)==0) break;
	 }
	fclose(t);
	for(j=0,k=1;i>0;i--,j++)
	{//if(strlen(p[i].na)==0) break;
	 printf("%d) ",k);
	 encode1(p[j].na);
	 encode(p[j].na);
	 decode(p[j].na);
	 printf("\n");
	 k++;
	 }
/*-------------------------------------*/

	printf("inter the number you want to edit -> ");
	scanf("%d",&name);
	clrscr();
	printf("Old information: ");
	encode1(p[name-1].na);
	encode(p[name-1].na);
	decode(p[name-1].na);
	printf("\n\t\tPress 1 to edit.\n\t\tPress 2 to edit another.\n\t\tPress 3 to go main menu\n\t\tType-> ");
	scanf("%d",&x);
	switch(x){
	case 1:	{ 	printf("enter new information:");
					scanf("%s",p[name-1].na);
					decode(p[name-1].na);
					clrscr();
					printf("\tYour entry is successfull.\n\n\tNew information:%d) ",name);
					encode1(p[name-1].na);
					encode(p[name-1].na);
					decode(p[name-1].na);
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
5) First almost all computer useable virsion (actually 1.01,102,103... virsion)
6) Al-most different than other virsions. so a unice or distinct virsion. a lots of new idea involved here
7) More safer virsion to store data than old virsions.
8) From now, other virsion's are dicleared as "old virsion" (specificaly before 1.13) & it is strongly recomanded that their update number & patern will not match with "new virsions" from now.
9) Now it contains the solution for pazzul of dual last data at ereasing time & "information showing" prob. when more than one data inputed as save option
10) It is a 'C' class programme, without graphics & run time memory allocation as well as no control of governing system process
11) week programme at all.
1.14) Improved search option
1.15) More handy search option.//(25-10-08)// But provlem is: it has problem to show first stored data. later sub virtion will have the solution
1.16) Encoder added to show better information. so far, for entering information, careness should be taken into account. Fome this virtion virtual "space" "new line" "tab" can be added with the input statement using special code(* for space, *** for dual space, \n for new line, \t for tab).(03/03/09)
1.16) Changed all() function.(03/03/09)

1.17) Codec added!!! So informations are sequre now. Trial virsion will be tested for some days. Then the permanent virsion will be relesed. (06/03/09)
		*** Recomanded relese date: 20/03/09
The most serrious problem is unavailable memory smaller than 64KB.

coming soon... : 1) Multiple erase option


Virsion "2" series:::::(relese date: 04/04/2009 04:56:00 PM)

I am glad to relese the "2" series of the personal phone book.
Here i have introduced some fundamental change, which will be discussed later.
It offers:
1) More secure data storage code.
2) Solution to the main fundamental problem on shortage of memory.
3) Multiple "Edit" and "Erase" opption.
4) Two way of directory display.
5) Solution of prob: 1.15 included

The "2" series will not match with privious virsions. All things are different from now.

Problems:
1) It is a trial virsion.
2) It cann't work with deeper folder than main drive like "C" "D" "E" "F". So directory like: "c\\phone\\phone.fat" is immpossible to operate.
3) It is not a graphical programme, so not good to see.

I wish these problems will meet to the end in near future.

2.12) Extra information of date created included. Extra option : 'setting' included to initialize setup as expected.
2.121) using handy ';' instide of '*' for space operator.(directory: f:\\sink.cat)
2.13) Now this programme is case insestivive. use ur case and enjoy urself!!!
2.131) Here the directory will be created where the .exe file is located.


next version contains: 1) Hidden information mode
							  2) Comand line facilitys
*/

/*------------------------- 3,4,10,35,36,49-63,77,117,1016-1037-----------------*/
/*----------------------------------------Trial---------------------------------*/
/*----------------------------------------3.000---------------------------------*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define	updat	3.000
#define	max 500
/*------------------------------------------------------------------------------*/
void filename();
void choice(void);
void cha_name();
void save(void);
void refresh();
void paste(char a[],char b[]);
void add(char x1[],char x2[],char x3[],char inf1[],char inf2[],char inf3[],char inf4[],char inf5[]);
void strcat_(char c[],char a[],char b[]);
void set();
void sar(void);
void all(void);
void det(void);
void alls(void);
void edit();
void delete_(char x1[],char x2[],char x3[]);
void erase();
void rule(void);
void tutorial();
void update();
int mlist(char a[]);
void decode(char a[]);
void encode1(char a[]);
int cheaker(char a[],char s[]);
void time1(char a[]);
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
char file[60]  = "data\\house.cat";
//char file_[60]  = "F:\\short.fat";
char file_1[60]  = "temp.cat";
char temp[60]	  = "data\\tem.cat";
char _file[20]="data\\house_.cat";
char up[60]    = "f:\\Phonebook\\upgrade.fat";
char file1[60]  ="data\\information.cat";
char inf[60]	="data\\setting.cat";
int a=1; //used not to show personal tag twice
int form=1;
int glob=0;//sequrity veriable
char q[8]="shaolin";
char r[20]="bangladesh";
char gen1[100]="\0";
char gen2[200]="\0";
char gen3[300]="\0";
char none[4]=";";
/*------------------------------------------------------------------------------*/
struct phone{
	char na[200];
//	char ph[50];
//	char ad[80];
	};
phone huge p[600];
/*------------------------------------------------------------------------------*/
/*struct personal{
	char inf[100];
	}n[50]; */
/*------------------------------------------------------------------------------*/
void main ()
{  update();
	filename();
	choice();
	}
/*------------------------------------------------------------------------------*/
void filename()
{	if(fopen(file,"rb")==NULL)
		{ strcpy(file,"house.cat");
		  strcpy(_file,"house_.cat");
		  strcpy(temp,"tem.cat");}
	if(fopen(file1,"rb")==NULL)
		{strcpy(file1,"information.cat");}
	if(fopen(inf,"rb")==NULL)
		{strcpy(inf,"setting.cat");}
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
	case 100:refresh();break;
	case 559:cha_name();break;
	case 1000:a=1;choice1();
	default :out();

	}
		 }

/*------------------------------------------------------------------------------*/
void cha_name()
{	if(fopen(_file,"rb")!=NULL)	{remove(file);
											 rename(_file,file);
											}
}
/*------------------------------------------------------------------------------*/
void save()
{	int i;
	char a[20],c[20],tim[20],*temp1,*temp2,*temp3;
	temp1= (char *) malloc(max);
	temp2= (char *) malloc(max);
	temp3= (char *) malloc(max);
	for(i=0;i<1;i++)
	{
	clrscr();
	time1(tim);
	printf("\nenter name:");
	scanf("%s",temp1);
	printf("\n\nenter phone:");
	scanf("%s",temp2);
	printf("\n\nenter address:");
	scanf("%s",temp3);
	}
	add(temp1,temp2,temp3,tim,none,none,none,none);
	clrscr();
	printf("\n\n\n\n\n\n\n\t\t\t\tTaking entry....");
	getchar();
	getchar();
	clrscr();
	printf("Wanna to enter more? Press 'Y'.\nIf not press anykey.\n");
	scanf("%s",&a);
	if(strcmp("y",a)==0||strcmp("Y",a)==0) {save();}
	clrscr();
	free(temp1);
	free(temp2);
	free(temp3);
	printf("To go to \"MAIN MENU\" press \"M\"\nTo exit press anykey.\n\n ->");
	scanf("%s",&c);
	if(strcmp("m",c)==0||strcmp("M",c)==0) {	clrscr();
															choice();}
	else out();

	}

/*------------------------------------------------------------------------------*/
void set()
{  int i=0,info,step;
	char a[20]="";
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
	double id;
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
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
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
													  /*if(a[0]=='*')	{printf("\n        Date created -> ");
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
																			 }        */

											  }
	 }
	 if(strcmp(name,"\0"))	{printf("\n\n\n * %d Search results\n\n\t\t\t. . . . . . . . . . . . . .\n\t\t\t. . . . . . . . . . . . . .\n\n",l);l=0;}
	 printf("\n\n");
	 fclose(u);
	 u=fopen(file,"rb");
	 if(strcmp(phone,"\0"))	printf("\n\t            ******************-***********************\n\t\t\t\b\bRESULT BAISED ON PHONE: \" %s \"\n\t            ******************-***********************\n",phone_);
	 for(i=1;i<max;i++)
	{       strcpy(temp2,"\0");
			  fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
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
													  /*	if(a[0]=='*')	{printf("\n        Date created -> ");
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
																			 }        */
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
	double id;
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
	 fscanf(t,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
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
	double id;
	temp= (char *) malloc(500);
	t=fopen(file,"rb");
	u=fopen(inf,"rb");
	fscanf(u,"%s %d %d",a,&i,&j);
//	printf("%d %d",i,j);
	fclose(u);
	for(i=0;i<500;i++)
	{strcpy(temp,"\0");
	 fscanf(t,"%s %s %s %s %s %s %s %s %lf\n",temp,temp,temp,temp,temp,temp,temp,temp,&id);
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
	double id;
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
			 fscanf(t,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
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
    getchar();
	 sto=getchar();
	 if(sto=='c'||sto=='C')	{clrscr();continue;}
	 clrscr();
    break;
	 }
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
void edit()
{  char name[20],ch[20],a[10];
	int i,j,k,info,step;
	int x;
	glob=0;
	char *temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9,*temp10,*temp11,*temp12,*temp13,*temp14,tim[20];
	double id;
	FILE *u,*w;
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
	for(i=0;i<max;i++)
	{  strcpy(temp1,"\0");
		fscanf(u,"%d %s %s %s %s %s %s %s %s %lf\n",&j,temp1,temp2,temp3,temp10,temp11,temp12,temp13,temp14,&id);
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
	if(i>j) {goto pass;}
	clrscr();
	u=fopen(temp,"rb");
	for(k=0,j=0;k<max;k++)
	{	fscanf(u,"%d %s %s %s %s %s %s %s %s %lf\n",&j,temp1,temp2,temp3,temp10,temp11,temp12,temp13,temp14,&id);
		if(!strcmp(temp1,"\0"))  break;
		if(j==i) {	again:printf("Old information:\nname -> ");
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
											 decode(temp12);
											 printf("\n\t\tOld phone -> ");
											 encode1(temp13);
											 encode(temp13);
											 decode(temp13);
											 printf("\n\t\tOld Address -> ");
											 encode1(temp14);
											 encode(temp14);
											 decode(temp14);
											}
                  glob++;
						break;
					}
	}
	fclose(u);
	remove(temp);
	printf("\n\n*********************     *******************************\n\nIf wanna to change name press 1\n\t\t\tif phone press 2\n\t\t\tIf address press 3\n\t\t\tIf nothing press 4\n\t\t\ttype: ");
	x=0;
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

	  switch(x){	case 1:{ printf("enter new name:");
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
															//remove(temp);
															printf("To edit another press \"E\".\n      To go to \"MAIN MENU\" press \"M\".\n      To exit press anykey.\n\n      -> ");
															scanf("%s",&ch);
															if(strcmp("e",ch)==0||strcmp("E",ch)==0) {clrscr();goto roll;}
															else if(strcmp("m",ch)==0||strcmp("M",ch)==0) {clrscr();choice();}
															else {goto end;}
														 }
												default: exit(1);
											}
							  encode1(temp1);
							  encode1(temp2);
							  encode1(temp3);
							  encode1(temp7);
							  encode1(temp8);
							  encode1(temp9);
							  encode1(temp10);
							  encode1(temp11);
							  encode1(temp12);
							  encode1(temp13);
							  encode1(temp14);
							  encode1(tim);
							  delete_(temp1,temp2,temp3);
							  add(temp7,temp8,temp9,temp10,tim,temp12,temp13,temp14);
							  decode(temp1);
							  decode(temp2);
							  decode(temp3);
							  decode(tim);
							  decode(temp10);
							  decode(temp11);
							  decode(temp12);
							  decode(temp13);
							  decode(temp14);
							  strcpy(temp1,temp7);
							  strcpy(temp2,temp8);
							  strcpy(temp3,temp9);
//							  strcpy(temp11,tim);
							  strcpy(temp7,"\0");
							  strcpy(temp8,"\0");
							  strcpy(temp9,"\0");
							  clrscr();
							  goto again;
end:	free(temp1);
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
	out();
}
/*------------------------------------------------------------------------------*/
 void erase()
{  int i,j,k;
 //	int x;
	char name[20],ch[20],c[20],*temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9,*temp10,*temp11;
	double id;
	FILE *u;
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

	clrscr();
	printf("inter the name you want to erase -> ");
	scanf("%s",&name);
	decode(name);
	j=mlist(name);
	clrscr();
	u=fopen(temp,"rb");
	if(j==0)	{printf("Sorry your name is not in directory.\n");getchar();getchar();goto pass;}
	for(i=0;i<max;i++)
	{  strcpy(temp1,"\0");
		fscanf(u,"%d %s %s %s %s %s %s %s %s %lf\n",&j,temp1,temp2,temp3,temp7,temp8,temp9,temp10,temp11,&id);
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
	if(i>j) {goto pass;}
	clrscr();
	u=fopen(temp,"rb");
	for(k=0,j=0;k<max;k++)
	{        fscanf(u,"%d %s %s %s %s %s %s %s %s %lf\n",&j,temp1,temp2,temp3,temp7,temp8,temp9,temp10,temp11,&id);
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
									 break;
							}
	}
	fclose(u);
	printf("\n\n\n\t\t\tWarning: Next step will permanently remove the name.\n\t\t\tBECAUSIOUS\n\t\t\t..........");
	getchar();
	printf("\n\t\tDO U WANNA PROCEDE???\n\t\tIf yes press \"y\"\n\t\tElse \"anykey\"\n\t\tType: ");
	scanf("%s",c);
	if(strcmp("y",c)==0||strcmp("Y",c)==0)  {	encode1(temp1);
															encode1(temp2);
															encode1(temp3);
															delete_(temp1,temp2,temp3);
															clrscr();
															printf("\n\n\n\n\n\n\n\t\t\t\tSucessfuly erased....");
														 }
	//mofile(temp1,temp2,temp3,temp4,temp5,temp6);
	getchar();
	getchar();

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
void refresh()
{  char *na_,*na1_,*na__,*na1__,*temp1,*temp2,*temp3,*temp1_,*temp2_,*temp3_,*temp4,*temp5,*temp6,*temp7,*temp8,*temp9;
//	int i,j,k;
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
	paste(_file,file);
	u=fopen(_file,"rb");
	v=fopen(file_1,"wb");

	clrscr();
	printf("\n\n\n\n\n\tRefresing data store... ...");

	for(a=0;;a++)
	{  count=1.0;
		strcpy(temp1,"\0");
		strcpy(temp2,"\0");
		strcpy(temp3,"\0");
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
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
			if(a==b) {	fscanf(w,"%s %s %s %s %s %s %s %s %lf\n",temp1_,temp2_,temp3_,temp9,temp9,temp9,temp9,temp9,&id);
							continue;
						}
			fscanf(w,"%s %s %s %s %s %s %s %s %lf\n",temp1_,temp2_,temp3_,temp9,temp9,temp9,temp9,temp9,&id);
			//printf("%s %s\n",na,na1);
			if(strlen(temp1_)==0) {break;}
			encode1(temp1_);
			encode1(temp2_);
			encode1(temp3_);
			strcat_(na1_,temp1_,temp2_);
			strcat_(na1__,na1_,temp3_);
			if(strcmp(na__,na1__)>0)   {count=count+1.0;}
		 }
//		 printf("\n\n");
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
remove(_file);
rename(temp,_file);
clrscr();
printf("\n\n\n\tTo ensure the process press 559 in the main menue. ");
getchar();
getchar();
choice();
}
/*------------------------------------------------------------------------------*/
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
/*------------------------------------------------------------------------------*/
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
							printf("Fatal error! \nType: Disorder found in data stake.\nOrder redestribution recomanded and the task is performing now...");
							fclose(u);
							getchar();
							getchar();
                     refresh();
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
	decode(x1);
	decode(x2);
	decode(x3);
	decode(temp4_);
	decode(temp5_);
	decode(temp6_);
	decode(temp7_);
	decode(temp8_);

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
/*------------------------------------------------------------------------------*/
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
                     clrscr();
							printf("Fatal error! \nType: Disorder found in data stake.\nOrder redestribution recomanded and the task is performing now...");
							fclose(u);
							getchar();
							getchar();
                     refresh();
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
/*------------------------------------------------------------------------------*/
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
void rule()
{  clrscr();
	char c[20];
	printf("\n\t\t\t     SOME INSTRACTIONS : \n\n\t   1)  This programme is case insensitive .\n\n\t   2)  After input, press enter.\n\n\t   3)  Don't put a space when putting a string. It will hamper\n\t       the internal stracture. Better put a ';'. The programme\n\t       will automatically convert it to a space. If you  wanna\n\t       putting  a ';' use ';;' . And ';;;' for a double space.\n\t       and ';;;; for a ' ;'.\n\n\t   4)  When exit please  close the  window, it does not close\n\t       automatically\n\n\t   5)  It is just a programme for personal using purpuse...\n\n\t   7)  Use setting option to see extra informations\n");
	getchar();
	getchar();
	clrscr();
	choice();
}
/*------------------------------------------------------------------------------*/
void tutorial()
{  char c[20];
	clrscr();
	printf("\n\t\t\t   If any problem rise :\n\t\t\t   .....................\n\n\t   1)  If phone book is not showing any saved information, Notice \n\t\t\bwhather or not  Phonebook.exe and the house.cat files stay\n\t\t\btogether.If not,copy house.cat and past in the Phonebook.exe\n\t\t\bfolder.house.cat holds all informations so be carefull to\n\t\t\bhandle it.\n\n\t   2)  Make sure u have got a valid password from the owner of\n\t\t\bthis program.\n\n\t   3)  For any problem please contact. Access \"About\" for contact\n\t\t\binformations from \"main menu\".\n  ");
	getchar();
	getchar();
	clrscr();
	choice();
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

/*..............................................................................*/
int mlist(char a[])
{  int i,j=0;
	char *temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8;
	double id;
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
		fscanf(u,"%s %s %s %s %s %s %s %s %lf\n",temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,&id);
		if(!strcmp(temp1,"\0"))		break;
		else if(cheaker(temp1,a))	{	 j++;
										 fprintf(v,"%d %s %s %s %s %s %s %s %s %lf\n",j,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,id);
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
/*------------------------------------------------------------------------------*/
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
	choice();
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
	for(i=0;i<max;i++)
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
	for(i=0;i<max;i++)
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
	for(i=0;i<max;i++)
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
	for(i=0;i<max;i++)
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
	for(i=0;i<max;i++)
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
															for(l=0;l<max;l++)
															{strcpy(p[l].na,"\0");
																	}
															clrscr();
															printf("\n\n\n\n\n\n\n\t\t\t\tSucessfuly erased....");
															getchar();
															getchar();
															load1();
															arr1();
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
	for(i=0;i<max;i++)
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
							  3) New version of unlimited storage!!! No dependency on RAM.(now atmost 1000 storage is ligal.)

version "3" series::::(relese date 15/10/2009 06:37:00 pm)
preface: I am feeling comfortable to release version 3 series of personal "phone book". Though version "2"
series offered tremendous support for 1000 of storage data facility, but it was not world class.
In mobile phone 1000 is enough but infinite storage is a must for a computer system. As I thought of it, I felt
ashamed so I have desined this version. It is felxible and easier to understand.

It offers:
1) Theoritically unlimited storage facility.
2) Easy processing.
3) Actually small dependency on RAM.

problem:
1)	The arranging system is time erronious and can cause a high order loop continuty.
2) It is a trial virsion. Time will prove its efficiancy and performance.

*/

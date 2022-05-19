#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void main()
{  FILE *u,*v,*w;
	int pass=1;
	char file[20]="a.cat",file1[20]="temp.cat",na[30],ra[30],na1[30],ra1[30],na_[500]="\0",na1_[500]="\0";
	char x[]="shaolin",y[]="bios",x_[500]="\0";
	double i,j,k,a,b,z,len,id,temp,count=1;
	//strcpy(x_,strcat(x,y));
	u=fopen(file,"rb");
	for(i=1;;i++)
	{  strcpy(na,"\0");
		strcpy(ra,"\0");
		fscanf(u,"%s %s %lf\n",na,ra,&temp);
		if(strlen(na)==0) {break;}
		if(temp!=i)	{	pass=0;
							printf("Fatal error! \nType: Disorder found in data stake.\nOrder redestribution recomanded. Do u wanna do it now?\nThen press 'y': ");
							exit(1);
						}
	}
	len=i-1;
	fclose(u);
	u=fopen(file,"rb");
	v=fopen(file1,"wb");
	pass=0;
	for(i=1;i<=len;i++)
	{	strcpy(na,"\0");
		strcpy(ra,"\0");
		fscanf(u,"%s %s %lf\n",na,ra,&temp);
		if(strlen(na)==0) {break;}
		if(strcmp(x,na)==0&&strcmp(y,ra)==0) {	pass=1;temp=1;}
		if(pass==1)	{fprintf(v,"%s %s %lf\n",na,ra,temp-1);}
		else	{fprintf(v,"%s %s %lf\n",na,ra,temp);}

	}
	if(pass==0) {printf("No record found to delete named: %s",x);exit(1);}
	fclose(u);
	fclose(v);
	u=fopen(file,"wb");
	for(a=1;a<=len;a++)
	{  v=fopen(file1,"rb");
		for(b=1;b<=len;b++)
		{	strcpy(na,"\0");
			strcpy(ra,"\0");
			fscanf(v,"%s %s %lf\n",na,ra,&id);
			if(strlen(na)==0) break;
			if(id==a)	{fprintf(u,"%s %s %lf\n",na,ra,id);
							 break;
							}
		}
		fclose(v);
	}
	fclose(u);
	remove(file1);
}

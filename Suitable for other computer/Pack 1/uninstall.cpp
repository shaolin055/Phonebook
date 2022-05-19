#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{  char c[20],p[20],q[20]="987654";
	printf("\t\t\t\t\t\t\t\tstep:1 of 4\n\n\n\n\n\n\n\n\n\t\t\tUNINSTALASION PACK\n\t\t\t......................");
	getchar();
	clrscr();
	printf("\t\t\t\t\t\t\t\tstep:2 of 4\n\n\n\n\n\n\n\n\t\tR u sure u want to uninstall phonebook ?\n\t\t  All saved data will be errased.\n\t\t       So be causious... ");
	getchar();
	clrscr();
	printf("\t\t\t\t\t\t\t\tstep:3 of 4\n\n\n\n\n\t\tIf u wanna resume uninstall process press 'y' or any-key\n\n\t\t\t\t Type -> ");
	scanf("%s",c);
   clrscr();
	if(strcmp("y",c)!=0) { exit(1);}
	printf("Enter passored please: ");
			  scanf("%s",p);
			  if(strcmp(p,q)!=0) {printf("sorry your passored is wrong!!!");exit(1);}
	getchar();
	clrscr();
	if(remove("e:\\storage.cat")!=0||remove("e:\\information.cat")!=0||remove("e:\\setting.cat")!=0) {printf("\n\n\n\n\n\n\n\n\t\tThis programme is already uninstalled or never installed.");exit(1);}
	printf("\t\t\t\t\t\t\t\tstep:4 of 4\n\n\n\n\n\n\n\n\t\t\tUninstalled...\n\n\n\t\t\tThank u to select this programme.***\n\n\n\t\t\tPlease run setup.exe for reinstall it.");
	}

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int i=0;

FILE *fp, *ft;
char another, choice;

struct emp
{
char name[40];
int age;
char address[80];
float bs;
};

struct emp e;

char empname[40];

long int recsize;

fp = fopen("EMP.DAT","rb+");
if(fp == NULL)
{
fp = fopen("EMP.DAT","wb+");
if(fp == NULL)
{
printf("Connot open file");
exit(1);
}
}

recsize = sizeof(e);

while(1)
{

system("cls");
gotoxy(7,2);

printf("============================================
===============");
gotoxy(7,3);
printf(":::::::::::::EMPLOYEES RECORD MANAGEMENT
SYSTEM:::::::::::::");
gotoxy(7,4);

printf("============================================
===============");
gotoxy(15,5);
printf("Avalible chooices are:");
gotoxy(30,7);
printf("1) Add Employee's Records \n");
gotoxy(30,9);
printf("2) List Employee's Records \n");
gotoxy(30,11);
printf("3) Modify Employee's Records\n");

gotoxy(30,13);
printf("4) Delete Employee's Records\n");
gotoxy(30,15);
printf("5) Exit System \n");
gotoxy(15,16);
printf("Your Choice: ");
fflush(stdin);
choice = getche();
switch(choice)
{
case '1':
system("cls");
fseek(fp,0,SEEK_END);

another = 'y';
while(another == 'y')
{
printf("\nEnter name: ");
scanf("%s",e.name);
printf("\nEnter age: ");
scanf("%d", &e.age);

printf("\nEnter Address:");
scanf("%s",e.address);
printf("\nEnter basic salary: ");
scanf("%f", &e.bs);

fwrite(&e,recsize,1,fp);

printf("\nAdd another record(y/n) ");
fflush(stdin);
another = getche();
}
break;
case '2':
system("cls");
printf("EMPLOYEE's RECORD LIST (name, age, address,
salary)");
rewind(fp);
while(fread(&e,recsize,1,fp)==1)
{
printf("\n\n%s \t\t%d \t%s
\t%.2f",e.name,e.age,e.address,e.bs);
}

getch();
break;

case '3':
system("cls");
another = 'y';
while(another == 'y')
{
printf("Enter the employee name to modify: ");

scanf("%s", empname);
rewind(fp);
while(fread(&e,recsize,1,fp)==1)
{
if(strcmp(e.name,empname) == 0)
{
printf("\nEnter new name: ");
scanf("%s",e.name);
printf("\n Enter new age:");
scanf("%d",&e.age);
printf("\n Enter new address:");
scanf("%s",&e.address);
printf("\n Enter new salary:");

scanf("%f",&e.bs);
fseek(fp,-recsize,SEEK_CUR);
fwrite(&e,recsize,1,fp);
break;
}
}
printf("\nModify another record(y/n)");
fflush(stdin);
another = getche();
}
break;
case '4':
system("cls");
another = 'y';
while(another == 'y')
{
printf("\nEnter name of employee to delete: ");
scanf("%s",empname);
ft = fopen("Temp.dat","wb");
rewind(fp);
while(fread(&e,recsize,1,fp) == 1)
{

if(strcmp(e.name,empname) != 0)
{
fwrite(&e,recsize,1,ft);
}
}
fclose(fp);
fclose(ft);
remove("EMP.DAT");
rename("Temp.dat","EMP.DAT");
fp = fopen("EMP.DAT", "rb+");
printf("Delete another record(y/n)");
fflush(stdin);
another = getche();
}
break;
case '5':
fclose(fp);
exit(0);
}
}
return 0;
}
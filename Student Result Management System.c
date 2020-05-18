

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//***************************************************************

#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#define RETURNTIME 15

//***************************************************************
//                   FUNCTION USED IN PROJECT
//***************************************************************

void returnfunc(void);
void mainmenu(void);
void menu(void);
void result(void);
void classresult(void);
void individualresult(int);
void addstudent();
int getstudent();
void deletestudent(void);
void searchstudent(void);
void viewstudent(void);
void editstudent(void);
void closeapplication(void);
void divisonresult(void);
int  checkid(int);
int t(void);
void Password();
void issuerecord();
void loaderanim();
void returnfunc1(void);


//***************************************************************
//        GLOBAL DECLRATION
//****************************************************************

FILE *fp,*ft,*fs,*fptr;
COORD coord = {0, 0};
int s;
char findstaff;
char password[10]={"pass"};

//***************************************************************
//        GOTO DECLARATION AND FUNCTION
//****************************************************************

void gotoxy (int x, int y)
{
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//***************************************************************
//        DAY AND DATE DECLARATION AND FUNCTION
//****************************************************************

struct meroDate
{
	int mm,dd,yy;
};

//***************************************************************
//        STRUCTURE USED IN PROJECT
//****************************************************************

struct staff
{
     int id;
     char stname[20];
     int p_marks,c_marks,m_marks,e_marks,cs_marks;
     float per;
     char grade;
     int std;
     int count;
     char *cat;
     struct meroDate issued;
     struct meroDate duedate;
}a;

//***************************************************************
//        PASSWORD FUNCTION
//****************************************************************

int main()
{
    Password();
    getch();
    return 0;
}

//***************************************************************
//        MAIN MENU OF THE PROGRAM
//****************************************************************

void mainmenu()
{
     system("cls");
     int i;
     gotoxy(20,3);
     printf("\n\t\t\t\t  MCA MORNING \n\n ");
     printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
     gotoxy(20,5);
     printf("\n\n\n\n\t MAIN MENU\n");
     printf("      ______________\n");
     gotoxy(20,9);
     printf("\n\n\n\t01. RESULT MENU");
     gotoxy(20,11);
     printf("\n\n\n\t02. ENTRY/EDIT MENU");
     gotoxy(20,13);
     printf("\n\n\n\t03. EXIT");
     gotoxy(20,17);
     printf("\n\n\tPlease Select Your Option (1-3) ");
     gotoxy(20,22);
     switch(getch())
     {
             case '1':  result();
                        break;
              case '2': menu();
                        break;
              case '3': Password();
              default:
                          {
                            gotoxy(10,25);
                            printf("\aWrong Entry!!Please re-entered correct option");
                            if(getch())
                            mainmenu();
                          }
      }
}

//***************************************************************
//        RESULT MENU
//****************************************************************

void result()
{
    system("cls");
    char ans;
    int rno;
	gotoxy(20,3);
	printf(" \n\t\t\t\tWELCOME TO RESULT MENU \n ");
 	printf("\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
 	gotoxy(20,9);
	printf("<1> Class Result");
	gotoxy(20,11);
	printf("<2> Individual Student Result");
	gotoxy(20,13);
	printf("<3> Divisionwise Result");
	gotoxy(20,15);
	printf("<4> Back to Main Menu");
	gotoxy(20,19);
	printf("Enter your choice:");
	switch(getch())
	{
		case '1':   
					system("cls");
					classresult();
                    break;
		case '2':
                    {
                        do
                        {
                        	system("cls");
                            char ans;
                            gotoxy(20,3);
                            printf("\n\nEnter Roll Number Of Student : ");
                            scanf("%d",&rno);
                            individualresult(rno);
                            gotoxy(20,20);
                            printf("\n\nDo you want to See More Result (y/n)?");
                            scanf("%c",&ans);
                        }while(ans=='y'||ans=='Y');
                        break;
                    }
		case '3':   divisonresult();
                    break;
        case '4':   mainmenu();
                    break;
		default:
		{
			gotoxy(10,25);
			printf("\aWrong Entry!!Please re-entered correct option");
			if(getch())
			mainmenu();
		}
    }
}

//***************************************************************
//        CLASS RESULT
//****************************************************************

void classresult()
{
      system("cls");
      fptr=fopen("student.dat","rb");
      if(fptr==NULL)
      {
            gotoxy(20,3);
            printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
            gotoxy(20,5);
            printf("\n\n\n Program is closing ....");
            getch();
            exit(0);
      }
	int i=0,j;
	system("cls");
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbRecord List\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	gotoxy(2,2);
	printf("\n ID === NAME ==== SUB1 == SUB2 == SUB3 == SUB4 == SUB5 == PERCENTAGE === GRADE      ");
	j=4;
	fp=fopen("student.dat","rb");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		gotoxy(1,j);
		printf("%d",a.id);
		gotoxy(8,j);
		printf("%s",a.stname);
		gotoxy(19,j);
		printf("%d",a.p_marks);
		gotoxy(27,j);
		printf("%d",a.c_marks);
		gotoxy(34,j);
		printf("%d",a.m_marks);
		gotoxy(43,j);
		printf("%d",a.e_marks);
		gotoxy(51,j);
		printf("%d",a.cs_marks);
		gotoxy(59,j);
		printf("%f",a.per);
		gotoxy(75,j);
		printf("%c",a.grade);
		j++;
	}
	fclose(fp);
	gotoxy(35,25);
	returnfunc1();
}
void returnfunc1(void)
{
	{
	gotoxy(15,25);
	printf("Press ENTER to return to RESULT MENU ");
	}
	a:
	if(getch()==13)
	result();
	else
	goto a;
}



//***************************************************************
//        INDIVIDUAL RESULT
//****************************************************************

void individualresult(int n)
{
	system("cls");
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&a,sizeof(a),1,fptr))>0)
    {
     if(a.id==n)
        {
        	system("cls");
        	gotoxy(20,3);
            printf("\nRoll number of student : %d",a.id);
            gotoxy(20,5);
			printf("\nName of student : %s",a.stname);
            gotoxy(20,7);
			printf("\nMarks in Mathematical Structure in Computer Science : %d",a.p_marks);
            gotoxy(20,9);
			printf("\nMarks in Computer Organisation : %d",a.c_marks);
            gotoxy(20,11);
			printf("\nMarks in Database Managment System : %d",a.m_marks);
            gotoxy(20,13);
			printf("\nMarks in Linux Operating System : %d",a.e_marks);
			gotoxy(20,15);
            printf("\nMarks in Programming in C : %d",a.cs_marks);
            gotoxy(20,17);
            printf("\nPercentage of student is  : %.2f",a.per);
            gotoxy(20,19);
            printf("\nGrade of student is : %c",a.grade);
            flag=1;
        }
    }
    fclose(fptr);
    if(flag==0)
        printf("\n\n\t\t\t\tRECORD NOT EXIST");
    getch();
    returnfunc1();
}

//***************************************************************
//        DIVISION WISE RESULT
//****************************************************************

void divisonresult()
{
	system("cls");
	fptr=fopen("student.dat","rb");

    printf("\n\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb FIRST DIVISION \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    while((fread(&a,sizeof(a),1,fptr))>0)
    {
        if(a.per>=60)
        {
            printf("%d %s\n",a.id,a.stname);
        }
    }

    rewind(fptr);
    printf("\n\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb SECOND DIVISION \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    while((fread(&a,sizeof(a),1,fptr))>0)
    {
        if(a.per>=50 && a.per<60)
        {
            printf("%d %s\n",a.id,a.stname);
        }
    }

    rewind(fptr);
    printf("\n\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb THIRD DIVISION \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    while((fread(&a,sizeof(a),1,fptr))>0)
    {
        if(a.per>=40 && a.per<50)
        {
            printf("%d %s\n",a.id,a.stname);
        }
    }

    rewind(fptr);
    printf("\n\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb FOUTH DIVISION \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    while((fread(&a,sizeof(a),1,fptr))>0)
    {
        if(a.per<40)
        {
            printf("%d %s\n",a.id,a.stname);
        }
    }
	fclose(fptr);
	returnfunc1();
}

//***************************************************************
//        ENTRY/EDIT MENU
//****************************************************************

void menu()
{
	system("cls");
	int i;
	gotoxy(20,3);
	printf("\t\t WELCOME TO ENTRY/EDIT MENU \n ");
 	printf("\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
 	gotoxy(7,7);
	printf("<1> Create Students Records   ");
	gotoxy(7,9);
	printf("<2> Remove Student Records");
	gotoxy(7,11);
	printf("<3> Search Records");
	gotoxy(7,13);
	printf("<4> View Record's list");
	gotoxy(7,15);
	printf("<5> Modify Record");
	gotoxy(7,17);
	printf("<6> Back To Main Menu");
	gotoxy(7,19);
	printf("<7> Close Application");
	gotoxy(20,23);
	printf("Enter your choice:");
	switch(getch())
	{
		case '1':   addstudent();
                    break;
		case '2':   deletestudent();
                    break;
		case '3':   searchstudent();
                    break;
		case '4':   viewstudent();
                    break;
		case '5':   editstudent();
                    break;
        case '6':   mainmenu();
        			break;
		case '7':
                    {
                        system("cls");
                        gotoxy(16,3);
                        printf("\tMCA RESULT Management System");
                        gotoxy(16,4);
                        printf("\tProject in C");
                        gotoxy(16,5);
                        exit(0);
                    }
		default:
                    {
                        gotoxy(10,25);
                        printf("\aWrong Entry!!Please re-entered correct option");
                        if(getch())
                        menu();
                    }
	}
}

//***************************************************************
//        GET RECORDS OF STUDENT
//****************************************************************

int getstudent()
{
	int t;
	gotoxy(20,3);
	printf("Enter the Information Below");
	gotoxy(21,6);
    printf("ID:");
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
		gotoxy(21,13);
		printf("\aThe id already exists\a");
		getch();
		menu();
		return 0;
	}
	a.id=t;
	printf("\n\nThe ID:%d\n",a.id);
    printf("\nEnter name:");
	scanf("%s",&a.stname);
	printf("Enter marks in Mathematical Structure in Computer Science :");
	scanf("%d",&a.p_marks);
	printf("Enter marks in Computer Organisation :");
	scanf("%d",&a.c_marks);
	printf("Enter marks in Database Managment System :");
	scanf("%d",&a.m_marks);
	printf("Enter marks in Linux Operating System :");
	scanf("%d",&a.e_marks);
	printf("Enter marks in Programmin in C :");
	scanf("%d",&a.cs_marks);
	a.per=(((a.p_marks+a.c_marks+a.m_marks+a.e_marks+a.cs_marks)/500.0)*100);
    if(a.per>=60)
       a.grade='A';
    else if(a.per>=50 && a.per<60)
      a.grade='B';
    else if(a.per>=33 && a.per<50)
      a.grade='C';
    else
     a.grade='F';
    printf("The grade of Student is :");
    printf("%c",a.grade);
    return 1;
}
int checkid(int t)
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
        return 0;
	return 1;
}

//***************************************************************
//        ADD RECORDS OF STUDENT
//****************************************************************

void addstudent()
{
	system("cls");
	int i;
	fp=fopen("student.dat","ab+");
	if(getstudent()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&a,sizeof(a),1,fp);
		fclose(fp);
		gotoxy(40,18);
		printf("\nThe record is sucessfully saved\n");
		gotoxy(21,20);
		printf("\nSave any more?(Y / N):\n");
		if(getch()=='n')
            menu();
		else
            system("cls");
        addstudent();
	}
}


//***************************************************************
//        DELETE RECORDS OF STUDENT
//****************************************************************

void deletestudent()
{
	system("cls");
	int d;
	char another='y';
	while(another=='y')  
	{
		system("cls");
		gotoxy(10,5);
		printf("Enter the ID to  remove:");
		scanf("%d",&d);
		fp=fopen("student.dat","rb+");
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(a.id==d)
			{
				gotoxy(10,7);
				printf("The record is available");
				gotoxy(10,8);
				printf("Name is %s",a.stname);
				gotoxy(10,9);
				findstaff='t';	
			}
		}
	if(findstaff!='t')
	{
		gotoxy(10,10);
		printf("No record is found modify the search");
		if(getch())
		menu();
	}
	if(findstaff=='t' )
	{
		gotoxy(10,9);
		printf("Do you want to delete it?(Y/N):");
		if(getch()=='y')
		{
			ft=fopen("test.dat","wb+");  
			rewind(fp);
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(a.id!=d)
				{
					fseek(ft,0,SEEK_CUR);
					fwrite(&a,sizeof(a),1,ft); 
				}                              
			}
			fclose(ft);
			fclose(fp);
			remove("student.dat");
			rename("test.dat","stf.dat"); 
			fp=fopen("student.dat","rb+");    
			if(findstaff=='t')	
			{
				gotoxy(10,10);
				printf("The record is sucessfully deleted");
				gotoxy(10,11);
				printf("\n\tDelete another record?(Y/N)");
			}
		}
		else
		mainmenu();
		fflush(stdin);
		another=getch();
	}
}
gotoxy(10,15);
menu();
}


//***************************************************************
//        SEARCH RECORDS OF STUDENT
//****************************************************************

void searchstudent()
{
	system("cls");
	int d;
    printf("\n\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  Search Record  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	gotoxy(20,10);
	printf("1. Search By ID");
	gotoxy(20,12);
	printf("2. Go to Entry/Edit Menu");
	gotoxy( 20,20);
	printf("Enter Your Choice");
	fp=fopen("student.dat","rb+");
	rewind(fp);
	switch(getch())
	{
		case '1':
		{ 
			system("cls");
			gotoxy(25,2);
			printf("\xdb\xdb\xdb\xdb\xdb\xdb  Search By Id  \xdb\xdb\xdb\xdb\xdb\xdb");
			gotoxy(20,5);
			printf("Enter the id:");
			scanf("%d",&d);
			while(fread(&a,sizeof(a),1,fp)==1)
			{	
				if(a.id==d)
				{
					Sleep(2);
					gotoxy(5,10);
					printf("The Record is available\n");
					gotoxy(5,12);
					printf("ID: %d",a.id);
					gotoxy(5,14);
					printf("NAME: %s",a.stname);
					gotoxy(5,16);
					printf("Marks in Mathematical Structure in Computer Science: %d",a.p_marks);
					gotoxy(5,18);
					printf("Marks in Computer Organisation %d ",a.c_marks);
					gotoxy(5,20);
					printf("Marks in Database Managment System %d ",a.m_marks);
					gotoxy(5,22);
					printf("Marks in Linux Operating System %d",a.e_marks);
					gotoxy(5,24);
					printf("Marks in Programming in C %d",a.cs_marks);
					findstaff='t';
				}
			}	
			if(findstaff!='t')  
			{
				printf("\aNo Record Found");
			}
			gotoxy(20,26);
			printf("Try another search?(Y/N)");
			if(getch()=='y')
			searchstudent();
			else
			menu();
			break;
		} 
	case '2': 
			 menu();
			 break;
	default :
	getch();
	searchstudent();
	}
	fclose(fp);
}

//***************************************************************
//       DISPLAY RECORDS OF STUDENT
//****************************************************************

void viewstudent(void)
{
	int i=0,j;
	system("cls");
	gotoxy(1,1);
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbRecord List\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	gotoxy(2,2);
	printf("\n ID === NAME ==== SUB1 == SUB2 == SUB3 == SUB4 == SUB5 == PERCENTAGE === GRADE      ");
	j=4;
	fp=fopen("student.dat","rb");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		gotoxy(1,j);
		printf("%d",a.id);
		gotoxy(8,j);
		printf("%s",a.stname);
		gotoxy(19,j);
		printf("%d",a.p_marks);
		gotoxy(27,j);
		printf("%d",a.c_marks);
		gotoxy(34,j);
		printf("%d",a.m_marks);
		gotoxy(43,j);
		printf("%d",a.e_marks);
		gotoxy(51,j);
		printf("%d",a.cs_marks);
		gotoxy(59,j);
		printf("%f",a.per);
		gotoxy(75,j);
		printf("%c",a.grade);
		j++;
	}
	fclose(fp);
	gotoxy(35,25);
	returnfunc();
}

//***************************************************************
//        MODIFY RECORDS OF STUDENT
//****************************************************************

void editstudent(void)
{
  system("cls");
  int c=0;
  int d,e;
  char another='y';
  while(another=='y')
  {
	system("cls");
	printf("\n\n\nEnter Id to be edited:\t");
	scanf("%d",&d);
	fp=fopen("student.dat","rb+");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		if(checkid(d)==0)
		{
			printf("\n\nThis Member is available");
			printf("\n\nThe ID:%d\t\t\n",a.id);
			printf("\n\nEnter new name:");
			scanf("%s",&a.stname);
			printf("Enter new marks in Mathematical Structure in Computer Science :");
			scanf("%d",&a.p_marks);
			printf("Enter new marks in Computer Organisation :");
			scanf("%d",&a.c_marks);
			printf("Enter new marks in Database Managment System :");
			scanf("%d",&a.m_marks);
			printf("Enter new marks in Linux Operating System :");
			scanf("%d",&a.e_marks);
			printf("Enter new marks in Programmin in C :");
			scanf("%d",&a.cs_marks);
			printf("\n\n\t\t\tThe record is modified");
			a.per=(((a.p_marks+a.c_marks+a.m_marks+a.e_marks+a.cs_marks)/500.0)*100);
    		if(a.per>=60)
       		a.grade='A';
    		else if(a.per>=50 && a.per<60)
      		a.grade='B';
    		else if(a.per>=33 && a.per<50)
      		a.grade='C';
    		else
            a.grade='F';
			fseek(fp,ftell(fp)-sizeof(a),0);
			fwrite(&a,sizeof(a),1,fp);
			fclose(fp);
			c=1;
		}
		if(c==0)
		{
			printf("No record found");
		}
	}
	printf("\n\nModify another Record?(Y/N)");
	fflush(stdin);
	another=getch() ;
	}
	returnfunc();
}
void returnfunc(void)
{
	{
	gotoxy(15,25);
	printf("Press ENTER to return to Edit/Entry menu");
	}
	a:
	if(getch()==13)
	menu();
	else
	goto a;
}

//***************************************************************
//        DATE AND TIME FUNCTION
//****************************************************************

int t(void)
{
	time_t t;
	time(&t);
	printf("Date and time:%s\n",ctime(&t));
	return 0 ;
}

//***************************************************************
//        PASSWORD FUNCTION
//****************************************************************

void Password(void)
{
	system("cls");
	char d[25]="Password Protected";
	char ch,pass[10];
	int i=0,j;
	printf("\n\n\n\t\t\t\t  WELCOME\n\t\t\t\t    TO \n\t\t   \xdb\xdb\xdb\xdb\xdb\xdb MCA RESULT MANAGMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t \n\n\n\n Enter Password:");
	while(ch!=13)
	{
		ch=getch();
		if(ch!=13 && ch!=8)
		{
			putch('*');
			pass[i] = ch;
			i++;
		}
	}
	pass[i] = '\0';
	if(strcmp(pass,password)==0)
	{
		printf("\n\n\n\t\t\t\tPassword matched!!");
		printf("\n\n\t\t\tPress any key to countinue.....");
		getch();
		mainmenu();
	}
	else
	{
		printf("\n\n\n\t\t\t\     Warning!! \n\n\t\t\tIncorrect Password.....");
		getch();
		Password();
	}

}






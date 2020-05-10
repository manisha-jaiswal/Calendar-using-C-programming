#include<stdio.h>
#include<conio.h>
#include<math.h>
int all_month();
void specificMonth(int ,int);
int Day(int,int,int);
int Days(int);
int findmonth(int, int);
int weekday(int , int , int);
int daycode(int);
void help();
void end();

int ch;
    //STARTING MAIN FUNCTION---------------------------------------------------------
    int main()
	{
                  int dat, mont, years;
                 int c;
                             system("CLS");
                  	printf("\n\n \t\t\t\t************** WELCOME TO MY C PROJECT CALANDAR **************** \n ");
                  	printf("\t\t\t\t\t\t\t\t\t\t\t GROUP MEMBER: MANISHA AND SONI \n\n");
                  do
                  {
				              system("CLS");
                  	printf("\n\t\t\t\t\t 1: display all months \n\n\t\t\t\t\t 2: display specific month \n\n\t\t\t\t\t 3: display specific day\n\n\t\t\t\t\t 4: HELP \n\n\t\t\t\t\t 5: EXIT ");
					  printf("\n\n\t\t\t\t\t ENTER YOUR CHOICE :");
					    system("color 0f");
                  		scanf("%d",&c);
                  	switch(c)
                  	{
                  		case 1:all_month();//print all months 
                  		break;//end printing of all month
                  		
					 case 2:printf("\n\t\t\t\t\t________________________________");
					        printf("\n\n\t\t\t\t\t\tEnter the year : ");//print specific month
                            scanf("%d", &years);
                            printf("\n\t\t\t\t\t\t Enter the month : ");
                            scanf("%d", &mont);
                            printf("\n\t\t\t\t\t________________________________");
                            
                  specificMonth(mont,years);
                  break;
                  
					 case 3:printf("\n\t\t\t\t____________________________________");
					        printf("\n\n\t\t\t\t     Enter the year : ");//printf specific day name
                            scanf("%d", &years);
                            printf("\n\t\t\t\t     Enter the month :     ");
                            scanf("%d", &mont);
                            printf("\n\t\t\t\t     Enter the date :      ");
                            scanf("%d", &dat);
                            printf("\n\t\t\t\t_____________________________________\n");
                                    weekday(dat, mont, years);
                            break;
                  
                  case 4: help();//help
                  break;
                  
                  case 5:end();
                  break;
                  
                  default:printf("\t\t\t\t invalid criteria u have choosen \n");
                  break;
				  }
				   printf("\n\n\t\t\t\t DO YOU WANT TO CONTINUE(1/0): ");
				  scanf("%d",&ch);
				  
			}while(ch!=0);
				 
}//--------------------------CLOSING MAIN FUNCTION--------------------------------------------

//-----------------STARTING FIRST CASE TO PRINT ALL MONTHS IN A YEAR-----------------------------------------------------------------------
int all_month()
{
	int year,i,d;
	char month[12][10]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
    printf("\n\t\t\t\t\t_________________________________"); 
	printf("\n\n\t\t\t\t\t\tEnter Year : ");
	scanf("%d",&year);
	printf("\n\t\t\t\t\t_________________________________");
	printf("\n");
	d=daycode(year);
	for(i=1;i<=12;i++)	{
		printf("\n\t\t%s [%d]\n\n",month[i-1],year);
		printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
		d=Days(d);
		d=Day(d,i,year);
	}
}

int Day(int n,int mont,int years)
{
	int i,l;
	   l= findmonth(mont,years);
	
	for(i=2;i<=l;i++)	
	{
		if(n<=6) 
		{
			printf(" %d ",i);
			n++;
		}
		if(n<=6)
			printf("\t");
		else	{
			n=0;
			printf("\n");
		}
	}
	printf("\n");
	return (n);
}

int Days(int n)
{
	switch(n)
	{
		case 0:printf(" 1");	break;
		case 1:printf(" \t 1");	break;
		case 2:printf(" \t \t 1");		break;
		case 3:printf(" \t \t \t 1");	break;
		case 4:printf(" \t \t \t \t 1");	break;
		case 5:printf(" \t \t \t \t \t 1");	break;
		case 6:printf(" \t \t \t \t \t \t 1");	break;
	}
	n++;
	if(n==7)	{
		printf("\n");
		n=0;
	}
	else	printf("\t");
	return(n);
}
//--------------------------------CLOSING OF 1ST CASETO PRINT ALL THE MONTHS IN A YEAR-----------------------------------------------------

//------------*****************************STARTING 2ND CASE TO PRINT SPECIFIC MONTH***************************-------------------------------
void specificMonth(int mont,int years)
{ 
    
    
    	int i,d;
	char month[12][10]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
	d=daycode(years);
	for(i=1;i<=12;i++)	{
		if(i==mont)
		{
		
		printf("\n\t\t%s [%d]\n\n",month[i-1],years);
		printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
		d=Days(d);
		d=Day(d,i,years);
	}
	}
	
}
//--------------------**********************CLOSING OF 2ND CASE TO SPECIFY MONTH*********************------------
  //-------------------*****************STARTING  3RD CASE FOR SPECIFIC DATE **********************--------------------
int weekday(int date, int month, int year) {
           int dayWeek, yr, yd;
           yr = year % 100;
           yd = year / 100;
           printf("\nThe Date Given is : %d / %d / %d \n\n", date, month, year);
           dayWeek = 1.25 * yr + findm(month, year) + date - 2 * (yd % 4);
           dayWeek = dayWeek % 7;
           switch (dayWeek){
           case 0:  printf("Day of Week of the Date is : Saturday");
                        break;
           case 1:  printf("Day of Week of the Date is : Sunday");
                        break;
           case 2:  printf("Day of Week of the Date is : Monday");
                        break;
           case 3:  printf("Day of Week of the Date is : Tuesday");
                        break;
           case 4:  printf("Day of Week of the Date is : Wednesday");
                        break;
           case 5:  printf("Day of Week of the Date is : Thursday");
                        break;
           case 6:  printf("Day of Week of the Date is : Friday");
                        break;
           default:  printf("The Given input data is wrong");
           }
           return 0;
           }
    int findm(int months, int yearss){
           int findmonth, leapyr;
           if ((yearss % 100 == 0) && (yearss % 400 != 0))
           leapyr = 0;
           else if (yearss % 4 == 0)
           leapyr = 1;
           else
           leapyr = 0;
           findmonth = 3 + (2 - leapyr) * ((months + 2) / (2 * months))
+ (5 * months + months / 9) / 2;
           findmonth = findmonth % 7;
           return findmonth;
    }
    //closing 3rd case..*******************************************************

int daycode(int years)
{
int d1,d2,d3,daycode;
d1=(years - 1)/4;
	d2=(years - 1)/100;
	d3=(years - 1)/400;
	daycode=(years+d1-d2+d3) %7;
	return daycode;
}
//----------------------*************CLOSING DAYCODE FUNCTION**************-----------


int findmonth(int mont,int years)
{
	int l;
	if(mont==1 || mont==3 || mont==5 || mont==7 || mont==8 || mont==10 || mont==12)
	{
	
		l=31;
		return l;
	}
	else if(mont==4 || mont==6 || mont==9 || mont==11)
	{
	
		l=30;
			return l;
		}
	else if((years%100==0 && years%400==0) || (years%100!=0 && years%4==0))
	{
	
			l=29;
			return l;
		}
	else
	{	
	    l=28;
	    	return l;
	    }
}
void help()
{
	printf("\n\n\t\t\t\t\t***** WELCOME TO HELPING DESK ******\n ");
	printf("\n\t\t-------------------------------------------------------------------------");
	printf("\n\t\t Mini Project CALENDAR APPLICATION is also a simple project built in C.");
	printf("\n\t\t------------------------------------------------------------------------");
	printf("\n\n\t\t\t\t This Project has following features.");
	printf("\n\t\t\t****************************************************");
	printf("\n\n\t\t___________________________________________________________________________________________");
	printf("\n\n\t\t| 1: You enter the valid option given in this menu.                                       |");
	printf("\n\n\t\t| 2: If you donot give the valid option ,system can generated a invalid option message.   |");
	printf("\n\n\t\t| 3: you can choose a valid year ,month and name to get the CALENDAR.                     |");
	printf("\n\n\t\t| 4: Option 1: displays a nicely formatted calendar of EVERY MONTH by entering the year.  |");
	printf("\n\n\t\t| 5: Option 2: You can find the month by entering the year and month.                     |");
	printf("\n\n\t\t| 6: Option 3: You can find the particular day name by entering year , month , da         |");
	printf("\n\n\t\t| 7: if You want to continue , please press 1.                                            |");
	printf("\n\n\t\t| 8: if you want to exit . please press 0 or any key.                                     |");
	printf("\n\n\t\t| 9: THANKU TO VISIT MY PROJECT.                                                          |");
	printf("\n\n\t\t|_________________________________________________________________________________________|");
	
}
void end()
{
 
    end (1);
    
}

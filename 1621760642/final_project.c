
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int isLeapYear( int year );        /* True if leap year */
int leapYears( int year );         /* The number of leap year */
int todayOf( int y, int m, int d); /* The number of days since the beginning of the year */
long days( int y, int m, int d);   /* Total number of days */
void calendar(int y, int m);       /* display calendar at m y */

int main(void){
    int year,month,day,c;
    int choice;
    while(1){
        system("cls");
        printf("1. Find Out the Day\n");
        printf("2. Print all the day of month\n");
         printf("3. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        system("cls");
         switch(choice){
            case 1:
                printf("Enter the month and year: ");
                scanf("%d %d", &month, &year);

                calendar(year, month);
                printf("\nPress any key to continue......");
                getch();
                break;
            case 2:
                printf("Enter year:");
                    scanf("%d",&year);
                    printf("Enter month(1-12):");
                    scanf("%d",&month);
                    printf("Enter day:");
                    scanf("%d",&day);
                    printf("%d\\%d\\%d is ",day,month,year);
                    Zellercongruence(day, month, year); //date (dd/mm/yyyy)
                    printf("\nPress any key to continue......");
                getch();
                break;
                 case 3 :
                exit(0);
                }


    }

    return 0;
}


//for showining the day using zeller's
int Zellercongruence(int day, int month,
					int year)
{
if (month == 1)
{
	month = 13;
	year--;
}
if (month == 2)
{
	month = 14;
	year--;
}
int q = day;
int m = month;
int k = year % 100;
int j = year / 100;
int h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j;
h = h % 7;
switch (h)
{
	case 0 : printf("Saturday \n"); break;
	case 1 : printf("Sunday \n") ; break;
	case 2 : printf("Monday \n"); break;
	case 3 : printf("Tuesday \n"); break;
	case 4 : printf("Wedneday \n"); break;
	case 5 : printf("Thirsday \n"); break;
	case 6 : printf("Friday \n"); break;
}
return 0;
}


//month displaying...
int isLeapYear( int y ) /* True if leap year */
{
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int leapYears( int y ) /* The number of leap year */
{
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d) /* The number of days since the beginning of the year */
{
    static int DayOfMonth[] =
        { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};

    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}

long days( int y, int m, int d) /* Total number of days */
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}

void calendar(int y, int m) /* display calendar at m y */
{
    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su Mo Tu We Th Fr Sa";
    int DayOfMonth[] =
        { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days(y, m, 1) % 7;
    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        printf("%2d ",day);
        if(i % 7 == 6)
            printf("\n");
    }
    printf("\n");
}


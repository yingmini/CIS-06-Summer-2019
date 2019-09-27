/**
 * Program Name: cis6Summer2019YingLHw3Ex1.c
 * Discussion:	 Hw #4, Ex #1
 * Written By:	 Ying Hsuen Lin
 * Date:		 2019/07/11
 */

#include <stdio.h>

void displayClassInfoYingL(void);
int displayRunMenuYingL();
int displayAllDigitYingL(int);

int main()
{
	displayClassInfoYingL();
	displayRunMenuYingL();

	return 0;
}

void displayClassInfoYingL()
{
	printf("CIS 6 - Introductioin to C Programming\n"
		"Laney College\n"
		"Ying Hsuen Lin\n\n"
		"Assignment Information --\n"
		"  Assignment Number:  Homework 4,\n"
		"                      "
		"Coding Assignment -- Exercise #1\n"
		"  Written by:         Ying Hsuen Lin\n"
		"  Submitted Date:     2019/07/11\n\n\n");
}

int displayRunMenuYingL()
{
	int option;
	int usrValue;

	do
	{
		printf("******************************************\n"
			"*              MENU - HW #4              *\n"
			"*  (1) Calling displayAllDigitYingL()    *\n"
			"*  (2) Quit                              *\n"
			"******************************************\n");

		printf("Enter an integer for option + Enter: ");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			printf("\nEnter an integer: ");
			scanf_s("%d", &usrValue);

			printf("\nCalling displayAllDigitYingL()"
				" with argument of %d --\n\n",
				usrValue);

			displayAllDigitYingL(usrValue);

			break;
		case 2:
			printf("\nHave fun!\n");

			break;
		default:
			printf("\nWrong Option!\n\n\n");
		}
	} while (option != 2);
}

int displayAllDigitYingL(int usrValue)
{
	int option;
	int msd;
	int lsd;
	int countDigit = 0;
	int countEven = 0;
	int countOdd = 0;

	if (usrValue == 0)
	{
		printf("  The given value is ZERO!\n\n\n");
	}
	else
	{
		(usrValue >= 0) ? printf("  %d is a "
			"positive number.\n", 
			((usrValue > 0) ? usrValue : -usrValue)) :
			printf("  %d is a negative number.\n",
			((usrValue < 0) ? usrValue : -usrValue));

		option = usrValue;
		lsd = usrValue % 10;

		do {
			if (usrValue % 2 == 0) 
			{
				countEven++;
			}
			else 
			{
				countOdd++;
			}
			msd = usrValue % 10;

			countDigit++;
			usrValue /= 10;
		} while (usrValue);

		printf("  There is/are %d digit(s).\n", countDigit);
		printf("\n  The LSD is %d and the MSD is %d", 
			((lsd < 0) ? -lsd : lsd),
			((msd < 0) ? -msd : msd));

		printf("\n  And all digit(s) would be");
		do 
		{
			printf("\n    %d", 
				((option % 10 < 0) ? -option % 10 : option % 10));
			option /= 10;
		} while (option);

		printf("\n\n  There is/are %d even digit(s).", countEven);
		printf("\n  There is/are %d odd digit(s).\n\n\n", countOdd);
	}
}

/*Program Output
CIS 6 - Introductioin to C Programming
Laney College
Ying Hsuen Lin

Assignment Information --
  Assignment Number:  Homework 4,
                      Coding Assignment -- Exercise #1
  Written by:         Ying Hsuen Lin
  Submitted Date:     2019/07/11


******************************************
*              MENU - HW #4              *
*  (1) Calling displayAllDigitYingL()    *
*  (2) Quit                              *
******************************************
Enter an integer for option + Enter: 6

Wrong Option!


******************************************
*              MENU - HW #4              *
*  (1) Calling displayAllDigitYingL()    *
*  (2) Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: -9

Calling displayAllDigitYingL()with argument of -9 --

  -9 is a negative number.
  There is/are 1 digit(s).

  The LSD is 9 and the MSD is 9
  And all digit(s) would be
    9

  There is/are 0 even digit(s).
  There is/are 1 odd digit(s).


******************************************
*              MENU - HW #4              *
*  (1) Calling displayAllDigitYingL()    *
*  (2) Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: -13454

Calling displayAllDigitYingL()with argument of -13454 --

  -13454 is a negative number.
  There is/are 5 digit(s).

  The LSD is 4 and the MSD is 1
  And all digit(s) would be
    4
    5
    4
    3
    1

  There is/are 2 even digit(s).
  There is/are 3 odd digit(s).


******************************************
*              MENU - HW #4              *
*  (1) Calling displayAllDigitYingL()    *
*  (2) Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: 3450406

Calling displayAllDigitYingL()with argument of 3450406 --

  3450406 is a positive number.
  There is/are 7 digit(s).

  The LSD is 6 and the MSD is 3
  And all digit(s) would be
    6
    0
    4
    0
    5
    4
    3

  There is/are 5 even digit(s).
  There is/are 2 odd digit(s).


******************************************
*              MENU - HW #4              *
*  (1) Calling displayAllDigitYingL()    *
*  (2) Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: -3450406

Calling displayAllDigitYingL() with argument of -3450406 --

  -3450406 is a negative number.
  There is/are 7 digit(s).

  The LSD is 6 and the MSD is 3
  And all digit(s) would be
    6
    0
    4
    0
    5
    4
    3

  There is/are 5 even digit(s).
  There is/are 2 odd digit(s).


******************************************
*              MENU - HW #4              *
*  (1) Calling displayAllDigitYingL()    *
*  (2) Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: 0

Calling displayAllDigitYingL() with argument of 0 --

  The given value is ZERO!


******************************************
*              MENU - HW #4              *
*  (1) Calling displayAllDigitYingL()    *
*  (2) Quit                              *
******************************************
Enter an integer for option + Enter: 2

Have fun!
 */

/*Logic_Code_Output Issues
No comments!
 */
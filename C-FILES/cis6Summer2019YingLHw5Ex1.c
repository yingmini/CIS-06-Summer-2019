/**
 * Program Name: cis6Summer2019YingLHw5Ex1.c
 * Discussion:	 Hw #5, Ex #1
 * Written By:	 Ying Hsuen Lin
 * Date:         2019/07/22
 */

#include <stdio.h>

void displayClassInfoYingL();
int displayAllDigitYingL();
int displayUniqueDigitYingL(int);

int main()
{
	displayClassInfoYingL();
	displayAllDigitYingL();

	return 0;
}

void displayClassInfoYingL()
{
	printf("CIS 6 - Introductioin to C Programming\n"
		"Laney College\n"
		"Ying Hsuen Lin\n\n"
		"Assignment Information --\n"
		"  Assignment Number:  Homework 5,\n"
		"                      "
		"Coding Assignment -- Exercise #1\n"
		"  Written by:         Ying Hsuen Lin\n"
		"  Submitted Date:     2019/07/22\n\n");
}

int displayAllDigitYingL()
{
	int option;
	int usrValue;

	do
	{
		printf("******************************************\n"
			"*              MENU - HW #5              *\n"
			"*   1. Calling displayUniqueDigitYingL() *\n"
			"*   2. Quit                              *\n"
			"******************************************\n");

		printf("Enter an integer for option + Enter: ");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			printf("\nEnter an integer: ");
			scanf_s("%d", &usrValue);

		    displayUniqueDigitYingL(usrValue);

			break;
		case 2:
			if (option == 2)
			{
				printf("\nHave fun!\n");
			}
			break;
		default:
			printf("\nWrong Option!\n\n");
		}
	} while (option = 2);
}

int displayUniqueDigitYingL(int usrValue)
{
	int uniqueDigitCount = 0;
	int largestUniqueDigit = 0;
	int smallestUniqueDigit = 0;
	int tmp = usrValue;
	int tmp2 = usrValue;
	int option = (usrValue < 0) ? -usrValue : usrValue;
	int uniqueDigits[10] = { 0 };
	int digit = 0;
	int i;
	int j;
	int k;
	int lsd;

	printf("\nCalling displayAllDigitYingL() --\n\n");

	do
	{
		lsd = option % 10;
		(uniqueDigits[lsd])++;
		digit++;
		option /= 10;
	} while (option);

	if (usrValue == 0)
	{
		printf("  The given value is ZERO!\n\n");
	}
	else
	{

		if (usrValue % 2 == 0)
		{
			printf("  %d is an even value!\n", usrValue);
		}
		else
		{
			printf("  %d is an odd value!\n", usrValue);
		}
		
		for (i = 0; i < 10; i++)
		{
			if (uniqueDigits[i])
			{
				uniqueDigitCount++;
			}
		}

		printf("  There is/are %d unique digit(s).\n", uniqueDigitCount);

		printf("  The unique digit(s) would be\n");
		j = (usrValue) ? -usrValue : usrValue;

		for (j = 0; j < 11; j++)
		{
			if (uniqueDigits[j] > 0)
			{
				printf("    %d seen", j);
				printf(" %d time(s)\n", uniqueDigits[j]);
				largestUniqueDigit = j;
			}
			
		}
		
		for (k = 9; k > -1; k--)
		{
			if (uniqueDigits[k])
			{
				smallestUniqueDigit = k;

			}
		}
		if (digit - 1)
		{
			printf("\n  The smallest unique digit is %d.\n", smallestUniqueDigit);
			printf("  The largest unique digit is %d.\n\n", largestUniqueDigit);
		} 
		else
		{
			printf("\n");
		}
	}
}

/*Program Output
CIS 6 - Introductioin to C Programming
Laney College
Ying Hsuen Lin

Assignment Information --
Assignment Number:  Homework 5,
Coding Assignment -- Exercise #1
Written by:         Ying Hsuen Lin
Submitted Date:     2019/07/22

******************************************
*              MENU - HW #5              *
*   1. Calling displayUniqueDigitYingL() *
*   2. Quit                              *
******************************************
Enter an integer for option + Enter: 6

Wrong Option!

******************************************
*              MENU - HW #5              *
*   1. Calling displayUniqueDigitYingL() *
*   2. Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: -9

Calling displayAllDigitYingL() --

-9 is an odd value!
There is/are 1 unique digit(s).
The unique digit(s) would be
9 seen 1 time(s)

******************************************
*              MENU - HW #5              *
*   1. Calling displayUniqueDigitYingL() *
*   2. Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: -13454

Calling displayAllDigitYingL() --

-13454 is an even value!
There is/are 4 unique digit(s).
The unique digit(s) would be
1 seen 1 time(s)
3 seen 1 time(s)
4 seen 2 time(s)
5 seen 1 time(s)

The smallest unique digit is 1.
The largest unique digit is 5.

******************************************
*              MENU - HW #5              *
*   1. Calling displayUniqueDigitYingL() *
*   2. Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: 3450406

Calling displayAllDigitYingL() --

3450406 is an even value!
There is/are 5 unique digit(s).
The unique digit(s) would be
0 seen 2 time(s)
3 seen 1 time(s)
4 seen 2 time(s)
5 seen 1 time(s)
6 seen 1 time(s)

The smallest unique digit is 0.
The largest unique digit is 6.

******************************************
*              MENU - HW #5              *
*   1. Calling displayUniqueDigitYingL() *
*   2. Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: -3450406

Calling displayAllDigitYingL() --

-3450406 is an even value!
There is/are 5 unique digit(s).
The unique digit(s) would be
0 seen 2 time(s)
3 seen 1 time(s)
4 seen 2 time(s)
5 seen 1 time(s)
6 seen 1 time(s)

The smallest unique digit is 0.
The largest unique digit is 6.

******************************************
*              MENU - HW #5              *
*   1. Calling displayUniqueDigitYingL() *
*   2. Quit                              *
******************************************
Enter an integer for option + Enter: 1

Enter an integer: 0

Calling displayAllDigitYingL() --

The given value is ZERO!

******************************************
*              MENU - HW #5              *
*   1. Calling displayUniqueDigitYingL() *
*   2. Quit                              *
******************************************
Enter an integer for option + Enter: 2

Have fun!
 */

/*Logic_Code_Output Issues
 No comments!
 */
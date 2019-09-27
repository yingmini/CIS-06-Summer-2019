/**
* Program Name: cis6Summer2019YingLHw6Ex1.c
* Discussion:	Hw #6, Ex #1
* Written By:	Ying Hsuen Lin
* Date:	        2019/07/25
*/

#include <stdio.h>

void displayClassInfoYingL();
void displayUniqueEvenOddDigitYingL();
void displayUniqueEvenDigitCount(int [], int size);
void displayUniqueOddDigitCount(int[], int size);
int isCountainingDigit(int, int);

int main()
{
	displayClassInfoYingL();
	displayUniqueEvenOddDigitYingL();

	return 0;
}

void displayClassInfoYingL()
{
	printf("CIS 6 - Introductioin to C Programming\n"
		"Laney College\n"
		"Ying Hsuen Lin\n\n"
		"Assignment Information --\n"
		"  Assignment Number:  Homework 6,\n"
		"                      "
		"Coding Assignment -- Exercise #1\n"
		"  Written by:         Ying Hsuen Lin\n"
		"  Submitted Date:     2019/07/25");
}

void displayUniqueEvenOddDigitYingL()
{
	int option;
	int arySize2[2] = { 0 };
	int size2 = 2;
	int arySize5[5] = { 0 };
	int size5 = 5;
	int sizeOption;
	int tmp;

	do
	{
		printf("\n\n\n************************************************\n"
			"*                    MENU - HW #6              *\n"
			"*  1. Calling displayUniqueEvenOddDigitYingL() *\n"
			"*  2. Quit                                     *\n"
			"************************************************\n");
		
		printf("Enter an int for option + Enter: ");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			do
			{
				printf("\nPlease select the size of the array -- (2 or 5): ");
				scanf_s("%d", &sizeOption);

				switch (sizeOption)
				{
				case 2:
					for (int i = 0; i < 2; i++)
					{
						printf("  Enter value #%d: ", i + 1);
						scanf_s("%d", &arySize2[i]);
					}
					printf("\n  Calling displayUnique"
						"EvenOddDigitYingL() with 2 int's --");

						displayUniqueEvenDigitCount(arySize2, 2);
						displayUniqueOddDigitCount(arySize2, 2);

					break;
				case 5:
					
					for (int i = 0; i < 5; i++)
					{
						printf("\n   Enter value #%d: ", i + 1);
						scanf_s("%d", &arySize5[i]);
					}
					printf("\n  Calling displayUnique"
						"EvenOddDigitYingL() with 5 int's --\n");
					
					displayUniqueEvenDigitCount(arySize5, 5);
					displayUniqueOddDigitCount(arySize5, 5);

					break;
				default:
					printf("\n  Wrong array size: ");
				}

			} while ((sizeOption != 2) && (sizeOption != 5));

			break;
		case 2:
				printf("\nHave fun!\n");
			break;
		default:
			printf("\nWrong Option!");
		}
	} while (option != 2);
}

void displayUniqueEvenDigitCount(int ary[], int size)
{
	int uniqueDigitAry[10] = { 0 };
	int digitExistingAry[10] = { 0 };
	int tmp;
	int i;
	int j;
	int digitCount = 0;
	int evenCount = 0;

	tmp = (ary[0] < 0) ? -ary[0] : ary[0];
	do
	{
		uniqueDigitAry[tmp % 10] = 1;
		
		tmp /= 10;
	} while (tmp);

	for (i = 1; i < size; i++)
	{
		
		tmp = (ary[i] < 0) ? -ary[i] : ary[i];
		do
		{
			
			digitExistingAry[tmp % 10] = 1;
			tmp /= 10;
		} while (tmp);

		for (j = 0; j < 10; j++)
		{
			
			uniqueDigitAry[j] += digitExistingAry[j];
		}

		for (j = 0; j < 10; j++)
		{
			
			digitExistingAry[j] = 0;
		}
	}

	for (j = 0; j < 10; j++)
	{
		if (uniqueDigitAry[j] != 1)
		{
			uniqueDigitAry[j] = 0;
		}
		else if (j % 2 == 0)
		{
			evenCount++;
		}
	}

	if (j % 2 == 0)
	{
		printf("\n    There is/are %d unique even digit(s).",
			evenCount);
		for (j = 0; j < 10; j += 2)
		{
			if (uniqueDigitAry[j])
			{
				for (i = 0; i < size; i++)
				{
					if (isCountainingDigit(ary[i], j) != 0)
					{
						digitCount = 0;
						tmp = (ary[i] < 0) ? -ary[i] : ary[i];
						do
						{
							if (tmp % 10 == j)
							{
								digitCount++;
							}

							tmp /= 10;
						} while (tmp);

						printf("\n    %d occurs %d time(s)", j, digitCount);

						i = size;
					}
					
				}
			}
			
		}
	}
}

void displayUniqueOddDigitCount(int ary[], int size)
{
	int uniqueDigitAry[10] = { 0 };
	int digitExistingAry[10] = { 0 };
	int tmp;
	int i;
	int j;
	int digitCount = 0;
	int oddCount;

	tmp = (ary[0] < 0) ? -ary[0] : ary[0];
	do
	{
		uniqueDigitAry[tmp % 10] = 1;
		tmp /= 10;
	} while (tmp);

	for (i = 1; i < size; i++)
	{
		tmp = (ary[i] < 0) ? -ary[i] : ary[i];
		do
		{
			digitExistingAry[tmp % 10] = 1;
			tmp /= 10;
		} while (tmp);

		for (j = 0; j < 10; j++)
		{
			uniqueDigitAry[j] += digitExistingAry[j];
		}

		for (j = 0; j < 10; j++)
		{
			digitExistingAry[j] = 0;
		}
	}

	oddCount = 0;

	for (j = 0; j < 10; j++)
	{
		if (uniqueDigitAry[j] != 1)
		{
			uniqueDigitAry[j] = 0;
		} 
		else if(j % 2 != 0)
		{
			oddCount++;
		}
	}



		printf("\n    There is/are %d unique odd digit(s).",
			oddCount);
		for (j = 1; j < 10; j += 2)
		{
			if (uniqueDigitAry[j])
			{
				for (i = 0; i < size; i++)
				{
					if (isCountainingDigit(ary[i], j) != 0)
					{
						digitCount = 0;
						tmp = (ary[i] < 0) ? -ary[i] : ary[i];
						do
						{
							if (tmp % 10 == j)
							{
								digitCount++;
							}

							tmp /= 10;
						} while (tmp);

						printf("\n    %d occurs %d time(s)", j, digitCount);

						i = size;
					}

				}
			}

		}
	}


int isCountainingDigit(int value, int digit)
{
	int returnFlag = 0;
	int count = 0;
	int tmp = (value < 0) ? -value : value;

	do
	{
		if (tmp % 10 == digit)
		{
			returnFlag = 1;

			count++;
			tmp = 0;
		}

		tmp /= 10;
	} while (tmp);

	return returnFlag;
}

/*Program Output
CIS 6 - Introductioin to C Programming
Laney College
Ying Hsuen Lin

Assignment Information --
  Assignment Number:  Homework 6,
                      Coding Assignment -- Exercise #1
  Written by:         Ying Hsuen Lin
  Submitted Date:     2019/07/25


************************************************
*                    MENU - HW #6              *
*  1. Calling displayUniqueEvenOddDigitYingL() *
*  2. Quit                                     *
************************************************
Enter an int for option + Enter: 6

Wrong Option!


************************************************
*                    MENU - HW #6              *
*  1. Calling displayUniqueEvenOddDigitYingL() *
*  2. Quit                                     *
************************************************
Enter an int for option + Enter: 1

Please select the size of the array -- (2 or 5): 2
  Enter value #1: -1
  Enter value #2: 18

  Calling displayUniqueEvenOddDigitYingL() with 2 int's --
    There is/are 1 unique even digit(s).
    8 occurs 1 time(s)
    There is/are 0 unique odd digit(s).


************************************************
*                    MENU - HW #6              *
*  1. Calling displayUniqueEvenOddDigitYingL() *
*  2. Quit                                     *
************************************************
Enter an int for option + Enter: 1

Please select the size of the array -- (2 or 5): 5

   Enter value #1: -1

   Enter value #2: 189

   Enter value #3: -20225

   Enter value #4: 180

   Enter value #5: -1767

  Calling displayUniqueEvenOddDigitYingL() with 5 int's --

    There is/are 2 unique even digit(s).
    2 occurs 3 time(s)
    6 occurs 1 time(s)
    There is/are 3 unique odd digit(s).
    5 occurs 1 time(s)
    7 occurs 2 time(s)
    9 occurs 1 time(s)


************************************************
*                    MENU - HW #6              *
*  1. Calling displayUniqueEvenOddDigitYingL() *
*  2. Quit                                     *
************************************************
Enter an int for option + Enter: 2

Have Fun!
*/

/*Logic_Code_Output Issues
No comments!
*/
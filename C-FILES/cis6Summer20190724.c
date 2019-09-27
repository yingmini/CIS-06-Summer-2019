/**
 * Program name: cis6Summer20190724.c
 * Discussion:   HW #6 HCQ & Hints
 * Written By:   Ying Hsuen Lin
 * Date:         2019/07/24
 */

#include <stdio.h>
//#define PI 3.14159265
// const double const_PI = 3.14159265;

//void displayAbsoluteOfInt(void);
void runMenuHw4Ver1(void);
void runMenuHw4Ver2(void);
void runMenuHw4Ver3(void);
void runMenuHw4Ver4(void);

void displayDigitCount(int);
void displayDigitCount2(int);

void displayExistingDigit(int);

int getDigitCountFor6(int);
int getDigitCount(int);
int getDigitCount(int, int);

void displayAllDigitCountVer1(int);
void testAll(void);

void displayAllDigitCountVer2(int);
void displayAllDigitCountWithWhile(int);

void displayDigitCountInfo(int);
int extractLargest(int array[], int size);

void printIntAry(int[], int);
void sortBubble1(int[], int);
void sortBubble2(int[], int);
void sortBubble3(int[], int);
void sortBubble4(int[], int);
void sortBubble5(int[], int);
void sortBubble6(int[], int);
void sortBubble7(int[], int);
void sortBubble8(int[], int);

void getLargestIntegerWithSmallestTDC();

void displayUniqueDigitOnly(int[], int);

int isCountainingDigit(int value, int digit);

int displayUniqueDigitCount(int[], int);
void runMenuHw6();

void runMenuHw6Ver2();
int getLargeIntegerWithSmallTDC(int [], int size);
int getSmallestTDC(int[], int size);

int main()
{
	int ary1[] = { 1189, -202251 };
	int size1 = 2;

	int ary2[] = { -12, 1189, -202251 };
	int size2 = 3;
	/*
	displayUniqueDigitOnly(ary1, size1);
	displayUniqueDigitOnly(ary2, size2);

	int ary1[] = { 2, -42, 42, 13};
	int size1 = 4;

	printf("\nBefore sorting --\n");
	printIntAry(ary1, size1);

	sortBubble2(ary1, size1);
	printf("\nAfter sorting --\n");
	
	int array[5] = { 135, -1969, 54, 1234, -9 };
	int size = 5;
	int largest;

	printf("\nThe address of the array variable array : %p\n", &array);
	printf("\nThe address of the array array : %p\n", array);
	printf("\nThe address of the first element of array : %p\n",
		&array[0]);

	largest = extractLargest(array, size);
	printf("\nThe largest value : %d\n", largest);
	printf("\nAddress of largest : %p\n", &largest);

	printf("\nEnter an int + Enter: ");
	scanf_s("%d", &usrValue);
	*/

	displayUniqueDigitCount(ary1, size1);

	return 0;
}

int getLargeIntegerWithSmallTDC(int ary[], int size)
{
	int largestValueWithSmallestTDC;
	int valueWithSmallestTDC;
	int tdc;
	int tmp;
	int smallestTDC = getSmallestTDC(ary, size);
	
	for (int i = 0; i < size; i++)
	{
		tdc = 0;
		tmp = ary[i];
		do
		{
			tdc++;

			tmp /= 10;
		} while (tmp);

		if (tdc == smallestTDC)
		{
			largestValueWithSmallestTDC = ary[i];  // assumed largest
			i = size;
		}
	}

	for (int i = 0; i < size; i++)
	{
		tdc = 0;
		tmp = ary[i];
		do
		{
			tdc++;

			tmp /= 10;
		} while (tmp);

		if (tdc == smallestTDC)
		{
			if (largestValueWithSmallestTDC < ary[i])
			{
				largestValueWithSmallestTDC = ary[i];
			}
		}
	}

	return largestValueWithSmallestTDC;
}

int getSmallestTDC(int ary[], int size)
{
	int smallestTDC;
	int tdc;
	int tmp;

	tdc = 0;
	tmp = ary[0];
	do
	{
		tdc++;

		tmp /= 10;
	} while (tmp);

	smallestTDC = tdc;

	for (int i = 1; i < size; i++)
	{
		tdc = 0;
		tmp = ary[0];
		do
		{
			tdc++;

			tmp /= 10;
		} while (tmp);

		if (smallestTDC > tdc)
			smallestTDC = tdc;
	}

	return smallestTDC;
}

void runMenuHw6Ver2()
{
	int option;
	int arySize2[2] = { 0 };
	int size2 = 2;
	int arySize5[5] = { 0 };
	int size5 = 5;
	int sizeOption;

	//option = 0;
	do
	{
		printf("\n*****"
			"\n* Menu HW #6 "
			"\n* 1. Calling displayAllDigit()"
			"\n* 2. Quit"
			"\n*****");
		//ask the user for the option
		printf("\nEnter an int for option + Enter: ");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:

			//printf("\nSelect the array size: ");
			//scanf_s("%d", &sizeOption);

			do
			{
				printf("\nSelect the array size: ");
				scanf_s("%d", &sizeOption);

				switch (sizeOption)
				{
				case 2:
					printf("\n  Enter the 2 values for the array of size 2:\n");
					for (int i = 0; i < 2; i++)
					{
						printf("\n   Enter value %d: ", i + 1);
						scanf_s("%d", &arySize2[i]);
					}
					displayUniqueDigitCount(arySize2, 2);

					break;
				case 5:
					printf("\n  Enter the 5 values for the array of size 5:\n");
					for (int i = 0; i < 5; i++)
					{
						printf("\n   Enter value %d: ", i + 1);
						scanf_s("%d", &arySize5[i]);
					}
					displayUniqueDigitCount(arySize5, 5);

					break;
				default:
					printf("\n  Wrong array size: ");
				}

			} while ((sizeOption != 2) && (sizeOption != 5));

			break;
		case 2:
			printf("\nQuit!\n");

			break;
		default:
			printf("\nWrong Option!\n");
		}
	} while (option != 2); // to avoid error

}

void runMenuHw6()
{
	int option;
	int arySize2[2] = { 0 };
	int size2 = 2;
	int arySize5[5] = { 0 };
	int size5 = 5;
	int sizeOption;

	//option = 0;
	do
	{
		printf("\n*****"
			"\n* Menu HW #6 "
			"\n* 1. Calling displayAllDigit()"
			"\n* 2. Quit"
			"\n*****");
		//ask the user for the option
		printf("\nEnter an int for option + Enter: ");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:

			printf("\nSelect the array size: ");
			scanf_s("%d", &sizeOption);
			if (sizeOption == 2)
			{
				printf("\n  Enter the 2 values for the array of size 2:\n");
				for (int i = 0; i < 2; i++)
				{
					printf("\n   Enter value %d: ", i + 1);
					scanf_s("%d", &arySize2[i]);
				}
				displayUniqueDigitCount(arySize2, 2);
			}
			else 
			{
				printf("\n  Enter the 5 values for the array of size 5:\n");
				for (int i = 0; i < 5; i++)
				{
					printf("\n   Enter value %d: ", i + 1);
					scanf_s("%d", &arySize5[i]);
				}
				displayUniqueDigitCount(arySize5, 5);
			}
			break;
		case 2:
			printf("\nQuit!\n");

			break;
		default:
			printf("\nWrong Option!\n");
		}
	} while (option != 2); // to avoid error

}

displayUniqueDigitCount(int ary[], int size)
{
	int uniqueDigitAry[10] = { 0 };
	int digitExistingAry[10] = { 0 };
	int tmp;
	int i;
	int j;
	int digitCount = 0;

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
		} while (tmp);

		for (j = 0; j < 10; j++)
		{
			uniqueDigitAry[j] += digitExistingAry[j];
		}

		for (j = 0; i < 10; j++)
		{
			digitExistingAry[j] = 0;
		}
	}

	for (j = 0; i < 10; j++)
	{
		if (uniqueDigitAry[j] != 1)
		{
			uniqueDigitAry[j] = 0;
		}
	}

	printf("\nWorking with Unique Even Digit(s):\n");
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
						//digitCount++;
						if (tmp % 10 == j)
						{
							digitCount++;
						}

						tmp /= 10;
					} while (tmp);

					printf("\n  %d occurs %d time(s)\n", j, digitCount);

					i = size; // quit the search for the value
				}
			}
		}
	}
}

int isCountainingDigit(int value, int digit)
{
	int returnFlag = 0;
	int tmp = (value < 0) ? -value : value;

	do
	{
		returnFlag = 1;

		tmp = 0;
	} while (tmp);

	return returnFlag;
}

void displayUniqueDigitOnly(int ary[], int size)
{
	int uniqueDigitAry[10] = { 0 };
	int digitExistingAry[10] = { 0 };
	int tmp;
	int i;
	int j;

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
		} while (tmp);

		for (j = 0; j < 10; j++)
		{
			/*
			if ((uniqueDigitAry[j] != 0) && (digitExistingAry[j] == 0))
			{
				uniqueDigitAry[j] = 1;
			}
			else if ((uniqueDigitAry[j] != 0) && (digitExistingAry[j] != 0))
			{
				uniqueDigitAry[j] = 1;
			}
			else if ((uniqueDigitAry[j] == 0) && (digitExistingAry[j] == 0))
			{
				uniqueDigitAry[j] = 0;
			}
			else 
			{
				uniqueDigitAry[j] = 0;
			}
			*/
			uniqueDigitAry[j] += digitExistingAry[j];
		}

		for (j = 0; i < 10; j++)
		{
			digitExistingAry[j] = 0;
		}
	}

	for (j = 0; i < 10; j++)
	{
		if (uniqueDigitAry[j] != 1)
		{
			uniqueDigitAry[j] = 0;
		}
	}

	printf("\nThe unique digits of the given array:\n");
	for (j = 0; j < 10; j++)
	{
		if (uniqueDigitAry[j] == 1)
		{
			printf("\n  1");
		}
		else 
		{
			printf("\n  0");
		}
		printf("\n  %d", uniqueDigitAry);
	}
}

void getLargestIntegerWithSmallestTDC()
{
	int stdc = 0;
	int tmp;
	int tmpDigitCount;
	int arg[10] = { 0 };

	tmp = (arg[0] < 0) ? -arg[0] : arg[0];
	do
	{
		stdc++;
		tmp /= 10;
	} while (tmp);

	for (int i = 1; i < stdc; i++)
	{
		tmp = arg[i];
		tmpDigitCount = 0;
		do
		{
			tmpDigitCount++;
			tmp /= 10;
		} while (tmp);
		if (stdc > tmpDigitCount)
		{
			stdc = tmpDigitCount;
		}
	}
}

void sortBubble8(int ary[], int size)
{
	int tmp;
	int j;
	int i;

	for (i = 1; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (ary[i] < ary[j])
			{
				tmp = ary[i];
				ary[i] = ary[j];
				ary[j] = tmp;
			}
		}
	}
}

void sortBubble7(int ary[], int size)
{
	int tmp;
	int j;
	int i;

	i = 0;
	//for (j = 1; j < size; j++)
	for (j = i + 1; j < size; j++)
	{
		if (ary[i] < ary[j])
		{
			tmp = ary[i];
			ary[i] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 2
	//Second largest to index 1
	
	i = 1;
	//for (j = 2; j < size; j++)
	for (j = i + 1; j < size; j++)
	{
		if (ary[i] < ary[j])
		{
			tmp = ary[i];
			ary[i] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 3
	// Third largest to index 2
	
	i = 2;
	//for (j = 3; j < size; j++)
	for (j = i + 1; j < size; j++)
	{
		if (ary[2] < ary[j])
		{
			tmp = ary[2];
			ary[2] = ary[j];
			ary[j] = tmp;
		}
	}
}

void sortBubble6(int ary[], int size)
{
	int tmp;
	int j;
	int i;

	/*
	for (j = 1; j < size; j++)
	{
		if (ary[0] < ary[j])
		{
			tmp = ary[0];
			ary[0] = ary[j];
			ary[j] = tmp;
		}
	}
	*/

	i = 0;
	for (j = 1; j < size; j++)
	{
		if (ary[i] < ary[j])
		{
			tmp = ary[i];
			ary[i] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 2
	//Second largest to index 1
	/*
	for (j = 2; j < size; j++)
	{
		if (ary[1] < ary[j])
		{
			tmp = ary[1];
			ary[1] = ary[j];
			ary[j] = tmp;
		}
	}
	*/

	i = 1;
	for (j = 2; j < size; j++)
	{
		if (ary[i] < ary[j])
		{
			tmp = ary[i];
			ary[i] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 3
	// Third largest to index 2
	/*
	for (j = 3; j < size; j++)
	{
		if (ary[2] < ary[j])
		{
			tmp = ary[2];
			ary[2] = ary[j];
			ary[j] = tmp;
		}
	}
	*/
	i = 2;
	for (j = 3; j < size; j++)
	{
		if (ary[2] < ary[j])
		{
			tmp = ary[2];
			ary[2] = ary[j];
			ary[j] = tmp;
		}
	}
}

void sortBubble5(int ary[], int size)
{
	int tmp;
	int j;

	for (j = 1; j < size; j++)
	{
		if (ary[0] < ary[j])
		{
			tmp = ary[0];
			ary[0] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 2
	//Second largest to index 1
	for (j = 2; j < size; j++)
	{
		if (ary[1] < ary[j])
		{
			tmp = ary[1];
			ary[1] = ary[j];
			ary[j] = tmp;
		}
	}

	/*
	j = 2;
	if (ary[1] < ary[j])
	{
		tmp = ary[1];
		ary[1] = ary[j];
		ary[j] = tmp;
	}
	j = 3;
	if (ary[1] < ary[j])
	{
		tmp = ary[1];
		ary[1] = ary[j];
		ary[j] = tmp;
	}
	
	//Goal 3
	// Third largest to index 2
	j = 3;
	if (ary[2] < ary[j])
	{
		tmp = ary[2];
		ary[2] = ary[j];
		ary[j] = tmp;
	}
	*/
	for (j = 3; j < size; j++)
	{
		if (ary[2] < ary[j])
		{
			tmp = ary[2];
			ary[2] = ary[j];
			ary[j] = tmp;
		}
	}
}

void sortBubble4(int ary[], int size)
{
	int tmp;
	int j;

	for (j = 1; j < size; j++)
	{
		if (ary[0] < ary[j])
		{
			tmp = ary[0];
			ary[0] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 2
	//Second largest to index 1
	j = 2;
	if (ary[1] < ary[j])
	{
		tmp = ary[1];
		ary[1] = ary[j];
		ary[j] = tmp;
	}
	j = 3;
	if (ary[1] < ary[j])
	{
		tmp = ary[1];
		ary[1] = ary[j];
		ary[j] = tmp;
	}

	//Goal 3
	// Third largest to index 2
	j = 3;
	if (ary[2] < ary[j])
	{
		tmp = ary[2];
		ary[2] = ary[j];
		ary[j] = tmp;
	}
}

void sortBubble3(int ary[], int size)
{
	int tmp;
	int j;
	
	for (j = 1; j < size; j++)
	{
		if (ary[0] < ary[j])
		{
			tmp = ary[0];
			ary[0] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 2
	//Second largest to index 1
	if (ary[1] < ary[2])
	{
		tmp = ary[1];
		ary[1] = ary[2];
		ary[2] = tmp;
	}
	if (ary[1] < ary[3])
	{
		tmp = ary[1];
		ary[1] = ary[3];
		ary[3] = tmp;
	}

	//Goal 3
	// Third largest to index 2

	if (ary[2] < ary[3])
	{
		tmp = ary[2];
		ary[2] = ary[3];
		ary[3] = tmp;
	}
}

void sortBubble2(int ary[], int size)
{
	int tmp;
	int j;
	//Goal #1
	// Largest to index 0
	/*
	j = 1;
	if (ary[0] < ary[j])
	{
		tmp = ary[0];
		ary[0] = ary[j];
		ary[j] = tmp;
	}
	j = 2;
	if (ary[0] < ary[j])
	{
		tmp = ary[0];
		ary[0] = ary[j];
		ary[j] = tmp;
	}
	j = 3;
	if (ary[0] < ary[j])
	{
		tmp = ary[0];
		ary[0] = ary[j];
		ary[j] = tmp;
	}
	*/

	for (j = 1; j < 4; j++)
	{
		if (ary[0] < ary[j])
		{
			tmp = ary[0];
			ary[0] = ary[j];
			ary[j] = tmp;
		}
	}

	//Goal 2
	//Second largest to index 1
	if (ary[1] < ary[2])
	{
		tmp = ary[1];
		ary[1] = ary[2];
		ary[2] = tmp;
	}
	if (ary[1] < ary[3])
	{
		tmp = ary[1];
		ary[1] = ary[3];
		ary[3] = tmp;
	}

	//Goal 3
	// Third largest to index 2

	if (ary[2] < ary[3])
	{
		tmp = ary[2];
		ary[2] = ary[3];
		ary[3] = tmp;
	}
}

void sortBubble1(int ary[], int size)
{
	int tmp;
	//Goal #1
	// Largest to index 0
	if (ary[0] < ary[1])
	{
		tmp = ary[0];
		ary[0] = ary[1];
		ary[1] = tmp;
	}
	if (ary[0] < ary[2])
	{
		tmp = ary[0];
		ary[0] = ary[2];
		ary[2] = tmp;
	}
	if (ary[0] < ary[3])
	{
		tmp = ary[0];
		ary[0] = ary[3];
		ary[3] = tmp;
	}

	//Goal 2
	//Second largest to index 1
	if (ary[1] < ary[2])
	{
		tmp = ary[1];
		ary[1] = ary[2];
		ary[2] = tmp;
	}
	if (ary[1] < ary[3])
	{
		tmp = ary[1];
		ary[1] = ary[3];
		ary[3] = tmp;
	}

	//Goal 3
	// Third largest to index 2

	if (ary[2] < ary[3])
	{
		tmp = ary[2];
		ary[2] = ary[3];
		ary[3] = tmp;
	}
}

void printIntAry(int ary[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("");
	}
}
int extractLargest(int array[], int size)
{
	//int largestValue;
	int largestValue = array[0];

	for (int i = 1; i < size; i++)
	{
		if (largestValue < array[i])
		{
			largestValue = array[i];
		}
	}

	return largestValue;
}

void displayDigitCountInfo(int arg)
{
	int digitCountArray[10] = { 0 };
	int tmp = (arg < 0) ? -arg : arg;
	int digit;

	arg = (arg < 0) ? -arg : arg;
	do
	{
		digitCountArray[tmp % 10]++;
		//digit = tmp % 10;
		//(digitCountArray[digit])++;
		tmp /= 10;
	} while (tmp);
	//add your own code
}

void displayAllDigitCountWithWhile(int arg)
{
	int digitCount;
	int i;

	int tmp;
	int digit;

	i = 0;
	//for (i = 0; i < 10; i++)
	while (i < 10)
	{
		digitCount = 0;
		do
		{
			tmp = (arg < 0) ? -arg : arg;

			digit = tmp % 10;
			if (digit == i)
			{
				digitCount++;
			}
			tmp /= 10;
		}
		while (tmp);
	} 

	printf("\nThere is/are %d digit %d in %d.\n",
		digitCount, i, arg);

	i++;
}

void displayAllDigitCountVer2(int arg)
{
	int digitCount;
	int i;

	int tmp;
	int digit;

	for (i = 0; i < 10; i++)
	{
		digitCount = 0;
		do
		{
			tmp = (arg < 0) ? -arg : arg;

			digit = tmp % 10;
			if (digit == i)
			{
				digitCount++;
			}
			tmp /= 10;
		}
		while (tmp);
	} 

	printf("\nThere is/are %d digit %d in %d.\n",
		digitCount, i, arg);
	
}

void displayAllDigitCountVer1(int arg)
{
	int digit0Count = 0;
	int digit1Count = 0;
	int digit2Count = 0;
	int digit3Count = 0;
	int digit4Count = 0;
	int digit5Count = 0;
	int digit6Count = 0;
	int digit7Count = 0;
	int digit8Count = 0;
	int digit9Count = 0;

	arg = (arg < 0) ? -arg : arg;
	do {
		if (arg % 10 == 0)
		{
			digit0Count++;
		}
		if (arg % 10 == 1)
		{
			digit1Count++;
		}
		if (arg % 10 == 2)
		{
			digit2Count++;
		}
		if (arg % 10 == 3)
		{
			digit3Count++;
		}
		if (arg % 10 == 4)
		{
			digit4Count++;
		}
		if (arg % 10 == 5)
		{
			digit5Count++;
		}
		if (arg % 10 == 6)
		{
			digit6Count++;
		}
		if (arg % 10 == 7)
		{
			digit7Count++;
		}
		if (arg % 10 == 8)
		{
			digit8Count++;
		}
		if (arg % 10 == 9)
		{
			digit9Count++;
		}

		arg /= 10;
	} while (arg);

	printf("\nThere is/are %d digit 0 in %d.\n", digit0Count, arg);
	printf("\nThere is/are %d digit 1 in %d.\n", digit1Count, arg);
	printf("\nThere is/are %d digit 2 in %d.\n", digit2Count, arg);
	printf("\nThere is/are %d digit 3 in %d.\n", digit3Count, arg);
	printf("\nThere is/are %d digit 4 in %d.\n", digit4Count, arg);
	printf("\nThere is/are %d digit 5 in %d.\n", digit5Count, arg);
	printf("\nThere is/are %d digit 6 in %d.\n", digit6Count, arg);
	printf("\nThere is/are %d digit 7 in %d.\n", digit7Count, arg);
	printf("\nThere is/are %d digit 8 in %d.\n", digit8Count, arg);
	printf("\nThere is/are %d digit 9 in %d.\n", digit9Count, arg);
	

}

void testAll()
{
	int usrValue;
	int digitCount;
	int usrDigit;

	printf("\nEnter an int + Enter: ");
	scanf_s("%d", &usrValue);
	//displayDigitCount2(usrValue);
	//displayExistingDigit(usrValue);

	digitCount = getDigitCountFor6(usrValue);
	printf("\nThere is/are %d digit 6 in %d.\n", digitCount, usrValue);

	printf("\nEnter the digit (0, 1, 2, ..., 9): ");
	scanf_s("%d", &usrDigit);
	digitCount = getDigitCount(usrValue, usrDigit);
	printf("\nThere is/are %d digit %d in %d.\n",
		digitCount, usrDigit, usrValue);

	return 0;
}

int getDigitCountFor6(int arg)
{
	int digit6Count = 0;

	arg = (arg < 0) ? -arg : arg;
	do
	{
		if (arg % 10 == 6)
		{
			digit6Count++;
		}

		arg /= 10;
	} while (arg);

	return digit6Count;
}

int getDigitCount(int arg)
{
	int digitCount = 0;
	int usrDigit;

	printf("\nEnter a digit to get its count: ");
	scanf_s("%d", &usrDigit);

    // data validation
	arg = (arg < 0) ? -arg : arg;
	do
	{
		if (arg % 10 == usrDigit)
		{
			digitCount++;
		}
		arg /= 10;
	} while (arg);

	return digitCount;
}

int getDigitCount(int arg, int digit)
{
	int digitCount = 0;

	arg = (arg < 0) ? -arg : arg;
	do
	{
		if (arg % 10 == digit)
		{
			digitCount++;
		}
		arg /= 10;
	} while (arg);

	return digitCount;
}

void displayExistingDigit(int arg)
{
	int tmp = (arg < 0) ? -arg : arg;

	do {
		printf("\n  %d", tmp % 10);

		tmp /= 10;
	} while (tmp);
}

void displayDigitCount2(int arg)
{
	int digitCount = 0;

	do {
		digitCount++;

		arg /= 10;
	} while (arg);

	printf("\nThere is/are %d digit(s)!\n", digitCount);
}

void displayDigitCount(int someValue)
{
	int digitCount;

	if (someValue == 0)
	{
		//printf("\nThere is/are 1 digit(s)!\n");
		digitCount = 1;
	}
	else 
	{
		digitCount = 0;
		while (someValue)
		{
			digitCount++;
			someValue /= 10;
		}
		//printf("\nThere is/are %d digit(s)!\n", digitCount);
	}
	printf("\nThere is/are %d digit(s)!\n", digitCount);
}
void runMenuHw4Ver4()
{
	int option;

	//option = 0;
	do
	{
		printf("\n*****"
			"\n* Menu HW #4 -- Version 4"
			"\n* 1. Calling displayAllDigit()"
			"\n* 2. Quit"
			"\n*****");
		//ask the user for the option
		printf("\nEnter an int for option + Enter: ");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			printf("\nCalling displayAllDigit!()\n");

			break;
		case 2:
			printf("\nQuit!\n");

			break;
		default:
			printf("\nWrong Option!\n");
		}
	} while (option != 2); // to avoid error

}

void runMenuHw4Ver2()
{
	int option;
	//display the menu
	printf("\n*****"
		"\n* Menu HW #4 -- Version 2"
		"\n* 1. Calling displayAllDigit()"
		"\n* 2. Quit"
		"\n*****");
	//ask the user for the option
	printf("\nEnter an int for option + Enter: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		printf("\nCalling displayAllDigit!()\n");
	
		break;
	case 2:
		printf("\nQuit!\n");

		break;
	default:
		printf("\nWrong Option!\n");
	}
}

void runMenuHw4Ver1()
{
	int option;
	//display the menu
	printf("\n*****"
		"\n* Menu HW #4"
		"\n* 1. Calling displayAllDigit()"
		"\n* 2. Quit"
		"\n*****");
	//ask the user for the option
	printf("\nEnter an int for option + Enter: ");
	scanf_s("%d", &option);

	if (option == 1)
	{
		printf("\nCalling displayAllDigit() ...");
	}
	else if (option == 2)
	{
		printf("\nQuit!");
	}
	else
	{
		printf("\nWrong Option!\n");
	}

	return 0;
}

// Application Driver
//int main()
//{
//	int returnDigit1;
//	int returnDigit10;
//	int returnDigit;

//	displayAbsoluteOfInt();
	// calling the function
//	returnDigit1 = extractDigit1();
	// printf() to confirm and so on

	// calling the function
//	returnDigit = extractDigit10();

//	return 0;  
//}
//void displayAbs(void);

//int main()
//{
//	void displayAbs(void);
//	return 0;
//}

// Function Difitnition

//void displayAbs()
//{
//	int usrValue;
//	int absValue;

//	scanf_s("%d", &usrValue);

//	if (usrValue < 0)
//	{
//		absValue = -usrValue;
//	}
//	if (usrValue >= 0)
//	{
//		absValue = usrValue;
//	}

//	printf("\n The absolute value of %d is %d!\n", usrValue, absValue);

//	return 0;
//}

//int extractDigit1()
//{
//	int digit1;
//    code here
//	return digit1;
//}
//void displayAbsoluteOfInt()
//{
//	int usrvalue;

//	printf("Enter an int: ");
//	scanf_s("%d", &usrValue);

//	printf("\nHow do we understand the displayed value of %d\n",
//		(usrvalue < 0) ? -usrvalue : usrvalue);

//	(usrValue >= 0) ? printf("\n%d is non-negative value!\n", usrValue) : printf("\n%d is a negative value\n", usrValue);

//	return 0;
//}

//		printf("\nThe earth temperatures -- "
//			"\nCore: %9d"
//			"\nArizona: %4d"
//			"\nBay Area: %2d"
//			"\nHawaii: %4d", 12000, 125, 85, 75);
//int main()
//{
//	int usrvalue;
//
//	printf("Enter an int: ");
//	scanf_s("%d", &usrvalue);
//
//	printf("\nHow do we understand the displayed value of %d\n",
//		(usrvalue < 0) ? -usrvalue : usrvalue);

//	displayAbsoluteOfInt(); // a function call

//	printf("Enter an int: ");
//	scanf_s("%d", &usrValue);

//	printf("\nHow do we understand the displayed value of %d\n",
//		(usrvalue < 0) ? -usrvalue : usrvalue);

//	return 0;
//}
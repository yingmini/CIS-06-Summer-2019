/**
 * Program Name: cis6Summer2019YingLHw3Ex1.c
 * Discussion:	 Hw #3, Ex #1
 * Written By:	 Ying Hsuen Lin
 * Date:		 2019/07/08
 */

#include <stdio.h>
void displayClassInfoYingL(void);
int extractDigit1YingL();
int extractDigit10YingL();

int main() 
{
	displayClassInfoYingL();
	extractDigit1YingL();
	extractDigit10YingL();

	return 0;
}

void displayClassInfoYingL()
{
	printf("CIS 6 - Introductioin to C Programming\n"
		"Laney College\n"
		"Ying Hsuen Lin\n\n"
		"Assignment Information --\n"
		"  Assignment Number:  Homework 3,\n"
		"                      "
		"Coding Assignment -- Exercise #1\n"
		"  Written by:         Ying Hsuen Lin\n"
		"  Submitted Date:     2019/07/08\n");
}

int extractDigit1YingL()
{
	double usrValue;
	int integralPortion;
	int digit1;

	printf("\nCalling extractDigitYingL()\n"
		"  Enter a floating-point: ");
        scanf_s("%lf", &usrValue);

	(usrValue >= -0.5) ? printf("\n  %.3lf is a non-negative"
		" value!\n\n", usrValue) :
		printf("\n  %.3lf is a negative value\n\n",
		(usrValue < 0) ? usrValue : -usrValue);

	integralPortion = usrValue;
	printf("  The integral portion of %.3lf"
		"  is %d!\n\n", usrValue, integralPortion);

	digit1 = integralPortion % 10;

	printf("After the function extractDigit1YingL()"
		"finished and returned:\n"
		"  1-digit : %d\n", ((digit1 <= 0) ? -digit1 : digit1));

	return 0;
}

int extractDigit10YingL()
{
	double usrValue;
	int integralPortion;
	int digit10;

	printf("\nCalling extractDigitYingL()\n"
		"  Enter a floating-point: ");
	scanf_s("%lf", &usrValue);

	(usrValue >= -0.5) ? printf("\n  %.3lf is a non-negative"
		" value!\n\n", usrValue) :
		printf("\n  %.3lf is a negative value\n\n", 
		(usrValue < 0) ? usrValue : -usrValue);

	integralPortion = usrValue;
	printf("  The integral portion of %.3lf"
		"  is %d!\n\n", usrValue, integralPortion);

	digit10 = (integralPortion / 10) % 10;
	printf("After the function extractDigit1YingL()"
		"finished and returned:\n"
		"  10-digit : %d\n", ((digit10 <= 0) ? -digit10 : digit10));

	return 0;
}

/*Program Output
//--------------- RUN #1 ---------------
// OUPUT - Sample Run #1
CIS 6 - Introductioin to C Programming
Laney College
Ying Hsuen Lin

Assignment Information --
  Assignment Number:  Homework 3,
                      Coding Assignment -- Exercise #1
  Written by:         Ying Hsuen Lin
  Submitted Date:     2019/07/08

Calling extractDigitYingL()
  Enter a floating-point: 12385.456

  12385.456 is a non-negative value!

  The integral portion of 12385.456  is 12385!

After the function extractDigit1YingL()finished and returned:
  1-digit : 5

Calling extractDigitYingL()
  Enter a floating-point: 12385.456

  12385.456 is a non-negative value!

  The integral portion of 12385.456  is 12385!

After the function extractDigit1YingL()finished and returned:
  10-digit : 8
//--------------- RUN #2 ---------------
// OUPUT - Sample Run #2
CIS 6 - Introductioin to C Programming
Laney College
Ying Hsuen Lin

Assignment Information --
  Assignment Number:  Homework 3,
                      Coding Assignment -- Exercise #1
  Written by:         Ying Hsuen Lin
  Submitted Date:     2019/07/08

Calling extractDigitYingL()
  Enter a floating-point: -12385.456

  -12385.456 is a negative value

  The integral portion of -12385.456  is -12385!

After the function extractDigit1YingL()finished and returned:
  1-digit : 5

Calling extractDigitYingL()
  Enter a floating-point: -12385.456

  -12385.456 is a negative value

  The integral portion of -12385.456  is -12385!

After the function extractDigit1YingL()finished and returned:
  10-digit : 8
//--------------- RUN #3 ---------------
// OUPUT - Sample Run #3
CIS 6 - Introductioin to C Programming
Laney College
Ying Hsuen Lin

Assignment Information --
  Assignment Number:  Homework 3,
                      Coding Assignment -- Exercise #1
  Written by:         Ying Hsuen Lin
  Submitted Date:     2019/07/08

Calling extractDigitYingL()
  Enter a floating-point: -1230.456

  -1230.456 is a negative value

  The integral portion of -1230.456  is -1230!

After the function extractDigit1YingL()finished and returned:
  1-digit : 0

Calling extractDigitYingL()
  Enter a floating-point: -1230.456

  -1230.456 is a negative value

  The integral portion of -1230.456  is -1230!

After the function extractDigit1YingL()finished and returned:
  10-digit : 3
//--------------- RUN #4 ---------------
// OUPUT - Sample Run #4
CIS 6 - Introductioin to C Programming
Laney College
Ying Hsuen Lin

Assignment Information --
  Assignment Number:  Homework 3,
					  Coding Assignment -- Exercise #1
  Written by:         Ying Hsuen Lin
  Submitted Date:     2019/07/08

Calling extractDigitYingL()
  Enter a floating-point: -0.456

  -0.456 is a non-negative value!

  The integral portion of -0.456  is 0!

After the function extractDigit1YingL()finished and returned:
  1-digit : 0

Calling extractDigitYingL()
  Enter a floating-point: -0.456

  -0.456 is a non-negative value!

  The integral portion of -0.456  is 0!
*/

/*Logic_Code_Output Issues
No comment!
*/
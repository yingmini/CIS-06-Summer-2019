/**
 * Program Name: cis6Summer2019YingLHw2Ex1.c
 * Discussion:	 Hw #2, Ex #1
 * Written By:	 Ying Hsuen Lin
 * Date:		 2019/06/27
 */

#include <stdio.h>
int main02()
{
	char cVar;
	int iVar;
	double dVar;
	
	printf("Class Information --\n"
		"  CIS 6 - Introductioin to Programming (C)\n"
		"  Laney College\n\n"
		"Assignment Information --\n"
		"  Assignment Number:  Homework 2\n"
		"                      Excercise #1\n"
		"  Written by:         Ying Hsuen Lin\n"
	    "  Due Date:           2019/06/27\n\n\n");

	printf("1234567890123456789012345678901234567890\n");
	
	printf("%8d%8c%10f\n", 23, 'z', 4.1);
	printf("%8c%8d%10f\n", 23, 'z', 4.1);
	printf("%8c%8d%10f\n", 'z', 23, 4.1);
	printf("%8c%10f%8d\n", 'z', 4.1, 23);

	printf("\n");
	printf("%8d%8c%10f\n", 23, 'z', 4.1);
	printf("%8c%8d%10f\n", 23, 'z', 4.1);
	
	cVar = 'z';
	iVar = 23;
	dVar = 4.1;

	printf("%8c%08d%10.4f\n", cVar, iVar, dVar);
	printf("%8c%010.2f%8d\n", cVar, dVar, iVar);
	printf("%-8d%8c\t%10f\n", iVar, cVar, dVar);
	printf("%-12c%12d  %f\n", iVar, cVar, dVar);

	printf("%-8c%08d%10.4f\n", cVar, iVar, dVar);
	printf("%-8c%010.2f%8d", cVar, dVar, iVar);
	return 0;
}

/* Program Output
Class Information --
  CIS 6 - Introductioin to Programming (C)
  Laney College

Assignment Information --
  Assignment Number:  Homework 2
					  Excercise #1
  Written by:         Ying Hsuen Lin
  Due Date:           2019/06/27


1234567890123456789012345678901234567890
	  23       z  4.100000
	   ↨     122  4.100000
	   z      23  4.100000
	   z  4.100000      23

	  23       z  4.100000
	   ↨     122  4.100000
	   z00000023    4.1000
	   z0000004.10      23
23             z          4.100000
↨                    122  4.100000
z       00000023    4.1000
z       0000004.10      23
*/

/* Logic_Code_Output Issues
1. Couldn't make underline in Cover Sheet
*/
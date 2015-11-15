/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <math.h>

char * stringrev(char *str)
{
	int len = 0;
	char *a = str;
	while (*a++)
		len++;
	int i, j;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		char temp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = temp;
	}
	return str;
}

void number_to_str(float number, char *str,int afterdecimal)
{
	str[0] = 0;
	int power = pow(10.0, afterdecimal);
	int num = number * power;
	int i = 0, j;

	if (number < 0)
		num /= -1;

	while (num)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}

	if (number < 0)
		str[i++] = '-';
	str[i] = 0;

	stringrev(str);

	for (j = i - 1; j >= 0 && str[j] == 0; j--)
		;
	str[j + 1] = 0;

	if (afterdecimal > 0)
	{
		int k = i;
		for (j = 0; j <= afterdecimal; j++)
		{
			str[k] = str[k - 1];
			k--;
		}
		str[i - j + 1] = '.';
		str[i + 1] = 0;
	}
}

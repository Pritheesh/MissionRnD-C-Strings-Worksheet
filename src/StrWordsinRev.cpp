/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

int stringlen(char * str)
{
	int len = 0;
	while (*str++)
		len++;
	return len;
}

char * stringrev(char * str, int len)
{
	int i, j;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		char temp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = temp;
	}
	return str;
}

void str_words_in_rev(char *input, int len)
{
	stringrev(input, stringlen(input));
	int i = 0, j = 0;
	while (1)
	{
		if (*(input + i) == ' ' || *(input + i) == 0)
		{
			stringrev(input + j, i - j);//j is pointer to start of word and i-j is length of word
			j = i + 1;
		}
		if (*(input + i) == 0)
			break;
		i++;
	}

}

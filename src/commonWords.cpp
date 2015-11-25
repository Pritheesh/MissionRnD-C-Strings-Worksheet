/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int strlength(char * str)
{
	int len = 0;
	while (*str++)
		len++;
	return len;
}

char * check(char * str1, int len1, char * str2, int len2)
{
	char * temp = (char *)malloc(sizeof(char)* (len1 + 1));
	int i, j, k, count;
	for (i = 0; i < len2; i++)
	{
		k = i;
		count = 0;
		for (j = 0; j < len1; j++)
		{
			if (*(str1 + j) == *(str2 + k))
			{
				k++;
				temp[count] = str1[j];
				count++;
			}
			else
				break;
		}
		if (count == len1)
		{
			temp[count] = 0;
			return temp;
		}
	}
	
	return NULL;
}

char ** commonWords(char *str1, char *str2) 
{

	if (str1 == NULL || str2 == NULL)
		return NULL;
	int len2 = strlength(str2);
	int i = 0, j = 0, k = -1;
	char ** res = (char **)calloc(31, sizeof(char*));
	char * temp;
	while (1)
	{
		
		if (*(str1 + i) == ' ' || *(str1 + i) == 0)
		{
			if (str1[j] != ' ' && str1[j] != 0)
			if (temp = check(str1 + j, i - j, str2, len2))
			{
				k++;
				res[k] = temp;
			}
			j = i + 1;
		}
		if (*(str1 + i) == 0)
			break;
		i++;
	}
	if (k == -1)
		return NULL;
	return res;
}
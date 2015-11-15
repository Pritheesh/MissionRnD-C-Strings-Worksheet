/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
int strlen(char * str)
{
	int len = 0;
	while (*str++)
		len++;
	return len;
}
char KthIndexFromEnd(char *str, int K) 
{
	if (str && K >= strlen(str))
		return '\0';
	if (K < 0 || str == 0)
		return '\0';
	return str[strlen(str) - K - 1];
}
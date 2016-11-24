# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "mystring.h"


char* safestrcat (char *a, char *b);
int substring (char *source, int from, int n, char *target);

/** Method safestrcat
  * combines two given strings (adds second onto first)
  * @param char *a: first string
  * @param char *b: second string
  * @return str: combination of a andd b
  */
char* safestrcat (char *a, char *b)
{
	//x will determine the size of the two strings combined
	int x = strlen(a) + strlen(b);

	//cha* str will be the returned string
	char* str = malloc(sizeof(char)*x);

	//adds the first word into the new string
	for (int t = 0; t < strlen(a); t++)
	{
		str[t] = a[t];
	}//end for loop
	
	//concatenates the second string to the first
	strcat(str, b);
	
	return (str);

}//end safestrcat



/** Method substring
  * Fills a given string with a substring of another string based off specified values
  * @param int from: starting point of the substring
  * @param int n: length of substring
  * @return int: 0 for success or -1 for failure
  */
int substring (char *source, int from, int n, char *target)
{
	//makes sure it is possible to get a substring with the given values
	if (n > (strlen(source)-from) || n < 1)
		return -1; //unsuccessful substring values

	//if it is possible, then get the substring
	else
	{	
		//starts at given value and copies the substring into target
		for (int x = 0; x < n; x++)
		{
			target[x] = source[x+from];
		}//end for loop

		return 0; //successfully copied the substring
	}

}//end substring
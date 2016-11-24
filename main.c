# include <stdio.h>
# include <stdlib.h>
# include "mystring.h"


int main (void)
{
	//testing for the first function, safestrcat
	char aa[]="Hello";
	char bb[]=" World";
	char* result;
	result = safestrcat (aa, bb);
	printf ("The content in variable a is: %s and the content is variable b is : %s\n", aa, bb);
	printf ("The final result is of adding b onto the end of a is: %s\n", result);
	free (result); //frees the char array from heap space

	//test variables for the second function, substring
	char word[] = "abcdefghi";
	char* target = malloc(sizeof(char));
	int from = 2;
	int n = 4;
	int worked = substring (word, from, n, target);

	//based on success of the function, output different things
	if (worked == 0)
		printf ("The %d element substring from the string %s starting at element %d is: %s\n", n, word, from, target);
	else
		printf ("The call of the function substring was not successful\n");

	free (target);//frees the char array from heap space
}
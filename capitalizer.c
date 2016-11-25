#include <stdlib.h>

#include <ctype.h>

#include <stdio.h>

#include <string.h>

int main(int argc, char *argv[]) {
    
    FILE *poem;

    poem = fopen("pome.txt", "r+");

    char string[255];

    long pos = ftell(poem); 
	
    while(fgets(string, 255, poem) != NULL) {

    	int j;
        
    	int size = strlen(string);

        int wordNumber = 1;

    	string[0] = toupper(string[0]);

    	for (j=1 ; j<size ; j++) {

    		if (isalpha(string[j]) && string[j-1] == ' ') {

    			if ((wordNumber % 2) == 0) {

    			string[j] = toupper(string[j]);

    			}

    			wordNumber++;

    		}

    	}

    	fseek(poem, pos, SEEK_SET);

    	fprintf(poem, "%s", string);

    	fflush(poem);

    	pos = ftell(poem);

    }

    fclose(poem);

    return 0;
	
}

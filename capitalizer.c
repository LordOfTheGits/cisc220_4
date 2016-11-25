#include <stdlib.h>

#include <ctype.h>

#include <stdio.h>

#include <string.h>

int main( int argc, char *argv[]) {
    
    FILE *pome;

    pome = fopen(argv[1], "r+");

    char string[500];

    long pos = ftell(pome); 
	
    while(fgets(string, 500, pome) != Null) {

    	int j;
        
    	int size = strlen(string);

        int wordNumber = 1;

    	string[0] = toupper(string[0]);

    	for (j=1 ; j<size ; j++) {

    		if (isalpha(string[j]) && string[j-1] == " ") {

    			if ((wordNumber % 2) == 0) {

    			string[j] = toupper(string[j]);

    			}

    			wordNumber++;

    		}

    	}

    	fseek(pome, pos, SEEK_SET);

    	fprintf(pome, "%s", string);

    	fflush(pome);

    	pos = ftell(pome);

    }

    fclose(pome);

    return 0;
}

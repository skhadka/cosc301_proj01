/*
 *
 * author name, date, and other info here
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "list.h"

void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}

void file_to_LL(FILE *datafile) {  //added this function
	//question from Carrie: do we want the pointer?
    //tokenize everything in file
    //check if int
    //if int, add to linked list
    char * items;
	const char * spc = " \n\t";
	char* tmp;
	char* word;
	int length;
	int i;
	int check;
	int addToList;
	struct node * head = malloc(sizeof(struct node));
	//create first node in memory
	while(fscanf(datafile, "%s", items) != EOF) {
		for(word=strtok_r(s,spc,&tmp); word!=NULL; word=strtok_r(NULL, spc,&tmp)) {
			length = strlen(word);
			i=0;
			check=0;
			for(;i<length;i++) {
				if(isdigit(word[i]==0) {
					check=1; //if part of word/string is not a digit, not happy
					break;
				}
			}
			if(check==0) { //means everything is a number (in the word....)
				addToList = atoi(word);
				list_insert(addToList, &head);
				//this calls to list.c
			}
		}
	}
}


int main(int argc, char **argv) {
    FILE *datafile = NULL;
    /* find out how we got invoked and deal with it */
    switch (argc) {
        case 1:
            /* only one program argument (the program name) */
            /* just equate stdin with our datafile */
            datafile = stdin;
            break;

        case 2:
            /* two arguments: program name and input file */
            /* open the file, assign to datafile */
            datafile = fopen(argv[1], "r");
            if (datafile == NULL) {
                printf("Unable to open file %s: %s\n", argv[1], strerror(errno));
                exit(-1);
            }
            break;

        default:
            perror("Please enter correct number of arguments."); //Carrie added
            /* more than two arguments?  throw hands up in resignation */
            usage(argv[0]);
		//add call to file_to_LL?
		//add getrusage thing?
    }

    /* 
     * you should be able to just read from datafile regardless 
     * whether it's stdin or a "real" file.
     */





    fclose(datafile);
    return 0;
}


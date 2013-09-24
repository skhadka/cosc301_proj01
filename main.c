/*
  Shreeya Khadka and Carrie Burgess
  Project 1: 09/25/13
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <ctype.h>

#include "list.h"

void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}

void file_to_LL(FILE *datafile) {  
    //tokenize everything in file
    //check if int
    //if int, add to linked list
    char items[126];
	struct node * head = (struct node *) malloc(sizeof(struct node));
	//create first node in memory
	while(fgets(items,126,datafile)!= NULL) {
	        //printf("Reading line, word: %s\n",items);
		const char * spc = " \n\t";
		char* tmp;
		char* word;
		for(word=strtok_r(items,spc,&tmp); word!=NULL; word=strtok_r(NULL,spc,&tmp)) {
			int length = strlen(word);
			int i = 0;
			int check = 1;

			if (word[0]=='-') i = 1; //taking care of negative integers
			for(;i<length;i++) {
				if(!isdigit((int)word[i])) {
					check=0; //character is not a digit
					break;
				}
			}
			if(check) { //check=1 -> all characters are digits
				int addToList = atoi(word);
				list_insert(addToList, &head);
				//this calls to list.c
			}
		}
	}
	list_print(&head); 
	list_clear(head);           
}


int main(int argc, char **argv) {
    FILE *datafile = NULL;
    /* find out how we got invoked and deal with it */
    switch (argc) {
        case 1:
            /* only one program argument (the program name) */
            /* just equate stdin with our datafile */
	    //printf("case1: reading stdin\n");
            datafile = stdin;
	    file_to_LL(datafile); //read stdin and put in in LL
            break;

        case 2:
	    //printf("case2: opening file\n");
            /* two arguments: program name and input file */
            /* open the file, assign to datafile */
            datafile = fopen(argv[1], "r");
            if (datafile == NULL) {
                printf("Unable to open file %s: %s\n", argv[1], strerror(errno));
                exit(-1);
            }	
	    file_to_LL(datafile); //read datafile and put in in LL
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


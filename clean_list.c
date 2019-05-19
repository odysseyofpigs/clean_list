/**
 * @file clean_list.c
 * @author Noe Garcia
 * @date 15 May, 2019
 * @description This file contains the functions needed for the clean_list
     functionality. The function takes a list, removes any duplicates it may
     find within the list, and returns the new, clean list.
 * todo none
 * @bugs size, fuck you size
 */
#include "clean_list.h"


/**
 * Function that takes an array and removes all duplicates within the array.
    The given array does not have to be sorted. The newly constructed array
    utilizes 0 as a placeholder for a NULL value within the newly constructed
    array (since static array resizing is not possible).
 * @param *a The given array
 * @param size The size (as an int) of the given array
 */
void nodupl(int *a, int size)
{
        /* err check */
        if (!a) {
                printf("Error: array does not exist\n");
                printf("Program terminated\n\n");
                exit(0);
        }

        int i = 0;    /* used for outer traversal */
        int n = 0;    /* used for inner traversal */
        int dupl = 0; /* used for duplication identification */

        printf("pre-operation\n");
        for (; i < size; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");

        /* find duplicates */
        int newsize = 1;
        int *b = malloc(sizeof(int));
        b[0] = a[0];
        /*memset(b, 0, size*sizeof(int));*/

        /* for each */
        for(i=1; i < size; i++) {
                dupl = 0;

                /* for each element within array *b */
                for(n = 0;n < newsize; n++) {
                        if (a[i] == b[n]) {
                                /* duplicate has been found */
                                dupl = 1;
                        }
                }

                /* if no duplicate was found */
                if (!dupl) {
                        newsize++;
                        b = realloc(b, newsize * sizeof(int));
                        b[newsize-1] = a[i];
                }
        } /* end of for statement *a */


        printf("post-operation\n");
        for (i=0;i<newsize;i++) {
                printf("%d ", b[i]);
        }
        printf("\n");

        /* remake original arary with new array */
        for(i = 0 ; i < newsize; i++) {
                a[i] = b[i];
        }

        if (i < size) {
                for (; i < size; i++) {
                        a[i] = 0;
                }
        }

        free(b);

}

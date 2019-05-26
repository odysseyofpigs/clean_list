/**
 * @file main.c
 * holds the main function for clean_list.c and clean_list.h
 */

#include <stdio.h>
#include "clean_list.h"

int main(void) {
        int i = 0;

        /* define array to be cleaned */
        int a[10] = {6, 3, 6, 7, 4, 3, 9, 5, 2, 6};
        int size = sizeof(a) / sizeof(int);

        nodupl(a,size);

        size = sizeof(a) / sizeof(int);
        printf("newly constructed array\n");
        for (; i < size; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");

        /* define sorted array */
        int d[11] = {1, 2, 2, 3, 5, 6, 6, 7, 7, 7, 9};
        size = sizeof(d) / sizeof(int);

        printf("\n");
        nosdupl(d,size);

        return 0;
}

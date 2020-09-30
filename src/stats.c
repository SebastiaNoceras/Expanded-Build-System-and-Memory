/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief In this file there is the implementation of the functions described 
 * in the file stats.h and the main function
 *
 * There are 7 functions, each function has only one task, these tasks are:
 * find the  median, mean, maximum, minimum, sort, print statistics and print 
 * array given an array of data.
 *
 * @author Sebastià A. Noceras Anderson
 * @date 08/09/2020
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"
/* Size of the Data Set */
#define SIZE (40)

void mainx() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test, SIZE);      // Prints original array
  print_statistics(test, SIZE); // Prints out the statistics
  sort_array(test, SIZE);
  print_array(test, SIZE);      // Prints sorted array
}

void print_statistics(unsigned char * ptr, unsigned int length){

	PRINTF("\nThe mean is: %d\n", find_mean(ptr, SIZE));
	PRINTF("\nThe minimum is: %d\n", find_minimum(ptr, SIZE));
	PRINTF("\nThe maximum is: %d\n", find_maximum(ptr, SIZE));
	PRINTF("\nThe median is: %d\n", find_median(ptr, SIZE));
}

void print_array(unsigned char * ptr, unsigned int length){

       #ifdef VERBOSE
         	for(int i = 0; i < length; ++i){

		if (i == 0) PRINTF("\nThe given array is: [");
		if (i != (length - 1)) PRINTF("%d, ", ptr[i]);
		else PRINTF("%d]\n", ptr[i]);
	}
       #endif
}

unsigned char find_median(unsigned char * ptr, unsigned int length){
        
	unsigned char auxArray[length];
	unsigned char aux;

	for (int i = 0; i < length; i++){ /* It copies the original array to auxArray
					     so the original array keeps untouched */
		auxArray[i] = ptr[i];
	}

	for (int i = 1; i < length; i++){ /* It sorts the auxiliar array from larger
					     to smaller */

		for (int j = 0; j < length - i; j++){

			if (auxArray[j + 1] > auxArray[j]){

				aux = auxArray[j];
				auxArray[j] =  auxArray[j + 1];
				auxArray[j + 1] = aux;
			}
		}
	}

	if (length % 2 == 1) return auxArray[(length - 1) / 2]; /* Returns the middle 
								   value of auxArray */
	else return ((auxArray[length / 2] + auxArray[(length / 2) - 1]) / 2);
	// Returns the average between the two middle values of auxArray
}

unsigned char find_mean(unsigned char * ptr, unsigned int length){
               
	unsigned int sum = 0;

	for (int i = 0; i < length; i++){

		sum += ptr[i];
	}

	if (sum == 0) return 0;
	else return sum/length;
}

unsigned char find_maximum(unsigned char * ptr, unsigned int length){

	unsigned char max = ptr[0];

	for (int i = 1; i < length; ++i){

		if (ptr[i] > max) max = ptr[i];
	}
	
	return max;
}

unsigned char find_minimum(unsigned char * ptr, unsigned int length){

	unsigned char min = ptr[0];

	for (int i = 1; i < length; ++i){

		if (ptr[i] < min) min = ptr[i];
	}
	
	return min;
}

void sort_array(unsigned char * ptr, unsigned int length){

        unsigned char aux; // auxiliar variable

	for (int i = 1; i < length; i++){

		for (int j = 0; j < length - i; j++){

			if (ptr[j + 1] > ptr[j]){

				aux = ptr[j];
				ptr[j] =  ptr[j + 1];
				ptr[j + 1] = aux;
			}
		}
	}
}

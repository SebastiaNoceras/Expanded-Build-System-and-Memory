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
 * @file stats.h 
 * @brief This file contains the function declaration of the functios in file
 * stats.c
 *
 * There are 7 functions, each function has only one task, these tasks are:
 * find the  median, mean, maximum, minimum, sort, print statistics and print 
 * array given an array of data.
 *
 * @author Sebastià A. Noceras Anderson
 * @date 08/09/2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean,
 * and median
 *
 * @param * ptr: Pointer to a data set
 * @param lenght: Number of items in data set
 *
 * @return void 
 */

void print_statistics(unsigned char * ptr, unsigned int length);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param * ptr: Pointer to a data set
 * @param lenght: Number of items in data set
 *
 * @return void
 */

void print_array(unsigned char * ptr, unsigned int lenght);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param * ptr: Pointer to a data set
 * @param lenght: Number of items in data set
 *
 * @return median value
 */

unsigned char find_median(unsigned char * ptr, unsigned int lenght);

/**
 * @brief Given an array of data and a length, returns the mean 
 *
 * @param * ptr: Pointer to a data set
 * @param lenght: Number of items in data set
 *
 * @return mean value
 */

unsigned char find_mean(unsigned char * ptr, unsigned int lenght);

/**
 * @brief Given an array of data and a length, returns the maximum*
 *
 * @param * ptr: Pointer to a data set
 * @param lenght: Number of items in data set
 *
 * @return maximum value
 */

unsigned char find_maximum(unsigned char * ptr, unsigned int lenght);

/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param * ptr: Pointer to a data set
 * @param lenght: Number of items in data set
 *
 * @return minimum value 
 */

unsigned char find_minimum(unsigned char * ptr, unsigned int lenght);

/**
 * @brief Given an array of data and a length, sorts the array from largest
 *  to smallest. (The zeroth Element should be the largest value, and the 
 *  last element (n-1) should be the smallest value)
 * 
 * @param * ptr: Pointer to a data set
 * @param lenght: Number of items in data set
 *
 * @return void
 */

void sort_array(unsigned char * ptr, unsigned int lenght);

#endif /* __STATS_H__ */

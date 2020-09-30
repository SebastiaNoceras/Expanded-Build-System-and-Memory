/******************************************************************************/


/**
 * @file data.h
 * @brief Conversion of integer to ascii and ascii to integer conversion
 *
 * This header file provides an abstraction of reading and
 * writing to data via function calls.
 *
 * @author Sebastia A. Noceras Anderson
 * @date 27/09/2020
 *
 */

/**
 * @brief Converts integer to ascii String
 *
 * Given a pointer to a char data set, and 32 bit integer, 
 * depending on the base provided, it converts the integer to 
 * ascii String representation. 
 *
 * @param ptr Pointer to data array
 * @param data Integer
 * @param base provided from 2 to 16	
 *
 * @return length of the String including null character and if present
 * -ve sign
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts ascii String to integer
 *
 * Given a pointer to a char data set, and the length of the string
 * dependin on the base it converts from ascii string to integer
 *
 * @param ptr Pointer to data array
 * @param digits Length of the String
 * @param base Base provided from 2 to 16
 *
 * @return value of the integer
 * 
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


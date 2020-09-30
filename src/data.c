/*******************************************************************************/

#include <stdint.h>
#include "data.h"


uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){

  int32_t temp;
  char negative = 0;
  uint8_t i = 0, length;
  
  if (data == 0) {
    
    *(ptr) = '0'; 
    *(ptr + 1) = '\0';
    return 2;	
  }
	
  if (data < 0 && base == 10){ // negative base = 10 data
  
    negative = 1;	
    data = -data;
  }
  
  while (data != 0) {
  
    int residuo = data % base;
    if (residuo > 9) *(ptr + i) = residuo - 10 + 'a';
    else *(ptr + i) = residuo + '0';
    i = i + 1;
    data = data / base;
  }

  if (negative == 1) *(ptr + i++) = '-';
	
  length = i;
  i = 0;

  for (i = 0; i < (length / 2); i++){ // reverse
  
    temp = *(ptr + i);
    *(ptr + i) = *(ptr + length - i - 1);
    *(ptr + length - i - 1) = temp;
  }
  
   *(ptr + length)= '\0';
   
  return length+1;
  
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

int32_t data = 0;
uint8_t i = 0;

if(!ptr) // If pointer is not zero
  return -1;

if (digits && (*ptr == '-'))
  i++;

while( i < (digits-1) ) {
  if (*(ptr + i) > '9') data = data*base + (*(ptr + i) + 10 - 'a');
  else data = data*base+ (*(ptr + i) - '0');
  i++;
}
if (digits && (*ptr == '-'))
  data = -data;

return data;
}

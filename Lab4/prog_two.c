//Written by Jiho Kim
 
#include <stdio.h>
#include <limits.h>
#include "read_input.h"

#define SIZE 50

int main(void)
{
  double n = 0;
  char digits[SIZE];  

  int y = EOF;
  
  while (1)
    {
		printf("\n\nEnter a double or press Ctrl-D to quit: ");
		y = read_real(digits, SIZE, &n); 
  
    if(y == 1)
	{
		printf("\nYour double value is: %.7f", n);
		//note that this is saying round off to 7th decimal point. I did not use the %lf because this rounds it off to the 6th decimal point 
		//which was insufficient in what was required in the lab for output (-0.0000067) requires 7 decimal points for full output.
	} else if(y == EOF){
		printf("\nGood Bye.\n");
		break;
    } else
		printf("\n%s is an invalid Double.", digits);
    }
    
  return 0;
}



//Written by Jiho Kim

#include "read_input.h"
 
int read_real(char* digits, int n, double* num)
{
	if(get_string(digits, n)== EOF)
    return EOF;

  if(is_valid_double(digits)){
    *num = convert_to_double(digits);
    return 1;
  }

  return 0;
}
 
 
int is_valid_double(const char* digits)
{
	int i = 0;
	int decimal_counter = 0;

	if(digits[0] <= '9' && digits[0] >= '0' || digits[0] >= '+' || digits[0] >= '-')
	{
		i++;
	}

	while(digits[i] != '\n' && digits[i] != '\0')
	{
		if(digits[i] <= '9' && digits[i] >= '0')
		{
			i++;
		} else if(digits[i] == '.' && decimal_counter == 0){
			i++;
			decimal_counter++;
		} else{
			return 0;
		}
	}
	return 1;
}


 
double convert_to_double(const char *digits)
{
	
	double value = 0;
	double decimal_value = .1;
	int multiplication_factor = 0;
	int i = 0, decimal_point;
	if(digits[0] == '-'){
		multiplication_factor = -1;
		i++;
	} else if (digits[0] == '+'){
		i++;
		multiplication_factor = 1;
	} else {
		multiplication_factor = 1;
	}
	
	while(digits[i] <= '9' && digits[i] >= '0')
	{
		value = value*10 + (digits[i] - '0');
		i++;
	}
	
	if(digits[i] == '.')
	{
		decimal_point = i;
		i++;
		
		while(digits[i] <= '9' && digits[i] >= '0')
		{
			value += decimal_value*(digits[i]-'0');
			decimal_value *= .1;
			i++;
		}
	}
	
	return value*multiplication_factor;
}
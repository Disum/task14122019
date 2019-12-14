#define INPUT_NAME "input.txt"
#define OUTPUT_NAME "output.txt"

#include <stdio.h>
#include "array.h"
#include "function.h"

int main(void)
{
	int n, n_new, result_print;
	char **a = NULL;

	n = read_array(&a, INPUT_NAME);
	if( n<0 )
	{
		switch( n )
		{
			case -1:
				fprintf(stderr, "Can not open file %s for read\n", INPUT_NAME);
				return 1;
			case -2:
				fprintf(stderr, "Can not read length of array from %s\n", INPUT_NAME);
				return 1;
			case -3:
				fprintf(stderr, "Can not allocate memory!\n");
				return 1;
			case -4:
				fprintf(stderr, "Can not read string from %s\n", INPUT_NAME);
				return 1;
			default:
				fprintf(stderr, "Unknown error with code %d\n", n);
				return 1;
		}
	}

	n_new = function(a, n);
	result_print = print_array(a, n_new, OUTPUT_NAME);
	if( result_print!=0 )
	{
		switch( result_print )
		{
			case -1:
				fprintf(stderr, "Can not open(or create) file %s for write\n", OUTPUT_NAME);
				return 1;
			default:
				fprintf(stderr, "Unknown error with code %d\n", result_print);
				return 1;
		}
	}
	free_array(a, n_new);
	return 0;
}

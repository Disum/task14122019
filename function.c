#include <string.h>
#include <stdlib.h>
#include "function.h"

/* Ф-ия выбрасывает из массива участки постоянства длин строк.
 * Возвращается длина получившегося в результате массива.
 * */
int function(char **a, int n)
{
	int i, counter, len1, len2, check;

	counter = 0;
	len1 = strlen(a[0]);
	check = 0;
	for( i = 1; i<n; i++, len1 = len2 )
	{
		len2 = strlen(a[i]);

		if( len1==len2 )
		{
			free(a[i - 1]);
			check = 1;
			continue;
		}

		if( check )// Длина a[i - 1] совпадала с длиной предыдущей, но не совпадает с длиной a[i]
		{
			free(a[i - 1]);
			check = 0;
			continue;
		}

		a[counter] = a[i - 1];
		counter++;
	}
	if( check )
	{
		free(a[i - 1]);
	} else
	{
		a[counter] = a[i - 1];
		counter++;
	}
	return counter;
}

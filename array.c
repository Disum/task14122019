#define LENGTH 1000

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* Считать массив строк из файла.
 * Возвращается -1, если не удалось открыть файл.
 * Возвращается -2, если не удалось считать целую проложительную длину массива.
 * Возвращается -3, если не удалось выделить память.
 * Возвращается -4, если не удалось считать строку.
 * Количество считанных строк, в случае успешного завершения.
 * */
int read_array(char ***a, const char *name)
{
	FILE *input_file;
	int i, j, k, n;
	char buffer[LENGTH];

	if( !(input_file = fopen(name, "r")) )
		return -1;

	if( ( !fgets(buffer, LENGTH, input_file) ) || ( !(sscanf(buffer, "%d", &n)) ) || (n<=0) )
	{
		fclose(input_file);
		return -2;
	}

	if( !(*a = (char **)malloc(n*sizeof(char *))) )
	{
		fclose(input_file);
		return -3;
	}

	for( i = 0; i<n; i++ )
	{
		if( !fgets(buffer, LENGTH, input_file) )
		{
			free_array(*a, i);
			fclose(input_file);
			return -4;
		}

		for( j = 0; (j<LENGTH) && (buffer[j]!='\0') && (buffer[j]!='\n'); j++ ) { }

		if( !((*a)[i] = (char *)malloc((j + 1)*sizeof(char))) )
		{
			free_array(*a, i);
			fclose(input_file);
			return -3;
		}

		for( k = 0; k<j; k++ )
		{
			(*a)[i][k] = buffer[k];
		}
		(*a)[i][j] = '\0';
	}

	fclose(input_file);
	return n;
}

void free_array(char **a, int n)
{
	int i;

	for( i = 0; i<n; i++ )
	{
		free(a[i]);
	}

	free(a);
}

int print_array(char **a, int n, const char *name)
{
	int i;
	FILE *output_file;

	if( !(output_file = fopen(name, "w")) )
		return -1;

	for( i = 0; i<n; i++ )
	{
		fprintf(output_file, "%s\n", a[i]);
	}

	fclose(output_file);
	return 0;
}

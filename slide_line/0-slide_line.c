#include "slide_line.h"
/**
 * slide_line_left - slides and merge an array of integers to the left
 * @line: pointer to an array of integers
 * @size: Size of the array
 * Return: 1 if success, 0 if fails.
 */
int slide_line_left(int *line, size_t size)
{
	int n_1 = 0, n_2 = 0;
	size_t count = 0, i;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && n_1 == 0)
			n_1 = line[i];
		else if (line[i] != 0 && n_1 != 0)
			n_2 = line[i];
		if (n_1 != 0 && n_2 != 0)
		{
			if (n_1 == n_2)
			{
				line[count++] = n_1 + n_2;
				n_1 = 0;
				n_2 = 0;
			}
			else
			{
				line[count++] = n_1;
				n_1 = n_2;
				n_2 = 0;
				if (i == size - 1)
					line[count++] = n_1;
			}
		}
		else if (n_1 != n_2 && i == size - 1)
			line[count++] = n_1;
	}
	for (i = count; i < size; i++)
		line[i] = 0;

	return (1);
}
/**
 * slide_line_right -  * slide_line_left - slides and merge an array of integers to the right
 * @line: pointer to an array of integers.
 * @size: size of the array
 * Return: 1 if success, 0 if fails.
 */
int slide_line_right(int *line, size_t size)
{
	int n_1 = 0, n_2 = 0;
	size_t count = size - 1, i;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && n_1 == 0)
			n_1 = line[i];
		else if (line[i] != 0 && n_1 != 0)
			n_2 = line[i];
		if (n_1 != 0 && n_2 != 0)
		{
			if (n_1 == n_2)
			{
				line[count--] = n_1 + n_2;
				n_1 = 0;
				n_2 = 0;
			}
			else
			{
				line[count--] = n_1;
				n_1 = n_2;
				n_2 = 0;
				if (i == 0)
					line[count--] = n_1;
			}
		}
		else if (n_1 != n_2 && i == 0)
			line[count--] = n_1;
	}
	for (i = 0; i < count + 1; i++)
		line[i] = 0;

	return (1);
}
/**
 * slide_line - slides and merge an integers array.
 * @line: pointer to an integers array.
 * @size: num of array elements.
 * @direction: can be either SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 if success, 0 if fails.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		return (slide_line_left(line, size));
	return (slide_line_right(line, size));
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * charModel - model
 * @x: row
 * @y: column
 * Return: the model
 */
char charModel(size_t x, size_t y)
{
	while (x && y)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (' ');
		x /= 3, y /= 3;
	}
	return ('#');
}
/**
 * menger - menger
 * @level: number of levels
 * Return: nothing
 */
void menger(int level)
{
	size_t len, x, y;

	if (level < 0)
		return;
	len = pow(3, level);
	for (x = 0; x < len; ++x)
	{
		for (y = 0; y < len; ++y)
			printf("%c", charModel(x, y));
		printf("\n");
	}
}

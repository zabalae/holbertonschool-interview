#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First 3x3 sandpile (will hold the result)
 * @grid2: Second 3x3 sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int unstable;

    /* Add grid2 to grid1 */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* Stabilize the sandpile */
    do {
        unstable = 0;

        /* Check if the sandpile is unstable */
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    unstable = 1;
                    break;
                }
            }
            if (unstable)
                break;
        }

        /* If unstable, print the grid */
        if (unstable)
        {
            printf("=\n");
            print_grid(grid1);

            /* Perform the toppling */
            int tmp[3][3] = {0}; /* Temp grid to store the toppling results */

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (grid1[i][j] > 3)
                    {
                        tmp[i][j] -= 4; /* Remove 4 grains from the current cell */
                        if (i - 1 >= 0)
                            tmp[i - 1][j] += 1; /* Add 1 grain to the cell above */
                        if (i + 1 < 3)
                            tmp[i + 1][j] += 1; /* Add 1 grain to the cell below */
                        if (j - 1 >= 0)
                            tmp[i][j - 1] += 1; /* Add 1 grain to the cell to the left */
                        if (j + 1 < 3)
                            tmp[i][j + 1] += 1; /* Add 1 grain to the cell to the right */
                    }
                }
            }

            /* Update grid1 with the results of the toppling */
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    grid1[i][j] += tmp[i][j];
                }
            }
        }
    } while (unstable);
}

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The grid to print
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

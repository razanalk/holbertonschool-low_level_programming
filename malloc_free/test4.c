#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void print_grid(int **grid, int width, int height)
{
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int **grid;

	grid = alloc_grid(6, 4);

	if (grid == NULL)
		return (1);

	print_grid(grid, 6, 4);

	grid[0][3] = 98;
	grid[3][4] = 402;

	printf("\n");

	print_grid(grid, 6, 4);

	free_grid(grid, 4);

	return (0);
}

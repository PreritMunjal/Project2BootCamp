#include <bits/stdc++.h>
#define EMPTY 0
#define N 9
using namespace std;
bool FindEmpty(int grid[N][N],int& row, int& col);
bool Safe(int grid[N][N], int row,int col, int n);
bool Solve(int grid[N][N])
{
	int row, col;
	if (!FindEmpty(grid, row, col))
    {
        return true;
    }
	for (int n = 1; n <= 9; n++)
	{
		if (Safe(grid, row, col, n))
		{
			grid[row][col] = n;
			if (Solve(grid))
            {
                 return true;
            }
			grid[row][col] = EMPTY;
		}
	}
	return false;
}
bool FindEmpty(int grid[N][N],int& row, int& col)
{
	for (row = 0; row < N; row++)
    {
       for (col = 0; col < N; col++)
        {
           if (grid[row][col] == EMPTY)
            {
                 return true;
            }
        }
    }
	return false;
}
bool inRow(int grid[N][N], int row, int n)
{
	for (int col = 0; col < N; col++)
    {
      if (grid[row][col] == n)
        {
                 return true;
        }
    }
    return false;
}
bool inCol(int grid[N][N], int col, int n)
{
	for (int row = 0; row < N; row++)
    {
      if (grid[row][col] == n)
        {
             return true;
        }
    }
    return false;
}
bool inBox(int grid[N][N], int boxStartRow,int boxStartCol, int n)
{
	for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
           if (grid[row + boxStartRow][col + boxStartCol] == n)
           {
               return true;
           }
        }
    }
    return false;
}
bool Safe(int grid[N][N], int row,int col, int n)
{
	return  !inRow(grid, row, n)
            && !inCol(grid, col, n)
            && !inBox(grid, row - row % 3,
                      col - col % 3, n)
            && grid[row][col] == EMPTY;
}
void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
	}
}
int main()
{
	int grid[N][N] = { { 0, 5, 0, 3, 1, 4, 0, 6, 0 },
					{ 8, 7, 0, 0, 0, 9, 4, 0, 3 },
					{ 6, 4, 3, 5, 0, 7, 1, 9, 2 },
					{ 0, 0, 7, 8, 0, 5, 2, 1, 0 },
					{ 4, 1, 0, 9, 0, 0, 0, 0, 6 },
					{ 0, 2, 5, 0, 6, 1, 9, 0, 7 },
					{ 7, 9, 0, 2, 5, 0, 8, 4, 0 },
					{ 0, 8, 4, 0, 9, 6, 0, 0, 5 },
					{ 0, 3, 2, 1, 0, 8, 6, 7, 0 } };
	if (Solve(grid) == true)
    {
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists";
    }
    return 0;
}


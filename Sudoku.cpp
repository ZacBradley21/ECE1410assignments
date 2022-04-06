#include <iostream>
#include "Sudoku.hpp"

bool solvePuzzle(Board board)
{
	int x, y;
	if (!checkNum(board, x, y))
	{
		return true;
	}
	for (int num = 1; num <= 9; num++)
	{
		if (canPlace(board, x, y, num))
		{
			board[x][y] = num;

			if (solvePuzzle(board))
			{
				return true;
			}
			board[x][y] = 0;
		}
	}
	return false;
}

bool checkNum(Board board, int& x, int& y)
{
	for (x = 0; x <= 8; x++)
	{
		for (y = 0; y <= 8; y++)
		{
			if (board[x][y] == 0)
			{
				return true;
			}
		}
	}
	return false;
}


bool canChange(Board board, int x, int y, int num)
{

	for (int column = 0; column <= 8; column++)
	{
		if (column != y && board[x][column] == num)
		{
			return false;
		}
	}

	for (int row = 0; row <= 8; row++)
	{
		if (row != num && board[row][y] == num)
		{
			return false;
		}
	}

	for (int row = (x % 3); row < (x % 3); row++)
	{
		for (int column = (x % 3); column < (x % 3); column++)
		{
			if (row != x && column != y && board[row][column] == num)
			{
				return false;
			}
		}
	}
	return true;
}

bool canPlace(Board board, int x, int y, int num)
{
	return !canChange(board, x, y, num) && (board[x][y] == 0);
}


Board solve(Board board)
{
	if (solvePuzzle(board) == true)
	{
		return board;
	}
	else
	{
		std::cout << "doesn't work" << std::endl;
	}
	return board;
}

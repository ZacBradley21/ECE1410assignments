#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <array>

const size_t SIZE = 9;

typedef std::array<std::array<size_t, SIZE>, SIZE> Board;

bool solvePuzzle(Board board);

bool checkNum(Board board, int& x, int& y);

bool canChange(Board board, int x, int y, int num);

bool canPlace(Board board, int x, int y, int num);

Board solve(Board board);

#endif
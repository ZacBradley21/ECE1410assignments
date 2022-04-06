
#include <gtest/gtest.h>

#include "Sudoku.hpp"


TEST(SudokuTest, StudentWrittenTests)
{
    Board board = { {{0, 0, 0, 0, 3, 0, 6, 4, 0},
                    {0, 3, 0, 7, 0, 5, 8, 0, 0},
                    {8, 2, 0, 0, 9, 6, 0, 7, 0},
                    {0, 0, 0, 0, 7, 0, 2, 9, 6},
                    {0, 0, 3, 4, 2, 9, 0, 1, 0},
                    {2, 9, 8, 5, 6, 1, 4, 0, 7},
                    {7, 0, 2, 9, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 6, 4},
                    {4, 5, 9, 0, 0, 0, 7, 0, 0}} };

    EXPECT_EQ(canChange(board, 0, 1, 1), true);
    EXPECT_EQ(canChange(board, 0, 0, 1), false);
    EXPECT_EQ(canChange(board, 0, 3, 7), true);
    EXPECT_EQ(canChange(board, 8, 0, 7), true);
    EXPECT_EQ(canChange(board, 4, 6, 1), true);
    EXPECT_EQ(canChange(board, 1, 4, 3), true);
    EXPECT_EQ(canChange(board, 0, 1, 5), false);

    Board response = solve(board);

    Board answer = { {{5, 1, 7, 8, 3, 2, 6, 4, 9},
                     {9, 3, 6, 7, 4, 5, 8, 2, 1},
                     {8, 2, 4, 1, 9, 6, 3, 7, 5},
                     {1, 4, 5, 3, 7, 8, 2, 9, 6},
                     {6, 7, 3, 4, 2, 9, 5, 1, 8},
                     {2, 9, 8, 5, 6, 1, 4, 3, 7},
                     {7, 6, 2, 9, 8, 4, 1, 5, 3},
                     {3, 8, 1, 2, 5, 7, 9, 6, 4},
                     {4, 5, 9, 6, 1, 3, 7, 8, 2}} };
    EXPECT_EQ(response, answer);
}

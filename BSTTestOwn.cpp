
#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "BST.hpp"

TEST(OwnWrittenTests, BSTOwn)
{
	Bst<size_t, size_t> bst;
	bst.add(4, 4);
	bst.add(3, 3);
	bst.add(42, 42);
	bst.add(41, 41);
	bst.add(23, 23);
	bst.add(36, 36);
	EXPECT_EQ(bst.size(), 6);

	EXPECT_EQ(bst.at(41), 41);
	EXPECT_EQ(bst.at(3), 3);
	EXPECT_EQ(bst[3], 3);
	EXPECT_EQ(bst[36], 36);

	bst.update(41, 100);
	EXPECT_EQ(bst.at(41), 100);
	EXPECT_EQ(bst[41], 100);

	std::vector<Direction> const path = { Direction::RIGHT, Direction::LEFT, Direction::LEFT, Direction::RIGHT };
	size_t x = bst.traverse(path);
	EXPECT_EQ(x, 36);

	std::vector<Direction> const path1 = { Direction::RIGHT, Direction::RIGHT, Direction::RIGHT };
	EXPECT_THROW(bst.traverse(path1), std::runtime_error);

	EXPECT_THROW(bst.at(27), std::runtime_error);
	EXPECT_THROW(bst[27], std::runtime_error);

	bst.remove(41);
	EXPECT_EQ(bst.size(), 5);
	EXPECT_THROW(bst.at(41), std::runtime_error);
	EXPECT_THROW(bst[41], std::runtime_error);

	EXPECT_THROW(bst.remove(20), std::runtime_error);

	EXPECT_THROW(bst.update(77, 100), std::runtime_error);
}
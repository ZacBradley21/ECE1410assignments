
#include <gtest/gtest.h>
#include "MergeSort.hpp"
#include "BigVector.hpp"
#include "SelectionSort.hpp"

TEST(StudentWrittenTests, MergeSort)
{
	auto ans = merge::sort(numbers);
	EXPECT_EQ(ans, sorted);
}

TEST(StudentWrittenTests, SelectionSort)
{
	auto ans = selection::sort(numbers);
	EXPECT_EQ(ans, sorted);
}
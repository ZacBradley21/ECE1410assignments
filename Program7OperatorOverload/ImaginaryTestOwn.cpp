
#include <gtest/gtest.h>

#include "ImaginaryNumber.hpp"

/*
Program Header
Function Title: ImaginaryTestOwn
Summary: This file are the unit tests given for us to make sure our code works
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Create all tests necessary for comparison and arithmetic
End
*/

TEST(ImaginaryNumberTest, DefaultConstructor)
{
	ImaginaryNumber num;
	EXPECT_EQ(num.getReal(), 0);
	EXPECT_EQ(num.getImaginary(), 0);
}

TEST(ImaginaryNumberTest, PlusEqual)
{
	ImaginaryNumber lhs(2, 2);
	ImaginaryNumber lhs1(2, 2);
	ImaginaryNumber lhs2(2, 2);
	ImaginaryNumber lhs3(2, 2);
	ImaginaryNumber rhs1(4, 0);
	ImaginaryNumber rhs2(0, 6);
	ImaginaryNumber rhs3(5, 6);
	ImaginaryNumber rhs4(0, 0);
	EXPECT_EQ(lhs += rhs1, ImaginaryNumber(6, 2));
	EXPECT_EQ(lhs1 += rhs2, ImaginaryNumber(2, 8));
	EXPECT_EQ(lhs2 += rhs3, ImaginaryNumber(7, 8));
	EXPECT_EQ(lhs3 += rhs4, ImaginaryNumber(2, 2));
}

TEST(ImaginaryNumberTest, Plus)
{
	ImaginaryNumber lhs(2, 2);
	ImaginaryNumber rhs1(4, 0);
	ImaginaryNumber rhs2(0, 6);
	ImaginaryNumber rhs3(5, 6);
	ImaginaryNumber rhs4(0, 0);
	EXPECT_EQ(lhs + rhs1, ImaginaryNumber(6, 2));
	EXPECT_EQ(lhs + rhs2, ImaginaryNumber(2, 8));
	EXPECT_EQ(lhs + rhs3, ImaginaryNumber(7, 8));
	EXPECT_EQ(lhs + rhs4, ImaginaryNumber(2, 2));
}

TEST(ImaginaryNumberTest, MinusEqual)
{
	ImaginaryNumber lhs(2, 2);
	ImaginaryNumber lhs1(2, 2);
	ImaginaryNumber lhs2(2, 2);
	ImaginaryNumber lhs3(2, 2);
	ImaginaryNumber rhs1(4, 0);
	ImaginaryNumber rhs2(0, 6);
	ImaginaryNumber rhs3(5, 6);
	ImaginaryNumber rhs4(0, 0);
	EXPECT_EQ(lhs -= rhs1, ImaginaryNumber(-2, 2));
	EXPECT_EQ(lhs1 -= rhs2, ImaginaryNumber(2, -4));
	EXPECT_EQ(lhs2 -= rhs3, ImaginaryNumber(-3, -4));
	EXPECT_EQ(lhs3 -= rhs4, ImaginaryNumber(2, 2));
}

TEST(ImaginaryNumberTest, Minus)
{
	ImaginaryNumber lhs(2, 2);
	ImaginaryNumber rhs1(4, 0);
	ImaginaryNumber rhs2(0, 6);
	ImaginaryNumber rhs3(5, 6);
	ImaginaryNumber rhs4(0, 0);
	EXPECT_EQ(lhs - rhs1, ImaginaryNumber(-2, 2));
	EXPECT_EQ(lhs - rhs2, ImaginaryNumber(2, -4));
	EXPECT_EQ(lhs - rhs3, ImaginaryNumber(-3, -4));
	EXPECT_EQ(lhs - rhs4, ImaginaryNumber(2, 2));
}

TEST(ImaginaryNumberTest, TimesEqual)
{
	ImaginaryNumber lhs(2, 2);
	ImaginaryNumber lhs1(2, 2);
	ImaginaryNumber lhs2(2, 2);
	ImaginaryNumber lhs3(2, 2);
	ImaginaryNumber rhs1(4, 0);
	ImaginaryNumber rhs2(0, 6);
	ImaginaryNumber rhs3(5, 6);
	ImaginaryNumber rhs4(0, 0);
	EXPECT_EQ(lhs *= rhs1, ImaginaryNumber(8, 0));
	EXPECT_EQ(lhs1 *= rhs2, ImaginaryNumber(0, 12));
	EXPECT_EQ(lhs2 *= rhs3, ImaginaryNumber(10, 12));
	EXPECT_EQ(lhs3 *= rhs4, ImaginaryNumber(0, 0));
}

TEST(ImaginaryNumberTest, Times)
{
	ImaginaryNumber lhs(2, 2);
	ImaginaryNumber rhs1(4, 0);
	ImaginaryNumber rhs2(0, 6);
	ImaginaryNumber rhs3(5, 6);
	ImaginaryNumber rhs4(0, 0);
	EXPECT_EQ(lhs * rhs1, ImaginaryNumber(8, 0));
	EXPECT_EQ(lhs * rhs2, ImaginaryNumber(0, 12));
	EXPECT_EQ(lhs * rhs3, ImaginaryNumber(10, 12));
	EXPECT_EQ(lhs * rhs4, ImaginaryNumber(0, 0));
}

TEST(ImaginaryNumberTest, Greater)
{
	ImaginaryNumber rhs(2, 0);
	ImaginaryNumber lhs1(2, 2);
	ImaginaryNumber lhs2(1, 1);
	ImaginaryNumber lhs3(0, 2);
	ImaginaryNumber lhs4(0, 0);
	EXPECT_EQ(rhs > lhs1, false);
	EXPECT_EQ(rhs > lhs2, false);
	EXPECT_EQ(rhs > lhs3, false);
	EXPECT_EQ(rhs > lhs4, true);
}


TEST(ImaginaryNumberTest, GreaterEqual)
{
	ImaginaryNumber rhs(2, 0);
	ImaginaryNumber rhs1(0, 0);
	ImaginaryNumber lhs1(2, 2);
	ImaginaryNumber lhs2(1, 1);
	ImaginaryNumber lhs3(0, 2);
	ImaginaryNumber lhs4(0, 0);
	EXPECT_EQ(rhs >= lhs1, false);
	EXPECT_EQ(rhs >= lhs2, true);
	EXPECT_EQ(rhs >= lhs3, true);
	EXPECT_EQ(rhs >= lhs4, true);
	EXPECT_EQ(rhs1 >= rhs, false);
	EXPECT_EQ(rhs1 >= lhs1, false);
}

TEST(ImaginaryNumberTest, EqualEqual)
{
	ImaginaryNumber rhs(2, 2);
	ImaginaryNumber lhs1(2, 2);
	ImaginaryNumber lhs2(1, 1);
	ImaginaryNumber lhs3(0, 2);
	ImaginaryNumber lhs4(0, 0);
	EXPECT_EQ(rhs == lhs1, true);
	EXPECT_EQ(rhs == lhs2, false);
	EXPECT_EQ(rhs == lhs3, true);
	EXPECT_EQ(rhs == lhs4, false);
}
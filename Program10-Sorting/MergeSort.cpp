#include <iostream>
#include <vector>
#include "MergeSort.hpp"

/*
Program Header
Function Title: MergeSort
Summary: This function takes a vector, splits it in half, sorts the
halves, then puts them back together after they're sorted.
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Provide a function header to define it for first use
	Provide the function for merge using sortfunction and return
	Define mergefunction by setting a temp variable to the lhs size to start
	Set variable left to the static cast integer temp
	Do the same thing for the right side
	Set three temporary integers equal to zero to be used later
	Use a while loop to compare temporary variables to left and right sides
	Compare if left at t1 is less than right at t2
	If it is, set vector at t to left at t1 and increment t1
	Else, set vector at t to right at t2 and increment t2
	Inside the while loop, increment t
	Use a while loop to compare t1 to left
	While this is true, set vector at t to left at t1
	Continue to increment t1 and t
	Use another while loop to compare t2 to right
	While this is true, set vector at t to right at t2
	Increment t2 and t
	Define sortfunction first by using an if statement
	This will see if the size of the vector is less than or equal to 1
	If it is, return
	We will then get the vector size, and get the real size as an integer
	Then we will get half size by dividing real size by 2
	We will then make two vectors, lhs and rhs
	We can use two for loops to push back the vectors of the lhs and rhs
	Then to use recursion, we can call the same function for lhs and rhs
	We will then merge the sides
End
*/

void sortfunction(std::vector<int>& vector);

std::vector<int> merge::sort(std::vector<int> vectorToSort)
{
	sortfunction(vectorToSort);
	return vectorToSort;
}

void mergefunction(std::vector<int>& lhs, std::vector<int>& rhs, std::vector<int>& vector)
{
	auto temp = lhs.size();
	int left = static_cast<int>(temp);

	auto temp1 = rhs.size();
	int right = static_cast<int>(temp1);

	int t = 0;
	int t1 = 0;
	int t2 = 0;

	while (t1 < left && t2 < right)
	{
		if (lhs[t1] < rhs[t2])
		{
			vector[t] = lhs[t1];
			t1++;
		}
		else
		{
			vector[t] = rhs[t2];
			t2++;
		}
		t++;
	}
	while (t1 < left)
	{
		vector[t] = lhs[t1];
		t1++;
		t++;
	}
	while (t2 < right)
	{
		vector[t] = rhs[t2];
		t2++;
		t++;
	}
}

void sortfunction(std::vector<int>& vector)
{
	if (vector.size() <= 1)
	{
		return;
	}
	auto size = vector.size();
	int rs = static_cast<int>(size);
	int hs = (rs) / 2;
	std::vector<int> lhs;
	std::vector<int> rhs;

	for (int i = 0; i < hs; i++)
	{
		lhs.push_back(vector[i]);
	}
	for (int i = 0; i < (rs) - hs; i++)
	{
		rhs.push_back(vector[hs + i]);
	}
	sortfunction(lhs);
	sortfunction(rhs);
	mergefunction(lhs, rhs, vector);
}
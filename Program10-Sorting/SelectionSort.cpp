#include <vector>
#include "SelectionSort.hpp"

/*
Program Header
Function Title: SelectionSort
Summary: This function takes a vector, finds the minimum value,
stores it in a temporary vector which continues adding the minimum
values to the temporary vector until it is sorted.
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Initialize a variable called size that returns the vector's size
	Use a static cast to make it an int from a size_t
	Sort through the unsorted array element by element
	Check if the temporary sorting algorithm is larger than the unsorted vectors current element
	If it is, put that element in the temporary array
	Check if temporary does not equal i
	If it does not, swap the elements
	Return the sorted vector
End
*/

//Begin
std::vector<int> selection::sort(std::vector<int> vectorToSort)
{
//Initialize a variable called size that returns the vector's size
	auto size = vectorToSort.size();
//Use a static cast to make it an int from a size_t
	int rs = static_cast<int>(size);
//Sort through the unsorted array element by element
	for (int i = 0; i < rs - 1; ++i)
	{
		int temp = i;
		for (int j = i + 1; j < rs; ++j)
		{
//Check if the temporary sorting algorithm is larger than the unsorted vectors current element
			if (vectorToSort[temp] > vectorToSort[j])
			{
//If it is, put that element in the temporary array
				temp = j;
			}
		}
//Check if temporary does not equal i
		if (temp != i)
		{
//If it does not, swap the elements
			std::swap(vectorToSort[i], vectorToSort[temp]);
		}
	}
//Return the sorted vector
	return vectorToSort;
//End
}
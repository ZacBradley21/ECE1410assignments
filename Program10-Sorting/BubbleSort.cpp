
#include <vector>
#include "BubbleSort.hpp"

/*
Program Header
Function Title: BubbleSort
Summary: This function sorts the vector from beginning to end by
comparing the first two elements, putting them in the correct order,
then continuing until the vector is sorted.
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
    Initialize a variable called size that returns the vector's size
	Use a static cast to make it an int from a size_t
    Initialize an integer called temp
    Sort through the unsorted array element by element
    Compare the vector at element j with the one next to it
    If it is greater, set a temporary vector equal to vector at element j
    Then set that element of the vector equal to the next one to continue along
    Then set the next element in the vector to the temporary integer and loop until its sorted
    Return the sorted vector
End
*/

//Begin
std::vector<int> bubble::sort(std::vector<int> vectorToSort)
{
//Initialize a variable called size that returns the vector's size
    auto size = vectorToSort.size();
//Use a static cast to make it an int from a size_t
    int rs = static_cast<int>(size);
//Initialize an integer called temp
    int temp;
//Sort through the unsorted array element by element
    for (int i = 0; i < (rs - 1); i++)
    {
        for (int j = 0; j < (rs - i - 1); j++)
        {
//Compare the vector at element j with the one next to it
            if (vectorToSort[j] > vectorToSort[j + 1])
            {
//If it is greater, set a temporary vector equal to vector at element j
                temp = vectorToSort[j];
//Then set that element of the vector equal to the next one to continue along
                vectorToSort[j] = vectorToSort[j + 1];
//Then set the next element in the vector to the temporary integer and loop until its sorted
                vectorToSort[j + 1] = temp;
            }
        }
    }
//Return the sorted vector
    return vectorToSort;
//End
}
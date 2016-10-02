/*A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left.
For example, if 2 left rotations are performed on array [1, 2, 3, 4, 5], then the array would become [3, 4, 5, 1, 2].
Given an array of integers and a number, d, perform d left rotations on the array.
Then print the updated array as a single line of space-separated integers.
*/

#include <iostream>
#include <vector>

std::vector<int> array_left_rotation(const std::vector<int> data, int size, int shift)
{
    std::vector<int> temp(size);
    
    for (size_t i = 0; i < size; ++i)
    {
        temp[i] = data[(i + shift + size) % size];
    }
    return temp;
}

int main()
{
    std::vector<int> input, result;
    size_t size, shift;
    int num;
    
    std::cin >> size >> shift;
    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> num;
        input.push_back(num);
    }
    
    result = array_left_rotation(input, size, shift);
    for (size_t i = 0; i < size; ++i)
        std::cout << result[i] << " ";
    std::cout << std::endl;
}
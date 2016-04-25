/*
There are N integers in an array A. All but one integer occur in pairs. Your task is to find
the number that occurs only once.

Input Format
The first line of the input contains an integer N, indicating the number of integers.
The next line contains N space-separated integers that form the array A.

Sample Input
5
0 0 1 2 1

Sample Output
2
*/

// The key idea of the solution:
// a ^ a = 0
// a ^ x ^ a = x
// a ^ x ^ b ^ a ^ b = x

#include <iostream>
#include <vector>

int solve (std::vector<int>& a)
{
		int lonely = 0;
		for (auto i: a)
		{
				lonely ^= i;
		}
		return lonely;
}

int main() {
		std::vector<int> v;
		int n, num;
    
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
				std::cin >> num;
				v.push_back(num);
		}
    
		std::cout << solve (v) << std::endl;
		return 0;
}
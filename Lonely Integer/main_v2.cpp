#include <iostream>

int main() {
		int n, num, lonely = 0;
    
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
				std::cin >> num;
				lonely ^= num;
		}
    
		std::cout << lonely << std::endl;
		return 0;
}
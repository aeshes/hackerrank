#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int number_needed(std::string &a, std::string &b)
{
    std::vector<int> freq(26, 0);
    auto count = 0;
    for (auto c : a) { ++freq[c - 'a']; }	// Calc frequences of every symbol in string 'a'
    for (auto c : b) { --freq[c - 'a']; }	// Substract freq. of every symbol in string 'a' from its freq. in 'b'
    for (auto f : freq) { count += abs(f); }	// If frequences of symbol c in string 'a'and 'b' are equal, freq[c] contains zero
    return count;
}

int main(){
    std::string a;
    std::cin >> a;
    std::string b;
    std::cin >> b;
    std::cout << number_needed(a, b) << std::endl;
    return 0;
}